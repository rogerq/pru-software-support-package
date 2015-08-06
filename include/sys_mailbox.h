#ifndef _SYS_MAILBOX_H_
#define _SYS_MAILBOX_H_
/* SYS_MAILBOX register set */
typedef struct{

	/* SYS_MAILBOX_REVISION register bit field */
	union {
		volatile uint32_t REVISION;

		volatile struct {
			unsigned MINOR 	: 6;		//5:0
			unsigned CUSTOM : 2;		//7:6
			unsigned MAJOR 	: 3;		//10:8
			unsigned RTL 	: 5;		//15:11
			unsigned FUNC 	: 12;		//27:16
			unsigned rsvd28 : 2;		//29:28
			unsigned SCHEME : 2;		//31:30
		} REVISION_bit;
	} ;	// 0x0

	uint32_t rsvd4[3];		// 0x4 - 0xC

	/* SYS_MAILBOX_SYSCONFIG register bit field */
	union {
		volatile uint32_t SYSCONFIG;

		volatile struct {
			unsigned SOFTRESET 	: 1;	//0
			unsigned rsvd 		: 1;	//1
			unsigned SLIDLEMODE : 2;	//3:2
			unsigned rsvd1 		: 28;	//31:4
		} SYSCONFIG_bit;
	} ;	// 0x10

	uint32_t rsvd14[11];		// 0x14 - 0x3C

	/* SYS_MAILBOX_MESSAGE register bit fields */
	union {
		volatile uint32_t MESSAGE[8];

		volatile struct {
			unsigned MESSAGE : 32;		//31:0
		} MESSAGE_bit[8];
	} ;	// 0x40-0x5C

	uint32_t rsvd60[8];		// 0x60 - 0x7C

	/* SYS_MAILBOX_FIFOSTATUS register bit fields */
	union {
		volatile uint32_t FIFOSTATUS[8];

		volatile struct {
			unsigned FIFOFULL 	: 1;		//0
			unsigned rsvd	 	: 31;		//31:1
		} FIFOSTATUS_bit[8];
	} ;	// 0x80-0x9C

	uint32_t rsvdA0[8];		// 0xA0 - 0xBC

	/* SYS_MAILBOX_MSGSTATUS register bit fields */
	union {
		volatile uint32_t MSGSTATUS[8];

		volatile struct {
			unsigned NBOFMSG : 3;		//2:0
			unsigned rsvd	 : 29;		//31:3
		} MSGSTATUS_bit[8];
	} ;	// 0xC0-DC

	uint32_t rsvdE0[8];		// 0xE0 - 0xFC

	volatile struct {
		union {
			volatile uint32_t STATUS_RAW;

			volatile struct {
				unsigned NEWMSGSTATUSMB0 	: 1;		//0
				unsigned NOTFULLSTATUSMB0 	: 1;		//1
				unsigned NEWMSGSTATUSMB1 	: 1;		//2
				unsigned NOTFULLSTATUSMB1 	: 1;		//3
				unsigned NEWMSGSTATUSMB2 	: 1;		//4
				unsigned NOTFULLSTATUSMB2 	: 1;		//5
				unsigned NEWMSGSTATUSMB3 	: 1;		//6
				unsigned NOTFULLSTATUSMB3 	: 1;		//7
				unsigned NEWMSGSTATUSMB4 	: 1;		//8
				unsigned NOTFULLSTATUSMB4 	: 1;		//9
				unsigned NEWMSGSTATUSMB5 	: 1;		//10
				unsigned NOTFULLSTATUSMB5 	: 1;		//11
				unsigned NEWMSGSTATUSMB6 	: 1;		//12
				unsigned NOTFULLSTATUSMB6 	: 1;		//13
				unsigned NEWMSGSTATUSMB7 	: 1;		//14
				unsigned NOTFULLSTATUSMB7 	: 1;		//15
				unsigned rsvd				: 16;		//31:16
			} STATUS_RAW_bit;
		};
		union {
			volatile uint32_t STATUS_CLR;

			volatile struct {
				unsigned NEWMSGSTATUSMB0 	: 1;		//0
				unsigned NOTFULLSTATUSMB0 	: 1;		//1
				unsigned NEWMSGSTATUSMB1 	: 1;		//2
				unsigned NOTFULLSTATUSMB1 	: 1;		//3
				unsigned NEWMSGSTATUSMB2 	: 1;		//4
				unsigned NOTFULLSTATUSMB2 	: 1;		//5
				unsigned NEWMSGSTATUSMB3 	: 1;		//6
				unsigned NOTFULLSTATUSMB3 	: 1;		//7
				unsigned NEWMSGSTATUSMB4 	: 1;		//8
				unsigned NOTFULLSTATUSMB4 	: 1;		//9
				unsigned NEWMSGSTATUSMB5 	: 1;		//10
				unsigned NOTFULLSTATUSMB5 	: 1;		//11
				unsigned NEWMSGSTATUSMB6 	: 1;		//12
				unsigned NOTFULLSTATUSMB6 	: 1;		//13
				unsigned NEWMSGSTATUSMB7 	: 1;		//14
				unsigned NOTFULLSTATUSMB7 	: 1;		//15
				unsigned rsvd				: 16;		//31:16
			} STATUS_CLR_bit;
		};
		union {
			volatile uint32_t ENABLE_SET;

			volatile struct {
				unsigned NEWMSGSTATUSMB0 	: 1;		//0
				unsigned NOTFULLSTATUSMB0 	: 1;		//1
				unsigned NEWMSGSTATUSMB1 	: 1;		//2
				unsigned NOTFULLSTATUSMB1 	: 1;		//3
				unsigned NEWMSGSTATUSMB2 	: 1;		//4
				unsigned NOTFULLSTATUSMB2 	: 1;		//5
				unsigned NEWMSGSTATUSMB3 	: 1;		//6
				unsigned NOTFULLSTATUSMB3 	: 1;		//7
				unsigned NEWMSGSTATUSMB4 	: 1;		//8
				unsigned NOTFULLSTATUSMB4 	: 1;		//9
				unsigned NEWMSGSTATUSMB5 	: 1;		//10
				unsigned NOTFULLSTATUSMB5 	: 1;		//11
				unsigned NEWMSGSTATUSMB6 	: 1;		//12
				unsigned NOTFULLSTATUSMB6 	: 1;		//13
				unsigned NEWMSGSTATUSMB7 	: 1;		//14
				unsigned NOTFULLSTATUSMB7 	: 1;		//15
				unsigned rsvd				: 16;		//31:16
			} ENABLE_SET_bit;
		};
		union {
			volatile uint32_t ENABLE_CLR;

			volatile struct {
				unsigned NEWMSGSTATUSMB0 	: 1;		//0
				unsigned NOTFULLSTATUSMB0 	: 1;		//1
				unsigned NEWMSGSTATUSMB1 	: 1;		//2
				unsigned NOTFULLSTATUSMB1 	: 1;		//3
				unsigned NEWMSGSTATUSMB2 	: 1;		//4
				unsigned NOTFULLSTATUSMB2 	: 1;		//5
				unsigned NEWMSGSTATUSMB3 	: 1;		//6
				unsigned NOTFULLSTATUSMB3 	: 1;		//7
				unsigned NEWMSGSTATUSMB4 	: 1;		//8
				unsigned NOTFULLSTATUSMB4 	: 1;		//9
				unsigned NEWMSGSTATUSMB5 	: 1;		//10
				unsigned NOTFULLSTATUSMB5 	: 1;		//11
				unsigned NEWMSGSTATUSMB6 	: 1;		//12
				unsigned NOTFULLSTATUSMB6 	: 1;		//13
				unsigned NEWMSGSTATUSMB7 	: 1;		//14
				unsigned NOTFULLSTATUSMB7 	: 1;		//15
				unsigned rsvd				: 16;		//31:16
			} ENABLE_CLR_bit;
		};
	} IRQ[4];

} sysMailbox;

volatile __far sysMailbox CT_MBX __attribute__((cregister("MBX0", far), peripheral));

#endif /* _SYS_MAILBOX_H_ */
