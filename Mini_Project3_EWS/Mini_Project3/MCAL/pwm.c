/*
 *  Module: PWM
 *  File Name: pwm.c
 *  Description: Source file for the PWM driver
 *  Author: Esraa Khaled
 */

#include "pwm.h"
#include "../LIB/atmega32_registers.h"
#include "../MCAL/gpio.h"

/*Function Definition*/

/*The function responsible for trigger the Timer0 with the PWM Mode*/
void PWM_Timer0_init(uint8 duty_cycle)
{
	/*Start counting from zero*/
	TCNT0.byte = 0;

	/*Set up the Compare value based on the required duty cycle*/
	OCR0.byte = ((uint16)(duty_cycle*255)) / 100;

	/*Setup the direction of OC0 -> o/p pin*/
	GPIO_setupPinDirection(PWM_OC0_PORT,PWM_OC0_PIN,PIN_OUTPUT);

	/*Setup Timer0 to work with PWM Non-Inverting Mode*/
	TCCR0.bits.WGM00 = 1;
	TCCR0.bits.WGM01 = 1;

	TCCR0.bits.COM01 = 1;

	/*Set the clock source with prescaler N = 8 */
	TCCR0.bits.CS01 = 1;
}
