/*
 * KEYPAD_prg.c
 *
 *  Created on: Feb 23, 2023
 *      Author: tarek
 */


#include <util/delay.h>
#include <stdlib.h>

#include "Mcu_HW.h"
#include "STD_TYPES.h"		//Library
#include "BIT_MATH.h"
#include "DIO_int.h"		//Lower Layer interface

#include "KEYPAD_priv.h"
#include "KEYPAD_types.h"
#include "KEYPAD_cfg.h"
#include "KEYPAD_int.h"
#include "LCD_int.h"


const static u8 rows[4]={KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN};
const static u8 cols[4]={KEYPAD_C0_PIN,KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN};


u8 H_KEYPAD_u8_getPressedKey(void){


	u8 r,c,rc;

	u8 colloc;

	do{
		KEY_PTR &= 0xC3;					//PULL Down all KEYPAD rows
		colloc = (KEY_PIN & 0xE8);			//Read All Columns

	}while(colloc != 0xE8);					//Check until all keys are released

	do{
		do{
			_delay_ms(20);					//Call Delay
			colloc = (KEY_PIN & 0xE8);		//See if any key is pressed
		}while(colloc == 0xE8);				//Keep Checking for key press
		_delay_ms(20);
		colloc = (KEY_PIN & 0xE8);			//Read columns
	}while(colloc == 0xE8);					//Wait for key press

//	/*
//	 * Check code for PADs
//	 */

	for (r=0;r<4;r++)
	{
		KEY_PTR=0xFF;
		M_Dio_void_setPinValue(rows[r], DIO_LOW);
		_delay_ms(1);
		for(c=0;c<4;c++)
		{
			if(M_Dio_en_getPinValue(cols[c])==DIO_LOW) rc=keypad[r][c];

		}
	}
	return rc;
}
