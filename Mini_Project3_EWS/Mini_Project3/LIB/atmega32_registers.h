/*
 *  Module: common
 *  File Name: atmega32_registers.h
 *  Description: Regsiters data types declaration and
 * 				 addresses for avr atmega32 uc
 *  Author: Esraa Khaled
 */

#ifndef ATMEGA32_REGISTERS_H_
#define ATMEGA32_REGISTERS_H_

#include "../LIB/std_types.h"

/*Register data types*/

/*Status Register - SREG*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 C_BIT: 1;
		uint8 Z_BIT: 1;
		uint8 N_BIT: 1;
		uint8 V_BIT: 1;
		uint8 S_BIT: 1;
		uint8 H_BIT: 1;
		uint8 T_BIT: 1;
		uint8 I_BIT: 1;
	}bits;
}SREG;

/*Stack Pointer - SP*/
typedef union
{
	uint16 byte2;
	struct
	{
		uint16 SP0:  1;
		uint16 SP1:  1;
		uint16 SP2:  1;
		uint16 SP3:  1;
		uint16 SP4:  1;
		uint16 SP5:  1;
		uint16 SP6:  1;
		uint16 SP7:  1;
		uint16 SP8:  1;
		uint16 SP9:  1;
		uint16 SP10: 1;
		uint16 SP11: 1;
		uint16     : 4;

	}bits;
}SP;

/*Output Compare Register - OCR0*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 OCR00: 1;
		uint8 OCR01: 1;
		uint8 OCR02: 1;
		uint8 OCR03: 1;
		uint8 OCR04: 1;
		uint8 OCR05: 1;
		uint8 OCR06: 1;
		uint8 OCR07: 1;
	}bits;
}OCR0;

/*General Interrupt Control Register - GICR */
typedef union
{
	uint8 byte;
	struct
	{
		uint8 IVCE:  1;
		uint8 IVSEL: 1;
		uint8      : 3;
		uint8 INT2:  1;
		uint8 INT0:  1;
		uint8 INT1:  1;
	}bits;
}GICR;

/*General Interrupt Flag Register – GIFR*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8      :  5;
		uint8 INTF2:  1;
		uint8 INTF0:  1;
		uint8 INTF1:  1;
	}bits;
}GIFR;

/*Timer/Counter Interrupt Mask Register – TIMSK*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 TOIE0:  1;
		uint8 OCIE0:  1;
		uint8 TOIE1:  1;
		uint8 OCIE1B: 1;
		uint8 OCIE1A: 1;
		uint8 TICIE1: 1;
		uint8 TOIE2:  1;
		uint8 OCIE2:  1;
	}bits;
}TIMSK;

/*Timer/Counter Interrupt Flag Register – TIFR*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 TOV0:  1;
		uint8 OCF0:  1;
		uint8 TOV1:  1;
		uint8 OCF1B: 1;
		uint8 OCF1A: 1;
		uint8 ICF1:  1;
		uint8 TOV2:  1;
		uint8 OCF2:  1;
	}bits;
}TIFR;

/*Store Program Memory Control Register – SPMCR*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 SPMEN:  1;
		uint8 PGERS:  1;
		uint8 PGWRT:  1;
		uint8 BLBSET: 1;
		uint8 RWWSRE: 1;
		uint8       : 1;
		uint8 RWWSB:  1;
		uint8 SPMIE:  1;
	}bits;
}SPMCR;

/*TWI Control Register – TWCR*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 TWIE:  1;
		uint8     :  1;
		uint8 TWEN:  1;
		uint8 TWWC:  1;
		uint8 TWSTO: 1;
		uint8 TWSTA: 1;
		uint8 TWEA:  1;
		uint8 TWINT: 1;
	}bits;
}TWCR;

/* MCU Control Register – MCUCR*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 ISC00: 1;
		uint8 ISC01: 1;
		uint8 ISC10: 1;
		uint8 ISC11: 1;
		uint8 SM0:   1;
		uint8 SM1:   1;
		uint8 SM2:   1;
		uint8 SE:    1;
	}bits;
}MCUCR;

/*MCU Control and Status Register – MCUCSR*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 PORF:  1;
		uint8 EXTRF: 1;
		uint8 BORF:  1;
		uint8 WDRF:  1;
		uint8 JTRF:  1;
		uint8     :  1;
		uint8 ISC2:  1;
		uint8 JTD:   1;
	}bits;
}MCUCSR;

/*Timer/Counter Control Register – TCCR0 */
typedef union
{
	uint8 byte;
	struct
	{
		uint8 CS00:   1;
		uint8 CS01:   1;
		uint8 CS02:   1;
		uint8 WGM01:  1;
		uint8 COM00:  1;
		uint8 COM01:  1;
		uint8 WGM00:  1;
		uint8 FOC0:   1;
	}bits;
}TCCR0;

