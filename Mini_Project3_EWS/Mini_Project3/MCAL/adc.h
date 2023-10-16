/*
 *  Module: ADC
 *  File Name: adc.h
 *  Description: Header file for the ADC driver
 *  Author: Esraa Khaled
 */

#ifndef ADC_H_
#define ADC_H_

#include "../LIB/std_types.h"

/*Definitions*/
#define ADC_REF_VOLT 2.56
#define ADC_MAX_VALUE 1023

/*Types Declaration*/
typedef enum
{
	AREF,AVCC,INTERNAL=3

}ADC_ReferenceVoltage;

typedef enum
{
	F_CPU_1,F_CPU_2,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;

typedef struct
{
	ADC_ReferenceVoltage ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*Initialization Function of the ADC*/
void ADC_init(const ADC_ConfigType* Config_Ptr);

/*Conversion Function of the ADC*/
uint16 ADC_readChannel(uint8 channel);




#endif /* ADC_H_ */
