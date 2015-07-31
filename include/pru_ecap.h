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
	volatile uint16_t ECCTL1; // 0x28

	/* PRU_ECAP_ECCTL2 register bit field */
	volatile uint16_t ECCTL2;	// 0x2A

	/* PRU_ECAP_ECEINT register bit field */
	volatile uint16_t ECEINT;	// 0x2C

	/* PRU_ECAP_ECFLG register bit field */
	volatile uint16_t ECFLG;	// 0x2E

	/* PRU_ECAP_ECCLR register bit field */
	volatile uint16_t ECCLR;	// 0x30

	/* PRU_ECAP_ECFRC register bit field */
	volatile uint16_t ECFRC;	// 0x32

	uint32_t rsvd34[10];		// 0x34 - 0x58

	/* PRU_ECAP_REVID register bit field */
	union {
		volatile uint32_t REVID;

		volatile struct {
			unsigned REV		: 32;		//31:0
		} REVID_bit;
	} ;	// 0x5C
} pruEcap;

volatile far pruEcap CT_ECAP __attribute__((cregister("PRU_ECAP", near), peripheral));

#endif /* _PRU_ECAP_H_ */
