 /*
 *
 *  Created on: Feb 24, 2023
 *      Author: tarek
 */


#include "Mcu_HW.h"
#include "GID_int.h"

void M_GID_void_Enable(void)
{
	SREG_REG |= 0x80;
}
void M_GID_void_Disable(void)
{
	SREG_REG &= 0x7F;
}
