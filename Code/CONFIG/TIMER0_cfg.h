/*
 * TIMERS_cfg.h
 *
 *  Created on: Feb 25, 2023
 *      Author: tarek
 */

#ifndef TIMER0_CFG_H_
#define TIMER0_CFG_H_

#include "TIMER0_types.h"

#define FCPU	16000000


typedef struct{
	TIMER0_CLK_SOURCE					CS;
	TIMER0_MODE_SELECTOR				WGM;
	TIMER0_OUTPUT_COMPARE_MODE			COM;
	u8 									CTC_value;
}TIMER0_SETTINGS_CONFIG;



#endif /* TIMER0_CFG_H_ */
