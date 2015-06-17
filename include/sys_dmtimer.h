#ifndef _SYS_DMTIMER_H_
#define _SYS_DMTIMER_H_
/* SYS_DMTIMER register set */
typedef struct{

	/* SYS_DMTIMER_TIDR register bit field */
	union {
		volatile uint32_t TIDR;

		volatile struct {
			unsigned Y_MINOR	: 6;		//5:0
			unsigned CUSTOM		: 2;		//7:6
			unsigned X_MAJOR	: 3;		//10:8
			unsigned R_RTL		: 5;		//15:11
			unsigned FUNC		: 12;		//27:16
			unsigned rsvd28		: 2;		//29:28
			unsigned SCHEME		: 2;		//31:30
		} TIDR_bit;
	} ;	// 0x0

	uint32_t rsvd4[3];		// 0x4 - 0xC

	/* SYS_DMTIMER_TIOCP_CFG register bit field */
	union {
		volatile uint32_t TIOCP_CFG;

		volatile struct {
			unsigned SOFTRESET	: 1;		//0
			unsigned EMUFREE	: 1;		//1
			unsigned IDLEMODE	: 2;		//3:2
			unsigned rsvd4		: 28;		//31:4
		} TIOCP_CFG_bit;
	} ;	// 0x10

	uint32_t rsvd14[3];		// 0x14 - 0x1C

	/* SYS_DMTIMER_IRQ_EOI register bit field */
	union {
		volatile uint32_t IRQ_EOI;

		volatile struct {
			//TODO: AM335x:DMAEVENT_ACK AM437x:LINE_NUMBER
			unsigned DMAEVENT_ACK	: 1;		//0
			unsigned rsvd1			: 31;		//31:1
		} IRQ_EOI_bit;
	} ;	// 0x20

	/* SYS_DMTIMER_IRQSTATUS_RAW register bit field */
	union {
		volatile uint32_t IRQSTATUS_RAW;

		volatile struct {
			unsigned MAT_IT_FLAG	: 1;		//0
			unsigned OVF_IT_FLAG	: 1;		//1
			unsigned TCAR_IT_FLAG	: 1;		//2
			unsigned rsvd3			: 29;		//31:3
		} IRQSTATUS_RAW_bit;
	} ;	// 0x24

	/* SYS_DMTIMER_IRQSTATUS register bit field */
	union {
		volatile uint32_t IRQSTATUS;

		volatile struct {
			unsigned MAT_IT_FLAG	: 1;		//0
			unsigned OVF_IT_FLAG	: 1;		//1
			unsigned TCAR_IT_FLAG	: 1;		//2
			unsigned rsvd3			: 29;		//31:3
		} IRQSTATUS_bit;
	} ;	// 0x28

	/* SYS_DMTIMER_IRQENABLE_SET register bit field */
	union {
		volatile uint32_t IRQENABLE_SET;

		volatile struct {
			unsigned MAT_EN_FLAG	: 1;		//0
			unsigned OVF_EN_FLAG	: 1;		//1
			unsigned TCAR_EN_FLAG	: 1;		//2
			unsigned rsvd3			: 29;		//31:3
		} IRQENABLE_SET_bit;
	} ;	// 0x2C

	/* SYS_DMTIMER_IRQENABLE_CLR register bit field */
	union {
		volatile uint32_t IRQENABLE_CLR;

		volatile struct {
			unsigned MAT_EN_FLAG	: 1;		//0
			unsigned OVF_EN_FLAG	: 1;		//1
			unsigned TCAR_EN_FLAG	: 1;		//2
			unsigned rsvd3			: 29;		//31:3
		} IRQENABLE_CLR_bit;
	} ;	// 0x30

	/* SYS_DMTIMER_IRQWAKEEN register bit field */
	union {
		volatile uint32_t IRQWAKEEN;

		volatile struct {
			unsigned MAT_WUP_ENA	: 1;		//0
			unsigned OVF_WUP_ENA	: 1;		//1
			unsigned TCAR_WUP_ENA	: 1;		//2
			unsigned rsvd3			: 29;		//31:3
		} IRQWAKEEN_bit;
	} ;	// 0x34

	/* SYS_DMTIMER_TCLR register bit field */
	union {
		volatile uint32_t TCLR;

		volatile struct {
			unsigned ST				: 1;		//0
			unsigned AR				: 1;		//1
			unsigned PTV			: 3;		//4:2
			unsigned PRE			: 1;		//5
			unsigned CE				: 1;		//6
			unsigned SCPWM			: 1;		//7
			unsigned TCM			: 2;		//9:8
			unsigned TRG			: 2;		//11:10
			unsigned PT				: 1;		//12
			unsigned CAPT_MODE		: 1;		//13
			unsigned GPO_CFG		: 1;		//14
			unsigned rsvd15			: 17;		//31:15
		} TCLR_bit;
	} ;	// 0x38

	/* SYS_DMTIMER_TCRR register bit field */
	union {
		volatile uint32_t TCRR;

		volatile struct {
			unsigned TIMER_COUNTER	: 32;		//31:0
		} TCRR_bit;
	} ;	// 0x3C

	/* SYS_DMTIMER_TLDR register bit field */
	union {
		volatile uint32_t TLDR;

		volatile struct {
			unsigned LOAD_VALUE		: 32;		//31:0
		} TLDR_bit;
	} ;	// 0x40

	/* SYS_DMTIMER_TTGR register bit field */
	union {
		volatile uint32_t TTGR;

		volatile struct {
			unsigned TTGR_VALUE		: 32;		//31:0
		} TTGR_bit;
	} ;	// 0x44

	/* SYS_DMTIMER_TWPS register bit field */
	union {
		volatile uint32_t TWPS;

		volatile struct {
			unsigned W_PEND_TCLR	: 1;		//0
			unsigned W_PEND_TCRR	: 1;		//1
			unsigned W_PEND_TLDR	: 1;		//2
			unsigned W_PEND_TTGR	: 1;		//3
			unsigned W_PEND_TMAR	: 1;		//4
			unsigned rsvd5			: 27;		//31:5
		} TWPS_bit;
	} ;	// 0x48

	/* SYS_DMTIMER_TMAR register bit field */
	union {
		volatile uint32_t TMAR;

		volatile struct {
			unsigned COMPARE_VALUE	: 32;		//31:0
		} TMAR_bit;
	} ;	// 0x4C

	/* SYS_DMTIMER_TCAR1 register bit field */
	union {
		volatile uint32_t TCAR1;

		volatile struct {
			unsigned CAPTURED_VALUE	: 32;		//31:0
		} TCAR1_bit;
	} ;	// 0x50

	/* SYS_DMTIMER_TSICR register bit field */
	union {
		volatile uint32_t TSICR;

		volatile struct {
			unsigned rsvd0			: 1;		//0
			unsigned SFT			: 1;		//1
			unsigned POSTED			: 1;		//2
			unsigned rsvd3			: 29;		//31:3
		} TSICR_bit;
	} ;	// 0x54

	/* SYS_DMTIMER_TCAR2 register bit field */
	union {
		volatile uint32_t TCAR2;

		volatile struct {
			unsigned CAPTURED_VALUE	: 32;		//31:0
		} TCAR2_bit;
	} ;	// 0x58

} sysDmtimer;

__far volatile sysDmtimer CT_DMTIMER2 __attribute__((cregister("DMTIMER2", far), peripheral));

#endif /* _SYS_DMTIMER_H_ */