/*Timer/Counter Register – TCNT0*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 TCNT0_0: 1;
		uint8 TCNT0_1: 1;
		uint8 TCNT0_2: 1;
		uint8 TCNT0_3: 1;
		uint8 TCNT0_4: 1;
		uint8 TCNT0_5: 1;
		uint8 TCNT0_6: 1;
		uint8 TCNT0_7: 1;
	}bits;
}TCNT0;

/*Oscillator Calibration Register – OSCCAL*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 OSCCAL0: 1;
		uint8 OSCCAL1: 1;
		uint8 OSCCAL2: 1;
		uint8 OSCCAL3: 1;
		uint8 OSCCAL4: 1;
		uint8 OSCCAL5: 1;
		uint8 OSCCAL6: 1;
		uint8 OSCCAL7: 1;
	}bits;
}OSCCAL;


/*On-chip Debug Register – OCDR*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 OCDR0: 1;
		uint8 OCDR1: 1;
		uint8 OCDR2: 1;
		uint8 OCDR3: 1;
		uint8 OCDR4: 1;
		uint8 OCDR5: 1;
		uint8 OCDR6: 1;
		uint8 OCDR7: 1;
	}bits;
}OCDR;

/*Special Function I/O Register – SFIOR */
typedef union
{
	uint8 byte;
	struct
	{
		uint8 PSR10: 1;
		uint8 PSR2:  1;
		uint8 PUD:   1;
		uint8 ACME:  1;
		uint8     :  1;
		uint8 ADTS0: 1;
		uint8 ADTS1: 1;
		uint8 ADTS2: 1;
	}bits;
}SFIOR;

/*Timer/Counter1 Control Register A – TCCR1A */
typedef union
{
	uint8 byte;
	struct
	{
		uint8 WGM10:  1;
		uint8 WGM11:  1;
		uint8 FOC1B:  1;
		uint8 FOC1A:  1;
		uint8 COM1B0: 1;
		uint8 COM1B1: 1;
		uint8 COM1A0: 1;
		uint8 COM1A1: 1;
	}bits;
}TCCR1A;

/* Timer/Counter1 Control Register B – TCCR1B*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 CS10:  1;
		uint8 CS11:  1;
		uint8 CS12:  1;
		uint8 WGM12: 1;
		uint8 WGM13: 1;
		uint8      : 1;
		uint8 ICES1: 1;
		uint8 ICNC1: 1;
	}bits;
}TCCR1B;


/*Timer/Counter1 – TCNT1H and TCNT1L*/
typedef union
{
	uint16 byte2;
	struct
	{
		uint16 TCNT1_0:  1;
		uint16 TCNT1_1:  1;
		uint16 TCNT1_2:  1;
		uint16 TCNT1_3:  1;
		uint16 TCNT1_4:  1;
		uint16 TCNT1_5:  1;
		uint16 TCNT1_6:  1;
		uint16 TCNT1_7:  1;
		uint16 TCNT1_8:  1;
		uint16 TCNT1_9:  1;
		uint16 TCNT1_10: 1;
		uint16 TCNT1_11: 1;
		uint16 TCNT1_12: 1;
		uint16 TCNT1_13: 1;
		uint16 TCNT1_14: 1;
		uint16 TCNT1_15: 1;
	}bits;
}TCNT1;

