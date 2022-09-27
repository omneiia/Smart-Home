/******************************************************************************/
/****************          Name    : Omneiia Atef        **********************/
/****************          Date    : 31/8/2022           **********************/
/****************          SWC     : LCD                 **********************/
/****************          Version : 1.0                 **********************/
/******************************************************************************/

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

#define LCD_u8_Line1          0
#define LCD_u8_Line2          1

void LCD_voidInit(void);
void LCD_voidCLR(void);
void LCD_voidSendCmd(u8 Copy_u8Cmd);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidWrtiteString(u8 *Copy_pu8Ptr);
void LCD_voidDisplayNumber(u32 Copy_u8Num);
void LCD_voidSendSpecialCharacter();
void LCD_voidGoToXY(u8 Copy_u8Row, u8 Copy_u8Column);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
