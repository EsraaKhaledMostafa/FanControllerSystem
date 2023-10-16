/*
 *  Module: LM35 temperature Sensor
 *  File Name: lm35.c
 *  Description: Source file for the LM35 temp sensor driver
 *  Author: Esraa Khaled
 */


#include "lm35_sensor.h"

#include "../MCAL/adc.h"


uint8 LM35_getTemperature(void)
{
	uint16 adc_value = 0;
	uint8 temperature = 0;

	adc_value = ADC_readChannel(LM35_channel);

	temperature = (uint8)(((uint32)LM35_MAX_TEMPERATURE*adc_value*ADC_REF_VOLT)/(LM35_MAX_VOLT*ADC_MAX_VALUE));

	return temperature;
}
