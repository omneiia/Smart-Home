/*
 * EEPROM_interface.h
 *
 *  Created on: Sep 13, 2022
 *      Author: DELL
 */

#ifndef HAL_EXT_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EXT_EEPROM_EEPROM_INTERFACE_H_

void EEPROM_voidInit(void);
u8 EEPROM_u8WriteDataByte(u8 Copy_u8Data, u16 Copy_u16ByteAddress);
u8 EEPROM_u8ReadDataByte(u8 *Copy_u8ReceivedData, u16 Copy_u16ByteAddress);

#endif /* HAL_EXT_EEPROM_EEPROM_INTERFACE_H_ */
