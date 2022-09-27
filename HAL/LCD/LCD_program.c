/******************************************************************************/
/****************          Name    : Omneiia Atef        **********************/
/****************          Date    : 31/8/2022           **********************/
/****************          SWC     : LCD                 **********************/
/****************          Version : 1.0                 **********************/
/******************************************************************************/

// Inclusion of Libraries
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>

// To connect pins to LCD we included DIO interface

#include "../../MCAL/DIO/DIO_interface.h"

// including Header files (HAL)

#include "LCD_private.h"
#include "LCD_config.h"
#include "LCD_interface.h"

void LCD_voidInit(void){

	#if MODE == EIGHT_BITS

	_delay_ms(35);
	LCD_voidSendCmd(0b00111000);
	_delay_us(40);
	LCD_voidSendCmd(0b00001111);
	_delay_us(40);
	LCD_voidSendCmd(0b00000001);
	_delay_ms(2);
	LCD_voidSendCmd(0b00001110);
     //#elif MODE == FOUR_BITS


	#endif
}
void LCD_voidCLR(void){
//	DIO_u8SetPinValue(CONTROL_PORT,RS_PIN,DIO_u8_LOW); // setting Rs=0
//	DIO_u8SetPinValue(CONTROL_PORT,RW_PIN,DIO_u8_LOW); // setting Rw=0
	LCD_voidSendCmd(DISPLAY_CLR);
	_delay_ms(2);
}
void LCD_voidSendCmd(u8 Copy_u8Cmd){
    // To send command we should clear RS & RW
	DIO_u8SetPinValue(CONTROL_PORT,RS_PIN,DIO_u8_LOW); // setting Rs=0
	DIO_u8SetPinValue(CONTROL_PORT,RW_PIN,DIO_u8_LOW); // setting Rw=0

	DIO_u8SetPortValue(DATA_PORT,Copy_u8Cmd);
	DIO_u8SetPinValue(CONTROL_PORT,E_PIN,DIO_u8_HIGH);  // E=1 then wait delay of  then E=0
	_delay_us(1);
	DIO_u8SetPinValue(CONTROL_PORT,E_PIN,DIO_u8_LOW);
	_delay_us(1);
}
void LCD_voidSendData(u8 Copy_u8Data){
	// To send command we should clear RW & set Rs
	DIO_u8SetPinValue(CONTROL_PORT,RS_PIN,DIO_u8_HIGH); // setting Rs=1
	DIO_u8SetPinValue(CONTROL_PORT,RW_PIN,DIO_u8_LOW); // setting Rw=0

	DIO_u8SetPortValue(DATA_PORT,Copy_u8Data);
	DIO_u8SetPinValue(CONTROL_PORT,E_PIN,DIO_u8_HIGH);  // E=1 then wait delay of  then E=0
	_delay_us(1);
	DIO_u8SetPinValue(CONTROL_PORT,E_PIN,DIO_u8_LOW);
	_delay_us(1);
}
void LCD_voidWrtiteString(u8 *Copy_pu8Ptr){
	if(Copy_pu8Ptr != NULL){
		u8 ptr = 0;
		while(Copy_pu8Ptr[ptr] != '\0'){
			LCD_voidSendData(Copy_pu8Ptr[ptr]);
			ptr++;
		}
	}
}
void LCD_voidDisplayNumber(u32 Copy_u8Num){
//	u32 Arr1[10];
//
//	while((Copy_u8Num != 0) ){
//
//		for(int i = 0 ; i <= 9 ; i++){
//			Arr1[i] = Copy_u8Num % 10 ;
//			Copy_u8Num = Copy_u8Num / 10;
//			if((Arr1[i]==0) && (Arr1[i-1] !=0)){
//				for(int j = i-1 ; j >= 0 ; j--){
//					LCD_voidSendData(Arr1[j] + '0');
//				}
//			}
//		}
//	}
	u8 Arr[10];
	u8 Local_counter = 0;

	for(s8 i = 0 ; i < 10 ; i++ )
	{
		if((Copy_u8Num > 0) || (Local_counter < 1))
		{
			Arr[i] = (Copy_u8Num%10);
			Copy_u8Num = (Copy_u8Num/10);
			Local_counter ++;
		}
	}

	for(s8 i =Local_counter-1; i >= 0 ;i-- )
	{
		LCD_voidSendData(Arr[i] + 48);

	}
}
void LCD_voidSendSpecialCharacter(){
	// From AC to CGRAM
	LCD_voidSendCmd(0b01000000);
	// Shape to be created
	LCD_voidSendData(0b00100001);
	LCD_voidSendData(0b00100111);
	LCD_voidSendData(0b00101001);
	LCD_voidSendData(0b00100001);
	LCD_voidSendData(0b00000110);
	LCD_voidSendData(0b00100001);
	LCD_voidSendData(0b00100001);
	LCD_voidSendData(0b00100001);
	//From AC to DDRAM
	LCD_voidGoToXY(LCD_u8_Line1,0);
	LCD_voidSendData(0);
}
void LCD_voidGoToXY(u8 Copy_u8Row, u8 Copy_u8Column){
	if((Copy_u8Row <= LCD_u8_Line2)&&(Copy_u8Column < 39)){
		switch(Copy_u8Row){
		case LCD_u8_Line1:
			LCD_voidSendCmd(0x80+Copy_u8Column);
		break;
		case LCD_u8_Line2 :
			LCD_voidSendCmd(0xC0+Copy_u8Column);
		break;
		}
	}
}
