/*
 * EXTI_program.c
 *
 *  Created on: Sep 14, 2022
 *      Author: DELL
 */

#include <avr/io.h>
#define F_CPU 8000000UL
#include "util/delay.h"

//            LIB Layer
#include "../../LIB/BIT_MATH/BIT_MATH.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"

// Interrupt header files
#include"EXTI_private.h"
#include"EXTI_interface.h"
#include"EXTI_config.h"

EXTI_ErrorStatus EXTI_enuEnable(u8 Copy_EXTIIndex, u8 Copy_EXTIEdge){
	u8 Local_enuErrorState = EXTI_OK;
	switch(Copy_EXTIIndex){
	case EXTI_u8_INT0:
		switch(Copy_EXTIEdge){
		  case EXTI_u8_FALLING_EGDE:
			  CLR_BIT(EXTI_u8_MCUCR_REG,0); //10
			  SET_BIT(EXTI_u8_MCUCR_REG,1);
		  break;
		  case EXTI_u8_RISING_EGDE:
			  SET_BIT(EXTI_u8_MCUCR_REG,0); //11
			  SET_BIT(EXTI_u8_MCUCR_REG,1);
		  break;
		  case EXTI_u8_ANY_LOGICAL_CHANGE:
			  SET_BIT(EXTI_u8_MCUCR_REG,0); //01
			  CLR_BIT(EXTI_u8_MCUCR_REG,1);
		  break;
		  case EXTI_u8_LOW_LEVEL:
			  CLR_BIT(EXTI_u8_MCUCR_REG,0);//00
			  CLR_BIT(EXTI_u8_MCUCR_REG,1);
		  break;
		default:
			Local_enuErrorState = EXTI_INT0_NOK;
		break;
	}
		//Enable PIE for INT0
		SET_BIT(EXTI_u8_GICR_REG,6);
		break;
	case EXTI_u8_INT1:
		switch(Copy_EXTIEdge){
			case EXTI_u8_FALLING_EGDE:
				 CLR_BIT(EXTI_u8_MCUCR_REG,2); //10
				 SET_BIT(EXTI_u8_MCUCR_REG,3);
			break;
			case EXTI_u8_RISING_EGDE:
				 SET_BIT(EXTI_u8_MCUCR_REG,2); //11
				 SET_BIT(EXTI_u8_MCUCR_REG,3);
			break;
			case EXTI_u8_ANY_LOGICAL_CHANGE:
				 SET_BIT(EXTI_u8_MCUCR_REG,2); //01
				 CLR_BIT(EXTI_u8_MCUCR_REG,3);
			break;
			case EXTI_u8_LOW_LEVEL:
				 CLR_BIT(EXTI_u8_MCUCR_REG,2);//00
				 CLR_BIT(EXTI_u8_MCUCR_REG,3);
			break;
			default:
				Local_enuErrorState = EXTI_INT1_NOK;
			break;
	}
	//Enable PIE for INT1
	SET_BIT(EXTI_u8_GICR_REG,7);
	break;
	case EXTI_u8_INT2:
		switch(Copy_EXTIEdge){
			case EXTI_u8_FALLING_EGDE:
				CLR_BIT(EXTI_u8_MCUCR_REG,6);
			break;
			case EXTI_u8_RISING_EGDE:
				SET_BIT(EXTI_u8_MCUCR_REG,6);
			break;
			default:
				Local_enuErrorState = EXTI_INT2_NOK;
			break;
	 }
	//Enable PIE for INT2
	SET_BIT(EXTI_u8_GICR_REG,5);
	break;
	default:
		Local_enuErrorState = EXTI_INT_INDEX_NOK; // invalid index
	break;
	}
	return Local_enuErrorState;
}

EXTI_ErrorStatus EXTI_enuDisable(u8 Copy_EXTIIndex){
	u8 Local_enuErrorState = EXTI_OK;
	switch(Copy_EXTIIndex){
	case EXTI_u8_INT0:
		CLR_BIT(EXTI_u8_GICR_REG,6);
	break;
	case EXTI_u8_INT1:
		CLR_BIT(EXTI_u8_GICR_REG,7);
	break;
	case EXTI_u8_INT2:
		CLR_BIT(EXTI_u8_GICR_REG,5);
	break;
	default:
		Local_enuErrorState = EXTI_DISABLE_INT_NOK;
	break;
	}
	return Local_enuErrorState;
}
void (*EXTI_PerformINT)(void) = NULL;

void EXTI_CallBack(void(* Copy_pf)(void)){
	EXTI_PerformINT =  Copy_pf;
}

void __vector_1(void)          __attribute__((signal));
void __vector_1(void){
	EXTI_PerformINT();
}

