/*
 * RCC_Pravite.h

 *
 *  Created on: Aug 18, 2022
 *      Author: Sara Ahmed
 */

#ifndef MCAL_RCC_RCC_PRAVITE_H_
#define MCAL_RCC_RCC_PRAVITE_H_

/**** Register Map *****/

#define RCC_BASE_ADDR		((u32)(0x40023800))

typedef struct
{
	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 reserved1[2];
	u32 APB1RSTR;
	u32 APB2RSTR;
	u32 reserved2[2];
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 reserved3[2] ;
	u32 APB1ENR;
	u32 APB2ENR;
}RCC_MemMap_t;

#define RCC  ((volatile RCC_MemMap_t*)(RCC_BASE_ADDR))


/********************   BIT NEEDED                 **********************/

#define CSSON         19          //Clock security system enable
/****
 * 0: Clock security system OFF (Clock detector OFF)
 * 1: Clock security system ON (Clock detector ON if HSE oscillator is stable, OFF if not)
 */
/***** HSE *******/
#define HSEON         16         //Internal high-speed clock enable
/**
 * 0: HSE oscillator OFF
 *  1: HSE oscillator ON
 **/
#define HSERDY   17                 // Internal high-speed clock ready flag
/**
 * 0: HSE oscillator not ready
 * 1: HSE oscillator ready
 **/
#define HSEBYP   18              //HSE clock bypass
/**
 * 0: HSE oscillator not bypassed
 * 1: HSE oscillator bypassed with an external clock
 */

/***** HSI *******/
#define HSION         0         //Internal high-speed clock enable
/**
 * 0: HSI oscillator OFF
 *  1: HSI oscillator ON
 **/
#define HSIRDY        1            // Internal high-speed clock ready flag
/**
 * 0: HSI oscillator not ready
 * 1: HSI oscillator ready
 **/
/***** PLL *****/
#define PLLON         24         //Internal high-speed clock enable
/**
 * 0:  PLL OFF
 * 1:  PLL ON
 **/
#define PLLRDY        25            // Internal high-speed clock ready flag
/**
 * 0: PLL locked
 * 1: PLL not locked
 **/

#define PLLSRC         22
/**
 *  0: HSI clock selected as PLL and PLLI2S clock entry
 *  1: HSE oscillator clock selected as PLL and PLLI2S clock entry
 */
/****** system clock *************/
#define SW0     0                  // System clock switch0
#define SW1     1                  // System clock switch1
/***
 * 00: HSI oscillator selected as system clock
 * 01: HSE oscillator selected as system clock
 * 10: PLL selected as system clock
 * 11: not allowe
 */

#define SWS0     0                  //  System clock switch status0
#define SWS1     1                  // : System clock switch status1
/***
 * 00: HSI oscillator used as the system clock
 * 01: HSE oscillator used as the system clock
 * 10: PLL used as the system clock
 * 11: not applicable
 */

/**** used in RCC_Config.j ***/
#define ENABLE           1
#define DISABLE          0

#define RCC_HSI          0
#define RCC_HSE          1
#define RCC_PLL          2
#endif /* MCAL_RCC_RCC_PRAVITE_H_ */