/*Output Compare Register 1 A – OCR1AH and OCR1AL*/
typedef union
{
	uint16 byte2;
	struct
	{
		uint16 OCR1A0:  1;
		uint16 OCR1A1:  1;
		uint16 OCR1A2:  1;
		uint16 OCR1A3:  1;
		uint16 OCR1A4:  1;
		uint16 OCR1A5:  1;
		uint16 OCR1A6:  1;
		uint16 OCR1A7:  1;
		uint16 OCR1A8:  1;
		uint16 OCR1A9:  1;
		uint16 OCR1A10: 1;
		uint16 OCR1A11: 1;
		uint16 OCR1A12: 1;
		uint16 OCR1A13: 1;
		uint16 OCR1A14: 1;
		uint16 OCR1A15: 1;
	}bits;
}OCR1A;


/*Output Compare Register 1 B – OCR1BH and OCR1BL*/
typedef union
{
	uint16 byte2;
	struct
	{
		uint16 OCR1B0:  1;
		uint16 OCR1B1:  1;
		uint16 OCR1B2:  1;
		uint16 OCR1B3:  1;
		uint16 OCR1B4:  1;
		uint16 OCR1B5:  1;
		uint16 OCR1B6:  1;
		uint16 OCR1B7:  1;
		uint16 OCR1B8:  1;
		uint16 OCR1B9:  1;
		uint16 OCR1B10: 1;
		uint16 OCR1B11: 1;
		uint16 OCR1B12: 1;
		uint16 OCR1B13: 1;
		uint16 OCR1B14: 1;
		uint16 OCR1B15: 1;
	}bits;
}OCR1B;

/*Input Capture Register 1 – ICR1H and ICR1L*/
typedef union
{
	uint16 byte2;
	struct
	{
		uint16 ICR1_0:  1;
		uint16 ICR1_1:  1;
		uint16 ICR1_2:  1;
		uint16 ICR1_3:  1;
		uint16 ICR1_4:  1;
		uint16 ICR1_5:  1;
		uint16 ICR1_6:  1;
		uint16 ICR1_7:  1;
		uint16 ICR1_8:  1;
		uint16 ICR1_9:  1;
		uint16 ICR1_10: 1;
		uint16 ICR1_11: 1;
		uint16 ICR1_12: 1;
		uint16 ICR1_13: 1;
		uint16 ICR1_14: 1;
		uint16 ICR1_15: 1;
	}bits;
}ICR1;

