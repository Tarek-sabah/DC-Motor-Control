/*
 * LCD_priv.h
 *
 *  Created on: Feb 19, 2023
 *      Author: tarek
 */

#ifndef LCD_LCD_PRIV_H_
#define LCD_LCD_PRIV_H_

/******************************************
  syntax : static void H_LCD_void_latchByte(u8 copy_u8Byte);

  Description : used to send data OR command (this function supports both 4bit mode and 8bit mode).
  	  	  	  *In 8 bit mode: it breaks the 8 bit (data/command) into 8 indivual bits and sends them over the 8 pins.
  	  	  	  *In bit mode: it breaks the 8 bit (data/command) into two halves(each half is 4 bits and send them over the 4 pins) each half at a time Note:
  	  	  	  	  high order half is sent before the low order one.
  	  	  	  *This static function is called by both the functions sendData and sendCommand.
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  const u8 * ArrPattern , u8 copy_u8charCode
  parameters (out) :  Non
  Return Value     : void
******************************************/
static void H_LCD_void_latchByte(u8 copy_u8Byte);

#endif /* LCD_LCD_PRIV_H_ */
