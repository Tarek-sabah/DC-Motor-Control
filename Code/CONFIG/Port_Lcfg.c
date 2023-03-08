/*
 * Port_Lcfg.c
 *
 *  Created on: Feb 17, 2023
 *      Author: aya_enan
 */

/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file     : Port_Lcfg.c
*  Module   : PORT
*  breif    : Config file for PORT Driver
*
*****************************************************************
*/
/******************************************
  INCLUDES
*******************************************/
#include "Std_Types.h"
#include "Port_Types.h"
#include "Port_Cfg.h"


/******************************************
  Local Macros / Functions
*******************************************/


/******************************************
  Local Data
*******************************************/

/******************************************
  Global Data
*******************************************/

const Port_ConfigType PORT_Config_Arr[PORT_PINS_CONFIG_ARR_SIZE]= {

											   {PORT_PB6,
											   PORT_PIN_LEVEL_LOW,
											   PORT_PINDIR_OUTPUT,
											   PORT_PIN_IN_ATTATCH_FLOATING},

                                               {PORT_PB5,
											   PORT_PIN_LEVEL_LOW,
											   PORT_PINDIR_OUTPUT,
											   PORT_PIN_IN_ATTATCH_FLOATING},

												/*Push Buttons PINS*/
												{PORT_PD7,
												PORT_PIN_LEVEL_HIGH,
												PORT_PINDIR_INPUT,
												PORT_PIN_IN_ATTATCH_PULLUP},
												{PORT_PD6,
												PORT_PIN_LEVEL_HIGH,
												PORT_PINDIR_INPUT,
												PORT_PIN_IN_ATTATCH_PULLUP},
												{PORT_PD5,
												PORT_PIN_LEVEL_HIGH,
												PORT_PINDIR_INPUT,
												PORT_PIN_IN_ATTATCH_PULLUP},
												{PORT_PD3,
												PORT_PIN_LEVEL_HIGH,
												PORT_PINDIR_INPUT,
												PORT_PIN_IN_ATTATCH_PULLUP},
												/*LCD PINS*/
												{PORT_PB0,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},
												{PORT_PB1,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},
												{PORT_PB2,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},
												{PORT_PB4,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},
												{PORT_PA3,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},
												{PORT_PA2,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},
												/*KEYPAD Buttons*/
												/*ROWS*/
												{PORT_PC5,
												PORT_PIN_LEVEL_HIGH,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},
												{PORT_PC4,
												PORT_PIN_LEVEL_HIGH,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},
												{PORT_PC3,
												PORT_PIN_LEVEL_HIGH,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},
												{PORT_PC2,
												PORT_PIN_LEVEL_HIGH,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},
												/*COLUMNS same as Push buttons config*/

												/*OCR0 PIN*/
												{PORT_PB3,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},


};
