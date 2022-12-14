/*
 * STEPPER_MOTOR_program.c
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
#include "STEPPER_MOTOR_config.h"
#include "STEPPER_MOTOR_private.h"
#include "STEPPER_MOTOR_interface.h"

// MCAL Layer
#include "../../MCAL/DIO/DIO_interface.h"

STP_ErrorStatus STP_enuRotate(u16 angle, u8 Copy_u8Direction){
	u8 Local_enuErrorState = STP_OK;
	u32 numberOfSteps = (u32)((angle * 2050UL)/360);
	numberOfSteps = numberOfSteps/4;
	switch(Copy_u8Direction){
	case STP_CLOCKWISE:
		for(u16 i = 0 ; i < numberOfSteps ; i++){
		    //for a full rotation
		    // Step1
		    DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_BLUE_COIL,DIO_u8_LOW);
		    DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PINK_COIL,DIO_u8_HIGH);
		    DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_YELLOW_COIL,DIO_u8_HIGH);
		    DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_ORANGE_COIL,DIO_u8_HIGH);
		    _delay_ms(10);
		    // Step2
		    DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_BLUE_COIL,DIO_u8_HIGH);
		    DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PINK_COIL,DIO_u8_LOW);
		    DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_YELLOW_COIL,DIO_u8_HIGH);
		    DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_ORANGE_COIL,DIO_u8_HIGH);
		    _delay_ms(10);
		    // Step3
		    DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_BLUE_COIL,DIO_u8_HIGH);
		    DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PINK_COIL,DIO_u8_HIGH);
		    DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_YELLOW_COIL,DIO_u8_LOW);
		    DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_ORANGE_COIL,DIO_u8_HIGH);
		    _delay_ms(10);
		    // Step4
		    DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_BLUE_COIL,DIO_u8_HIGH);
		    DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PINK_COIL,DIO_u8_HIGH);
		    DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_YELLOW_COIL,DIO_u8_HIGH);
		    DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_ORANGE_COIL,DIO_u8_LOW);
		    _delay_ms(10);
		}
	break;
	case STP_ANTICLOCKWISE:
		for(u16 i = 0 ; i < numberOfSteps ; i++){
			//for a full rotation
			// Step1
			DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_BLUE_COIL,DIO_u8_HIGH);
			DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PINK_COIL,DIO_u8_HIGH);
			DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_YELLOW_COIL,DIO_u8_HIGH);
			DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_ORANGE_COIL,DIO_u8_LOW);
			_delay_ms(10);
			// Step2
			DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_BLUE_COIL,DIO_u8_HIGH);
			DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PINK_COIL,DIO_u8_HIGH);
			DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_YELLOW_COIL,DIO_u8_LOW);
			DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_ORANGE_COIL,DIO_u8_HIGH);
			_delay_ms(10);
			// Step3
			DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_BLUE_COIL,DIO_u8_HIGH);
			DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PINK_COIL,DIO_u8_LOW);
			DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_YELLOW_COIL,DIO_u8_HIGH);
			DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_ORANGE_COIL,DIO_u8_HIGH);
			_delay_ms(10);
			// Step4
			DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_BLUE_COIL,DIO_u8_LOW);
			DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PINK_COIL,DIO_u8_HIGH);
			DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_YELLOW_COIL,DIO_u8_HIGH);
			DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_ORANGE_COIL,DIO_u8_HIGH);
			_delay_ms(10);
		}
	break;
	default:
		Local_enuErrorState = STP_NOK;
	break;
	}
	return Local_enuErrorState;
}
void STP_voidStop(void){

	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_BLUE_COIL,DIO_u8_HIGH);
	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PINK_COIL,DIO_u8_HIGH);
	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_YELLOW_COIL,DIO_u8_HIGH);
	DIO_u8SetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_ORANGE_COIL,DIO_u8_HIGH);
}
