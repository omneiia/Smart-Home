/*
 * EEPROM_program.c
 *
 *  Created on: Sep 13, 2022
 *      Author: DELL
 */
// LIB Layer
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"

// KPD header files
#include "EEPROM_config.h"
#include "EEPROM_private.h"
#include "EEPROM_interface.h"

// MCAL Layer
#include "../../MCAL/TWI/TWI_interface.h"

//HAL Layer
#include "../LCD/LCD_interface.h"

static u8 Private_u8ErrorStatusCheck(TWI_ErrorStatus Copy_enumErrorStatus){
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if(Copy_enumErrorStatus != TWI_OK){
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

void EEPROM_voidInit(void){
	TWI_voidMasterInit();
}
u8 EEPROM_u8WriteDataByte(u8 Copy_u8Data, u16 Copy_u16ByteAddress){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	TWI_ErrorStatus Local_enuTWIErrorStatus = TWI_OK;
	u8 Local_u8EEPROMAddress = (EEPROM_FIXED_ADDRESS) | (EEPROM_A2_VALUE<<2)|(u8)(Copy_u16ByteAddress>>8);

	// Start Condition
	Local_enuTWIErrorStatus = TWI_enuSendStartCondition();
	Local_u8ErrorState = Private_u8ErrorStatusCheck(Local_enuTWIErrorStatus);

	// Sending slave address + W
	Local_enuTWIErrorStatus = TWI_enuSendSlaveWithWrite(Local_u8EEPROMAddress);
	Local_u8ErrorState = Private_u8ErrorStatusCheck(Local_enuTWIErrorStatus);

	// Sending the rest of the Byte address
	Local_enuTWIErrorStatus = TWI_enuSendDataByte((u8)Copy_u16ByteAddress);
	Local_u8ErrorState = Private_u8ErrorStatusCheck(Local_enuTWIErrorStatus);

	// Send Data Byte
	Local_enuTWIErrorStatus = TWI_enuSendDataByte(Copy_u8Data);
	Local_u8ErrorState = Private_u8ErrorStatusCheck(Local_enuTWIErrorStatus);

	// Send Stop Condition
	TWI_u8SendStopCondition();

	_delay_ms(5);
	return Local_u8ErrorState;
}
u8 EEPROM_u8ReadDataByte(u8 *Copy_u8ReceivedData, u16 Copy_u16ByteAddress){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	TWI_ErrorStatus Local_enuTWIErrorStatus = TWI_OK;
	u8 Local_u8EEPROMAddress = (EEPROM_FIXED_ADDRESS) | (EEPROM_A2_VALUE<<2)|(u8)(Copy_u16ByteAddress>>8);

	if(Copy_u8ReceivedData != NULL){
		// Start Condition
	    Local_enuTWIErrorStatus = TWI_enuSendStartCondition();
	    Local_u8ErrorState = Private_u8ErrorStatusCheck(Local_enuTWIErrorStatus);

	    // Sending slave address + W
	    Local_enuTWIErrorStatus = TWI_enuSendSlaveWithWrite(Local_u8EEPROMAddress);
	    Local_u8ErrorState = Private_u8ErrorStatusCheck(Local_enuTWIErrorStatus);

	    // Sending the rest of the Byte address
	    Local_enuTWIErrorStatus = TWI_enuSendDataByte((u8)Copy_u16ByteAddress);
	    Local_u8ErrorState = Private_u8ErrorStatusCheck(Local_enuTWIErrorStatus);

	    // Restart Condition
	    Local_enuTWIErrorStatus = TWI_enuSendReStartCondition();
	    Local_u8ErrorState = Private_u8ErrorStatusCheck(Local_enuTWIErrorStatus);

	    // Sending slave address + R
	    Local_enuTWIErrorStatus = TWI_enuSendSlaveWithRead(Local_u8EEPROMAddress);
	    Local_u8ErrorState = Private_u8ErrorStatusCheck(Local_enuTWIErrorStatus);

	    // Receiving the data
	    Local_enuTWIErrorStatus = TWI_enuReceiveDataByte(Copy_u8ReceivedData); // & will give you the address of the pointer
	    Local_u8ErrorState = Private_u8ErrorStatusCheck(Local_enuTWIErrorStatus);

	    // Stop condition
	    TWI_u8SendStopCondition();

	    _delay_ms(5);
	}else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

