/*
 * Copyright (c) 2014, Texas Instruments, Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE. */

#include <stdint.h>
#include <pru_cfg.h>
#include <resource_table_empty.h>

/* Mapping Constant Table (CT) registers to variables */
volatile far pruCfg CT_CFG __attribute__((cregister("PRU_CFG", near), peripheral));
volatile far uint32_t CT_MCSPI0 __attribute__((cregister("MCSPI0", near), peripheral));

#ifndef PRU_SRAM
#define PRU_SRAM near __attribute__((cregister("PRU_SHAREDMEM", near)))
#endif

/* NOTE:  Allocating shared_freq_x to PRU Shared Memory means that other PRU cores on
 *        the same subsystem must take care not to allocate data to that memory.
 *	 	  Users also cannot rely on where in shared memory these variables are placed
 *        so accessing them from another PRU core or from the ARM is an undefined behavior.
 */
PRU_SRAM uint32_t shared_freq_1;
PRU_SRAM uint32_t shared_freq_2;
PRU_SRAM uint32_t shared_freq_3;

/* PRCM Registers */
#define CM_PER_BASE	((volatile uint32_t *)(0x44E00000))
#define SPI0_CLKCTRL  (0x4C / 4)
#define ON (0x2)

#define MCSPI0_MODULCTRL (*((volatile uint32_t*)(&CT_MCSPI0 + 0x128/4)))

/* This is a char so that I can force access to R31.b0 for the host interrupt */
volatile register uint8_t __R31;

/* PRU-to-ARM interrupt */
#define PRU_ARM_INTERRUPT (19+16)

int main(){
	uint32_t result;
	volatile uint32_t *ptr_cm;

	ptr_cm = CM_PER_BASE;

	/*****************************************************************/
	/* Access PRU peripherals using Constant Table & PRU header file */
	/*****************************************************************/

	/* Clear SYSCFG[STANDBY_INIT] to enable OCP master port */
	CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;

	/* Read IEPCLK[OCP_EN] for IEP clock source */
	result = CT_CFG.IEPCLK_bit.OCP_EN;


	/*****************************************************************/
	/* Access SoC peripherals using Constant Table                   */
	/*****************************************************************/

	/* Access PRCM (without CT) to initialize McSPI0 clock */
	ptr_cm[SPI0_CLKCTRL] = ON;

	/* Read McSPI0_MODULCTRL (offset 0x128)*/
	result = MCSPI0_MODULCTRL;

	/* Toggle MCSPI0_MODULCTRL[MS] (offset 0x128, bit 2) */
	MCSPI0_MODULCTRL ^= 0x4;

	/* Reset MCSPI0_MODULCTRL[MS] to original value */
	MCSPI0_MODULCTRL = result;

	/*****************************************************************/
	/* Access PRU Shared RAM using Constant Table                    */
	/*****************************************************************/

	/* Define value of shared_freq_1 */
	shared_freq_1 = 1;

	/* Read PRU Shared RAM Freq_1 memory */
	if (shared_freq_1 == 1)
		shared_freq_2 = shared_freq_2 + 1;
	else
		shared_freq_2 = shared_freq_3;

	/* Halt PRU core */
	__halt();
}
