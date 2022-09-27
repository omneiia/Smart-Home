/***********************************************************************************/
/*************   			  Name : Mohamed Ahmed  	    ************************/  
/*************   			  Date : 	31/08/2022	  	    ************************/  
/*************   		 	   SWC :	 ADC		 	    ************************/     
/*************   		   Version :     1.0  			    ************************/    
/***********************************************************************************/  

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/* Macros for HW REG */
#define ADC_u8_ADMUX_REG            *((volatile u8*)0x27)
#define ADC_u8_ADCSRA_REG           *((volatile u8*)0x26)
#define ADC_u8_ADCH_REG             *((volatile u8*)0x25)
#define ADC_u8_ADCL_REG             *((volatile u8*)0x24)

#define ADC_u16_ADC_REG              *((volatile u16*)0x24)

#define ADC_u8_SFIOR_REG             *((volatile u8*)0x50)





#endif