/*
 * GINT_program.c
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
#include"GINT_private.h"
#include"GINT_interface.h"


void GINT_voidGINTEnable(void){
	SET_BIT(GINT_u8_SREG_REG,7);
}
void GINT_voidGINTDisable(void){
	CLR_BIT(GINT_u8_SREG_REG,7);
}
