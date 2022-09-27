/*
 * EXTI.interface.h
 *
 *  Created on: Sep 14, 2022
 *      Author: DELL
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

typedef enum{
	EXTI_OK = 1,
	EXTI_INT0_NOK ,
	EXTI_INT1_NOK,
	EXTI_INT2_NOK,
	EXTI_INT_INDEX_NOK,
	EXTI_DISABLE_INT_NOK,
}EXTI_ErrorStatus;

// Macros for external interrupt indices
#define EXTI_u8_INT0     0
#define EXTI_u8_INT1     1
#define EXTI_u8_INT2     2

//Macros for choosing whether it's rising or falling edge
#define EXTI_u8_FALLING_EGDE                      0
#define EXTI_u8_RISING_EGDE                       1
#define EXTI_u8_ANY_LOGICAL_CHANGE                2
#define EXTI_u8_LOW_LEVEL                         3

EXTI_ErrorStatus EXTI_enuEnable(u8 Copy_EXTIIndex, u8 Copy_EXTIEdge);

EXTI_ErrorStatus EXTI_enuDisable(u8 Copy_EXTIIndex);

void EXTI_CallBack(void(* Copy_pf)(void));
#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
