/*
 * TIMERS_int.h
 *
 *  Created on: Feb 25, 2023
 *      Author: tarek
 */

#ifndef TIMER0_TIMER0_INT_H_
#define TIMER0_TIMER0_INT_H_

#include "STD_TYPES.h"
#include "TIMER0_cfg.h"



void M_TIMER0_void_Timer_Init();
void M_TIMER0_void_Timer_start();
void M_TIMER0_void_Timer_stop(void);
//u32 M_TIMER0_void_Timer_GetCounts();							// Return Number of Counts
void M_TIMER0_void_Timer_setDelayTimeMilliSec(u16 Delay_Time_ms);
void M_TIMER0_void_EnableInt();
void M_TIMER0_void_DisableInt(void);
void M_TIMER0_void_COMP_setCallBack(void (*ptr)(void));
void M_TIMER0_void_OVF_setCallBack(void (*ptr)(void));
void M_TIMER0_void_setFastPWM(u32 Frequency ,u8 Duty);
void M_TIMER0_void_setphaseCorrectPWM(u32 Frequency ,u8 Duty);




#endif /* TIMER0_TIMER0_INT_H_ */
