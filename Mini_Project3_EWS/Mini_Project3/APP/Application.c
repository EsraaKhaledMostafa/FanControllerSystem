/*
 *  Module: main
 *  File Name: application.c
 *  Description: Application for interfacing temp sensor and ADc with atmega32
 *  Author: Esraa Khaled
 */

#include "../MCAL/adc.h"
#include "../HAL/lcd.h"
#include "../HAL/lm35_sensor.h"
#include "../HAL/dc_motor.h"

int main(void)
{
	uint8 temperature = 0, speed = 0, motor_state = STOP;

	ADC_ConfigType ADC_Configurations = {INTERNAL,F_CPU_8}; /*Configuration struct for ADC Driver*/

	LCD_init(); /* initialize LCD driver */
	ADC_init(&ADC_Configurations); /* initialize ADC driver */
	DcMotor_Init(); /* initialize DC Motor driver*/

	/* Display this strings "FAN is " and "Temp = " only once on LCD at the first row */
	LCD_displayStringRowColumn(0,2,"FAN is ");
	LCD_displayStringRowColumn(1,2,"Temp = ");

    while(1)
    {
    	/* Read ADC channel 0 where the potentiometer is connected */
		temperature = LM35_getTemperature();

		/* Display the ADC digital value every time at same position */
		if(temperature >= 100)
		{
			LCD_moveCursor(1,9);
			LCD_integerToString(temperature);
		}
		else
		{
			LCD_moveCursor(1,9);
			LCD_integerToString(temperature);
			/* In case the digital value is one or two digits print spaces in the next digit place */
			LCD_displayString(" ");
		}
		LCD_displayStringRowColumn(1,12,"C");

		/*Control the Fan motion according to the temperature*/
		if(temperature >= 120)
		{
			speed = 100;
			motor_state = CW;
			LCD_displayStringRowColumn(0,8," ON ");
		}
		else if(temperature >= 90)
		{
			speed = 75;
			motor_state = CW;
			LCD_displayStringRowColumn(0,8," ON ");
		}
		else if(temperature >= 60)
		{
			speed = 50;
			motor_state = CW;
			LCD_displayStringRowColumn(0,8," ON ");
		}
		else if(temperature >= 30)
		{
			speed = 25;
			motor_state = CW;
			LCD_displayStringRowColumn(0,8," ON ");
		}
		else if(temperature < 30)
		{
			speed = 0;
			motor_state = STOP;
			LCD_displayStringRowColumn(0,8," OFF");
		}
		DcMotor_Rotate(motor_state,speed);
    }
}


