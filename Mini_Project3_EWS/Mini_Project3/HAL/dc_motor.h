/*
 *  Module: DC Motor
 *  File Name: dc_motor.h
 *  Description: Header file for the DC Motor driver
 *  Author: Esraa Khaled
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "../LIB/std_types.h"

/*DC Motor HW pins and ports*/
#define DC_MOTOR_H_BRIDGE_IN1_PORT     PORTB_ID
#define DC_MOTOR_H_BRIDGE_IN2_PORT     PORTB_ID

#define DC_MOTOR_H_BRIDGE_IN1_PIN      PIN0_ID
#define DC_MOTOR_H_BRIDGE_IN2_PIN      PIN1_ID

/*Types Declarations*/
typedef enum
{
	STOP,CW,ACW
}DcMotor_State;

/*Functions Prototype*/

/*Initialization of the DC Motor*/
void DcMotor_Init(void);

/*Setup the direction of rotation of the motor*/
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
