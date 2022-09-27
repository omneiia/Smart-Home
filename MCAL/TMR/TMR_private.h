/*
 * TMR_private.h
 *
 *  Created on: Sep 20, 2022
 *      Author: DELL
 */

#ifndef MCAL_TMR_TMR_PRIVATE_H_
#define MCAL_TMR_TMR_PRIVATE_H_

// TMR0 registers
#define TWR0_u8_TCCR0_REG              *((volatile u8*)0x53)
#define TWR0_u8_TCNT0_REG              *((volatile u8*)0x52)
#define TWR0_u8_OCR0_REG               *((volatile u8*)0x5C)
#define TWR0_u8_TIFR_REG               *((volatile u8*)0x58)

//TMR1 Registers
#define TWR1_u8_TCCR1A_REG             *((volatile u8*)0x4F)
#define TWR1_u8_TCCR1B_REG             *((volatile u8*)0x4E)
#define TWR1_u8_TCNT1H_REG             *((volatile u8*)0x4D)
#define TWR1_u8_TCNT1L_REG             *((volatile u8*)0x4C)
#define TWR1_u16_TCNT1_REG             *((volatile u16*)0x4C)

#define TWR1_u8_OCR1AH_REG             *((volatile u8*)0x4B)
#define TWR1_u8_OCR1AL_REG             *((volatile u8*)0x4A)

#define TWR1_u16_OCR1A_REG             *((volatile u16*)0x4A) // OCR value for Channel A // for ON Period

#define TWR1_u8_OCR1BH_REG             *((volatile u8*)0x49)
#define TWR1_u8_OCR1BL_REG             *((volatile u8*)0x48)

#define TWR1_u16_OCR1B_REG             *((volatile u16*)0x48) // OCR value for channel B // for ON Period

#define TWR1_u8_ICR1H_REG              *((volatile u8*)0x47)
#define TWR1_u8_ICR1L_REG              *((volatile u8*)0x46)

#define TWR1_u16_ICR1_REG              *((volatile u16*)0x46) // ICR top value for timer 1

// Interrupt mask register which is shared between the three timers
#define TWR0_u8_TIMSK_REG              *((volatile u8*)0x59)


#endif /* MCAL_TMR_TMR_PRIVATE_H_ */
