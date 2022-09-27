/*
 * SPI_program.c
 *
 *  Created on: Sep 11, 2022
 *      Author: DELL
 */

#include "../../LIB/BIT_MATH/BIT_MATH.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"

#include "SPI_private.h"
#include "SPI_interface.h"
#include "SPI_config.h"


void SPI_voidInit(){

#if SPI_MODE == SPI_MASTER_MODE

	// Data Order MSB
	CLR_BIT(SPI_u8_SPCR_REG,5);
	//Master
	SET_BIT(SPI_u8_SPCR_REG,4);
	//Falling then Rising
	SET_BIT(SPI_u8_SPCR_REG,3);
	//phase
	SET_BIT(SPI_u8_SPCR_REG,2);
	//Frequency fosc/64   10
	SET_BIT(SPI_u8_SPCR_REG,1);
	CLR_BIT(SPI_u8_SPCR_REG,0);
#elif SPI_MODE == SPI_SLAVE_MODE
	// Data Order MSB
	CLR_BIT(SPI_u8_SPCR_REG,5);
	//Slave
	CLR_BIT(SPI_u8_SPCR_REG,4);
	//Falling then Rising
	SET_BIT(SPI_u8_SPCR_REG,3);
	//phase
	SET_BIT(SPI_u8_SPCR_REG,2);
	#endif
	//Enable the peripheral
	SET_BIT(SPI_u8_SPCR_REG,6);

}
//void SPI_u8TxRx(u8 Copy_u8Data , u8 *Copy_pu8RxData){
//	if(Copy_pu8RxData != NULL){
//		SPI_u8_SPDR_REG = Copy_u8Data;
//		while(GET_BIT(SPI_u8_SPSR_REG,7)!= 1);
//		*Copy_pu8RxData =  SPI_u8_SPDR_REG;
//	}
//}
