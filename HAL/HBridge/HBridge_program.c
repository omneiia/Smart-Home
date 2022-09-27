/*
 * HBridge_program.c
 *
 *  Created on: Sep 20, 2022
 *      Author: DELL
 */

// LIB Layer
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"

// Stepper Motor header files
#include "HBridge_config.h"
#include "HBridge_private.h"
#include "HBridge_interface.h"

// MCAL Layer
#include "../../MCAL/DIO/DIO_interface.h"

HBRD_ErrorStatus HBRD_enuRotate(u8 Copy_u8Direction){
	u8 Local_enuErrorStatus = HBRD_OK;
	switch(Copy_u8Direction){
	case HBRD_CLOCKWISE:
		DIO_u8SetPinValue(HBRD_PORT, HBRD_PINA, DIO_u8_LOW);
		DIO_u8SetPinValue(HBRD_PORT, HBRD_PINB, DIO_u8_HIGH);
	break;
	case HBRD_ANTICLOCKWISE:
		DIO_u8SetPinValue(HBRD_PORT, HBRD_PINA, DIO_u8_HIGH);
		DIO_u8SetPinValue(HBRD_PORT, HBRD_PINB, DIO_u8_LOW);
	break;
	default:
		Local_enuErrorStatus = HBRD_NOK;
	break;
	}
	return Local_enuErrorStatus;
}
void HBRD_voidStop(void){
	DIO_u8SetPinValue(HBRD_PORT, HBRD_PINA, DIO_u8_LOW);
	DIO_u8SetPinValue(HBRD_PORT, HBRD_PINB, DIO_u8_LOW);
}
