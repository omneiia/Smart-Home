/*
 * EXTI_private.h
 *
 *  Created on: Sep 14, 2022
 *      Author: DELL
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

// Macros for hardware Registers

#define EXTI_u8_GICR_REG                      *((volatile u8*)0x5B)
#define EXTI_u8_GIFR_REG                      *((volatile u8*)0x5A)
#define EXTI_u8_MCUCR_REG                     *((volatile u8*)0x55)
#define EXTI_u8_MCUSCR_REG                    *((volatile u8*)0x54)


#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
