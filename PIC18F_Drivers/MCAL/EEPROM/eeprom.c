#include"eeprom.h"

Std_ReturnType Data_EEPROM_WriteByte(uint16_t bAdd,uint8_t bData){
    Std_ReturnType ret=E_OK;
    //read the interrupt status
    Std_ReturnType Global_Interrupt_Status=READ_BIT(INTCON,7);
    //update register address
    EEADRH=(uint8_t)((bAdd>>8)&0x03);
    EEADR=(uint8_t)(bAdd & 0xFF);
    //update the data register
    EEDATA=bData;
    //select Access data EPPROM memory  
    CLEAR_BIT(EECON1,7);
    CLEAR_BIT(EECON1,6 );
    //allows write cycle to flash program
    SET_BIT(EECON1,2); 
    // disable all interrupt
    CLEAR_BIT(INTCON,7);
    //write the required sequence  : x ->0xAA
    EECON2=0x55;
    EECON2=0xAA;
    //initiates a data EEPROM erase/write 
    SET_BIT(EECON1,1);
    //wait for write complete
    while(READ_BIT(EECON1,1));       
    //iInhibts write cycle to flash program/data EEPROM
    CLEAR_BIT(EECON1,2);
    //Restore The interrupt status
    if(Global_Interrupt_Status==1)SET_BIT(INTCON,7);
    return ret;
}
Std_ReturnType Data_EEPROM_Read_Byte(uint16_t bAdd,uint8_t *bData){
    Std_ReturnType ret=E_OK;
    if(NULL==bData) ret=E_NOT_OK;
    else{
    //update register address
    EEADRH=(uint8_t)((bAdd>>8)&0x03);
    EEADR=(uint8_t)(bAdd & 0xFF);
    //select Access data EPPROM memory  
    CLEAR_BIT(EECON1,7);
    CLEAR_BIT(EECON1,6);
    //Initiates a data EEPROM read cycle
    SET_BIT(EECON1,1);
    NOP();
    NOP();
    //Return data
    *bData=EEDATA;  
 
    }
    
    return ret;
}
