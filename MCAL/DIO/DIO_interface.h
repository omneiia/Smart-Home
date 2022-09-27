/******************************************************************************/
/****************          Name    : Omneiia Atef        **********************/
/****************          Date    : 29/8/2022           **********************/
/****************          SWC     : DIO                 **********************/
/****************          Version : 1.0                 **********************/
/******************************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

// Macros for PORTS Id
#define DIO_u8_PORTA       0
#define DIO_u8_PORTB       1
#define DIO_u8_PORTC       2
#define DIO_u8_PORTD       3
 
 //Macros for PINS Id
#define DIO_u8_Pin0       0
#define DIO_u8_Pin1       1
#define DIO_u8_Pin2       2
#define DIO_u8_Pin3       3
#define DIO_u8_Pin4       4
#define DIO_u8_Pin5       5
#define DIO_u8_Pin6       6
#define DIO_u8_Pin7       7

// Macros for Pin Directions
#define DIO_u8_INPUT        0
#define DIO_u8_OUTPUT       1

// Macros for Pin Value
#define DIO_u8_LOW        0
#define DIO_u8_HIGH       1

// Prototypes of DIO Drivers 

void DIO_Init(void);

u8 DIO_u8SetPinDirection    (u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinDirection);
u8 DIO_u8SetPinValue        (u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinValue);
u8 DIO_u8GetPinValue        (u8 Copy_u8PortId , u8 Copy_u8PinId , u8 *Copy_pu8ReturnedPinValue);

u8 DIO_u8etPortDirection   (u8 Copy_u8PortId , u8 Copy_u8PortDirection);
u8 DIO_u8SetPortValue       (u8 Copy_u8PortId , u8 Copy_u8PortValue);
u8 DIO_u8GetPortValue       (u8 Copy_u8PortId , u8 *Copy_pu8ReturnedPortValue);
#endif