/*Timer/Counter Control Register – TCCR2*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 CS20:  1;
		uint8 CS21:  1;
		uint8 CS22:  1;
		uint8 WGM21: 1;
		uint8 COM20: 1;
		uint8 COM21: 1;
		uint8 WGM20: 1;
		uint8 FOC2:  1;
	}bits;
}TCCR2;

/*Timer/Counter Register – TCNT2*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 TCNT2_0: 1;
		uint8 TCNT2_1: 1;
		uint8 TCNT2_2: 1;
		uint8 TCNT2_3: 1;
		uint8 TCNT2_4: 1;
		uint8 TCNT2_5: 1;
		uint8 TCNT2_6: 1;
		uint8 TCNT2_7: 1;
	}bits;
}TCNT2;

/*Output Compare Register – OCR2*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 OCR2_0: 1;
		uint8 OCR2_1: 1;
		uint8 OCR2_2: 1;
		uint8 OCR2_3: 1;
		uint8 OCR2_4: 1;
		uint8 OCR2_5: 1;
		uint8 OCR2_6: 1;
		uint8 OCR2_7: 1;
	}bits;
}OCR2;

/*Asynchronous Status Register – ASSR*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 TCR2UB: 1;
		uint8 OCR2UB: 1;
		uint8 TCN2UB: 1;
		uint8 AS2:    1;
		uint8       : 4;
	}bits;
}ASSR;

/*Watchdog Timer Control Register – WDTCR*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 WDP0:  1;
		uint8 WDP1:  1;
		uint8 WDP2:  1;
		uint8 WDE:   1;
		uint8 WDTOE: 1;
		uint8     :  3;
	}bits;
}WDTCR;

/*USART Baud Rate Registers – UBRRH*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 UBRR8:  1;
		uint8 UBRR9:  1;
		uint8 UBRR10: 1;
		uint8 UBRR11: 1;
		uint8       : 3;
		uint8 URSEL:  1;
	}bits;
}UBRRH;

/*USART Control and Status Register C – UCSRC*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 UCPOL: 1;
		uint8 UCSZ0: 1;
		uint8 UCSZ1: 1;
		uint8 USBS:  1;
		uint8 UPM0:  1;
		uint8 UPM1:  1;
		uint8 UMSEL: 1;
		uint8 URSEL: 1;
	}bits;
}UCSRC;

/*The EEPROM Address Register – EEARH and EEARL*/
typedef union
{
	uint16 byte2;
	struct
	{
		uint16 EEAR0:  1;
		uint16 EEAR1:  1;
		uint16 EEAR2:  1;
		uint16 EEAR3:  1;
		uint16 EEAR4:  1;
		uint16 EEAR5:  1;
		uint16 EEAR6:  1;
		uint16 EEAR7:  1;
		uint16 EEAR8:  1;
		uint16 EEAR9:  1;
		uint16      :  6;
	}bits;
}EEAR;

/*The EEPROM Data Register – EEDR*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 EEDR0: 1;
		uint8 EEDR1: 1;
		uint8 EEDR2: 1;
		uint8 EEDR3: 1;
		uint8 EEDR4: 1;
		uint8 EEDR5: 1;
		uint8 EEDR6: 1;
		uint8 EEDR7: 1;
	}bits;
}EEDR;

/*The EEPROM Control Register – EECR*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 EERE:  1;
		uint8 EEWE:  1;
		uint8 EEMWE: 1;
		uint8 EERIE: 1;
		uint8      : 4;
	}bits;
}EECR;

/*Port A Data Register – PORTA*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 PORTA0: 1;
		uint8 PORTA1: 1;
		uint8 PORTA2: 1;
		uint8 PORTA3: 1;
		uint8 PORTA4: 1;
		uint8 PORTA5: 1;
		uint8 PORTA6: 1;
		uint8 PORTA7: 1;
	}bits;
}PORTA;

/*Port A Data Direction Register – DDRA*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 DDA0: 1;
		uint8 DDA1: 1;
		uint8 DDA2: 1;
		uint8 DDA3: 1;
		uint8 DDA4: 1;
		uint8 DDA5: 1;
		uint8 DDA6: 1;
		uint8 DDA7: 1;
	}bits;
}DDRA;


/*Port A Input Pins Address – PINA */
typedef union
{
	uint8 byte;
	struct
	{
		uint8 PINA0: 1;
		uint8 PINA1: 1;
		uint8 PINA2: 1;
		uint8 PINA3: 1;
		uint8 PINA4: 1;
		uint8 PINA5: 1;
		uint8 PINA6: 1;
		uint8 PINA7: 1;
	}bits;
}PINA;

/*Port B Data Register – PORTB*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 PORTB0: 1;
		uint8 PORTB1: 1;
		uint8 PORTB2: 1;
		uint8 PORTB3: 1;
		uint8 PORTB4: 1;
		uint8 PORTB5: 1;
		uint8 PORTB6: 1;
		uint8 PORTB7: 1;
	}bits;
}PORTB;


/*Port B Data Direction Register – DDRB*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 DDB0: 1;
		uint8 DDB1: 1;
		uint8 DDB2: 1;
		uint8 DDB3: 1;
		uint8 DDB4: 1;
		uint8 DDB5: 1;
		uint8 DDB6: 1;
		uint8 DDB7: 1;
	}bits;
}DDRB;

/*Port B Input Pins Address – PINB */
typedef union
{
	uint8 byte;
	struct
	{
		uint8 PINB0: 1;
		uint8 PINB1: 1;
		uint8 PINB2: 1;
		uint8 PINB3: 1;
		uint8 PINB4: 1;
		uint8 PINB5: 1;
		uint8 PINB6: 1;
		uint8 PINB7: 1;
	}bits;
}PINB;


