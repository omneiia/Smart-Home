/*
 * EEPROM_private.h
 *
 *  Created on: Sep 13, 2022
 *      Author: DELL
 */
#include "../../MCAL/TWI/TWI_interface.h"

#ifndef HAL_EXT_EEPROM_EEPROM_PRIVATE_H_
#define HAL_EXT_EEPROM_EEPROM_PRIVATE_H_

#define EEPROM_FIXED_ADDRESS                  0x50

static u8 Private_u8ErrorStatusCheck(TWI_ErrorStatus Copy_enumErrorStatus);

#endif /* HAL_EXT_EEPROM_EEPROM_PRIVATE_H_ */




