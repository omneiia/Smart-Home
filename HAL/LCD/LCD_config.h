/******************************************************************************/
/****************          Name    : Omneiia Atef        **********************/
/****************          Date    : 31/8/2022           **********************/
/****************          SWC     : LCD                 **********************/
/****************          Version : 1.0                 **********************/
/******************************************************************************/

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

// for 8 bit Mode set DB4 by 1 for 4 bit Mode clear it

#define MODE                    EIGHT_BITS

// initialization of LCD
#define FUNCTION_SET			0b00111000
#define DISPLAY_ON_OFF			0b00001111
#define DISPLAY_CLR				0b00000001
#define ENTRY_MODE_SET			0b00001110

#define CONTROL_PORT            DIO_u8_PORTB
#define RS_PIN                  DIO_u8_Pin0
#define RW_PIN                  DIO_u8_Pin1
#define E_PIN                   DIO_u8_Pin2

// Macro for data port

#define DATA_PORT               DIO_u8_PORTC

#endif /* HAL_LCD_LCD_CONFIG_H_ */
