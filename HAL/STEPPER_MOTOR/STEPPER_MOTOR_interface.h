/*
 * STEPPER_MOTOR_interface.h
 *
 *  Created on: Sep 20, 2022
 *      Author: DELL
 */

#ifndef HAL_STEPPER_MOTOR_STEPPER_MOTOR_INTERFACE_H_
#define HAL_STEPPER_MOTOR_STEPPER_MOTOR_INTERFACE_H_

// Stepper error status
typedef enum{
	STP_OK = 1,
	STP_NOK ,
}STP_ErrorStatus;

// Macros for motor rotation direction
#define STP_CLOCKWISE                          0
#define STP_ANTICLOCKWISE                      1

STP_ErrorStatus STP_enuRotate(u16 angle, u8 Copy_u8Direction);
void STP_voidStop(void);

#endif /* HAL_STEPPER_MOTOR_STEPPER_MOTOR_INTERFACE_H_ */
