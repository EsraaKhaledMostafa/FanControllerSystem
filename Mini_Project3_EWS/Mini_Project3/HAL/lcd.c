/*
 *  Module: LCD
 *  File Name: lcd.c
 *  Description: Source file for the LCD driver
 *  Author: Esraa Khaled
 */

#include "lcd.h"
#include "../MCAL/gpio.h"
#include <util/delay.h>
#include "../LIB/common_macros.h"


/*Initialization of LCD with the required mode and configuration*/
void LCD_init(void)
{
	/*Configure the direction of RS and E pins as o/p pins*/
	GPIO_setupPinDirection(LCD_RS_PORT,LCD_RS_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_ENABLE_PORT,LCD_ENABLE_PIN,PIN_OUTPUT);

	/*LCD power ON delay is always 15 ms*/
	_delay_ms(20);

#if(LCD_DATA_BITS_MODE == 4)
	/*Configure the 4 pins on the data port as o/p*/
	GPIO_setupPinDirection(LCD_DATA_BUS_PORT,LCD_DATA_BUS_PIN4,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_BUS_PORT,LCD_DATA_BUS_PIN5,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_BUS_PORT,LCD_DATA_BUS_PIN6,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_BUS_PORT,LCD_DATA_BUS_PIN7,PIN_OUTPUT);

	/*Send initialization commands for 4 bit mode*/
	LCD_sendCommand(LCD_MODE_2LINES_4BITS_INIT1);
	LCD_sendCommand(LCD_MODE_2LINES_4BITS_INIT2);

	/*choose the mode of operation of LCD*/
	LCD_sendCommand(LCD_MODE_2LINES_4BITS);

#elif (LCD_DATA_BITS_MODE == 8)
	/*Configure the data port as o/p port*/
	GPIO_setupPortDirection(LCD_DATA_BUS_PORT,PORT_OUTPUT);

	/*choose the mode of operation of LCD*/
	LCD_sendCommand(LCD_MODE_2LINES_8BITS);

#endif

	/*Send initialization display commands*/
	LCD_sendCommand(LCD_DISPLAY_ON_CURSOR_OFF);
	LCD_sendCommand(LCD_CLEAR_DISPLAY_SCREEN);
}


/*Send the required command to the LCD*/
void LCD_sendCommand(uint8 command)
{
	/*RS = 0 for sending command*/
	GPIO_writePin(LCD_RS_PORT,LCD_RS_PIN,LOGIC_LOW);
	_delay_ms(1); /*Delay for processing Tas = 50ns*/
	/*Enable LCD E = 1*/
	GPIO_writePin(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOGIC_HIGH);
	_delay_ms(1); /*Delay for processing Tpw - Tdws = 190ns*/

#if(LCD_DATA_BITS_MODE == 4)
	/*send the required 8 bits command on two times through the same 4 pins*/
	GPIO_writePin(LCD_DATA_BUS_PORT,LCD_DATA_BUS_PIN4,GET_BIT(command,4));
	GPIO_writePin(LCD_DATA_BUS_PORT,LCD_DATA_BUS_PIN5,GET_BIT(command,5));
	GPIO_writePin(LCD_DATA_BUS_PORT,LCD_DATA_BUS_PIN6,GET_BIT(command,6));
	GPIO_writePin(LCD_DATA_BUS_PORT,LCD_DATA_BUS_PIN7,GET_BIT(command,7));

	_delay_ms(1); /*Delay for processing Tdsw = 100ns*/
	/*Disable LCD E = 0*/
	GPIO_writePin(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOGIC_LOW);
	_delay_ms(1);/*Delay for processing Th = 13ns*/

	/*Enable LCD E = 1*/
	GPIO_writePin(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOGIC_HIGH);
	_delay_ms(1); /*Delay for processing Tpw - Tdws = 190ns*/

	GPIO_writePin(LCD_DATA_BUS_PORT,LCD_DATA_BUS_PIN4,GET_BIT(command,0));
	GPIO_writePin(LCD_DATA_BUS_PORT,LCD_DATA_BUS_PIN5,GET_BIT(command,1));
	GPIO_writePin(LCD_DATA_BUS_PORT,LCD_DATA_BUS_PIN6,GET_BIT(command,2));
	GPIO_writePin(LCD_DATA_BUS_PORT,LCD_DATA_BUS_PIN7,GET_BIT(command,3));

	_delay_ms(1); /*Delay for processing Tdsw = 100ns*/
	/*Disable LCD E = 0*/
	GPIO_writePin(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOGIC_LOW);
	_delay_ms(1);/*Delay for processing Th = 13ns*/


#elif (LCD_DATA_BITS_MODE == 8)
	/*Send the required command on the data bus*/
	GPIO_writePort(LCD_DATA_BUS_PORT,command);
	_delay_ms(1); /*Delay for processing Tdsw = 100ns*/
	/*Disable LCD E = 0*/
	GPIO_writePin(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOGIC_LOW);
	_delay_ms(1);/*Delay for processing Th = 13ns*/
#endif
}

