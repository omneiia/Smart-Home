/***********************************************************************************/
/*************   			  Name : Mohamed Ahmed  	    ************************/  
/*************   			  Date : 	12/09/2022	  	    ************************/  
/*************   		 	   SWC :	 TWI		 	    ************************/     
/*************   		   Version :     1.0  			    ************************/    
/***********************************************************************************/  
#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"


#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"


void TWI_voidMasterInit(void)
{
	/* set prescaler Value */
	CLR_BIT(TWI_u8_TWSR_REG,0);
	CLR_BIT(TWI_u8_TWSR_REG,1);
	/* Set TWBR Value => 200KHZ */
	TWI_u8_TWBR_REG = 12;
	/* Enable ACK */
	SET_BIT(TWI_u8_TWCR_REG,6);
	/* Enable TWI */
	SET_BIT(TWI_u8_TWCR_REG,2);
}
u8   TWI_u8SlaveInit(u8 Copy_u8SlaveAddress)
{
	u8 Local_u8ErrorStatus = STD_TYPES_OK;
	/* Set Slave Address in TWAR Register */
	TWI_u8_TWAR_REG = Copy_u8SlaveAddress << 1;
	/* Enable ACK */
	SET_BIT(TWI_u8_TWCR_REG,6);
	/* Enable TWI */
	SET_BIT(TWI_u8_TWCR_REG,2);
	return Local_u8ErrorStatus;
}

TWI_ErrorStatus   TWI_enuSendStartCondition(void)
{
	u8 Local_enuErrorState = TWI_OK;
		/* Send Start Condition */
		SET_BIT(TWI_u8_TWCR_REG,5);
		/* Clear Flag */
		CLR_BIT(TWI_u8_TWCR_REG,7);
		/* wait for the Flag to be set */
		while((TWI_u8_TWCR_REG,7) != 1);
		/* Check ACK => REPEATED START CONDITION */
		if((TWI_u8_TWSR_REG & 0xF8) == 0x08){
			Local_enuErrorState = TWI_StartCondError;
		}
		return Local_enuErrorState;
}

TWI_ErrorStatus   TWI_enuSendReStartCondition(void)
{
	u8 Local_enuErrorState = TWI_OK;
	/* Send Start Condition */
	SET_BIT(TWI_u8_TWCR_REG,5);
	/* Clear Flag */
	CLR_BIT(TWI_u8_TWCR_REG,7);
	/* wait for the Flag to be set */
	while((TWI_u8_TWCR_REG,7) != 1);
	/* Check ACK => REPEATED START CONDITION */
	if((TWI_u8_TWSR_REG & 0xF8) == 0x10){
		Local_enuErrorState = TWI_RestartCondError;
	}
	return Local_enuErrorState;
}

TWI_ErrorStatus   TWI_enuSendSlaveWithWrite(u8 Copy_u8SlaveAddress)
{
	u8 Local_enuErrorState = TWI_OK;
	/* Set TWDR = SLA + W */
	TWI_u8_TWDR_REG = Copy_u8SlaveAddress << 1 ; // since the address is the MSB 7bits
	CLR_BIT(TWI_u8_TWDR_REG,0);
	/* Clear Start Condition */
	CLR_BIT(TWI_u8_TWCR_REG,5);
	/* Clear Flag */
	CLR_BIT(TWI_u8_TWCR_REG,7);
	/* wait for the Flag to be set */
	while((TWI_u8_TWCR_REG,7) != 1);
	/* Check ACK */
	if((TWI_u8_TWSR_REG & 0xF8) == 0x18){
		Local_enuErrorState = TWI_SlaveWithWriteError;
	}
	return Local_enuErrorState;
}

TWI_ErrorStatus   TWI_enuSendSlaveWithRead(u8 Copy_u8SlaveAddress)
{
	u8 Local_enuErrorState = TWI_OK;
	/* Set TWDR = SLA + R */
	TWI_u8_TWDR_REG = Copy_u8SlaveAddress << 1 ; // since the address is the MSB 7bits
	SET_BIT(TWI_u8_TWDR_REG,0);
	/* Clear Start Condition */
	CLR_BIT(TWI_u8_TWCR_REG,5);
	/* Clear Flag */
	CLR_BIT(TWI_u8_TWCR_REG,7);
	/* wait for the Flag to be set */
	while((TWI_u8_TWCR_REG,7) != 1);
	/* Check ACK */
	if((TWI_u8_TWSR_REG & 0xF8) == 0x40){
		Local_enuErrorState = TWI_SlaveWithReadError;
	}
	return Local_enuErrorState;
}

TWI_ErrorStatus  TWI_enuSendDataByte(u8 Copy_u8SendData)
{
	u8 Local_enuErrorState = TWI_OK;
	/* Set TWDR = DATA */
	TWI_u8_TWDR_REG = Copy_u8SendData;
	/* Clear Flag */
	CLR_BIT(TWI_u8_TWCR_REG,7);
	/* wait for the Flag to be set */
	while((TWI_u8_TWCR_REG,7) != 1);
	/* Check ACK */
	if((TWI_u8_TWSR_REG & 0xF8) == 0x28){
		Local_enuErrorState = TWI_TransmittedDataError;
	}
	return Local_enuErrorState;
}

TWI_ErrorStatus   TWI_enuReceiveDataByte(u8 *Copy_pu8ReceivedData)
{
	u8 Local_enuErrorState = TWI_OK;
	/* Check Pointer */
	if (Copy_pu8ReceivedData != NULL)
	{/* Clear Flag */
	CLR_BIT(TWI_u8_TWCR_REG,7);
	/* wait for the Flag to be set */
	while((TWI_u8_TWCR_REG,7) != 1);
	/* Check ACK */
	if((TWI_u8_TWSR_REG & 0xF8) == 0x50){
		Local_enuErrorState = TWI_ReceivedDataError;
	}else{
		/* Read Data */
		*Copy_pu8ReceivedData = TWI_u8_TWDR_REG;
	}
	}else{
		Local_enuErrorState = TWI_NullPointerError;
	}
	return Local_enuErrorState;
}

void   TWI_u8SendStopCondition(void)
{
	/* Send Stop Condition */
	SET_BIT(TWI_u8_TWCR_REG,4);
	/* Clear Flag */
	CLR_BIT(TWI_u8_TWCR_REG,7);
}