/*Port C Data Register – PORTC*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 PORTC0: 1;
		uint8 PORTC1: 1;
		uint8 PORTC2: 1;
		uint8 PORTC3: 1;
		uint8 PORTC4: 1;
		uint8 PORTC5: 1;
		uint8 PORTC6: 1;
		uint8 PORTC7: 1;
	}bits;
}PORTC;


/*Port C Data Direction Register – DDRC*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 DDC0: 1;
		uint8 DDC1: 1;
		uint8 DDC2: 1;
		uint8 DDC3: 1;
		uint8 DDC4: 1;
		uint8 DDC5: 1;
		uint8 DDC6: 1;
		uint8 DDC7: 1;
	}bits;
}DDRC;

/*Port C Input Pins Address – PINC */
typedef union
{
	uint8 byte;
	struct
	{
		uint8 PINC0: 1;
		uint8 PINC1: 1;
		uint8 PINC2: 1;
		uint8 PINC3: 1;
		uint8 PINC4: 1;
		uint8 PINC5: 1;
		uint8 PINC6: 1;
		uint8 PINC7: 1;
	}bits;
}PINC;

/*Port D Data Register – PORTD*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 PORTD0: 1;
		uint8 PORTD1: 1;
		uint8 PORTD2: 1;
		uint8 PORTD3: 1;
		uint8 PORTD4: 1;
		uint8 PORTD5: 1;
		uint8 PORTD6: 1;
		uint8 PORTD7: 1;
	}bits;
}PORTD;


/*Port D Data Direction Register – DDRD*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 DDD0: 1;
		uint8 DDD1: 1;
		uint8 DDD2: 1;
		uint8 DDD3: 1;
		uint8 DDD4: 1;
		uint8 DDD5: 1;
		uint8 DDD6: 1;
		uint8 DDD7: 1;
	}bits;
}DDRD;

/*Port D Input Pins Address – PIND */
typedef union
{
	uint8 byte;
	struct
	{
		uint8 PIND0: 1;
		uint8 PIND1: 1;
		uint8 PIND2: 1;
		uint8 PIND3: 1;
		uint8 PIND4: 1;
		uint8 PIND5: 1;
		uint8 PIND6: 1;
		uint8 PIND7: 1;
	}bits;
}PIND;

