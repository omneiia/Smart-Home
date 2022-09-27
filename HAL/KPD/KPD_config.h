/*
 * KPD_config.h
 *
 *  Created on: Sep 13, 2022
 *      Author: DELL
 */

#ifndef HAL_KPD_KPD_CONFIG_H_
#define HAL_KPD_KPD_CONFIG_H_

#define KPD_u8_PORT1					DIO_u8_PORTA
#define KPD_u8_PORT2					DIO_u8_PORTD

#define KPD_u8_R1					DIO_u8_Pin4
#define KPD_u8_R2					DIO_u8_Pin5
#define KPD_u8_R3					DIO_u8_Pin6
#define KPD_u8_R4					DIO_u8_Pin7

#define KPD_u8_C1					DIO_u8_Pin0
#define KPD_u8_C2					DIO_u8_Pin1
#define KPD_u8_C3					DIO_u8_Pin2
#define KPD_u8_C4					DIO_u8_Pin3


// Multi-dimensional array for the keys
#define KPD_Au8_KEY_VALUE          {					   \
		                               {'7','8','9','/'} , \
		                               {'4','5','6','*'} , \
		                               {'1','2','3','-'} , \
		                               {'^','0','=','+'} , \
};

#endif /* HAL_KPD_KPD_CONFIG_H_ */
