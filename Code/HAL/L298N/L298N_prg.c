/*
 * L298N_prg.c
 *
 *  Created on: Mar 4, 2023
 *      Author: tarek
 */


#include <util/delay.h>
#include <stdlib.h>

#include "Mcu_HW.h"
#include "STD_TYPES.h"		//Library
#include "BIT_MATH.h"
#include "DIO_int.h"		//Lower Layer interface

#include "L298N_priv.h"
#include "L298N_types.h"
#include "L298N_cfg.h"
#include "L298N_int.h"

#include "TIMER0_int.h"


void L298N_Init(u8 DIR,u8 EN)
{
	switch(DIR)
	{
	case L298N_FORWARD: M_Dio_void_setPinValue(L298N_DIR, DIO_LOW);break;
	case L298N_REVERSE: M_Dio_void_setPinValue(L298N_DIR, DIO_HIGH);break;
	}

	switch(EN)
	{
	case L298N_DISABLE: M_Dio_void_setPinValue(L298N_EN, DIO_HIGH);break;
	case L298N_ENABLE: M_Dio_void_setPinValue(L298N_EN, DIO_LOW);break;
	}

}


void L298N_Start(u8 freq,u8 duty)
{
	M_TIMER0_void_setphaseCorrectPWM(freq,duty);

}
