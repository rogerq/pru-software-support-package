#include <stdint.h>
#include <stdio.h>
#include <pru_cfg.h>
#include <rsc_types.h>
#include <pru_virtqueue.h>
#include <pru_rpmsg.h>
#include <sys_mailbox.h>
#include "resource_table_1.h"

/* The mailboxes used for RPMsg are defined in the Linux device tree
 * PRU0 uses mailboxes 2 (From ARM) and 3 (To ARM)
 * PRU1 uses mailboxes 4 (From ARM) and 5 (To ARM)
 */
#define MB_TO_ARM_HOST		5
#define MB_FROM_ARM_HOST	4

/*
 * The name 'rpmsg-pru' corresponds to the rpmsg_pru driver found
 * at linux-x.y.z/drivers/rpmsg/rpmsg_pru.c
 */
#define CHAN_NAME			"rpmsg-pru"
#define CHAN_DESC			"Channel 31"
#define CHAN_PORT			31

uint8_t payload[RPMSG_BUF_SIZE];

/*
 * main.c
 */
void main() {
	struct pru_rpmsg_transport transport;
	uint16_t src, dst, len;

	/* allow OCP master port access by the PRU so the PRU can read external memories */
	CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;

	/* Initialize pru_virtqueue corresponding to vring0 (PRU to ARM Host direction) */
	pru_virtqueue_init(&transport.virtqueue0, &resourceTable.rpmsg_vring0, MB_TO_ARM_HOST, MB_FROM_ARM_HOST);

	/* Initialize pru_virtqueue corresponding to vring1 (ARM Host to PRU direction) */
	pru_virtqueue_init(&transport.virtqueue1, &resourceTable.rpmsg_vring1, MB_TO_ARM_HOST, MB_FROM_ARM_HOST);

	/* Create the RPMsg channel between the PRU and ARM user space using the transport structure.
	 * The name 'rpmsg-pru' corresponds to the rpmsg_pru driver found
	 * at linux-x.y.z/drivers/rpmsg/rpmsg_pru.c
	 */
	while(pru_rpmsg_channel(RPMSG_NS_CREATE, &transport, CHAN_NAME, CHAN_DESC, CHAN_PORT) != PRU_RPMSG_SUCCESS);
	while(1){
		if(CT_MBX.MESSAGE[MB_FROM_ARM_HOST] == 1){
			/* Receive the message */
			if(pru_rpmsg_receive(&transport, &src, &dst, payload, &len) == PRU_RPMSG_SUCCESS){
				/* Echo the message back to the same address from which we just received */
				pru_rpmsg_send(&transport, dst, src, payload, len);
			}
		}
	}
}
