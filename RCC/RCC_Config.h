/*
 * RCC_Config.h


 *
 *  Created on: Aug 18, 2022
 *      Author: Sara Ahmed
 */

#ifndef MCAL_RCC_RCC_CONFIG_H_
#define MCAL_RCC_RCC_CONFIG_H_

/**** WE have 2 option ****/
/*
 * ENABLE
 * DISABLE
 */
#define RCC_HSI_ENABLE		DISABLE
#define RCC_HSE_ENABLE		ENABLE
#define RCC_PLL_ENABLE		DISABLE
#define RCC_CSS_ENABLE		ENABLE
#define HSE_BYP_ENABLE      DISABLE

/**** WE have 3 option ****/
/*
 * HSI
 * HSE
 * PLL
 */
#define RCC_SYS_CLK			RCC_HSE

/*** AHB Prescalers  ****/
typedef enum
{
  AHB_PRE1=0,
  AHB_PRE2=8,
  AHB_PRE4,
  AHB_PRE8,
  AHB_PRE16,
  AHB_PRE64,
  AHB_PRE128,
  AHB_PRE256,
  AHB_PRE3512
}AHB_Pre_t;

#define AHB_PRE_ENABLE  AHB_PRE1


/*** APB1 Prescalers  ****/
typedef enum
{
  APB1_PRE1=0,
  APB1_PRE2=4,
  APB1_PRE4,
  APB1_PRE8,
  APB1_PRE16

}APB1_Pre_t;

#define APB1_PRE_ENABLE  APB1_PRE1    //The software has to set these bits correctly not to exceed 42 MHz on this domain.

/*** APB2 Prescalers  ****/
typedef enum
{
  APB2_PRE1=0,
  APB2_PRE2=4,
  APB2_PRE4,
  APB2_PRE8,
  APB2_PRE16

}APB2_Pre_t;

#define APB2_PRE_ENABLE  APB2_PRE1    //The software has to set these bits correctly not to exceed 84 MHz on this domain.

/*** MCO2 prescaler ***/
typedef enum
{
    MOC2_PRE1=0,
	MOC2_PRE2=4,
	MOC2_PRE3,
	MOC2_PRE4,
	MOC2_PRE5

}MOC2_Pre_t;

#define MOC2_PRE_ENABLE    MOC2_PRE1   //recommended to configure these bits only after reset before enabling the external
                                       //oscillators and the PLLs.
/*** MCO1 prescaler ***/
typedef enum
{
    MOC1_PRE1=0,
	MOC1_PRE2=4,
	MOC1_PRE3,
	MOC1_PRE4,
	MOC1_PRE5

}MOC1_Pre_t;

#define MOC1_PRE_ENABLE    MOC1_PRE1   //recommended to configure these bits only after reset before enabling the external
                                       //oscillators and the PLLs.


/*** PLL Clock Source ***/
typedef enum
{
	PLL_HSI=0,     // HSI clock selected as PLL and PLLI2S clock entry
	PLL_HSE,       // HSE oscillator clock selected as PLL and PLLI2S clock entry
}PLL_CLKSrc_t;


#define PLL_CLK_SRC    PLL_HSE   //This bit can be written only when PLL and PLLI2S are disabled.


/*
 *  • f(VCO clock) = f(PLL clock input) × (PLLN / PLLM)
 *  • f(PLL general clock output) = f(VCO clock) / PLLP
 *  • f(USB OTG FS, SDIO, RNG clock output) = f(VCO clock) / PLLQ
 */

/*PLLQ: Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks
 *The USB OTG FS requires a 48 MHz clock to work correctly. The SDIO and the
 random number generator need a frequency lower than or equal to 48 MHz to work
 correctly
 *USB OTG FS clock frequency = VCO frequency / PLLQ with 2 ≤PLLQ ≤15
*/

/*
   0000: PLLQ = 0, wrong configuration
   0001: PLLQ = 1, wrong configuration
   0010: PLLQ = 2
   0011: PLLQ = 3
   0100: PLLQ = 4
   ...
   1111: PLLQ = 15
 */

#define PLLQ       2

/*
 * PLLP: Main PLL (PLL) division factor for main system clock
   Set and cleared by software to control the frequency of the general PLL output clock. These
   bits can be written only if PLL is disabled.
   The software has to set these bits correctly not to exceed 84 MHz on this domain.
   PLL output clock frequency = VCO frequency / PLLP with PLLP = 2, 4, 6, or 8
*/

/*
   00: PLLP = 2
   01: PLLP = 4
   10: PLLP = 6
   11: PLLP = 8
*/

#define PLLP      2

/*
   PLLN: Main PLL (PLL) multiplication factor for VCO
   Set and cleared by software to control the multiplication factor of the VCO. These bits can
   be written only when PLL is disabled. Only half-word and word accesses are allowed to
   write these bits.
   The software has to set these bits correctly to ensure that the VCO output
   frequency is between 192 and 432 MHz.
   VCO output frequency = VCO input frequency × PLLN with 192 ≤ PLLN ≤ 432
 */

/*
    000000000: PLLN = 0, wrong configuration
    000000001: PLLN = 1, wrong configuration
    ...
    ...
    110110000: PLLN = 432
    110110001: PLLN = 433, wrong configuration
    ...
    111111111: PLLN = 511, wrong configuration
*/
#define PLLN         2

/*
   PLLM: Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
   Set and cleared by software to divide the PLL and PLLI2S input clock before the VCO.
   These bits can be written only when the PLL and PLLI2S are disabled.
   The software has to set these bits correctly to ensure that the VCO input frequency
   ranges from 1 to 2 MHz. It is recommended to select a frequency of 2 MHz to limit
   PLL jitter.
   VCO input frequency = PLL input clock frequency / PLLM with 2 ≤ PLLM ≤ 63
 */

/*
   000000: PLLM = 0, wrong configuration
   000001: PLLM = 1, wrong configuration
   000010: PLLM = 2
   000011: PLLM = 3
   000100: PLLM = 4
   ...
   111110: PLLM = 62
   111111: PLLM = 63
 */
#define PLLM      2


#endif /* MCAL_RCC_RCC_CONFIG_H_ */
