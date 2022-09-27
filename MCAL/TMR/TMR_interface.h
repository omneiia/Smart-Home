/*
 * TMR_interface.h
 *
 *  Created on: Sep 20, 2022
 *      Author: DELL
 */

#ifndef MCAL_TMR_TMR_INTERFACE_H_
#define MCAL_TMR_TMR_INTERFACE_H_

// TMR Error Status
typedef enum{
	TMR0_OK = 1,
	TMR0_NOK ,
}TMR0_ErrorStatus;

#define TMR0_NORMAL_MODE                          0
#define TMR0_PMW_PHASE_CORRECT_MODE               1
#define TMR0_CTC_MODE                             2
#define TMR0_FAST_PMW_MODE                        3

//TMR0
void TMR_voidTMR0Init(u8 Copy_TMR0_Mode);
void TMR_u8TMR0_OVF_CallBack(void(* Copy_pf)(void));
void TMR_u8TMR0_CTC_CallBack(void(* Copy_pf)(void));
void TMR_voidTMR0SetCompareMatch(u8 Copy_u8OCR0Value);

// TMR1
void TMR_voidTMR1Init();
void TMR_voidTMR1SetCompareMatchChannelA(u16 Copy_u8OCR1Value);

#endif /* MCAL_TMR_TMR_INTERFACE_H_ */
