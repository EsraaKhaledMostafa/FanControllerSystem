/*
 *  Module: ADC
 *  File Name: adc.c
 *  Description: Source file for the ADC driver
 *  Author: Esraa Khaled
 */


#include "../LIB/atmega32_registers.h"
#include "adc.h"


/*Initialization Function of the ADC*/
void ADC_init(const ADC_ConfigType* Config_Ptr)
{
	/*Analog channel --> ADC0 with no gain MUX0 - MUX5 -> 00000*/
	/*ADLAR -> right adjusted*/
	ADMUX.bits.MUX0 = 0;
	ADMUX.bits.MUX1 = 0;
	ADMUX.bits.MUX2 = 0;
	ADMUX.bits.MUX3 = 0;
	ADMUX.bits.MUX4 = 0;
	ADMUX.bits.ADLAR = 0;

	/*Adjust reference selection bits to choose AREF -> REFS0, REFS1 = 0*/
	ADMUX.byte = (ADMUX.byte & 0x3F) | ((Config_Ptr->ref_volt) << 6);

	/*ADC Enable = 1*/
	ADCSRA.bits.ADEN = 1;
	/*Disable ADC Interrupt*/
	ADCSRA.bits.ADIE = 0;
	/*Chose the prescaler -> FADC = FCPU/ N*/
	ADCSRA.byte = (ADCSRA.byte & 0xFB) | (Config_Ptr->prescaler);



}


/*Conversion Function of the ADC*/
uint16 ADC_readChannel(uint8 channel)
{
	ADMUX.byte = (ADMUX.byte & 0xE0) | (channel & 0x07); /*Adjust the ADC analog channel to the one connected to the sensor*/
	ADCSRA.bits.ADSC = 1; /*ADC start conversion*/
	while(ADCSRA.bits.ADIF == 0)
	{

	}
	ADCSRA.bits.ADIF = 1; /*clear the flag*/
	return ADC.byte2; /*read the data*/
}



