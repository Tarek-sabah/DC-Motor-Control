/*
 * KEYPAD_priv.h
 *
 *  Created on: Feb 23, 2023
 *      Author: tarek
 */

#ifndef KEYPAD_KEYPAD_PRIV_H_
#define KEYPAD_KEYPAD_PRIV_H_


#define KEY_PTR		PORTC_REG
#define KEY_PIN		PIND_REG

static const u8 keypad[4][4]={{7,8,9,'/'},
							  {4,5,6,'x'},
							  {1,2,3,'-'},
							  {'C',0,'=','+'}};


#endif /* KEYPAD_KEYPAD_PRIV_H_ */
