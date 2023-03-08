/*
 * TIMERS_priv.h
 *
 *  Created on: Feb 25, 2023
 *      Author: tarek
 */

#ifndef TIMER0_TIMER0_PRIV_H_
#define TIMER0_TIMER0_PRIV_H_

#define TCNT0_FOC0_ENABLE_MASK	0x80				//Used in register TCNT0 to enable Force Compare Match

#define TOV0_BIT_INDEX	0							//Timer Overflow Flag BIT
#define OCF0_BIT_INDEX	1							//Timer Output Compare Flag BIT


/******************************************
  TCCR0 Masking
*******************************************/

#define TCCR0_WGM_MASK			0xB7
#define TCCR0_COM_MASK			0xCF
#define TCCR0_CS_MASK			0xF8




void __vector_10 (void) __attribute__((signal,used));
void __vector_11 (void) __attribute__((signal,used));



#endif /* TIMER0_TIMER0_PRIV_H_ */




/*Special things about this driver*/

/*
 * For TOV0 (Timer Overflow Flag BIT) This flag still 1 until the software clears it
   The strange thing is that you should write 1 to it in order to clear it
   TIFR = 0b00000001

*/

/************************************************************************/
/*Steps to program TIMER0 in Normal Mode*/
/*
 * 1- TCNT0=0;
 * 2- Select the prescaler u want
 * 3- keep monitoring the TOV0 to see if it is raised
 * 4- Stop the timer by disconnecting the Clock Source
 * 5- Clear FOV0 Flag
 * 6- Go to step 1 again
 *
 * */
