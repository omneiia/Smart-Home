#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#include "LIB/BIT_MATH/BIT_MATH.h"
#include "LIB/STD_TYPES/STD_TYPES.h"

//           MCAL
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/GINT/GINT_interface.h"
#include "MCAL/ADC/ADC_interface.h"
#include "MCAL/TMR/TMR_interface.h"
#include "MCAL/SPI/SPI_interface.h"
#include "MCAL/TWI/TWI_interface.h"

#include "MCAL/ADC/ADC_private.h"

//           HAL
#include "HAL/LCD/LCD_interface.h"
#include "HAL/KPD/KPD_interface.h"
#include "HAL/HBridge/HBridge_interface.h"
#include "HAL/STEPPER_MOTOR/STEPPER_MOTOR_interface.h"
#include "HAL/Ext_EEPROM/EEPROM_interface.h"

// Function prototype
void APP_voidFlagLED(void);
void LCD_CLR()
			{
			  LCD_voidSendCmd (0x01);    /* clear display */
			  LCD_voidSendCmd (0x80);    /* cursor at home position */
			}

int main(void){
	u16 Local_u16DigitalValue , Local_u16AnalogValue,Local_u16DigitalValue2 , Local_u16AnalogValue2;
	DIO_Init();
	ADC_voidInit();
	LCD_voidInit();
//-------------------------------------------------Password-------------------------------------------------------
		//TMR_voidTMR1SetCompareMatchChannelA(1999);
		//  void APP_LOGIN(void)

		u8 Local_u8Data;
		LCD_voidCLR();//clear LCD
		u32 Num1 = 0 ,  value = 0;//make variable to store number on it
		u8 counter = 0 , flag = 0;//make counter to count every time we enter loop
		LCD_voidWrtiteString("Enter Passcode: ");//print enter password in LCD once you get home
		LCD_voidGoToXY(1,0);//print this statement in line 2 in LCD
		while(1){
			KPD_enuGetKey(&Local_u8Data);//Get key if pressed in Keypad
			if(Local_u8Data != KPD_NOT_PRESSED)//check if kpd is pressed or not
			{
				// counter ++ ;  //counter =1
				switch(Local_u8Data)//switch on value pressed in KPD
				{
				case '0'://if 0 is pressed
				{
					LCD_voidSendData('*');//display 0 in LCD
					value =0;//put 0 in value
					Num1=(Num1*10)+value;//store value in Num1 which is updated by added this value to Num1 and
					//multiply old value of Num1*10 to shift every old number pressed by KPD
					break;
				}
				case '1'://if 1 is pressed
				{
					LCD_voidSendData('*');//display 1 in LCD
					value =1;//put 1 in value
					Num1=(Num1*10)+value;//store value in Num1 which is updated by added this value to Num1 and
					//multiply old value of Num1*10 to shift every old number pressed by KPD
					break;
				}
				case '2'://if 2 is pressed
				{
					LCD_voidSendData('*');//display 2 in LCD
					//LCD_voidDisplayNumber(Local_Variable-48);
					value=2;//put 2 in value
					Num1=(Num1*10)+value;//store value in Num1 which is updated by added this value to Num1 and
					//multiply old value of Num1*10 to shift every old number pressed by KPD
					break;
				}
				case '3'://if 3 is pressed
				{
					LCD_voidSendData('*');//display 3 in LCD
					value=3;//put 3 in value
					Num1=(Num1*10)+value;//store value in Num1 which is updated by added this value to Num1 and
					//multiply old value of Num1*10 to shift every old number pressed by KPD
					break;
				}
				case '4'://if 4 is pressed
				{
					LCD_voidSendData('*');//display 4 in LCD
					value=4;//put 4 in value
					Num1=(Num1*10)+value;//store value in Num1 which is updated by added this value to Num1 and
					//multiply old value of Num1*10 to shift every old number pressed by KPD
					break;
				}
				case '5'://if 5 is pressed
				{
					LCD_voidSendData('*');//display 5 in LCD
					value=5;//put 5 in value
					Num1=(Num1*10)+value;//store value in Num1 which is updated by added this value to Num1 and
					//multiply old value of Num1*10 to shift every old number pressed by KPD
					break;
				}
				case '6'://if 6 is pressed
				{
					LCD_voidSendData('*');//display 6 in LCD
					value=6;//put 6 in value
					Num1=(Num1*10)+value;//store value in Num1 which is updated by added this value to Num1 and
					//multiply old value of Num1*10 to shift every old number pressed by KPD
					break;
				}
				case '7'://if 7 is pressed
				{
					LCD_voidSendData('*');//display 7 in LCD
					value=7;//put 7 in value
					Num1=(Num1*10)+value;;//store value in Num1 which is updated by added this value to Num1 and
					//multiply old value of Num1*10 to shift every old number pressed by KPD
					break;
				}
				case '8'://display 8 in LCD
				{

					LCD_voidSendData('*');//put 8 in value
					value=8;//put 8 in value
					Num1=(Num1*10)+value;;//store value in Num1 which is updated by added this value to Num1 and
					//multiply old value of Num1*10 to shift every old number pressed by KPD

					break;
				}
				case '9'://display 9 in LCD
				{

					LCD_voidSendData('*');//put 9 in value
					value=9;
					Num1=(Num1*10)+value;//store value in Num1 which is updated by added this value to Num1 and
					//multiply old value of Num1*10 to shift every old number pressed by KPD

					break;
				}
				case '^'://when finishing entering password press enter
					LCD_voidCLR();//clear LCD again
					if(Num1 == 345)//check if entered number=saved password
					{
						LCD_voidGoToXY(0,0);//go to first place in LCD
						LCD_voidWrtiteString("Welcome");//if yes then print welcome in LCD
						_delay_ms(500);//make delay for printing welcome
						// Enable Global interrupt
						GINT_voidGINTEnable();
						// Initiate TMR1
						TMR_voidTMR1Init();
//------------------------------------------------Opens the door--------------------------------------------------
						for(u16 i = 999 ; i <=1499 ; i++)
							{
							  TMR_voidTMR1SetCompareMatchChannelA(i);
								_delay_ms(10);
							 }

						flag = 1;//make flag =1
					}
					else{ //if not true

						if(counter <= 1)//Enter password if false 2 times again and check om=n it
						{
							LCD_voidCLR();//clear LCD
							LCD_voidGoToXY(0,0);//go to first place in LCD
							LCD_voidWrtiteString("Reenter password");//print re_enter password again if it was false
							LCD_voidGoToXY(1,0);//print this text in line 2 in LCD
							Num1 = 0;//set number to 0 again
							counter ++ ;
						}
						else
						{
							LCD_voidCLR();//clear LCD
							LCD_voidGoToXY(0,0);//go to first place in LCD
							LCD_voidWrtiteString("Calling 911");//This means that number of tries has ended then call the police
							flag = 1;//set flag to one
						}
					}
					break;
				}
				if(flag == 1)//check on flag if =1
				{
					break;  //then exit the while loop
				}
			}
		}
//-------------------------------------Temperature sensor----------------------------------------------------------------

			LCD_voidCLR();//clear LCD
			LCD_voidInit();//Init LCD again after entery system

		  while(1)
		   {
		 	 LCD_voidCLR();
		     LCD_voidGoToXY(0,0);//go to first place in LCD
		     LCD_voidWrtiteString("Temperature ");//display word Temperature on LCD


		     ADC_u8GetDigitalValue(ADC_u8_CHANNEL_0,&Local_u16DigitalValue);//Get digital value from ADC
		        		Local_u16AnalogValue = (u16)((Local_u16DigitalValue * 5000UL) /1023) ;//Get analog value
		        		u8 temp=Local_u16AnalogValue/10;//Get temperature

		        		LCD_voidDisplayNumber(temp);//display value of temperature in LCD
		        		LCD_voidSendData('C');//Means Celsius

//------------------------------------------------Air conditioner------------------------------------------------
		        		// Enable GINT
			        		GINT_voidGINTEnable();
			        	// initiate TMR0
			        		TMR_voidTMR0Init(TMR0_FAST_PMW_MODE);
			        	// Setting the OCR0 value to be the value of the temperture*5 such that it's changed during run time
			        		TMR_voidTMR0SetCompareMatch(temp*5);

////---------------------------------------Fire alarm-----------------------------------------------------
		        	 if((temp)>=50)//check if temperature greater than 50 to check if there is a fire
		        	 {
		        		 //If temperature greater than 50 then open alarm which is open LED
		        		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_Pin1,DIO_u8_HIGH);
		        	 }
		        	 else
		        	 {
		        		 //IF not then close alarm which is close LED
		        		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_Pin1,DIO_u8_LOW);
		        	 }

///--------------------------------------Light sensor-------------------------------------------------------------------
 			     ADC_u8GetDigitalValue(ADC_u8_CHANNEL_2,&Local_u16DigitalValue2);//Get digital value from ADC
 			     Local_u16AnalogValue2 = (u16)((Local_u16DigitalValue2 * 5000UL) /1023) ;  //Get analog value

 			     //check if there is a light of high intensity then open led
 			                   if(Local_u16AnalogValue2>=2500)
 			     				{
 			     					DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_Pin3,DIO_u8_HIGH);
 			     				}
 			           //else close led
 			                   else
 			     				{
 			     						DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_Pin3,DIO_u8_LOW);
 			     				}
 			     				//LCD_voidGoToXY(1,0);

 			     				_delay_ms(500);

		        	 		}

return 0;
}


// Function to toggle led used previously when used pointer to function in timer0 and timer1
void APP_voidFlagLED(void){
	static u8 Local_u8_Flag = 0;
	if(Local_u8_Flag == 0){
		DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_Pin3,DIO_u8_LOW);
		Local_u8_Flag = 1;
	}else{
		DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_Pin3,DIO_u8_HIGH);
	    Local_u8_Flag = 0;
	}
}
