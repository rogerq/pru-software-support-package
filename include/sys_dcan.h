#ifndef _SYS_DCAN_H_
#define _SYS_DCAN_H_
/* SYS_DCAN register set */
typedef struct{
	/* SYS_DCAN_CTL register bit field */
	union {
		volatile uint32_t CTL;

		volatile struct {
			unsigned INIT		: 1;		//0
			unsigned IE0		: 1;		//1
			unsigned SIE		: 1;		//2
			unsigned EIE		: 1;		//3
			unsigned rsvd4		: 1;		//4
			unsigned DAR		: 1;		//5
			unsigned CCE		: 1;		//6
			unsigned TEST		: 1;		//7
			unsigned IDS		: 1;		//8
			unsigned ABO		: 1;		//9
			unsigned PMD		: 4;		//13:10
			unsigned rsvd14		: 1;		//14
			unsigned SWR		: 1;		//15
			unsigned INITDBG	: 1;		//16
			unsigned IE1		: 1;		//17
			unsigned DE1		: 1;		//18
			unsigned DE2		: 1;		//19
			unsigned DE3		: 1;		//20
			unsigned rsvd21		: 3;		//23:21
			unsigned PDR		: 1;		//24
			unsigned WUBA		: 1;		//25
			unsigned rsvd26		: 6;		//31:26
		} CTL_bit;
	} ;	// 0x0

	/* SYS_DCAN_ES register bit field */
	union {
		volatile uint32_t ES;

		volatile struct {
			unsigned LEC		: 3;		//2:0
			unsigned TXOK		: 1;		//3
			unsigned RXOK		: 1;		//4
			unsigned EPASS		: 1;		//5
			unsigned EWARN		: 1;		//6
			unsigned BOFF		: 1;		//7
			unsigned PER		: 1;		//8
			unsigned WAKEUP_PND	: 1;		//9
			unsigned PDA		: 1;		//10
			unsigned rsvd11		: 21;		//31:11
		} ES_bit;
	} ;	// 0x4

	/* SYS_DCAN_ERRC register bit field */
	union {
		volatile uint32_t ERRC;

		volatile struct {
			unsigned TEC_7_0	: 8;		//7:0
			unsigned REC_6_0	: 7;		//14:8
			unsigned RP			: 1;		//15
			unsigned rsvd16		: 16;		//31:16
		} ERRC_bit;
	} ;	// 0x8

	/* SYS_DCAN_BTR register bit field */
	union {
		volatile uint32_t BTR;

		volatile struct {
			unsigned BRP		: 6;		//5:0
			unsigned SJW		: 2;		//7:6
			unsigned TSEG1		: 4;		//11:8
			unsigned TSEG2		: 3;		//14:12
			unsigned rsvd15		: 1;		//15
			unsigned BRPE		: 4;		//19:16
			unsigned rsvd20		: 12;		//31:17
		} BTR_bit;
	} ;	// 0xC

	/* SYS_DCAN_INT register bit field */
	union {
		volatile uint32_t INT;

		volatile struct {
			unsigned INT0ID_15_0	: 16;		//15:0
			unsigned INT1ID_23_16	: 8;		//23:16
			unsigned rsvd24			: 8;		//31:24
		} INT_bit;
	} ;	// 0x10

	/* SYS_DCAN_TEST register bit field */
	union {
		volatile uint32_t TEST;

		volatile struct {
			unsigned rsvd0		: 3;		//2:0
			unsigned SILENT		: 1;		//3
			unsigned LBACK		: 1;		//4
			unsigned TX_1_0		: 2;		//6:5
			unsigned RX			: 1;		//7
			unsigned EXL		: 1;		//8
			unsigned RDA		: 1;		//9
			unsigned rsvd10		: 22;		//31:10
		} TEST_bit;
	} ;	// 0x14

	uint32_t rsvd18[1];		// 0x18

	/* SYS_DCAN_PERR register bit field */
	union {
		volatile uint32_t PERR;

		volatile struct {
			unsigned MESSAGE_NUMBER		: 8;		//7:0
			unsigned WORD_NUMBER		: 3;		//10:8
			unsigned rsvd11				: 21;		//31:11
		} PERR_bit;
	} ;	// 0x1C

	uint32_t rsvd20[24];		// 0x20 - 0x7C

	/* SYS_DCAN_ABOTR register bit field */
	union {
		volatile uint32_t ABOTR;

		volatile struct {
			unsigned ABO_TIME		: 32;		//31:0
		} ABOTR_bit;
	} ;	// 0x80

	/* SYS_DCAN_TXRQ_X register bit field */
	union {
		volatile uint32_t TXRQ_X;

		volatile struct {
			unsigned TXRQSTREG1		: 2;		//1:0
			unsigned TXRQSTREG2		: 2;		//3:2
			unsigned TXRQSTREG3		: 2;		//5:4
			unsigned TXRQSTREG4		: 2;		//7:6
			unsigned TXRQSTREG5		: 2;		//9:8
			unsigned TXRQSTREG6		: 2;		//11:10
			unsigned TXRQSTREG7		: 2;		//13:12
			unsigned TXRQSTREG8		: 2;		//15:14
			unsigned rsvd16			: 16;		//31:16
		} TXRQ_X_bit;
	} ;	// 0x84

	/* SYS_DCAN_TXRQ12 register bit field */
	union {
		volatile uint32_t TXRQ12;

		volatile struct {
			unsigned TXRQS_16_1		: 16;		//15:0
			unsigned TXRQS_32_17	: 16;		//31:16
		} TXRQ12_bit;
	} ;	// 0x88

	/* SYS_DCAN_TXRQ34 register bit field */
	union {
		volatile uint32_t TXRQ34;

		volatile struct {
			unsigned TXRQS_48_33	: 16;		//15:0
			unsigned TXRQS_64_49	: 16;		//31:16
		} TXRQ34_bit;
	} ;	// 0x8C

	/* SYS_DCAN_TXRQ56 register bit field */
	union {
		volatile uint32_t TXRQ56;

		volatile struct {
			unsigned TXRQS_80_65	: 16;		//15:0
			unsigned TXRQS_96_81	: 16;		//31:16
		} TXRQ56_bit;
	} ;	// 0x90

	/* SYS_DCAN_TXRQ78 register bit field */
	union {
		volatile uint32_t TXRQ78;

		volatile struct {
			unsigned TXRQS_112_97	: 16;		//15:0
			unsigned TXRQS_128_113	: 16;		//31:16
		} TXRQ78_bit;
	} ;	// 0x94

	/* SYS_DCAN_NWDAT_X register bit field */
	union {
		volatile uint32_t NWDAT_X;

		volatile struct {
			unsigned NEWDATREG1		: 2;		//1:0
			unsigned NEWDATREG2		: 2;		//3:2
			unsigned NEWDATREG3		: 2;		//5:4
			unsigned NEWDATREG4		: 2;		//7:6
			unsigned NEWDATREG5		: 2;		//9:8
			unsigned NEWDATREG6		: 2;		//11:10
			unsigned NEWDATREG7		: 2;		//13:12
			unsigned NEWDATREG8		: 2;		//15:14
			unsigned rsvd16			: 16;		//31:16
		} NWDAT_X_bit;
	} ;	// 0x98

	/* SYS_DCAN_NWDAT12 register bit field */
	union {
		volatile uint32_t NWDAT12;

		volatile struct {
			unsigned NEWDAT_16_1	: 16;		//15:0
			unsigned NEWDAT_32_17	: 16;		//31:16
		} NWDAT12_bit;
	} ;	// 0x9C

	/* SYS_DCAN_NWDAT34 register bit field */
	union {
		volatile uint32_t NWDAT34;

		volatile struct {
			unsigned NEWDAT_48_33	: 16;		//15:0
			unsigned NEWDAT_64_49	: 16;		//31:16
		} NWDAT34_bit;
	} ;	// 0xA0

	/* SYS_DCAN_NWDAT56 register bit field */
	union {
		volatile uint32_t NWDAT56;

		volatile struct {
			unsigned NEWDAT_80_65	: 16;		//15:0
			unsigned NEWDAT_96_81	: 16;		//31:16
		} NWDAT56_bit;
	} ;	// 0xA4

	/* SYS_DCAN_NWDAT78 register bit field */
	union {
		volatile uint32_t NWDAT78;

		volatile struct {
			unsigned NEWDAT_112_97	: 16;		//15:0
			unsigned NEWDAT_128_113	: 16;		//31:16
		} NWDAT78_bit;
	} ;	// 0xA8

	/* SYS_DCAN_INTPND_X register bit field */
	union {
		volatile uint32_t INTPND_X;

		volatile struct {
			unsigned INTPNDREG1		: 2;		//1:0
			unsigned INTPNDREG2		: 2;		//3:2
			unsigned INTPNDREG3		: 2;		//5:4
			unsigned INTPNDREG4		: 2;		//7:6
			unsigned INTPNDREG5		: 2;		//9:8
			unsigned INTPNDREG6		: 2;		//11:10
			unsigned INTPNDREG7		: 2;		//13:12
			unsigned INTPNDREG8		: 2;		//15:14
			unsigned rsvd16			: 16;		//31:16
		} INTPND_X_bit;
	} ;	// 0xAC

	/* SYS_DCAN_INTPND12 register bit field */
	union {
		volatile uint32_t INTPND12;

		volatile struct {
			unsigned INTPND_16_1	: 16;		//15:0
			unsigned INTPND_32_17	: 16;		//31:16
		} INTPND12_bit;
	} ;	// 0xB0

	/* SYS_DCAN_INTPND34 register bit field */
	union {
		volatile uint32_t INTPND34;

		volatile struct {
			unsigned INTPND_48_33	: 16;		//15:0
			unsigned INTPND_64_49	: 16;		//31:16
		} INTPND34_bit;
	} ;	// 0xB4

	/* SYS_DCAN_INTPND56 register bit field */
	union {
		volatile uint32_t INTPND56;

		volatile struct {
			unsigned INTPND_80_65	: 16;		//15:0
			unsigned INTPND_96_81	: 16;		//31:16
		} INTPND56_bit;
	} ;	// 0xB8

	/* SYS_DCAN_INTPND78 register bit field */
	union {
		volatile uint32_t INTPND78;

		volatile struct {
			unsigned INTPND_112_97	: 16;		//15:0
			unsigned INTPND_128_113	: 16;		//31:16
		} INTPND78_bit;
	} ;	// 0xBC

	/* SYS_DCAN_MSGVAL_X register bit field */
	union {
		volatile uint32_t MSGVAL_X;

		volatile struct {
			unsigned MSGVALREG1		: 2;		//1:0
			unsigned MSGVALREG2		: 2;		//3:2
			unsigned MSGVALREG3		: 2;		//5:4
			unsigned MSGVALREG4		: 2;		//7:6
			unsigned MSGVALREG5		: 2;		//9:8
			unsigned MSGVALREG6		: 2;		//11:10
			unsigned MSGVALREG7		: 2;		//13:12
			unsigned MSGVALREG8		: 2;		//15:14
			unsigned rsvd16			: 16;		//31:16
		} MSGVAL_X_bit;
	} ;	// 0xC0

	/* SYS_DCAN_MSGVAL12 register bit field */
	union {
		volatile uint32_t MSGVAL12;

		volatile struct {
			unsigned MSGVAL_16_1	: 16;		//15:0
			unsigned MSGVAL_32_17	: 16;		//31:16
		} MSGVAL12_bit;
	} ;	// 0xC4

	/* SYS_DCAN_MSGVAL34 register bit field */
	union {
		volatile uint32_t MSGVAL34;

		volatile struct {
			unsigned MSGVAL_48_33	: 16;		//15:0
			unsigned MSGVAL_64_49	: 16;		//31:16
		} MSGVAL34_bit;
	} ;	// 0xC8

	/* SYS_DCAN_MSGVAL56 register bit field */
	union {
		volatile uint32_t MSGVAL56;

		volatile struct {
			unsigned MSGVAL_80_65	: 16;		//15:0
			unsigned MSGVAL_96_81	: 16;		//31:16
		} MSGVAL56_bit;
	} ;	// 0xCC

	/* SYS_DCAN_MSGVAL78 register bit field */
	union {
		volatile uint32_t MSGVAL78;

		volatile struct {
			unsigned MSGVAL_112_97	: 16;		//15:0
			unsigned MSGVAL_128_113	: 16;		//31:16
		} MSGVAL78_bit;
	} ;	// 0xD0

	uint32_t rsvdD4[1];		// 0xD4

	/* SYS_DCAN_INTMUX12 register bit field */
	union {
		volatile uint32_t INTMUX12;

		volatile struct {
			unsigned INTMUX			: 32;		//31:0
		} INTMUX12_bit;
	} ;	// 0xD8

	/* SYS_DCAN_INTMUX34 register bit field */
	union {
		volatile uint32_t INTMUX34;

		volatile struct {
			unsigned INTMUX			: 32;		//31:0
		} INTMUX34_bit;
	} ;	// 0xDC

	/* SYS_DCAN_INTMUX56 register bit field */
	union {
		volatile uint32_t INTMUX56;

		volatile struct {
			unsigned INTMUX			: 32;		//31:0
		} INTMUX56_bit;
	} ;	// 0xE0

	/* SYS_DCAN_INTMUX78 register bit field */
	union {
		volatile uint32_t INTMUX78;

		volatile struct {
			unsigned INTMUX			: 32;		//31:0
		} INTMUX78_bit;
	} ;	// 0xE4

	uint32_t rsvdE8[7];		// 0xE8 - 0xFC

	/* SYS_DCAN_IF1CMD register bit field */
	union {
		volatile uint32_t IF1CMD;

		volatile struct {
			unsigned MESSAGE_NUMBER	: 8;		//7:0
			unsigned rsvd8			: 6;		//13:8
			unsigned DMAACTIVE		: 1;		//14
			unsigned BUSY			: 1;		//15
			unsigned DATA_B			: 1;		//16
			unsigned DATA_A			: 1;		//17
			unsigned TXRQST_NEWDATA	: 1;		//18
			unsigned CLRINTPND		: 1;		//19
			unsigned CONTROL		: 1;		//20
			unsigned ARB			: 1;		//21
			unsigned MASK			: 1;		//22
			unsigned WR_RD			: 1;		//23
			unsigned rsvd24			: 8;		//31:14
		} IF1CMD_bit;
	} ;	// 0x100

	/* SYS_DCAN_IF1MSK register bit field */
	union {
		volatile uint32_t IF1MSK;

		volatile struct {
			unsigned MSK_28_0		: 29;		//28:0
			unsigned rsvd29			: 1;		//29
			unsigned MDIR			: 1;		//30
			unsigned MXTD			: 1;		//31
		} IF1MSK_bit;
	} ;	// 0x104

	/* SYS_DCAN_IF1ARB register bit field */
	union {
		volatile uint32_t IF1ARB;

		volatile struct {
			unsigned ID28_0			: 29;		//28:0
			unsigned DIR			: 1;		//29
			unsigned XTD			: 1;		//30
			unsigned MSGVAL			: 1;		//31
		} IF1ARB_bit;
	} ;	// 0x108

	/* SYS_DCAN_IF1MCTL register bit field */
	union {
		volatile uint32_t IF1MCTL;

		volatile struct {
			unsigned DLC			: 4;		//3:0
			unsigned rsvd4			: 3;		//6:4
			unsigned EOB			: 1;		//7
			unsigned TXRQST			: 1;		//8
			unsigned RMTEN			: 1;		//9
			unsigned RXIE			: 1;		//10
			unsigned TXIE			: 1;		//11
			unsigned UMASK			: 1;		//12
			unsigned INTPND			: 1;		//13
			unsigned MSGLST			: 1;		//14
			unsigned NEWDAT			: 1;		//15
			unsigned rsvd16			: 16;		//31:16
		} IF1MCTL_bit;
	} ;	// 0x10C

	/* SYS_DCAN_IF1DATA register bit field */
	union {
		volatile uint32_t IF1DATA;

		volatile struct {
			unsigned DATA_0			: 8;		//7:0
			unsigned DATA_1			: 8;		//15:8
			unsigned DATA_2			: 8;		//23:16
			unsigned DATA_3			: 8;		//31:24
		} IF1DATA_bit;
	} ;	// 0x110

	/* SYS_DCAN_IF1DATB register bit field */
	union {
		volatile uint32_t IF1DATB;

		volatile struct {
			unsigned DATA_4			: 8;		//7:0
			unsigned DATA_5			: 8;		//15:8
			unsigned DATA_6			: 8;		//23:16
			unsigned DATA_7			: 8;		//31:24
		} IF1DATB_bit;
	} ;	// 0x114

	uint32_t rsvd118[2];		// 0x118

	/* SYS_DCAN_IF2CMD register bit field */
	union {
		volatile uint32_t IF2CMD;

		volatile struct {
			unsigned MESSAGE_NUMBER	: 8;		//7:0
			unsigned rsvd8			: 6;		//13:8
			unsigned DMAACTIVE		: 1;		//14
			unsigned BUSY			: 1;		//15
			unsigned DATA_B			: 1;		//16
			unsigned DATA_A			: 1;		//17
			unsigned TXRQST_NEWDATA	: 1;		//18
			unsigned CLRINTPND		: 1;		//19
			unsigned CONTROL		: 1;		//20
			unsigned ARB			: 1;		//21
			unsigned MASK			: 1;		//22
			unsigned WR_RD			: 1;		//23
			unsigned rsvd24			: 8;		//31:14
		} IF2CMD_bit;
	} ;	// 0x120

	/* SYS_DCAN_IF2MSK register bit field */
	union {
		volatile uint32_t IF2MSK;

		volatile struct {
			unsigned MSK_28_0		: 29;		//28:0
			unsigned rsvd29			: 1;		//29
			unsigned MDIR			: 1;		//30
			unsigned MXTD			: 1;		//31
		} IF2MSK_bit;
	} ;	// 0x124

	/* SYS_DCAN_IF2ARB register bit field */
	union {
		volatile uint32_t IF2ARB;

		volatile struct {
			unsigned ID28_0			: 29;		//28:0
			unsigned DIR			: 1;		//29
			unsigned XTD			: 1;		//30
			unsigned MSGVAL			: 1;		//31
		} IF2ARB_bit;
	} ;	// 0x128

	/* SYS_DCAN_IF2MCTL register bit field */
	union {
		volatile uint32_t IF2MCTL;

		volatile struct {
			unsigned DLC			: 4;		//3:0
			unsigned rsvd4			: 3;		//6:4
			unsigned EOB			: 1;		//7
			unsigned TXRQST			: 1;		//8
			unsigned RMTEN			: 1;		//9
			unsigned RXIE			: 1;		//10
			unsigned TXIE			: 1;		//11
			unsigned UMASK			: 1;		//12
			unsigned INTPND			: 1;		//13
			unsigned MSGLST			: 1;		//14
			unsigned NEWDAT			: 1;		//15
			unsigned rsvd16			: 16;		//31:16
		} IF2MCTL_bit;
	} ;	// 0x12C

	/* SYS_DCAN_IF2DATA register bit field */
	union {
		volatile uint32_t IF2DATA;

		volatile struct {
			unsigned DATA_0			: 8;		//7:0
			unsigned DATA_1			: 8;		//15:8
			unsigned DATA_2			: 8;		//23:16
			unsigned DATA_3			: 8;		//31:24
		} IF2DATA_bit;
	} ;	// 0x130

	/* SYS_DCAN_IF2DATB register bit field */
	union {
		volatile uint32_t IF2DATB;

		volatile struct {
			unsigned DATA_4			: 8;		//7:0
			unsigned DATA_5			: 8;		//15:8
			unsigned DATA_6			: 8;		//23:16
			unsigned DATA_7			: 8;		//31:24
		} IF2DATB_bit;
	} ;	// 0x134

	uint32_t rsvd138[2];		// 0x138 - 0x13C

	/* SYS_DCAN_IF3OBS register bit field */
	union {
		volatile uint32_t IF3OBS;

		volatile struct {
			unsigned MASK			: 1;		//0
			unsigned ARB			: 1;		//1
			unsigned CTRL			: 1;		//2
			unsigned DATAA			: 1;		//3
			unsigned DATAB			: 1;		//4
			unsigned rsvd5			: 3;		//7:5
			unsigned IF3_SM			: 1;		//8
			unsigned IF3_SA			: 1;		//9
			unsigned IF3_SC			: 1;		//10
			unsigned IF3_SDA		: 1;		//11
			unsigned IF3_SDB		: 1;		//12
			unsigned rsvd13			: 2;		//14:13
			unsigned IF3_UPD		: 1;		//15
			unsigned rsvd16			: 16;		//31:16
		} IF3OBS_bit;
	} ;	// 0x140

	/* SYS_DCAN_IF3MSK register bit field */
	union {
		volatile uint32_t IF3MSK;

		volatile struct {
			unsigned MSK_28_0		: 29;		//28:0
			unsigned rsvd29			: 1;		//29
			unsigned MDIR			: 1;		//30
			unsigned MXTD			: 1;		//31
		} IF3MSK_bit;
	} ;	// 0x144

	/* SYS_DCAN_IF3ARB register bit field */
	union {
		volatile uint32_t IF3ARB;

		volatile struct {
			unsigned ID28_0			: 29;		//28:0
			unsigned DIR			: 1;		//29
			unsigned XTD			: 1;		//30
			unsigned MSGVAL			: 1;		//31
		} IF3ARB_bit;
	} ;	// 0x148

	/* SYS_DCAN_IF3MCTL register bit field */
	union {
		volatile uint32_t IF3MCTL;

		volatile struct {
			unsigned DLC			: 4;		//3:0
			unsigned rsvd4			: 3;		//6:4
			unsigned EOB			: 1;		//7
			unsigned TXRQST			: 1;		//8
			unsigned RMTEN			: 1;		//9
			unsigned RXIE			: 1;		//10
			unsigned TXIE			: 1;		//11
			unsigned UMASK			: 1;		//12
			unsigned INTPND			: 1;		//13
			unsigned MSGLST			: 1;		//14
			unsigned NEWDAT			: 1;		//15
			unsigned rsvd16			: 16;		//31:16
		} IF3MCTL_bit;
	} ;	// 0x14C

	/* SYS_DCAN_IF3DATA register bit field */
	union {
		volatile uint32_t IF3DATA;

		volatile struct {
			unsigned DATA_0			: 8;		//7:0
			unsigned DATA_1			: 8;		//15:8
			unsigned DATA_2			: 8;		//23:16
			unsigned DATA_3			: 8;		//31:24
		} IF3DATA_bit;
	} ;	// 0x150

	/* SYS_DCAN_IF3DATB register bit field */
	union {
		volatile uint32_t IF3DATB;

		volatile struct {
			unsigned DATA_4			: 8;		//7:0
			unsigned DATA_5			: 8;		//15:8
			unsigned DATA_6			: 8;		//23:16
			unsigned DATA_7			: 8;		//31:24
		} IF3DATB_bit;
	} ;	// 0x154

	uint32_t rsvd158[2];		// 0x158 - 0x15C

	/* SYS_DCAN_IF3UPD12 register bit field */
	union {
		volatile uint32_t IF3UPD12;

		volatile struct {
			unsigned IF3UPDEN_16_1		: 16;		//15:0
			unsigned IF3UPDEN_32_17		: 16;		//31:16
		} IF3UPD12_bit;
	} ;	// 0x160

	/* SYS_DCAN_IF3UPD34 register bit field */
	union {
		volatile uint32_t IF3UPD34;

		volatile struct {
			unsigned IF3UPDEN_48_33		: 16;		//15:0
			unsigned IF3UPDEN_64_49		: 16;		//31:16
		} IF3UPD34_bit;
	} ;	// 0x164

	/* SYS_DCAN_IF3UPD56 register bit field */
	union {
		volatile uint32_t IF3UPD56;

		volatile struct {
			unsigned IF3UPDEN_80_65		: 16;		//15:0
			unsigned IF3UPDEN_96_81		: 16;		//31:16
		} IF3UPD56_bit;
	} ;	// 0x168

	/* SYS_DCAN_IF3UPD78 register bit field */
	union {
		volatile uint32_t IF3UPD78;

		volatile struct {
			unsigned IF3UPDEN_112_97	: 16;		//15:0
			unsigned IF3UPDEN_128_113	: 16;		//31:16
		} IF3UPD78_bit;
	} ;	// 0x16C

	uint32_t rsvd168[28];		// 0x168 - 1DC

	/* SYS_DCAN_TIOC register bit field */
	union {
		volatile uint32_t TIOC;

		volatile struct {
			unsigned IN			: 1;		//0
			unsigned OUT		: 1;		//1
			unsigned DIR		: 1;		//2
			unsigned FUNC		: 1;		//3
			unsigned rsvd4		: 12;		//15:4
			unsigned OD			: 1;		//16
			unsigned PD			: 1;		//17
			unsigned PU			: 1;		//18
			unsigned rsvd19		: 13;		//31:19
		} TIOC_bit;
	} ;	// 0x1E0

	/* SYS_DCAN_RIOC register bit field */
	union {
		volatile uint32_t RIOC;

		volatile struct {
			unsigned IN			: 1;		//0
			unsigned OUT		: 1;		//1
			unsigned DIR		: 1;		//2
			unsigned FUNC		: 1;		//3
			unsigned rsvd4		: 12;		//15:4
			unsigned OD			: 1;		//16
			unsigned PD			: 1;		//17
			unsigned PU			: 1;		//18
			unsigned rsvd19		: 13;		//31:19
		} RIOC_bit;
	} ;	// 0x1E4

} sysDcan;

__far volatile sysDcan CT_DCAN0 __attribute__((cregister("DCAN0", far), peripheral));
__far volatile sysDcan CT_DCAN1 __attribute__((cregister("DCAN1", far), peripheral));

#endif /* _SYS_DCAN_H_ */
