/*
 *  Module: LCD
 *  File Name: lcd.h
 *  Description: Header file for the LCD driver
 *  Author: Esraa Khaled
 */
 
#ifndef LCD_H_
#define LCD_H_

#include "../LIB/std_types.h"

/*LCD bits mode configuration*/
#define LCD_DATA_BITS_MODE 8

#if ((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8))

#error "Number of Data bits should be equal 4 or 8 only"

#endif

/*LCD HW pins and ports*/
/*RS and ENable pins configurations*/
#define LCD_RS_PORT                 PORTD_ID
#define LCD_RS_PIN                  PIN0_ID

#define LCD_ENABLE_PORT             PORTD_ID
#define LCD_ENABLE_PIN              PIN2_ID

/*Check for bits mode to configure the whole port or only the last 4 pins*/
#define LCD_DATA_BUS_PORT           PORTC_ID

#if (LCD_DATA_BITS_MODE == 4)

#define LCD_DATA_BUS_PIN4           PIN3_ID
#define LCD_DATA_BUS_PIN5           PIN4_ID
#define LCD_DATA_BUS_PIN6           PIN5_ID
#define LCD_DATA_BUS_PIN7           PIN6_ID

#endif


/*Initialization Modes Commands*/
#define LCD_MODE_1LINE_8BITS          0x30
#define LCD_MODE_2LINES_8BITS         0x38
#define LCD_MODE_1LINE_4BITS          0x20
#define LCD_MODE_2LINES_4BITS         0x28
#define LCD_MODE_2LINES_4BITS_INIT1   0x33
#define LCD_MODE_2LINES_4BITS_INIT2   0x32


/*LCD Commands*/
#define LCD_CLEAR_DISPLAY_SCREEN              0x01
#define LCD_RETURN_HOME                       0x02
#define LCD_SHIFT_CURSOR_TO_LEFT              0x04
#define LCD_SHIFT_DISPLAY_RIGHT               0x05
#define LCD_SHIFT_CURSOR_TO_RIGHT             0x06
#define LCD_SHIFT_DISPLAY_LEFT                0x07
#define LCD_DISPLAY_OFF_CURSOR_OFF            0x08
#define LCD_DISPLAY_OFF_CURSOR_ON             0x0A
#define LCD_DISPLAY_ON_CURSOR_OFF             0x0C
#define LCD_DISPLAY_ON_CURSOR_ON              0x0E
#define LCD_SHIFT_CURSOR_POSITION_TO_LEFT     0x10
#define LCD_SHIFT_CURSOR_POSITION_TO_RIGHT    0x14
#define LCD_SHIFT_ENTIRE_DISPLAY_TO_LEFT      0x18
#define LCD_SHIFT_ENTIRE_DISPLAY_TO_RIGHT     0x1C
#define LCD_MOVE_CURSOR_TO_FIRST_LINE         0x80
#define LCD_MOVE_CURSOR_TO_SECOND_LINE        0xC0





/*Functions Prototypes*/
/*Initialization of LCD with the required mode and configuration*/
void LCD_init(void);

/*Send the required command to the LCD*/
void LCD_sendCommand(uint8 command);

/*Display the required character on the LCD*/
void LCD_displayCharacter(uint8 character);

/*Display the required string on the lCD*/
void LCD_displayString(const sint8* string);

/*Move the cursor to a specified row and column on the LCD*/
void LCD_moveCursor(uint8 row,uint8 column);

/*Display the required string in sepcified position on teh LCD*/
void LCD_displayStringRowColumn(uint8 row,uint8 column,const sint8* string);

/*Display the required decimal value to the screen*/
void LCD_integerToString(int data);

/*Send the command that clears the display screen*/
void LCD_clearScreen(void);

#endif /* LCD_H_ */
