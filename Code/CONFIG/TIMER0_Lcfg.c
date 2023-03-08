/*
 * TIMERS_Lcfg.h
 *
 *  Created on: Feb 25, 2023
 *      Author: tarek
 */


#include "Std_Types.h"
#include "TIMER0_types.h"
#include "TIMER0_cfg.h"



const TIMER0_SETTINGS_CONFIG TIMER0_SETTINGS_PARAMETERS={
	TIMER0_CLK_SOURCE_1024_PRESCALING,
	TIMER0_MODE_SELECTOR_FAST_PWM,
	OUTPUT_COMPARE_Mode_SET,
	250
};
