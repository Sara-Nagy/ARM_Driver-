/*

 * RCC_Interface.h
 *
 *  Created on: Aug 18, 2022
 *      Author: Sara Nagy
 */

#ifndef MCAL_RCC_RCC_INTERFACE_H_
#define MCAL_RCC_RCC_INTERFACE_H_

/*******                      BUS That Peripheral Connect With            *******/
typedef enum
{
	RCC_AHB1=0,
	RCC_AHB2,
	RCC_APB1,
	RCC_APB2
}BusName_t;

/*** MOC2 Clock Source ***/
typedef enum
{
   MOC2_SYSCLK=0,      // System clock (SYSCLK) selected
   MOC2_PLLI2S ,        // PLLI2S clock selected
   MOC2_HSE,            // HSE oscillator clock selected
   MOC2_PLL           // PLL clock selected
}MOC2_CLK_SCR_T;

/*** MOC1 Clock Source ***/
typedef enum
{
  MOC1_HSI=0,          // HSI clock selected
  MOC1_LSE,          // LSE oscillator selected
  MOC1_HSE,            //HSE oscillator clock selected
  MOC1_PLL             // PLL clock selected
}MOC1_CLK_SCR_T;




/*** AHB1 Peripherals ****/
#define   GPIOA_EN      0
#define   GPIOB_EN      1
#define   GPIOC_EN      2
#define   DMA1_EN       21
#define   DMA2_EN       22

/**** AHB2 Peripherals ***/
#define OTGFS_EN       7

/**** APB1 Peripherals ***/
#define TIM2_EN        0
#define TIM3_EN        1
#define TIM4_EN        2
#define TIM5_EN        3
#define WWDG_EN        11
#define SPI2_EN        14
#define SPI3_EN        15
#define USART2_EN      17
#define I2C1_EN        21
#define I2C2_EN        22
#define I2C3_EN        23
#define PWR_EN         28

/**** APB2 Peripherals ***/
#define TIM1_EN        0
#define USART1_EN      4
#define USART6_EN      5
#define ADC1_EN        8
#define SDIO_EN        11
#define SPI1_EN        12
#define SPI4_EN        13
#define SYSCFG_EN      14
#define TIM9_EN        16
#define TIM10_EN       17
#define TIM11_EN       18





void MRCC_vInit(void);
/*
 * FUNCTION NAME:       MRCC_vInit
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  nothing(void)
 * FUNCTION DESCRIPTION:set the clock of the system.
 */

void MRCC_vEnableClock(BusName_t copy_busname,u8 u8copy_PerNum );
/*
 * FUNCTION NAME:       MRCC_vEnableClock
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  1_the name of the bus for the peripheral
 *                      2_the number of the peripheral in the selected register
 * FUNCTION DESCRIPTION:enable the clock of a peripheral in a bus.
 */

void MRCC_vDisableClock(BusName_t copy_busname,u8 u8copy_PerNum );
/*
 * FUNCTION NAME:       MRCC_vDisableClock
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  1_the name of the bus for the peripheral
 *                      2_the number of the peripheral in the selected register
 * FUNCTION DESCRIPTION:disable the clock of a peripheral in a bus.
 */
void MRCC_V_OUT_MOC1(u8 u8copy_MCO1_SRC);
/*
 * FUNCTION NAME:       MRCC_V_OUT_MOC1
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  the clock source of the Micro controller output 1(unsigned char).
 * FUNCTION DESCRIPTION:enable the output clock of MOC1.
 */
void MRCC_V_OUT_MOC2(u8 u8copy_MCO2_SRC);
/*
 * FUNCTION NAME:       MRCC_V_OUT_MOC1
 * FUNCTION RETURN:     nothing(void)
 * FUNCTION ARGUMENTS:  the clock source of the Micro controller output 2(unsigned char).
 * FUNCTION DESCRIPTION:enable the output clock of MOC2.
 */
#endif /* MCAL_RCC_RCC_INTERFACE_H_ */
