/*
 *  Module: LM35 temperature Sensor
 *  File Name: lm35.h
 *  Description: Header file for the LM35 temp sensor driver
 *  Author: Esraa Khaled
 */

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_


#include "../LIB/std_types.h"

/*Definitions*/
#define LM35_MAX_VOLT 1.5
#define LM35_MAX_TEMPERATURE 150

/*Configuration*/
#define LM35_channel 2

/*Function to analyze and return the digital value converted by the ADC*/
uint8 LM35_getTemperature(void);

#endif /* LM35_SENSOR_H_ */
