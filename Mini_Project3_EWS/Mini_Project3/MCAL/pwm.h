/*
 *  Module: PWM
 *  File Name: pwm.h
 *  Description: Header file for the PWM driver
 *  Author: Esraa Khaled
 */

#ifndef PWM_H_
#define PWM_H_

#include "../LIB/std_types.h"

/*HW Interfacing Port and pin*/
#define PWM_OC0_PORT     PORTB_ID
#define PWM_OC0_PIN      PIN3_ID

/*Function Prototype*/

/*The function responsible for trigger the Timer0 with the PWM Mode*/
void PWM_Timer0_init(uint8 duty_cycle);

#endif /* PWM_H_ */
