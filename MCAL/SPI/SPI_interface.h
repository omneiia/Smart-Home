/*
 * SPI_interface.h
 *
 *  Created on: Sep 11, 2022
 *      Author: DELL
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

void SPI_voidInit();
void SPI_u8TxRx(u8 Copy_u8Data , u8 *Copy_pu8RxData);

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
