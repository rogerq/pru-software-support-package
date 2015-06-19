#ifndef _SYS_PWMSS_H_
#define _SYS_PWMSS_H_
/* SYS_PWMSS register set */
typedef struct{

	/***************************/
	/* PWM Subsystem Registers */
	/***************************/
	/* SYS_PWMSS_IDVER register bit field */
	union {
		volatile uint32_t IDVER;

		volatile struct {
			unsigned Y_MINOR	: 6;		//5:0
			unsigned CUSTOM		: 2;		//7:6
			unsigned X_MAJOR	: 3;		//10:8
			unsigned R_RTL		: 5;		//15:11
			unsigned FUNC		: 12;		//27:16
			unsigned rsvd28		: 2;		//29:28
			unsigned SCHEME		: 2;		//31:30
		} IDVER_bit;
	} ;	// 0x0

	/* SYS_PWMSS_SYSCONFIG register bit field */
	union {
		volatile uint32_t SYSCONFIG;

		volatile struct {
			unsigned SOFTRESET		: 1;		//0
			unsigned FREEEMU		: 1;		//1
			unsigned IDLEMODE		: 2;		//3:2
			unsigned STANDBYMODE	: 2;		//5:4
			unsigned rsvd6			: 26;		//31:6
		} SYSCONFIG_bit;
	} ;	// 0x4

	/* SYS_PWMSS_CLKCONFIG register bit field */
	union {
		volatile uint32_t CLKCONFIG;

		volatile struct {
			unsigned ECAPCLK_EN			: 1;		//0
			unsigned ECAPCLKSTOP_REQ	: 1;		//1
			unsigned rsvd2				: 2;		//3:2
			unsigned EQEPCLK_EN			: 1;		//4
			unsigned EQEPCLKSTOP_REQ	: 1;		//5
			unsigned rsvd6				: 2;		//7:6
			unsigned EPWMCLK_EN			: 1;		//8
			unsigned EPWMCLKSTOP_REQ	: 1;		//9
			unsigned rsvd10				: 22;		//31:10
		} CLKCONFIG_bit;
	} ;	// 0x8

	/* SYS_PWMSS_CLKSTATUS register bit field */
	union {
		volatile uint32_t CLKSTATUS;

		volatile struct {
			unsigned ECAPCLK_EN_ACK		: 1;		//0
			unsigned ECAPCLKSTOP_ACK	: 1;		//1
			unsigned rsvd2				: 2;		//3:2
			unsigned EQEPCLK_EN_ACK		: 1;		//4
			unsigned EQEPCLKSTOP_ACK	: 1;		//5
			unsigned rsvd6				: 2;		//7:6
			unsigned EPWMCLK_EN_ACK		: 1;		//8
			unsigned EPWMCLKSTOP_ACK	: 1;		//9
			unsigned rsvd10				: 22;		//31:10
		} CLKSTATUS_bit;
	} ;	// 0xC

	uint32_t rsvd10[60];		// 0x10 - 0xFC

	/*************************/
	/* eCAP Module Registers */
	/*************************/
	/* SYS_PWMSS_ECAP_TSCTR register bit field */
	union {
		volatile uint32_t ECAP_TSCTR;

		volatile struct {
			unsigned TSCTR	: 32;		//31:0
		} ECAP_TSCTR_bit;
	} ;	// 0x100

	/* SYS_PWMSS_ECAP_CTRPHS register bit field */
	union {
		volatile uint32_t ECAP_CTRPHS;

		volatile struct {
			unsigned CTRPHS	: 32;		//31:0
		} ECAP_CTRPHS_bit;
	} ;	// 0x104

	/* SYS_PWMSS_ECAP_CAP1 register bit field */
	union {
		volatile uint32_t ECAP_CAP1;

		volatile struct {
			unsigned CAP1	: 32;		//31:0
		} ECAP_CAP1_bit;
	} ;	// 0x108

	/* SYS_PWMSS_ECAP_CAP2 register bit field */
	union {
		volatile uint32_t ECAP_CAP2;

		volatile struct {
			unsigned CAP2	: 32;		//31:0
		} ECAP_CAP2_bit;
	} ;	// 0x10C

	/* SYS_PWMSS_ECAP_CAP3 register bit field */
	union {
		volatile uint32_t ECAP_CAP3;

		volatile struct {
			unsigned CAP3	: 32;		//31:0
		} ECAP_CAP3_bit;
	} ;	// 0x110

	/* SYS_PWMSS_ECAP_CAP4 register bit field */
	union {
		volatile uint32_t ECAP_CAP4;

		volatile struct {
			unsigned CAP4	: 32;		//31:0
		} ECAP_CAP4_bit;
	} ;	// 0x114

	uint32_t rsvd118[4];		// 0x118 - 0x124

	/* SYS_PWMSS_ECAP_ECCTL1 register bit field */
	union {
		volatile uint16_t ECAP_ECCTL1;

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
		} ECAP_ECCTL1_bit;
	} ;	// 0x128

	/* SYS_PWMSS_ECAP_ECCTL2 register bit field */
	union {
		volatile uint16_t ECAP_ECCTL2;

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
		} ECAP_ECCTL2_bit;
	} ;	// 0x12A

	/* SYS_PWMSS_ECAP_ECEINT register bit field */
	union {
		volatile uint16_t ECAP_ECEINT;

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
		} ECAP_ECEINT_bit;
	} ;	// 0x12C

	/* SYS_PWMSS_ECAP_ECFLG register bit field */
	union {
		volatile uint16_t ECAP_ECFLG;

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
		} ECAP_ECFLG_bit;
	} ;	// 0x12E

	/* SYS_PWMSS_ECAP_ECCLR register bit field */
	union {
		volatile uint16_t ECAP_ECCLR;

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
		} ECAP_ECCLR_bit;
	} ;	// 0x130

	/* SYS_PWMSS_ECAP_ECFRC register bit field */
	union {
		volatile uint16_t ECAP_ECFRC;

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
		} ECAP_ECFRC_bit;
	} ;	// 0x132

	uint32_t rsvd134[10];		// 0x134 - 0x158

	/* SYS_PWMSS_ECAP_REVID register bit field */
	union {
		volatile uint32_t ECAP_REVID;

		volatile struct {
			unsigned REV		: 32;		//31:0
		} ECAP_REVID_bit;
	} ;	// 0x15C

	uint32_t rsvd160[8];		// 0x160 - 0x17C

	/*************************/
	/* eQEP Module Registers */
	/*************************/
	/* SYS_PWMSS_EQEP_QPOSCNT register bit field */
	union {
		volatile uint32_t EQEP_QPOSCNT;

		volatile struct {
			unsigned QPOSCNT	: 32;		//31:0
		} EQEP_QPOSCNT_bit;
	} ;	// 0x180

	/* SYS_PWMSS_EQEP_QPOSINIT register bit field */
	union {
		volatile uint32_t EQEP_QPOSINIT;

		volatile struct {
			unsigned QPOSINIT	: 32;		//31:0
		} EQEP_QPOSINIT_bit;
	} ;	// 0x184

	/* SYS_PWMSS_EQEP_QPOSMAX register bit field */
	union {
		volatile uint32_t EQEP_QPOSMAX;

		volatile struct {
			unsigned QPOSMAX	: 32;		//31:0
		} EQEP_QPOSMAX_bit;
	} ;	// 0x188

	/* SYS_PWMSS_EQEP_QPOSCMP register bit field */
	union {
		volatile uint32_t EQEP_QPOSCMP;

		volatile struct {
			unsigned QPOSCMP	: 32;		//31:0
		} EQEP_QPOSCMP_bit;
	} ;	// 0x18C

	/* SYS_PWMSS_EQEP_QPOSILAT register bit field */
	union {
		volatile uint32_t EQEP_QPOSILAT;

		volatile struct {
			unsigned QPOSILAT	: 32;		//31:0
		} EQEP_QPOSILAT_bit;
	} ;	// 0x190

	/* SYS_PWMSS_EQEP_QPOSSLAT register bit field */
	union {
		volatile uint32_t EQEP_QPOSSLAT;

		volatile struct {
			unsigned QPOSSLAT	: 32;		//31:0
		} EQEP_QPOSSLAT_bit;
	} ;	// 0x194

	/* SYS_PWMSS_EQEP_QPOSLAT register bit field */
	union {
		volatile uint32_t EQEP_QPOSLAT;

		volatile struct {
			unsigned QPOSLAT	: 32;		//31:0
		} EQEP_QPOSLAT_bit;
	} ;	// 0x198

	/* SYS_PWMSS_EQEP_QUTMR register bit field */
	union {
		volatile uint32_t EQEP_QUTMR;

		volatile struct {
			unsigned QUTMR	: 32;		//31:0
		} EQEP_QUTMR_bit;
	} ;	// 0x19C

	/* SYS_PWMSS_EQEP_QUPRD register bit field */
	union {
		volatile uint32_t EQEP_QUPRD;

		volatile struct {
			unsigned QUPRD	: 32;		//31:0
		} EQEP_QUPRD_bit;
	} ;	// 0x1A0

	/* SYS_PWMSS_EQEP_QWDTMR register bit field */
	union {
		volatile uint16_t EQEP_QWDTMR;

		volatile struct {
			uint16_t QWDTMR	: 16;		//15:0
		} EQEP_QWDTMR_bit;
	} ;	// 0x1A4

	/* SYS_PWMSS_EQEP_QWDPRD register bit field */
	union {
		volatile uint16_t EQEP_QWDPRD;

		volatile struct {
			uint16_t QWDPRD	: 16;		//15:0
		} EQEP_QWDPRD_bit;
	} ;	// 0x1A6

	/* SYS_PWMSS_EQEP_QDECCTL register bit field */
	union {
		volatile uint16_t EQEP_QDECCTL;

		volatile struct {
			uint16_t rsvd0	: 5;		//4:0
			uint16_t QSP	: 1;		//5
			uint16_t QIP	: 1;		//6
			uint16_t QBP	: 1;		//7
			uint16_t QAP	: 1;		//8
			uint16_t IGATE	: 1;		//9
			uint16_t SWAP	: 1;		//10
			uint16_t XCR	: 1;		//11
			uint16_t SPSEL	: 1;		//12
			uint16_t SOEN	: 1;		//13
			uint16_t QSRC	: 2;		//15:14
		} EQEP_QDECCTL_bit;
	} ;	// 0x1A8

	/* SYS_PWMSS_EQEP_QEPCTL register bit field */
	union {
		volatile uint16_t EQEP_QEPCTL;

		volatile struct {
			uint16_t WDE		: 1;		//0
			uint16_t UTE		: 1;		//1
			uint16_t QCLM		: 1;		//2
			uint16_t PHEN		: 1;		//3
			uint16_t IEL		: 2;		//5:4
			uint16_t SEL		: 1;		//6
			uint16_t SWI		: 1;		//7
			uint16_t IEI		: 2;		//9:8
			uint16_t SEI		: 2;		//11:10
			uint16_t PCRM		: 2;		//13:12
			uint16_t FREE_SOFT	: 2;		//15:14
		} EQEP_QEPCTL_bit;
	} ;	// 0x1AA

	/* SYS_PWMSS_EQEP_QCAPCTL register bit field */
	union {
		volatile uint16_t EQEP_QCAPCTL;

		volatile struct {
			uint16_t UPPS		: 4;		//3:0
			uint16_t CCPS		: 3;		//6:4
			uint16_t rsvd7		: 8;		//14:7
			uint16_t CEN		: 1;		//15
		} EQEP_QCAPCTL_bit;
	} ;	// 0x1AC

	/* SYS_PWMSS_EQEP_QPOSCTL register bit field */
	union {
		volatile uint16_t EQEP_QPOSCTL;

		volatile struct {
			uint16_t PCSPW		: 12;		//11:0
			uint16_t PCE		: 1;		//12
			uint16_t PCPOL		: 1;		//13
			uint16_t PCLOAD		: 1;		//14
			uint16_t PCSHDW		: 1;		//15
		} EQEP_QPOSCTL_bit;
	} ;	// 0x1AE

	/* SYS_PWMSS_EQEP_QEINT register bit field */
	union {
		volatile uint16_t EQEP_QEINT;

		volatile struct {
			uint16_t rsvd0		: 1;		//0
			uint16_t PCE		: 1;		//1
			uint16_t PHE		: 1;		//2
			uint16_t QDC		: 1;		//3
			uint16_t WTO		: 1;		//4
			uint16_t PCU		: 1;		//5
			uint16_t PCO		: 1;		//6
			uint16_t PCR		: 1;		//7
			uint16_t PCM		: 1;		//8
			uint16_t SEL		: 1;		//9
			uint16_t IEL		: 1;		//10
			uint16_t UTO		: 1;		//11
			uint16_t rsvd12		: 4;		//15:12
		} EQEP_QEINT_bit;
	} ;	// 0x1B0

	/* SYS_PWMSS_EQEP_QFLG register bit field */
	union {
		volatile uint16_t EQEP_QFLG;

		volatile struct {
			uint16_t INT		: 1;		//0
			uint16_t PCE		: 1;		//1
			uint16_t PHE		: 1;		//2
			uint16_t QDC		: 1;		//3
			uint16_t WTO		: 1;		//4
			uint16_t PCU		: 1;		//5
			uint16_t PCO		: 1;		//6
			uint16_t PCR		: 1;		//7
			uint16_t PCM		: 1;		//8
			uint16_t SEL		: 1;		//9
			uint16_t IEL		: 1;		//10
			uint16_t UTO		: 1;		//11
			uint16_t rsvd12		: 4;		//15:12
		} EQEP_QFLG_bit;
	} ;	// 0x1B2

	/* SYS_PWMSS_EQEP_QCLR register bit field */
	union {
		volatile uint16_t EQEP_QCLR;

		volatile struct {
			uint16_t INT		: 1;		//0
			uint16_t PCE		: 1;		//1
			uint16_t PHE		: 1;		//2
			uint16_t QDC		: 1;		//3
			uint16_t WTO		: 1;		//4
			uint16_t PCU		: 1;		//5
			uint16_t PCO		: 1;		//6
			uint16_t PCR		: 1;		//7
			uint16_t PCM		: 1;		//8
			uint16_t SEL		: 1;		//9
			uint16_t IEL		: 1;		//10
			uint16_t UTO		: 1;		//11
			uint16_t rsvd12		: 4;		//15:12
		} EQEP_QCLR_bit;
	} ;	// 0x1B4

	/* SYS_PWMSS_EQEP_QFRC register bit field */
	union {
		volatile uint16_t EQEP_QFRC;

		volatile struct {
			uint16_t rsvd0		: 1;		//0
			uint16_t PCE		: 1;		//1
			uint16_t PHE		: 1;		//2
			uint16_t QDC		: 1;		//3
			uint16_t WTO		: 1;		//4
			uint16_t PCU		: 1;		//5
			uint16_t PCO		: 1;		//6
			uint16_t PCR		: 1;		//7
			uint16_t PCM		: 1;		//8
			uint16_t SEL		: 1;		//9
			uint16_t IEL		: 1;		//10
			uint16_t UTO		: 1;		//11
			uint16_t rsvd12		: 4;		//15:12
		} EQEP_QFRC_bit;
	} ;	// 0x1B6

	/* SYS_PWMSS_EQEP_QEPSTS register bit field */
	union {
		volatile uint16_t EQEP_QEPSTS;

		volatile struct {
			uint16_t PCEF		: 1;		//0
			uint16_t FIMF		: 1;		//1
			uint16_t CDEF		: 1;		//2
			uint16_t COEF		: 1;		//3
			uint16_t QDLF		: 1;		//4
			uint16_t QDF		: 1;		//5
			uint16_t FDF		: 1;		//6
			uint16_t UPEVNT		: 1;		//7
			uint16_t rsvd8		: 8;		//15:8
		} EQEP_QEPSTS_bit;
	} ;	// 0x1B8

	/* SYS_PWMSS_EQEP_QCTMR register bit field */
	union {
		volatile uint16_t EQEP_QCTMR;

		volatile struct {
			uint16_t QCTMR		: 16;		//15:0
		} EQEP_QCTMR_bit;
	} ;	// 0x1BA

	/* SYS_PWMSS_EQEP_QCPRD register bit field */
	union {
		volatile uint16_t EQEP_QCPRD;

		volatile struct {
			uint16_t QCPRD		: 16;		//15:0
		} EQEP_QCPRD_bit;
	} ;	// 0x1BC

	/* SYS_PWMSS_EQEP_QCTMRLAT register bit field */
	union {
		volatile uint16_t EQEP_QCTMRLAT;

		volatile struct {
			uint16_t QCTMRLAT		: 16;		//15:0
		} EQEP_QCTMRLAT_bit;
	} ;	// 0x1BE

	/* SYS_PWMSS_EQEP_QCPRDLAT register bit field */
	union {
		volatile uint16_t EQEP_QCPRDLAT;

		volatile struct {
			uint16_t QCPRDLAT		: 16;		//15:0
		} EQEP_QCPRDLAT_bit;
	} ;	// 0x1C0

	uint16_t rsvd1C2[1];		// 0x1C2 - 0x1C3
	uint32_t rsvd1C4[6];		// 0x1C4 - 0x1D8

	/* SYS_PWMSS_EQEP_REVID register bit field */
	union {
		volatile uint32_t EQEP_REVID;

		volatile struct {
			unsigned REVID	: 32;		//31:0
		} EQEP_REVID_bit;
	} ;	// 0x1DC

	uint32_t rsvd1E0[8];		// 0x1E0 - 0x1FC

	/*************************/
	/* ePWM Module Registers */
	/*************************/
	/* SYS_PWMSS_EPWM_TBCTL register bit field */
	union {
		volatile uint16_t EPWM_TBCTL;

		volatile struct {
			uint16_t CTRMODE	: 2;		//1:0
			uint16_t PHSEN		: 1;		//2
			uint16_t PRDLD		: 1;		//3
			uint16_t SYNCOSEL	: 2;		//5:4
			uint16_t SWFSYNC	: 1;		//6
			uint16_t HSPCLKDIV	: 3;		//9:7
			uint16_t CLKDIV		: 3;		//12:10
			uint16_t PHSDIR		: 1;		//13
			uint16_t FREE_SOFT	: 2;		//15:14
		} EPWM_TBCTL_bit;
	} ;	// 0x200

	/* SYS_PWMSS_EPWM_TBSTS register bit field */
	union {
		volatile uint16_t EPWM_TBSTS;

		volatile struct {
			uint16_t CTRDIR		: 1;		//0
			uint16_t SYNCI		: 1;		//1
			uint16_t CTRMAX		: 1;		//2
			uint16_t rsvd3		: 13;		//15:3
		} EPWM_TBSTS_bit;
	} ;	// 0x202

	/* SYS_PWMSS_EPWM_TBPHSHR register bit field */
	union {
		volatile uint16_t EPWM_TBPHSHR;

		volatile struct {
			uint16_t rsvd0		: 8;		//7:0
			uint16_t TBPHSH		: 8;		//15:8
		} EPWM_TBPHSHR_bit;
	} ;	// 0x204

	/* SYS_PWMSS_EPWM_TBPHS register bit field */
	union {
		volatile uint16_t EPWM_TBPHS;

		volatile struct {
			uint16_t TBPHS		: 16;		//15:0
		} EPWM_TBPHS_bit;
	} ;	// 0x206

	/* SYS_PWMSS_EPWM_TBCNT register bit field */
	union {
		volatile uint16_t EPWM_TBCNT;

		volatile struct {
			uint16_t TBCNT		: 16;		//15:0
		} EPWM_TBCNT_bit;
	} ;	// 0x208

	/* SYS_PWMSS_EPWM_TBPRD register bit field */
	union {
		volatile uint16_t EPWM_TBPRD;

		volatile struct {
			uint16_t TBPRD		: 16;		//15:0
		} EPWM_TBPRD_bit;
	} ;	// 0x20A

	uint16_t rsvd20C[1];		// 0x20C - 0x20D

	/* SYS_PWMSS_EPWM_CMPCTL register bit field */
	union {
		volatile uint16_t EPWM_CMPCTL;

		volatile struct {
			uint16_t LOADAMODE		: 2;		//1:0
			uint16_t LOADBMODE		: 2;		//3:2
			uint16_t SHDWAMODE		: 1;		//4
			uint16_t rsvd5			: 1;		//5
			uint16_t SHDWBMODE		: 1;		//6
			uint16_t rsvd7			: 1;		//7
			uint16_t SHDWAFULL		: 1;		//8
			uint16_t SHDWBFULL		: 1;		//9
			uint16_t rsvd10			: 6;		//15:10
		} EPWM_CMPCTL_bit;
	} ;	// 0x20E

	/* SYS_PWMSS_EPWM_CMPAHR register bit field */
	union {
		volatile uint16_t EPWM_CMPAHR;

		volatile struct {
			uint16_t rsvd0		: 8;		//7:0
			uint16_t CMPAHR		: 8;		//15:8
		} EPWM_CMPAHR_bit;
	} ;	// 0x210

	/* SYS_PWMSS_EPWM_CMPA register bit field */
	union {
		volatile uint16_t EPWM_CMPA;

		volatile struct {
			uint16_t CMPA		: 16;		//15:0
		} EPWM_CMPA_bit;
	} ;	// 0x212

	/* SYS_PWMSS_EPWM_CMPB register bit field */
	union {
		volatile uint16_t EPWM_CMPB;

		volatile struct {
			uint16_t CMPB		: 16;		//15:0
		} EPWM_CMPB_bit;
	} ;	// 0x214

	/* SYS_PWMSS_EPWM_AQCTLA register bit field */
	union {
		volatile uint16_t EPWM_AQCTLA;

		volatile struct {
			uint16_t ZRO		: 2;		//1:0
			uint16_t PRD		: 2;		//3:2
			uint16_t CAU		: 2;		//5:4
			uint16_t CAD		: 2;		//7:6
			uint16_t CBU		: 2;		//9:8
			uint16_t CBD		: 2;		//11:10
			uint16_t rsvd12		: 4;		//15:12
		} EPWM_AQCTLA_bit;
	} ;	// 0x216

	/* SYS_PWMSS_EPWM_AQCTLB register bit field */
	union {
		volatile uint16_t EPWM_AQCTLB;

		volatile struct {
			uint16_t ZRO		: 2;		//1:0
			uint16_t PRD		: 2;		//3:2
			uint16_t CAU		: 2;		//5:4
			uint16_t CAD		: 2;		//7:6
			uint16_t CBU		: 2;		//9:8
			uint16_t CBD		: 2;		//11:10
			uint16_t rsvd12		: 4;		//15:12
		} EPWM_AQCTLB_bit;
	} ;	// 0x218

	/* SYS_PWMSS_EPWM_AQSFRC register bit field */
	union {
		volatile uint16_t EPWM_AQSFRC;

		volatile struct {
			uint16_t ACTSFA		: 2;		//1:0
			uint16_t OTSFA		: 1;		//2
			uint16_t ACTSFB		: 2;		//4:3
			uint16_t OTSFB		: 1;		//5
			uint16_t RLDCSF		: 2;		//7:6
			uint16_t rsvd8		: 8;		//15:8
		} EPWM_AQSFRC_bit;
	} ;	// 0x21A

	/* SYS_PWMSS_EPWM_AQCSFRC register bit field */
	union {
		volatile uint16_t EPWM_AQCSFRC;

		volatile struct {
			uint16_t CSFA		: 2;		//1:0
			uint16_t CSFB		: 2;		//3:2
			uint16_t rsvd4		: 12;		//15:4
		} EPWM_AQCSFRC_bit;
	} ;	// 0x21C

	/* SYS_PWMSS_EPWM_DBCTL register bit field */
	union {
		volatile uint16_t EPWM_DBCTL;

		volatile struct {
			uint16_t OUT_MODE	: 2;		//1:0
			uint16_t POLSEL		: 2;		//3:2
			uint16_t IN_MODE	: 2;		//5:4
			uint16_t rsvd6		: 10;		//15:6
		} EPWM_DBCTL_bit;
	} ;	// 0x21E

	/* SYS_PWMSS_EPWM_DBRED register bit field */
	union {
		volatile uint16_t EPWM_DBRED;

		volatile struct {
			uint16_t DEL		: 10;		//9:0
			uint16_t rsvd6		: 6;		//15:10
		} EPWM_DBRED_bit;
	} ;	// 0x220

	/* SYS_PWMSS_EPWM_DBFED register bit field */
	union {
		volatile uint16_t EPWM_DBFED;

		volatile struct {
			uint16_t DEL		: 10;		//9:0
			uint16_t rsvd6		: 6;		//15:10
		} EPWM_DBFED_bit;
	} ;	// 0x222

	/* SYS_PWMSS_EPWM_TZSEL register bit field */
	union {
		volatile uint16_t EPWM_TZSEL;

		volatile struct {
			uint16_t CBCn		: 8;		//7:0
			uint16_t OSHTn		: 8;		//15:8
		} EPWM_TZSEL_bit;
	} ;	// 0x224

	uint16_t rsvd226[1];		// 0x226 - 0x227

	/* SYS_PWMSS_EPWM_TZCTL register bit field */
	union {
		volatile uint16_t EPWM_TZCTL;

		volatile struct {
			uint16_t TZA		: 2;		//1:0
			uint16_t TZB		: 2;		//3:2
			uint16_t rsvd4		: 12;		//15:4
		} EPWM_TZCTL_bit;
	} ;	// 0x228

	/* SYS_PWMSS_EPWM_TZEINT register bit field */
	union {
		volatile uint16_t EPWM_TZEINT;

		volatile struct {
			uint16_t rsvd0		: 1;		//0
			uint16_t CBC		: 1;		//1
			uint16_t OST		: 1;		//2
			uint16_t rsvd3		: 13;		//15:3
		} EPWM_TZEINT_bit;
	} ;	// 0x22A

	/* SYS_PWMSS_EPWM_TZFLG register bit field */
	union {
		volatile uint16_t EPWM_TZFLG;

		volatile struct {
			uint16_t INT		: 1;		//0
			uint16_t CBC		: 1;		//1
			uint16_t OST		: 1;		//2
			uint16_t rsvd3		: 13;		//15:3
		} EPWM_TZFLG_bit;
	} ;	// 0x22C

	/* SYS_PWMSS_EPWM_TZCLR register bit field */
	union {
		volatile uint16_t EPWM_TZCLR;

		volatile struct {
			uint16_t INT		: 1;		//0
			uint16_t CBC		: 1;		//1
			uint16_t OST		: 1;		//2
			uint16_t rsvd3		: 13;		//15:3
		} EPWM_TZCLR_bit;
	} ;	// 0x22E

	/* SYS_PWMSS_EPWM_TZFRC register bit field */
	union {
		volatile uint16_t EPWM_TZFRC;

		volatile struct {
			uint16_t rsvd0		: 1;		//0
			uint16_t CBC		: 1;		//1
			uint16_t OST		: 1;		//2
			uint16_t rsvd3		: 13;		//15:3
		} EPWM_TZFRC_bit;
	} ;	// 0x230

	/* SYS_PWMSS_EPWM_ETSEL register bit field */
	union {
		volatile uint16_t EPWM_ETSEL;

		volatile struct {
			uint16_t INTSEL		: 3;		//2:0
			uint16_t INTEN		: 1;		//3
			uint16_t rsvd4		: 12;		//15:4
		} EPWM_ETSEL_bit;
	} ;	// 0x232

	/* SYS_PWMSS_EPWM_ETPS register bit field */
	union {
		volatile uint16_t EPWM_ETPS;

		volatile struct {
			uint16_t INTPRD		: 2;		//1:0
			uint16_t INTCNT		: 2;		//3:2
			uint16_t rsvd4		: 12;		//15:4
		} EPWM_ETPS_bit;
	} ;	// 0x234

	/* SYS_PWMSS_EPWM_ETFLG register bit field */
	union {
		volatile uint16_t EPWM_ETFLG;

		volatile struct {
			uint16_t INT		: 1;		//0
			uint16_t rsvd1		: 15;		//15:1
		} EPWM_ETFLG_bit;
	} ;	// 0x236

	/* SYS_PWMSS_EPWM_ETCLR register bit field */
	union {
		volatile uint16_t EPWM_ETCLR;

		volatile struct {
			uint16_t INT		: 1;		//0
			uint16_t rsvd1		: 15;		//15:1
		} EPWM_ETCLR_bit;
	} ;	// 0x238

	/* SYS_PWMSS_EPWM_ETFRC register bit field */
	union {
		volatile uint16_t EPWM_ETFRC;

		volatile struct {
			uint16_t INT		: 1;		//0
			uint16_t rsvd1		: 15;		//15:1
		} EPWM_ETFRC_bit;
	} ;	// 0x23A

	/* SYS_PWMSS_EPWM_PCCTL register bit field */
	union {
		volatile uint16_t EPWM_PCCTL;

		volatile struct {
			uint16_t CHPEN		: 1;		//0
			uint16_t OSHTWTH	: 4;		//4:1
			uint16_t CHPFREQ	: 3;		//7:5
			uint16_t CHPDUTY	: 3;		//10:8
			uint16_t rsvd11		: 5;		//15:11
		} EPWM_PCCTL_bit;
	} ;	// 0x23C

	uint16_t rsvd23E[1];		// 0x23E - 0x23F
	uint32_t rsvd240[32];		// 0x240 - 0x2BC

	/* SYS_PWMSS_EPWM_HRCNGF register bit field */
	union {
		volatile uint16_t EPWM_HRCNGF;

		volatile struct {
			uint16_t EDGMODE	: 2;		//1:0
			uint16_t CTLMODE	: 1;		//2
			uint16_t HRLOAD		: 1;		//3
			uint16_t rsvd4		: 12;		//15:4
		} EPWM_HRCNGF_bit;
	} ;	// 0x2C0

} sysPwmss;

__far volatile sysPwmss CT_PWMSS0 __attribute__((cregister("PWMSS0", far), peripheral));
__far volatile sysPwmss CT_PWMSS1 __attribute__((cregister("PWMSS1", far), peripheral));
__far volatile sysPwmss CT_PWMSS2 __attribute__((cregister("PWMSS2", far), peripheral));

#endif /* _SYS_PWMSS_H_ */
