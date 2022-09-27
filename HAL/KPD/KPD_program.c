/*
 * KPD_program.c
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
#include "KPD_config.h"
#include "KPD_private.h"
#include "KPD_interface.h"

// MCAL Layer
#include "../../MCAL/DIO/DIO_interface.h"

u8 KPD_Au8Keys[4][4] = KPD_Au8_KEY_VALUE;

// Let rows as output and columns as input
u8 KPD_Au8RowPins[4]={KPD_u8_R1,KPD_u8_R2,KPD_u8_R3,KPD_u8_R4};
u8 KPD_Au8ColumnPins[4]={KPD_u8_C1,KPD_u8_C2,KPD_u8_C3,KPD_u8_C4};

KPD_ErrorStatus KPD_enuGetKey(u8 *Copy_pu8ReturnedKey){
	u8 Local_enuErrorState = KPD_OK;
	u8 Local_u8RowsCounter, Local_u8ColumnsCounter, Local_u8ReturnedKey, Local_u8Flag = 0;
	if(Copy_pu8ReturnedKey != NULL){

		*Copy_pu8ReturnedKey = KPD_NOT_PRESSED;

		for(Local_u8RowsCounter = 0; Local_u8RowsCounter <= 3 ; Local_u8RowsCounter++){
			DIO_u8SetPinValue(KPD_u8_PORT1,KPD_Au8RowPins[Local_u8RowsCounter],DIO_u8_LOW); //activate Rows
			for(Local_u8ColumnsCounter = 0; Local_u8ColumnsCounter <= 3 ; Local_u8ColumnsCounter++){
				DIO_u8GetPinValue(KPD_u8_PORT2,KPD_Au8ColumnPins[Local_u8ColumnsCounter],&Local_u8ReturnedKey); //reading columns
			if(Local_u8ReturnedKey == 0){
				// To avoid debouncing problem we added a delay
				_delay_ms(20);
				while(Local_u8ReturnedKey == 0){
					DIO_u8GetPinValue(KPD_u8_PORT2,KPD_Au8ColumnPins[Local_u8ColumnsCounter],&Local_u8ReturnedKey); //to keep checking the value of the pressed key
				}
				*Copy_pu8ReturnedKey = KPD_Au8Keys[Local_u8RowsCounter][Local_u8ColumnsCounter];
				Local_u8Flag = 1;
				// breaks the loop once the key is pressed
				break;
			}
		  }
			DIO_u8SetPinValue(KPD_u8_PORT1,KPD_Au8RowPins[Local_u8RowsCounter],DIO_u8_HIGH); // to avoid activating all rows not knowing which key in which row was pressed
			if (Local_u8Flag == 1){
				break;
			}
		}
	}else{
		Local_enuErrorState = KPD_GetKeyReturnedError;
	}
	return Local_enuErrorState;
}
