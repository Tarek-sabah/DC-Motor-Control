/*
 * main.c
 *
 *  Created on: Feb 17, 2023
 *      Author: aya_enan
 */
#include <util/delay.h>
#include "main.h"
#include "Mcu_HW.h"


int main()
{

	M_TIMER0_void_Timer_Init();
	L298N_Init(L298N_REVERSE,L298N_DISABLE);



	while(1)
	{
		MENU();
		_delay_ms(1000);
	}
	return 0;
}