/*Display the required character on the LCD*/
void LCD_displayCharacter(uint8 character)
{
	/*RS = 1 for sending command*/
		GPIO_writePin(LCD_RS_PORT,LCD_RS_PIN,LOGIC_HIGH);
		_delay_ms(1); /*Delay for processing Tas = 50ns*/
		/*Enable LCD E = 1*/
		GPIO_writePin(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOGIC_HIGH);
		_delay_ms(1); /*Delay for processing Tpw - Tdws = 190ns*/

	#if(LCD_DATA_BITS_MODE == 4)
		/*send the required 8 bits command on two times through the same 4 pins*/
		GPIO_writePin(LCD_DATA_BUS_PORT,LCD_DATA_BUS_PIN4,GET_BIT(character,4));
		GPIO_writePin(LCD_DATA_BUS_PORT,LCD_DATA_BUS_PIN5,GET_BIT(character,5));
		GPIO_writePin(LCD_DATA_BUS_PORT,LCD_DATA_BUS_PIN6,GET_BIT(character,6));
		GPIO_writePin(LCD_DATA_BUS_PORT,LCD_DATA_BUS_PIN7,GET_BIT(character,7));

		_delay_ms(1); /*Delay for processing Tdsw = 100ns*/
		/*Disable LCD E = 0*/
		GPIO_writePin(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOGIC_LOW);
		_delay_ms(1);/*Delay for processing Th = 13ns*/

		/*Enable LCD E = 1*/
		GPIO_writePin(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOGIC_HIGH);
		_delay_ms(1); /*Delay for processing Tpw - Tdws = 190ns*/

		GPIO_writePin(LCD_DATA_BUS_PORT,LCD_DATA_BUS_PIN4,GET_BIT(character,0));
		GPIO_writePin(LCD_DATA_BUS_PORT,LCD_DATA_BUS_PIN5,GET_BIT(character,1));
		GPIO_writePin(LCD_DATA_BUS_PORT,LCD_DATA_BUS_PIN6,GET_BIT(character,2));
		GPIO_writePin(LCD_DATA_BUS_PORT,LCD_DATA_BUS_PIN7,GET_BIT(character,3));

		_delay_ms(1); /*Delay for processing Tdsw = 100ns*/
		/*Disable LCD E = 0*/
		GPIO_writePin(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOGIC_LOW);
		_delay_ms(1);/*Delay for processing Th = 13ns*/


	#elif (LCD_DATA_BITS_MODE == 8)
		/*Send the required command on the data bus*/
		GPIO_writePort(LCD_DATA_BUS_PORT,character);
		_delay_ms(1); /*Delay for processing Tdsw = 100ns*/
		/*Disable LCD E = 0*/
		GPIO_writePin(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOGIC_LOW);
		_delay_ms(1);/*Delay for processing Th = 13ns*/
	#endif
}

/*Display the required string on the lCD*/
void LCD_displayString(const sint8* string)
{
	while(*(string) != '\0')
	{
		LCD_displayCharacter(*string);
		string++;
	}
}

/*Move the cursor to a specified row and column on the LCD*/
void LCD_moveCursor(uint8 row,uint8 column)
{
	uint8 lcd_memory_address;
	/*Calculate the required address in the LCD DDRAM*/
	switch(row)
	{
		case 0:
			lcd_memory_address = column;
			break;
		case 1:
			lcd_memory_address = column + 0x40;
			break;
		case 2:
			lcd_memory_address = column + 0x10;
			break;
		case 3:
			lcd_memory_address = column + 0x50;
			break;
	}
	/*Move the LCD cursor to the calculated address*/
	LCD_sendCommand(lcd_memory_address | LCD_MOVE_CURSOR_TO_FIRST_LINE);
}

/*Display the required string in specified position on teh LCD*/
void LCD_displayStringRowColumn(uint8 row,uint8 column,const sint8* string)
{
	/*Go to the required LCD position*/
	LCD_moveCursor(row,column);
	/*Display the string*/
	LCD_displayString(string);
}

/*Display the required decimal value to the screen*/
void LCD_integerToString(int data)
{
	char buff[16]; /*array to hold the ASCII result of each number*/
	itoa(data,buff,10); /*itoa c function to convert the integer data to corresponding ASCII vale, 10 --> base 10 for decimal*/
	LCD_displayString(buff);
}

/*Send the command that clears the display screen*/
void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_DISPLAY_SCREEN);
}




