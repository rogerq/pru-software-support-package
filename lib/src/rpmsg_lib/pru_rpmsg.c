/**
 *  File	:	pru_rpmsg.c
 *
 *  Summary	:	An RPMsg implementation for the PRU to use while communicating
 *  			with the ARM host.
 *
 *  Notes	:
 *  - Implementaion of the interface described in "pru_rpmsg.h"
 */

#include <pru_rpmsg.h>

struct pru_rpmsg_hdr {
	uint32_t 	src;
	uint32_t 	dst;
	uint32_t 	reserved;
	uint16_t 	len;
	uint16_t 	flags;
	uint8_t 	data[0];
};

struct pru_rpmsg_ns_msg {
    char 		name[RPMSG_NAME_SIZE];
    char 		desc[RPMSG_NAME_SIZE];
    uint32_t 	addr;
    uint32_t 	flags;
};

int16_t pru_rpmsg_send (
	struct pru_rpmsg_transport 	*transport,
	uint32_t 					src,
	uint32_t 					dst,
	void 						*data,
	uint16_t 					len
)
{
	struct pru_rpmsg_hdr 	*msg;
	uint32_t 				msg_len;
	int16_t 				head;
	struct pru_virtqueue 	*virtqueue;

	/*
	 * The length of our payload is larger than the maximum RPMsg buffer size
	 * allowed
	 */
	if(len > (RPMSG_BUF_SIZE - sizeof(struct pru_rpmsg_hdr)))
		return PRU_RPMSG_BUF_TOO_SMALL;

	virtqueue = &transport->virtqueue0;

	/* Get an available buffer */
	head = pru_virtqueue_get_avail_buf(virtqueue, (void **)&msg, &msg_len);

	if(head < 0)
		return PRU_RPMSG_NO_BUF_AVAILABLE;

	/* Copy local data buffer to the descriptor buffer address */
	memcpy(msg->data, data, len);
	msg->len = len;
	msg->dst = dst;
	msg->src = src;
	msg->flags = 0;
	msg->reserved = 0;

	/* Add the used buffer */
	if(pru_virtqueue_add_used_buf(virtqueue, head, msg_len) < 0)
		return PRU_RPMSG_INVALID_HEAD;

	/* Kick the ARM host */
	pru_virtqueue_kick(virtqueue);

	return PRU_RPMSG_SUCCESS;
}

int16_t pru_rpmsg_receive (
	struct pru_rpmsg_transport 	*transport,
	uint16_t 					*src,
	uint16_t 					*dst,
	void 						*data,
	uint16_t 					*len
)
{
	int16_t 				head;
	struct pru_rpmsg_hdr 	*msg;
	uint32_t 				msg_len;
	struct pru_virtqueue 	*virtqueue;

	virtqueue = &transport->virtqueue1;

	/* Get an available buffer */
	head = pru_virtqueue_get_avail_buf(virtqueue, (void **)&msg, &msg_len);

	if(head < 0)
		return PRU_RPMSG_NO_BUF_AVAILABLE;


	/* Copy the message payload to the local data buffer provided */
	memcpy(data, msg->data, msg->len);
	*src = msg->src;
	*dst = msg->dst;
	*len = msg->len;

	/* Add the used buffer */
	if(pru_virtqueue_add_used_buf(virtqueue, head, msg_len) < 0)
		return PRU_RPMSG_INVALID_HEAD;

	/* Kick the ARM host */
	pru_virtqueue_kick(virtqueue);

	return PRU_RPMSG_SUCCESS;
}

int16_t pru_rpmsg_channel (
	enum pru_rpmsg_ns_flags 	flags ,
	struct pru_rpmsg_transport 	*transport,
	char 						*name,
	char 						*desc,
	int32_t 					port
)
{
    struct pru_rpmsg_ns_msg 	ns_msg;
    uint8_t 					i;

    for(i = 0; i < RPMSG_NAME_SIZE; i++){
    	ns_msg.name[i] = name[i];
    	ns_msg.desc[i] = desc[i];
    }
    ns_msg.addr = port;
    ns_msg.flags = flags;

    return pru_rpmsg_send(transport, port, 53, &ns_msg, sizeof(ns_msg));
}
