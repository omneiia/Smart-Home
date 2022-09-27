/*
 * KPD_interface.h
 *
 *  Created on: Sep 13, 2022
 *      Author: DELL
 */

#ifndef HAL_KPD_KPD_INTERFACE_H_
#define HAL_KPD_KPD_INTERFACE_H_

typedef enum{
	KPD_OK = 1,
	KPD_GetKeyReturnedError,
}KPD_ErrorStatus;

KPD_ErrorStatus KPD_enuGetKey(u8 *Copy_pu8ReturnedKey);
#define KPD_NOT_PRESSED             0xFF

#endif /* HAL_KPD_KPD_INTERFACE_H_ */