/*SPI Data Register – SPDR*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 SPDR0: 1;
		uint8 SPDR1: 1;
		uint8 SPDR2: 1;
		uint8 SPDR3: 1;
		uint8 SPDR4: 1;
		uint8 SPDR5: 1;
		uint8 SPDR6: 1;
		uint8 SPDR7: 1;
	}bits;
}SPDR;

/*SPI Status Register – SPSR*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 SPI2X: 1;
		uint8     :  5;
		uint8 WCOL:  1;
		uint8 SPIF:  1;
	}bits;
}SPSR;

/*SPI Control Register – SPCR*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 SPR0: 1;
		uint8 SPR1: 1;
		uint8 CPHA: 1;
		uint8 CPOL: 1;
		uint8 MSTR: 1;
		uint8 DORD: 1;
		uint8 SPE:  1;
		uint8 SPIE: 1;
	}bits;
}SPCR;

/*USART I/O Data Register – UDR*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 UDR0: 1;
		uint8 UDR1: 1;
		uint8 UDR2: 1;
		uint8 UDR3: 1;
		uint8 UDR4: 1;
		uint8 UDR5: 1;
		uint8 UDR6: 1;
		uint8 UDR7: 1;
	}bits;
}UDR;

/*USART Control and Status Register A – UCSRA*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 MPCM: 1;
		uint8 U2X:  1;
		uint8 PE:   1;
		uint8 DOR:  1;
		uint8 FE:   1;
		uint8 UDRE: 1;
		uint8 TXC:  1;
		uint8 RXC:  1;
	}bits;
}UCSRA;


/*USART Control and Status Register B – UCSRB*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 TXB8:  1;
		uint8 RXB8:  1;
		uint8 UCSZ2: 1;
		uint8 TXEN:  1;
		uint8 RXEN:  1;
		uint8 UDRIE: 1;
		uint8 TXCIE: 1;
		uint8 RXCIE: 1;
	}bits;
}UCSRB;

/*USART Baud Rate Registers – UBRRL*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 UBRR0: 1;
		uint8 UBRR1: 1;
		uint8 UBRR2: 1;
		uint8 UBRR3: 1;
		uint8 UBRR4: 1;
		uint8 UBRR5: 1;
		uint8 UBRR6: 1;
		uint8 UBRR7: 1;
	}bits;
}UBRRL;


/*Analog Comparator Control and Status Register – ACSR*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 ACIS0: 1;
		uint8 ACIS1: 1;
		uint8 ACIC:  1;
		uint8 ACIE:  1;
		uint8 ACI:   1;
		uint8 ACO:   1;
		uint8 ACBG:  1;
		uint8 ACD:   1;
	}bits;
}ACSR;


/*ADC Multiplexer Selection Register – ADMUX*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 MUX0:  1;
		uint8 MUX1:  1;
		uint8 MUX2:  1;
		uint8 MUX3:  1;
		uint8 MUX4:  1;
		uint8 ADLAR: 1;
		uint8 REFS0: 1;
		uint8 REFS1: 1;
	}bits;
}ADMUX;


/*ADC Control and Status Register A – ADCSRA*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 ADPS0: 1;
		uint8 ADPS1: 1;
		uint8 ADPS2: 1;
		uint8 ADIE:  1;
		uint8 ADIF:  1;
		uint8 ADATE: 1;
		uint8 ADSC:  1;
		uint8 ADEN:  1;
	}bits;
}ADCSRA;


/*The ADC Data Register – ADCL and ADCH*/
typedef union
{
	uint16 byte2;
	struct
	{
		uint16 ADC0:  1;
		uint16 ADC1:  1;
		uint16 ADC2:  1;
		uint16 ADC3:  1;
		uint16 ADC4:  1;
		uint16 ADC5:  1;
		uint16 ADC6:  1;
		uint16 ADC7:  1;
		uint16 ADC8:  1;
		uint16 ADC9:  1;
		uint16 ADC10: 1;
		uint16 ADC11: 1;
		uint16 ADC12: 1;
		uint16 ADC13: 1;
		uint16 ADC14: 1;
		uint16 ADC15: 1;
	}bits;
}ADC;

/*TWI Data Register – TWDR*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 TWD0:  1;
		uint8 TWD1:  1;
		uint8 TWD2:  1;
		uint8 TWD3:  1;
		uint8 TWD4:  1;
		uint8 TWD5:  1;
		uint8 TWD6:  1;
		uint8 TWD7:  1;
	}bits;
}TWDR;

/*TWI (Slave) Address Register – TWAR*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 TWGCE: 1;
		uint8 TWA0:  1;
		uint8 TWA1:  1;
		uint8 TWA2:  1;
		uint8 TWA3:  1;
		uint8 TWA4:  1;
		uint8 TWA5:  1;
		uint8 TWA6:  1;
	}bits;
}TWAR;

/*TWI Status Register – TWSR*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 TWPS0: 1;
		uint8 TWPS1: 1;
		uint8      : 1;
		uint8 TWS3:  1;
		uint8 TWS4:  1;
		uint8 TWS5:  1;
		uint8 TWS6:  1;
		uint8 TWS7:  1;
	}bits;
}TWSR;

/*TWI Bit Rate Register – TWBR*/
typedef union
{
	uint8 byte;
	struct
	{
		uint8 TWBR0: 1;
		uint8 TWBR1: 1;
		uint8 TWBR2: 1;
		uint8 TWBR3: 1;
		uint8 TWBR4: 1;
		uint8 TWBR5: 1;
		uint8 TWBR6: 1;
		uint8 TWBR7: 1;
	}bits;
}TWBR;




