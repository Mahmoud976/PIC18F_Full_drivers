#include"interrupt_manager.h"


#if INT_ENA_PRIORITY ==0
void __interrupt() General_Interrupt(void){
if(READ_BIT(INTCON,BIT1))
        INT0_ISR();
}
#else 
    //pass
#endif