/*
 * TIMERS_prg.c
 *
 *  Created on: Feb 25, 2023
 *      Author: tarek
 */

#include "Mcu_HW.h"
#include "STD_TYPES.h"		//Library
#include "BIT_MATH.h"
#include "DIO_int.h"		//Lower Layer interface

#include "TIMER0_priv.h"
#include "TIMER0_types.h"
#include "TIMER0_cfg.h"
#include "TIMER0_int.h"
#include "LCD_int.h"


static void (*TIMER0_OVF_CallBack) (void)= NULL;
static void (*TIMER0_COMP_CallBack) (void)= NULL;

u32 TIMER0_OVERFLOW_COUNTER=0;
u32	TIMER0_REQUIRED_OVERFLOW_COUNTS=0;
u32	TIMER0_REQUIRED_REMINDER_COUNTS=0;


extern const TIMER0_SETTINGS_CONFIG TIMER0_SETTINGS_PARAMETERS;



void M_TIMER0_void_Timer_Init()
{

	TCCR0_REG &= TCCR0_WGM_MASK;
	TCCR0_REG |= TIMER0_MODE_SELECTOR_PWM_PC;

	TCCR0_REG &= TCCR0_COM_MASK;
	TCCR0_REG |= OUTPUT_COMPARE_Mode_CLEAR;
//	if(TIMER0_SETTINGS_PARAMETERS.WGM == TIMER0_MODE_SELECTOR_CTC)
//	{
//		OCR0_REG = TIMER0_SETTINGS_PARAMETERS.CTC_value;
//		H_LCD_void_sendIntNum(OCR0_REG);
//	}

}

void M_TIMER0_void_Timer_start()
{
//	TCNT0_REG=TIMER0_REQUIRED_REMINDER_COUNTS;
	TCCR0_REG &= TCCR0_CS_MASK;
	TCCR0_REG|= TIMER0_CLK_SOURCE_0_PRESCALING;

}

void M_TIMER0_void_Timer_stop()
{
	TCCR0_REG &=TCCR0_CS_MASK;
	TCNT0_REG=0;
}

//u32 M_TIMER0_void_Timer_GetCounts()
//{
//	u32 counter = 0;
//
//}


void M_TIMER0_void_Timer_setDelayTimeMilliSec(u16 Delay_Time_ms)
{
	u16 arr[]={0,1,8,64,1024};

	f32 Tick_Time = (f32) (arr[TIMER0_SETTINGS_PARAMETERS.CS-1])/FCPU;
	u32 Desired_Ticks = (u32)(Delay_Time_ms/1000) / Tick_Time;

	if(TIMER0_SETTINGS_PARAMETERS.WGM == TIMER0_MODE_SELECTOR_NORMAL)
	{
		TIMER0_REQUIRED_OVERFLOW_COUNTS = Desired_Ticks / 256;
		TIMER0_REQUIRED_REMINDER_COUNTS = Desired_Ticks % 256;
	}

	else if(TIMER0_SETTINGS_PARAMETERS.WGM == TIMER0_MODE_SELECTOR_CTC)
	{
		TIMER0_REQUIRED_OVERFLOW_COUNTS = Desired_Ticks / TIMER0_SETTINGS_PARAMETERS.CTC_value;
		TIMER0_REQUIRED_REMINDER_COUNTS = Desired_Ticks % TIMER0_SETTINGS_PARAMETERS.CTC_value;
	}

}



void M_TIMER0_void_EnableInt()
{
	TIMSK_REG &=0xFC;
	if(TIMER0_SETTINGS_PARAMETERS.WGM==TIMER0_MODE_SELECTOR_NORMAL)
	{
		TIMSK_REG |= 0x01;
	}
	else if(TIMER0_SETTINGS_PARAMETERS.WGM == TIMER0_MODE_SELECTOR_CTC)
	{
		TIMSK_REG |= 0x02;
	}

}
void M_TIMER0_void_DisableInt()
{
	TIMSK_REG &= 0xFE;
}


void M_TIMER0_void_COMP_setCallBack(void (*ptr)(void))
{
	if(ptr != NULL)
	{
		TIMER0_COMP_CallBack = ptr;
	}
}


void M_TIMER0_void_OVF_setCallBack(void (*ptr)(void))
{
	if(ptr != NULL)
	{
		TIMER0_OVF_CallBack = ptr;
	}
}


void M_TIMER0_void_setFastPWM(u32 Frequency ,u8 Duty)
{
	OCR0_REG=100;
	TCCR0_REG &= TCCR0_CS_MASK;
	TCCR0_REG |= TIMER0_CLK_SOURCE_8_PRESCALING;
}

void M_TIMER0_void_setphaseCorrectPWM(u32 Frequency ,u8 Duty)
{

	OCR0_REG = (u8)(255*Duty/100);
	TCCR0_REG &= TCCR0_CS_MASK;
	TCCR0_REG |= Frequency;
}



void __vector_10 (void)
{
	TIMER0_OVERFLOW_COUNTER++;

	if(TIMER0_OVERFLOW_COUNTER==(TIMER0_REQUIRED_OVERFLOW_COUNTS+1))
	{
		TIMER0_COMP_CallBack ();
		TIMER0_OVERFLOW_COUNTER=0;
	}

}


void __vector_11 (void)
{
	TIMER0_OVERFLOW_COUNTER++;

	if(TIMER0_OVERFLOW_COUNTER==(TIMER0_REQUIRED_OVERFLOW_COUNTS+1))
	{
		TIMER0_OVF_CallBack();
		TIMER0_OVERFLOW_COUNTER=0;
	}
}



