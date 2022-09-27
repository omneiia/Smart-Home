/***********************************************************************************/
/*************   			  Name : Mohamed Ahmed  	    ************************/  
/*************   			  Date : 	12/09/2022	  	    ************************/  
/*************   		 	   SWC :	 TWI		 	    ************************/     
/*************   		   Version :     1.0  			    ************************/    
/***********************************************************************************/  

#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H

typedef enum{
	TWI_OK = 1,
	TWI_StartCondError ,
	TWI_RestartCondError,
	TWI_SlaveWithWriteError,
	TWI_SlaveWithReadError,
	TWI_TransmittedDataError,
	TWI_ReceivedDataError,
	TWI_NullPointerError,
}TWI_ErrorStatus;



void TWI_voidMasterInit(void);

u8   TWI_u8SlaveInit(u8 Copy_u8SlaveAddress);

TWI_ErrorStatus   TWI_enuSendStartCondition(void);

TWI_ErrorStatus   TWI_enuSendReStartCondition(void);

TWI_ErrorStatus   TWI_enuSendSlaveWithWrite(u8 Copy_u8SlaveAddress);

TWI_ErrorStatus   TWI_enuSendSlaveWithRead(u8 Copy_u8SlaveAddress);

TWI_ErrorStatus   TWI_enuSendDataByte(u8 Copy_u8SendData);

TWI_ErrorStatus   TWI_enuReceiveDataByte(u8 *Copy_pu8ReceivedData);

void   TWI_u8SendStopCondition(void);


#endif