/*Register Addresses*/
#define SREG    (*(volatile SREG*)0x5F)
#define SP      (*(volatile SP*)0x5D)
#define OCR0    (*(volatile OCR0*)0x5C)
#define GICR    (*(volatile GICR*)0x5B)
#define GIFR    (*(volatile GIFR*)0x5A)
#define TIMSK   (*(volatile TIMSK*)0x59)
#define TIFR    (*(volatile TIFR*)0x58)
#define SPMCR   (*(volatile SPMCR*)0x57)
#define TWCR    (*(volatile TWCR*)0x56)
#define MCUCR   (*(volatile MCUCR*)0x55)
#define MCUCSR  (*(volatile MCUCSR*)0x54)
#define TCCR0   (*(volatile TCCR0*)0x53)
#define TCNT0   (*(volatile TCNT0*)0x52)
#define OSCCAL  (*(volatile OSCCAL*)0x51)
#define OCDR    (*(volatile OCDR*)0x51)
#define SFIOR   (*(volatile SFIOR*)0x50)
#define TCCR1A  (*(volatile TCCR1A*)0x4F)
#define TCCR1B  (*(volatile TCCR1B*)0x4E)
#define TCNT1   (*(volatile TCNT1*)0x4C)
#define OCR1A   (*(volatile OCR1A*)0x4A)
#define OCR1B   (*(volatile OCR1B*)0x48)
#define ICR1    (*(volatile ICR1*)0x46)
#define TCCR2   (*(volatile TCCR2*)0x45)
#define TCNT2   (*(volatile TCNT2*)0x44)
#define OCR2    (*(volatile OCR2*)0x43)
#define ASSR    (*(volatile ASSR*)0x42)
#define WDTCR   (*(volatile WDTCR*)0x41)
#define UBRRH   (*(volatile UBRRH*)0x40)
#define UCSRC   (*(volatile UCSRC*)0x40)
#define EEAR    (*(volatile EEAR*)0x3E)
#define EEDR    (*(volatile EEDR*)0x3D)
#define EECR    (*(volatile EECR*)0x3C)
#define PORTA   (*(volatile PORTA*)0x3B)
#define DDRA    (*(volatile DDRA*)0x3A)
#define PINA    (*(volatile PINA*)0x39)
#define PORTB   (*(volatile PORTB*)0x38)
#define DDRB    (*(volatile DDRB*)0x37)
#define PINB    (*(volatile PINB*)0x36)
#define PORTC   (*(volatile PORTC*)0x35)
#define DDRC    (*(volatile DDRC*)0x34)
#define PINC    (*(volatile PINC*)0x33)
#define PORTD   (*(volatile PORTD*)0x32)
#define DDRD    (*(volatile DDRD*)0x31)
#define PIND    (*(volatile PIND*)0x30)
#define SPDR    (*(volatile SPDR*)0x2F)
#define SPSR    (*(volatile SPSR*)0x2E)
#define SPCR    (*(volatile SPCR*)0x2D)
#define UDR     (*(volatile UDR*)0x2C)
#define UCSRA   (*(volatile UCSRA*)0x2B)
#define UCSRB   (*(volatile UCSRB*)0x2A)
#define UBRRL   (*(volatile UBRRL*)0x29)
#define ACSR    (*(volatile ACSR*)0x28)
#define ADMUX   (*(volatile ADMUX*)0x27)
#define ADCSRA  (*(volatile ADCSRA*)0x26)
#define ADC     (*(volatile ADC*)0x24)
#define TWDR    (*(volatile TWDR*)0x23)
#define TWAR    (*(volatile TWAR*)0x22)
#define TWSR    (*(volatile TWSR*)0x21)
#define TWBR    (*(volatile TWBR*)0x20)


#endif /* ATMEGA32_REGISTERS_H_ */
