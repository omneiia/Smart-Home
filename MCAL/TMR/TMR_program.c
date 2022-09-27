/*
 * TMR_program.c
 *
 *  Created on: Sep 20, 2022
 *      Author: DELL
 */
#include <avr/io.h>
#define F_CPU 8000000UL
#include "util/delay.h"

//            LIB Layer
#include "../../LIB/BIT_MATH/BIT_MATH.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"

// Interrupt header files
#include"TMR_private.h"
#include"TMR_interface.h"
#include"TMR_config.h"

void TMR_voidTMR0Init(u8 Copy_TMR0_Mode){
	//u8 Local_u8_ErrorStatus = TMR0_OK;
	// Selecting mode = Normal Mode
	switch(Copy_TMR0_Mode){
	case TMR0_NORMAL_MODE:
		CLR_BIT(TWR0_u8_TCCR0_REG,6);
		CLR_BIT(TWR0_u8_TCCR0_REG,3);

		// Set preload value
		TWR0_u8_TCNT0_REG = 192;

		// Enable PIE of OVF
		SET_BIT(TWR0_u8_TIMSK_REG,0);

		// Prescaler = 8
		CLR_BIT(TWR0_u8_TCCR0_REG,0);
		SET_BIT(TWR0_u8_TCCR0_REG,1);
		CLR_BIT(TWR0_u8_TCCR0_REG,2);

	break;
	case TMR0_PMW_PHASE_CORRECT_MODE:
		SET_BIT(TWR0_u8_TCCR0_REG,6);
		CLR_BIT(TWR0_u8_TCCR0_REG,3);

		// Set 0C0 when Downcounting
		SET_BIT(TWR0_u8_TCCR0_REG,5);
		CLR_BIT(TWR0_u8_TCCR0_REG,4);

	break;
	case TMR0_CTC_MODE:
		CLR_BIT(TWR0_u8_TCCR0_REG,6);
		SET_BIT(TWR0_u8_TCCR0_REG,3);

		// Enable PIE of Compare match
		SET_BIT(TWR0_u8_TIMSK_REG,1);

	break;
	case TMR0_FAST_PMW_MODE:
		SET_BIT(TWR0_u8_TCCR0_REG,6);
		SET_BIT(TWR0_u8_TCCR0_REG,3);

		// Non-inverting
		SET_BIT(TWR0_u8_TCCR0_REG,5);
		CLR_BIT(TWR0_u8_TCCR0_REG,4);

		// Prescaler = 8
		CLR_BIT(TWR0_u8_TCCR0_REG,0);
		SET_BIT(TWR0_u8_TCCR0_REG,1);
		CLR_BIT(TWR0_u8_TCCR0_REG,2);

	break;
	}
}

void TMR_voidTMR1Init(){
	// Selecting Mode
	CLR_BIT(TWR1_u8_TCCR1A_REG,0);
	SET_BIT(TWR1_u8_TCCR1A_REG,1);
	SET_BIT(TWR1_u8_TCCR1B_REG,3);
	SET_BIT(TWR1_u8_TCCR1B_REG,4);

	// Channel A -> Non-inverting
	CLR_BIT(TWR1_u8_TCCR1A_REG,6);
	SET_BIT(TWR1_u8_TCCR1A_REG,7);

	// Setting the top value
	TWR1_u16_ICR1_REG = 19999;

	// Prescaler = 8
	CLR_BIT(TWR1_u8_TCCR1B_REG,0);
	SET_BIT(TWR1_u8_TCCR1B_REG,1);
	CLR_BIT(TWR1_u8_TCCR1B_REG,2);
}

void TMR_voidTMR0SetCompareMatch(u8 Copy_u8OCR0Value){
	TWR0_u8_OCR0_REG = Copy_u8OCR0Value;
}
void TMR_voidTMR1SetCompareMatchChannelA(u16 Copy_u8OCR1Value){
	TWR1_u16_OCR1A_REG = Copy_u8OCR1Value;
}
void (*TMR0_performOVF)(void) = NULL;
void (*TMR0_performCTC)(void) = NULL;

void TMR_u8TMR0_OVF_CallBack(void(* Copy_pf)(void)){
	TMR0_performOVF =  Copy_pf;
}

void TMR_u8TMR0_CTC_CallBack(void(* Copy_pf)(void)){
	TMR0_performCTC =  Copy_pf;
}

// TMR0 Overflow interrupt
void __vector_11(void)       __attribute__((signal));
void __vector_11(void) {
	static u16 Local_u16Counter = 0;
	Local_u16Counter ++;
	if(Local_u16Counter == 3907){
		TWR0_u8_TCNT0_REG = 192;
		Local_u16Counter = 0;
		// to perform the ISR we an interrupt TMR0 occurs
		TMR0_performOVF();
	}
}

// TMR0 Compare match interrupt
void __vector_10(void)       __attribute__((signal));
void __vector_10(void) {
	static u16 Local_u16Counter = 0;
	Local_u16Counter ++;
	if(Local_u16Counter == 10000){
		Local_u16Counter = 0;
		// to perform the ISR we an interrupt TMR0 occurs
		TMR0_performCTC();
	}
}

