/*
 *  Module: DC Motor
 *  File Name: dc_motor.c
 *  Description: Source file for the DC Motor driver
 *  Author: Esraa Khaled
 */


#include "dc_motor.h"
#include "../MCAL/gpio.h"
#include "../MCAL/pwm.h"



/*Functions Definitions*/

/*Initialization of the DC Motor*/
void DcMotor_Init(void)
{
	GPIO_setupPinDirection(DC_MOTOR_H_BRIDGE_IN1_PORT,DC_MOTOR_H_BRIDGE_IN1_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_H_BRIDGE_IN2_PORT,DC_MOTOR_H_BRIDGE_IN2_PIN,PIN_OUTPUT);

	GPIO_writePin(DC_MOTOR_H_BRIDGE_IN1_PORT,DC_MOTOR_H_BRIDGE_IN1_PIN,LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_H_BRIDGE_IN2_PORT,DC_MOTOR_H_BRIDGE_IN2_PIN,LOGIC_LOW);
}



/*Setup the direction of rotation of the motor*/
void DcMotor_Rotate(DcMotor_State state, uint8 speed)
{
	switch(state)
	{
		case STOP:
			GPIO_writePin(DC_MOTOR_H_BRIDGE_IN1_PORT,DC_MOTOR_H_BRIDGE_IN1_PIN,LOGIC_LOW);
			GPIO_writePin(DC_MOTOR_H_BRIDGE_IN2_PORT,DC_MOTOR_H_BRIDGE_IN2_PIN,LOGIC_LOW);
			break;
		case CW:
			GPIO_writePin(DC_MOTOR_H_BRIDGE_IN1_PORT,DC_MOTOR_H_BRIDGE_IN1_PIN,LOGIC_LOW);
			GPIO_writePin(DC_MOTOR_H_BRIDGE_IN2_PORT,DC_MOTOR_H_BRIDGE_IN2_PIN,LOGIC_HIGH);
			break;
		case ACW:
			GPIO_writePin(DC_MOTOR_H_BRIDGE_IN1_PORT,DC_MOTOR_H_BRIDGE_IN1_PIN,LOGIC_HIGH);
			GPIO_writePin(DC_MOTOR_H_BRIDGE_IN2_PORT,DC_MOTOR_H_BRIDGE_IN2_PIN,LOGIC_LOW);
			break;
	}
	PWM_Timer0_init(speed);
}
