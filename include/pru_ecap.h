#ifndef _PRU_ECAP_H_
#define _PRU_ECAP_H_

/* PRU_ECAP register set */
typedef struct{

	/* PRU_ECAP_TSCTR register bit field */
	union {
		volatile uint32_t TSCTR;

		volatile struct {
			unsigned TSCTR	: 32;		//31:0
		} TSCTR_bit;
	} ;	// 0x0

	/* PRU_ECAP_CTRPHS register bit field */
	union {
		volatile uint32_t CTRPHS;

		volatile struct {
			unsigned CTRPHS	: 32;		//31:0
		} CTRPHS_bit;
	} ;	// 0x4

	/* PRU_ECAP_CAP1 register bit field */
	union {
		volatile uint32_t CAP1;

		volatile struct {
			unsigned CAP1	: 32;		//31:0
		} CAP1_bit;
	} ;	// 0x8

	/* PRU_ECAP_CAP2 register bit field */
	union {
		volatile uint32_t CAP2;

		volatile struct {
			unsigned CAP2	: 32;		//31:0
		} CAP2_bit;
	} ;	// 0xC

	/* PRU_ECAP_CAP3 register bit field */
	union {
		volatile uint32_t CAP3;

		volatile struct {
			unsigned CAP3	: 32;		//31:0
		} CAP3_bit;
	} ;	// 0x10

	/* PRU_ECAP_CAP4 register bit field */
	union {
		volatile uint32_t CAP4;

		volatile struct {
			unsigned CAP4	: 32;		//31:0
		} CAP4_bit;
	} ;	// 0x14

	uint32_t rsvd118[4];		// 0x118 - 0x124

	/* PRU_ECAP_ECCTL1 register bit field */
	union {
		volatile uint16_t ECCTL1;

		volatile struct {
			uint16_t CAP1POL	: 1;		//0
			uint16_t CTRRST1	: 1;		//1
			uint16_t CAP2POL	: 1;		//2
			uint16_t CTRRST2	: 1;		//3
			uint16_t CAP3POL	: 1;		//4
			uint16_t CTRRST3	: 1;		//5
			uint16_t CAP4POL	: 1;		//6
			uint16_t CTRRST4	: 1;		//7
			uint16_t CAPLDEN	: 1;		//8
			uint16_t PRESCALE	: 5;		//13:9
			uint16_t FREE_SOFT	: 2;		//15:14
		} ECCTL1_bit;
	} ;	// 0x28

	/* PRU_ECAP_ECCTL2 register bit field */
	union {
		volatile uint16_t ECCTL2;

		volatile struct {
			uint16_t CONT_ONESHT	: 1;		//0
			uint16_t STOP_WRAP		: 2;		//2:1
			uint16_t RE_ARM			: 1;		//3
			uint16_t TSCTRSTOP		: 1;		//4
			uint16_t SYNCI_EN		: 1;		//5
			uint16_t SYNCO_SEL		: 2;		//7:6
			uint16_t SWSYNC			: 1;		//8
			uint16_t CAP_APWM		: 1;		//9
			uint16_t APWMPOL		: 1;		//10
			uint16_t rsvd11			: 5;		//15:11
		} ECCTL2_bit;
	} ;	// 0x2A

	/* PRU_ECAP_ECEINT register bit field */
	union {
		volatile uint16_t ECEINT;

		volatile struct {
			uint16_t rsvd0		: 1;		//0
			uint16_t CEVT1		: 1;		//1
			uint16_t CEVT2		: 1;		//2
			uint16_t CEVT3		: 1;		//3
			uint16_t CEVT4		: 1;		//4
			uint16_t CNTOVF		: 1;		//5
			uint16_t PRDEQ		: 1;		//6
			uint16_t CMPEQ		: 1;		//7
			uint16_t rsvd8		: 8;		//15:8
		} ECEINT_bit;
	} ;	// 0x2C

	/* PRU_ECAP_ECFLG register bit field */
	union {
		volatile uint16_t ECFLG;

		volatile struct {
			uint16_t INT		: 1;		//0
			uint16_t CEVT1		: 1;		//1
			uint16_t CEVT2		: 1;		//2
			uint16_t CEVT3		: 1;		//3
			uint16_t CEVT4		: 1;		//4
			uint16_t CNTOVF		: 1;		//5
			uint16_t PRDEQ		: 1;		//6
			uint16_t CMPEQ		: 1;		//7
			uint16_t rsvd8		: 8;		//15:8
		} ECFLG_bit;
	} ;	// 0x2E

	/* PRU_ECAP_ECCLR register bit field */
	union {
		volatile uint16_t ECCLR;

		volatile struct {
			uint16_t INT		: 1;		//0
			uint16_t CEVT1		: 1;		//1
			uint16_t CEVT2		: 1;		//2
			uint16_t CEVT3		: 1;		//3
			uint16_t CEVT4		: 1;		//4
			uint16_t CNTOVF		: 1;		//5
			uint16_t PRDEQ		: 1;		//6
			uint16_t CMPEQ		: 1;		//7
			uint16_t rsvd8		: 8;		//15:8
		} ECCLR_bit;
	} ;	// 0x30

	/* PRU_ECAP_ECFRC register bit field */
	union {
		volatile uint16_t ECFRC;

		volatile struct {
			uint16_t rsvd0		: 1;		//0
			uint16_t CEVT1		: 1;		//1
			uint16_t CEVT2		: 1;		//2
			uint16_t CEVT3		: 1;		//3
			uint16_t CEVT4		: 1;		//4
			uint16_t CNTOVF		: 1;		//5
			uint16_t PRDEQ		: 1;		//6
			uint16_t CMPEQ		: 1;		//7
			uint16_t rsvd8		: 8;		//15:8
		} ECFRC_bit;
	} ;	// 0x32

	uint32_t rsvd134[10];		// 0x134 - 0x158

	/* PRU_ECAP_REVID register bit field */
	union {
		volatile uint32_t REVID;

		volatile struct {
			unsigned REV		: 32;		//31:0
		} REVID_bit;
	} ;	// 0x5C
} pruEcap;

#endif /* _PRU_ECAP_H_ */
