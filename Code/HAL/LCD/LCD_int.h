/*
 * LCD_int.h
 *
 *  Created on: Feb 19, 2023
 *      Author: tarek
 */

#ifndef LCD_LCD_INT_H_
#define LCD_LCD_INT_H_

/******************************************
  INCLUDES
*******************************************/



/******************************************
  INSTRUCTIONS
*******************************************/

#define CLEAR_DISPLAY		0x01
#define RETURN_HOME			0x02
#define FUNCTION_SET		0x32		//Mode .
#define	DISPLAY_SETUP		0x28		//LCD Lines . 5x7 Matrix
#define DISPLAY_ON			0x0E		//Display ON . Cursur ON
#define	CURSOR_LEFT			0x10
#define	CURSOR_RIGHT		0x06	//Display encryment with 1 position
#define	DISPLAY_LEFT		0x18
#define	DISPLAY_RIGHT		0x1C
//#define





/******************************************
  syntax : void H_LCD_void_Init(void);

  Description : It should perform initialization sequence as mentioned in data sheet

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  Non
  parameters (out) :  Non
  Return Value     : void
******************************************/
void H_LCD_void_Init(void);
/******************************************
  syntax : void H_LCD_void_sendData(u8 copy_u8data );

  Description : 1- set RS pin to be in data mode.
  	  	  	  	2- send data to static fn that latches data through pins.
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  Non
  parameters (out) :  Non
  Return Value     : void
******************************************/
void H_LCD_void_sendData(u8 copy_u8data );
/******************************************
  syntax : void H_LCD_void_sendCommand(u8 copy_u8command);

  Description : 1- set RS pin to be in command mode.
  	  	  	  	2- send data to static fn that latches data through pins .
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  u8 copy_u8command
  parameters (out) :  Non
  Return Value     : void
******************************************/
void H_LCD_void_sendCommand(u8 copy_u8command);
/******************************************
  syntax : void H_LCD_void_sendString(const s8 * pstr);

  Description : this function should break the string to characters and calls sendData()
  	  	  	  	to display the string character by character.
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  const s8 * pstr
  parameters (out) :  Non
  Return Value     : void
******************************************/
void H_LCD_void_sendString(const u8 * pstr);
/******************************************
  syntax : void H_LCD_void_sendIntNum(s32 copy_s32Num);

  Description : this fn receives a signed integer Number and
  	  	  	  	should convert it to Ascii format then calls sendData()
  	  	  	  	to display the Ascii of the character one by one .
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  s32 copy_s32Num
  parameters (out) :  Non
  Return Value     : void
******************************************/
void H_LCD_void_sendIntNum(s32 copy_s32Num);
/******************************************
  syntax : void H_LCD_void_gotoXY(u8 copy_u8Row,u8 copy_u8Col);

  Description : this function should set the DDRAM address to a specific location ,
  	  	  	  	in order to display the characters in any row and any column .
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  u8 copy_u8Row , u8 copy_u8Col
  parameters (out) :  Non
  Return Value     : void
******************************************/
void H_LCD_void_gotoXY(u8 copy_u8Row,u8 copy_u8Col);
/******************************************
  syntax : void H_LCD_void_creatCustomChar (const u8 * ArrPattern,u8 copy_u8charCode);

  Description : This function creates a custom character such as smiley face and saves its pattern in CGRAM.
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  const u8 * ArrPattern , u8 copy_u8charCode
  parameters (out) :  Non
  Return Value     : void
******************************************/
void H_LCD_void_creatCustomChar (const u8 * ArrPattern,u8 copy_u8charCode);


void H_LCD_void_displayCustomChar (u8 copy_u8charCode);

#endif /* LCD_LCD_INT_H_ */
