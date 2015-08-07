/**
 *  File	:	pru_virtqueue.c
 *
 *  Summary	:	A virtual queue implementation to simplify vring usage.
 *
 *  Notes	:
 *  - Implementaion of the interface described in "pru_virtqueue.h"
 */
#include <pru_virtqueue.h>

void pru_virtqueue_init (
	struct pru_virtqueue 		*vq,
	struct fw_rsc_vdev_vring 	*vring,
	uint32_t 					to_arm_mbx,
	uint32_t 					from_arm_mbx
)
{
	vq->id = vring->notifyid;
	vq->to_arm_mbx = to_arm_mbx;
	vq->from_arm_mbx = from_arm_mbx;
	vq->last_avail_idx = 0;

	vring_init(&vq->vring, vring->num, (void*)vring->da, vring->align);
}

int16_t pru_virtqueue_get_avail_buf (
	struct pru_virtqueue 	*vq,
	void 					**buf,
	uint32_t 				*len
)
{
	int16_t 			head;
	struct vring_desc 	desc;
	struct vring_avail 	*avail;

	avail = vq->vring.avail;

    /* There's nothing available */
    if (vq->last_avail_idx == avail->idx)
        return PRU_VIRTQUEUE_NO_BUF_AVAILABLE;

	/*
	 * Grab the next descriptor number the ARM host is advertising, and
	 * increment the last available index we've seen.
	 */
	head = avail->ring[vq->last_avail_idx++ & (vq->vring.num - 1)];

	desc = vq->vring.desc[head];
	*buf = (void *)(uint32_t)desc.addr;
	*len = desc.len;

    return (head);
}

int16_t pru_virtqueue_add_used_buf (
	struct pru_virtqueue 	*vq,
	int16_t 				head,
	uint32_t 				len
)
{
    struct vring_used_elem 	*used_elem;
    uint32_t 				num;
    struct vring_used 		*used;

    num = vq->vring.num;
    used = vq->vring.used;

    if (head > num)
        return PRU_VIRTQUEUE_INVALID_HEAD;

    /*
     * The virtqueue's vring contains a ring of used buffers.  Get a pointer to
     * the next entry in that used ring.
     */
    used_elem = &used->ring[used->idx++ & (num - 1)];
    used_elem->id = head;
    used_elem->len = len;

    return PRU_VIRTQUEUE_SUCCESS;
}

int16_t pru_virtqueue_kick (
	struct pru_virtqueue 	*vq
)
{
	/* If requested, do not kick the ARM host */
	if (vq->vring.avail->flags & VRING_AVAIL_F_NO_INTERRUPT)
		return PRU_VIRTQUEUE_NO_KICK;

	/* Kick mailbox with the notify id of the vring in use */
	CT_MBX.MESSAGE[vq->to_arm_mbx] = vq->id;

	return PRU_VIRTQUEUE_SUCCESS;
}
