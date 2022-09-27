/******************************************************************************/
/****************          Name    : Omneiia Atef        **********************/
/****************          Date    : 29/8/2022           **********************/
/****************          SWC     : DIO                 **********************/
/****************          Version : 1.0                 **********************/
/******************************************************************************/
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

// Macros for hardware registers

#define PORTA_u8_REG        *((volatile u8*)0x3B)
#define DDRA_u8_REG         *((volatile u8*)0x3A)
#define PINA_u8_REG         *((volatile u8*)0x39)

#define PORTB_u8_REG        *((volatile u8*)0x38)
#define DDRB_u8_REG         *((volatile u8*)0x37)
#define PINB_u8_REG         *((volatile u8*)0x36)

#define PORTC_u8_REG        *((volatile u8*)0x35)
#define DDRC_u8_REG         *((volatile u8*)0x34)
#define PINC_u8_REG         *((volatile u8*)0x33)

#define PORTD_u8_REG        *((volatile u8*)0x32)
#define DDRD_u8_REG         *((volatile u8*)0x31)
#define PIND_u8_REG         *((volatile u8*)0x30)

// Macros for the pin directions in config file
#define DIO_u8_INITIAL_INPUT        0
#define DIO_u8_INITIAL_OUTPUT       1

// Macros for input values
#define DIO_u8_INITIAL_INPUT_FLOATING         0
#define DIO_u8_INITIAL_INPUT_PULL_UP          1
#define DIO_u8_INITIAL_OUTPUT_HIGH            1
#define DIO_u8_INITIAL_OUTPUT_LOW             0

// Macro for concatenation in order to concatenate the pins in the format of 0bP7P6P5P4P3P2P1P0 in two steps
// since the macro functions have higher priority than macro objects
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0) 				CONC_DUP(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_DUP(b7,b6,b5,b4,b3,b2,b1,b0)			0b##b7##b6##b5##b4##b3##b2##b1##b0

#define EIGHT_BIT_MODE         1
#define FOUR_BIT_MODE          2

#define RS_DATA                 1
#define RS_COMMAND              0
#endif
