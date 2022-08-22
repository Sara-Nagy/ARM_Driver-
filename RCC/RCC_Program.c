/*

 * RCC_Program.c
 *
 *  Created on: Aug 18, 2022
 *      Author: Sara Nagy
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "RCC_Interface.h"
#include "RCC_Config.h"
#include "RCC_Pravite.h"


void MRCC_vInit(void)
{

	/*1- CSS (ON/OFF) */
#if RCC_CSS_ENABLE==ENABLE
	SET_BIT(RCC->CR,CSSON);
#else
	CLR_BIT(RCC->CR,CSSON);
#endif
	/*2- HSE_BYP */
#if HSE_BYP_ENABLE==ENABLE
	SET_BIT(RCC->CR,HSEBYP);
#else
	CLR_BIT(RCC->CR,HSEBYP);
#endif
	/*3- select clock switch (HSI/HSE/PLL) */
#if  RCC_SYS_CLK==RCC_HSI

	CLR_BIT(RCC->CFGR,SW0);
	CLR_BIT(RCC->CFGR,SW1);

#elif RCC_SYS_CLK==RCC_HSE

	SET_BIT(RCC->CFGR,SW0);
	CLR_BIT(RCC->CFGR,SW1);

#elif RCC_SYS_CLK==RCC_PLL

	CLR_BIT(RCC->CFGR,SW0);
	SET_BIT(RCC->CFGR,SW1);
#endif
	/*4- Bus prescalers   */
	//1_AHB prescaler
#if AHB_PRE_ENABLE !=  -1
	RCC->CFGR &=(~(0b1111<<4));
	RCC->CFGR |=(AHB_PRE_ENABLE<<4);
#else
#waring  Wrong Prescaler of AHB
#endif

	//2_APB1 prescaler
#if APB1_PRE_ENABLE != -1
	RCC->CFGR &=(~(0b111<<10));
	RCC->CFGR |=(APB1_PRE_ENABLE<<10);
#else
#waring  Wrong Prescaler of APB1
#endif

	//3_APB2 prescaler
#if APB2_PRE_ENABLE != -1
	RCC->CFGR &=(~(0b111<<13));
	RCC->CFGR |=(APB2_PRE_ENABLE<<13);
#else
#waring  Wrong Prescaler of APB2
#endif
	/*5- PLL configuration */
	//1_PLL clock source
#if  PLL_CLK_SRC == PLL_HSE
	SET_BIT(RCC->PLLCFGR,PLLSRC);
#elif PLL_CLK_SRC ==PLL_HSI
	CLR_BIT(RCC->PLLCFGR,PLLSRC);
#endif

	//2_ PLL OUTPUT Range must be less than or equal to  84MHZ
#if RCC_SYS_CLK==RCC_PLL
	//PLLQ
	RCC->PLLCFGR &=(~(0b1111<<24));
	RCC->PLLCFGR |=(PLLQ<<24);
	//PLLP
	RCC->PLLCFGR &=(~(0b11<<16));
	RCC->PLLCFGR |=(PLLP<<16);
	//PLLN
	RCC->PLLCFGR &=(~(0b111111111<<6));
	RCC->PLLCFGR |=(PLLN<<6);
	//PLLM
	RCC->PLLCFGR &=(~(0b111111<<0));
	RCC->PLLCFGR |=(PLLM<<0);
#else
	/*** no thing o do ***/
#endif
	/*6- Enable the selected clock (HSI ON / HSE ON / PLL ON)*/
#if   RCC_SYS_CLK==RCC_HSI

	SET_BIT(RCC->CR,HSION);                        //1_enable HSI
	while(GET_BIT(RCC->RC,HSIRDY)==0);               //2_check if HSI is ready

#elif RCC_SYS_CLK==RCC_HSE

	SET_BIT(RCC->CR,HSEON);                         //1_enable HSE
	while(GET_BIT(RCC->CR,HSERDY)==0);              //2_check if HSE is ready

#elif RCC_SYS_CLK==RCC_PLL

	SET_BIT(RCC->CR,PLLON);                         //1_enable PLL
	while(GET_BIT(RCC->CR,PLLRDY)==0);              //2_check if PLL is ready

#endif
}

void MRCC_vEnableClock(BusName_t copy_busname,u8 u8copy_PerNum )
{
	/*		Range Check			*/
	if(u8copy_PerNum < 32)
	{
		switch(copy_busname)
		{
		case	RCC_AHB1 :
			SET_BIT(RCC->AHB1ENR,u8copy_PerNum );
			break;
		case	RCC_AHB2 :
			SET_BIT(RCC->AHB2ENR,u8copy_PerNum );
			break;
		case	RCC_APB1 :
			SET_BIT(RCC->APB1ENR,u8copy_PerNum );
			break;
		case	RCC_APB2 :
			SET_BIT(RCC->APB2ENR,u8copy_PerNum );
			break;
		default :
			/** Wrong range ****/
			break;
		}
	}
	else
	{			/*		OUT OF RANGE		*/		}
}

void MRCC_vDisableClock(BusName_t copy_busname,u8 u8copy_PerNum)
{
	/*		Range Check			*/
	if(u8copy_PerNum < 32)
	{
		switch(copy_busname)
		{
		case	RCC_AHB1 :
			CLR_BIT(RCC->AHB1ENR,u8copy_PerNum );
			break;
		case	RCC_AHB2 :
			CLR_BIT(RCC->AHB2ENR,u8copy_PerNum );
			break;
		case	RCC_APB1 :
			CLR_BIT(RCC->APB1ENR,u8copy_PerNum );
			break;
		case	RCC_APB2 :
			CLR_BIT(RCC->APB2ENR,u8copy_PerNum );
			break;
		default :
			/** Wrong range ****/
			break;
		}
	}
	else
	{			/*		OUT OF RANGE		*/		}

}

void MRCC_V_OUT_MOC1(u8 u8copy_MCO1_SRC)
{
	/*** check range ***/
	if(u8copy_MCO1_SRC<4)
	{
		RCC->CFGR &=(~(0b11<<21));
		RCC->CFGR |=(u8copy_MCO1_SRC<<21);
	}
	else
	{
		/**** wrong choise ***/
	}

#if MOC1_PRE_ENABLE != -1
	RCC->CFGR &=(~(0b111<<24));
	RCC->CFGR |=(MOC1_PRE_ENABLE<<24);
#else
#waring  Wrong Prescaler of MOC1
#endif


}

void MRCC_V_OUT_MOC2(u8 u8copy_MCO2_SRC)
{
	/*** check range ***/
	if(u8copy_MCO2_SRC<4)
	{
		RCC->CFGR &=(~(0b11<<30));
		RCC->CFGR |=(u8copy_MCO2_SRC<<30);
	}
	else
	{
		/**** wrong choise ***/
	}

#if MOC2_PRE_ENABLE != -1
	RCC->CFGR &=(~(0b111<<27));
	RCC->CFGR |=(MOC2_PRE_ENABLE<<27);
#else
#waring  Wrong Prescaler of MOC1
#endif


}
