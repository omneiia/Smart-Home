/*
 * HBridge_interface.h
 *
 *  Created on: Sep 20, 2022
 *      Author: DELL
 */

#ifndef HAL_HBRIDGE_HBRIDGE_INTERFACE_H_
#define HAL_HBRIDGE_HBRIDGE_INTERFACE_H_

typedef enum{
	HBRD_OK = 1,
	HBRD_NOK ,
}HBRD_ErrorStatus;

// Macros for motor rotation direction
#define HBRD_CLOCKWISE                          0
#define HBRD_ANTICLOCKWISE                      1

HBRD_ErrorStatus HBRD_enuRotate(u8 Copy_u8Direction);
void HBRD_voidStop(void);

#endif /* HAL_HBRIDGE_HBRIDGE_INTERFACE_H_ */
