/*
 * LCD_prg.c
 *
 *  Created on: Feb 19, 2023
 *      Author: tarek
 */

#include <util/delay.h>
#include <stdlib.h>

#include "STD_TYPES.h"		//Library
#include "BIT_MATH.h"
#include "DIO_int.h"		//Lower Layer interface

#include "LCD_priv.h"
#include "LCD_types.h"
#include "LCD_cfg.h"
#include "LCD_int.h"



static void H_LCD_void_latchByte(u8 copy_u8Byte)
{
#if(LCD_MODE == _4_BIT_MODE)
	{
		/*
		 * HIGH LEVEL PINS
		 */
		M_Dio_void_setPinValue(LCD_EN_PIN,DIO_LOW);//LCD EN=0
		M_Dio_void_setPinValue(LCD_D4_PIN,GET_BIT(copy_u8Byte,4));
		M_Dio_void_setPinValue(LCD_D5_PIN,GET_BIT(copy_u8Byte,5));
		M_Dio_void_setPinValue(LCD_D6_PIN,GET_BIT(copy_u8Byte,6));
		M_Dio_void_setPinValue(LCD_D7_PIN,GET_BIT(copy_u8Byte,7));

		M_Dio_void_setPinValue(LCD_EN_PIN,DIO_HIGH);//LCD EN=1
		_delay_us(1);
		M_Dio_void_setPinValue(LCD_EN_PIN,DIO_LOW);//LCD EN=1
		_delay_us(100);
		/*
		 * LOW LEVEL PINS
		 */
		M_Dio_void_setPinValue(LCD_EN_PIN,DIO_LOW);//LCD EN=0
		M_Dio_void_setPinValue(LCD_D4_PIN,GET_BIT(copy_u8Byte,0));
		M_Dio_void_setPinValue(LCD_D5_PIN,GET_BIT(copy_u8Byte,1));
		M_Dio_void_setPinValue(LCD_D6_PIN,GET_BIT(copy_u8Byte,2));
		M_Dio_void_setPinValue(LCD_D7_PIN,GET_BIT(copy_u8Byte,3));

		M_Dio_void_setPinValue(LCD_EN_PIN,DIO_HIGH);//LCD EN=1
		_delay_us(1);
		M_Dio_void_setPinValue(LCD_EN_PIN,DIO_LOW);//LCD EN=1
		_delay_us(100);

	}
#elif(LCD_MODE == _8_BIT_MODE)

#endif
}


void H_LCD_void_Init(void)
{
	M_Dio_void_setPinValue(LCD_EN_PIN,DIO_LOW);//LCD EN=0
	_delay_us(2000);

	H_LCD_void_sendCommand(0x33);
	H_LCD_void_sendCommand(FUNCTION_SET);
	H_LCD_void_sendCommand(DISPLAY_SETUP);
	H_LCD_void_sendCommand(DISPLAY_ON);
	H_LCD_void_sendCommand(CLEAR_DISPLAY);
	_delay_us(2000);

	H_LCD_void_sendCommand(CURSOR_RIGHT);

}

void H_LCD_void_sendData(u8 copy_u8data )
{
	//SET RS PIN
	M_Dio_void_setPinValue(LCD_RS_PIN,DIO_HIGH);
	H_LCD_void_latchByte(copy_u8data);

}

void H_LCD_void_sendCommand(u8 copy_u8command)
{
	//CLEAR RS PIN
	M_Dio_void_setPinValue(LCD_RS_PIN,DIO_LOW);
	H_LCD_void_latchByte(copy_u8command);
}

void H_LCD_void_sendString(const u8 * pstr)
{

	while(*pstr!='\0')
	{
		H_LCD_void_sendData(*pstr);
		pstr++;
	}
}

void H_LCD_void_sendIntNum(s32 copy_s32Num)
{

	u32 LOC_u16Reversed = 1;
	if (copy_s32Num == 0) {
		H_LCD_void_sendData('0');
	} else {
		while (copy_s32Num != 0) {
			LOC_u16Reversed = (LOC_u16Reversed * 10) + (copy_s32Num % 10);
			copy_s32Num /= 10;
		}
		while (LOC_u16Reversed != 1) {
			H_LCD_void_sendData(LOC_u16Reversed % 10 + '0');
			LOC_u16Reversed /= 10;
		}
	}

//	u32 s[20]={0};
//	if(copy_s32Num < 0)
//	{
//		H_LCD_void_sendData('-');
//		copy_s32Num *= (-1);
//	}
//	ltoa(copy_s32Num,s,10);
//	H_LCD_void_sendString(s);
}

void H_LCD_void_gotoXY(u8 copy_u8Row,u8 copy_u8Col)
{
	u8 firstCharAdr[]={0x80,0xC0,0x94,0xD4};
	H_LCD_void_sendCommand(firstCharAdr[copy_u8Col-1]+copy_u8Row-1);
	_delay_us(100);
}

