/*
 * UART_private.h
 *
 *  Created on: Sep 8, 2022
 *      Author: DELL
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_


#define UBRRH           *(volatile(u8*)0x40)
#define UCSRC           *(volatile(u8*)0x40)

#define UDR             *(volatile(u8*)0x2C)
#define UCSRA           *(volatile(u8*)0x2B)
#define UCSRB           *(volatile(u8*)0x2A)
#define UBRRL           *(volatile(u8*)0x29)


#endif /* MCAL_UART_UART_PRIVATE_H_ */
