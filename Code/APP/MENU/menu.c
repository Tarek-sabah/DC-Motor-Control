/*
 * menu.c
 *
 *  Created on: Mar 4, 2023
 *      Author: tarek
 */

#include <util/delay.h>

#include "STD_TYPES.h"
#include "Port_int.h"
#include "Dio_int.h"
#include "LCD_int.h"
#include "KEYPAD_int.h"

extern const Port_ConfigType PORT_Config_Arr[PORT_PINS_CONFIG_ARR_SIZE];

u8 Duty=10;
u8 Freq=1;


void MENU()
{

/**********************************DECLARATION****************************************/
	u8 d=0;
	u8 Duty_counter=0;
	Port_Init(PORT_Config_Arr);

/*************************************************************************************/

/**********************************INTIALIZATION****************************************/

	H_LCD_void_Init();
/*************************************************************************************/

	H_LCD_void_sendString("Select Frequency:");
	H_LCD_void_gotoXY(1, 2);
	H_LCD_void_sendString("1-31kHz");
	H_LCD_void_gotoXY(9, 2);
	H_LCD_void_sendString("2-4kHz");

	H_LCD_void_gotoXY(1, 3);
	H_LCD_void_sendString("3-500Hz");

	H_LCD_void_gotoXY(9, 3);
	H_LCD_void_sendString("4-30Hz");


	switch(H_KEYPAD_u8_getPressedKey())
	{
	case 1:H_LCD_void_sendCommand(CLEAR_DISPLAY);H_LCD_void_sendString("31kHz");Freq=1;break;
	case 2:H_LCD_void_sendCommand(CLEAR_DISPLAY);H_LCD_void_sendString("4kHz");Freq=2;break;
	case 3:H_LCD_void_sendCommand(CLEAR_DISPLAY);H_LCD_void_sendString("500Hz");Freq=3;break;
	case 4:H_LCD_void_sendCommand(CLEAR_DISPLAY);H_LCD_void_sendString("122Hz");Freq=4;break;
	}
	_delay_ms(1000);

	L298N_Start(Freq,Duty);

	H_LCD_void_sendCommand(CLEAR_DISPLAY);
	H_LCD_void_sendString("Enter Duty: ");
	H_LCD_void_gotoXY(1, 2);



	Duty = H_KEYPAD_u8_getPressedKey();
	H_LCD_void_sendData(Duty+'0');
	Duty_counter++;
	while(d != 'C')
	{
		d = H_KEYPAD_u8_getPressedKey();
		if(d == 'C')
			break;
		Duty *= 10;
		Duty += d;
		H_LCD_void_sendData(d+'0');
		Duty_counter++;
	}



	H_LCD_void_gotoXY(1, 3);
	if(Duty<0 || Duty>100)
	{
		H_LCD_void_sendString("Wrong Value");
		Duty=0;
	}
	else
	{
		H_LCD_void_sendIntNum(Duty);
	}

	L298N_Start(Freq,Duty);


}
