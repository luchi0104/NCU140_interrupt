#include "mygpio.h"

void SystemInit (void)
{
	
} 

void Init_LED()
{	
	// initialize GPIO pins RGB LED
	DrvGPIO_Open(E_GPA, 12, E_IO_OUTPUT); // GPA12 pin set to output mode
	DrvGPIO_Open(E_GPA, 13, E_IO_OUTPUT); // GPA13 pin set to output mode
	DrvGPIO_Open(E_GPA, 14, E_IO_OUTPUT); // GPA14 pin set to output mode

	// initialize GPIO pins LED
	DrvGPIO_Open(E_GPC, 12, E_IO_OUTPUT); // GPA12 pin set to output mode
	DrvGPIO_Open(E_GPC, 13, E_IO_OUTPUT); // GPA13 pin set to output mode
	DrvGPIO_Open(E_GPC, 14, E_IO_OUTPUT); // GPA14 pin set to output mode
	DrvGPIO_Open(E_GPC, 15, E_IO_OUTPUT); // GPA14 pin set to output mode
}    

void RGB_LED()
{
    // turn on pin 12 LED
    DrvGPIO_ClrBit(E_GPA,12);		
    DrvGPIO_SetBit(E_GPA,13);		
    DrvGPIO_SetBit(E_GPA,14);		
    DrvSYS_Delay(50000);
    // turn off all
    DrvGPIO_SetBit(E_GPA,12); // GPA12 = Blue,  0 : on, 1 : off
    DrvGPIO_SetBit(E_GPA,13); 
    DrvGPIO_SetBit(E_GPA,14); 

    // turn on pin 13 LED
    DrvGPIO_SetBit(E_GPA,12);		
    DrvGPIO_ClrBit(E_GPA,13);		
    DrvGPIO_SetBit(E_GPA,14);		
    DrvSYS_Delay(50000);
    // turn off all
    DrvGPIO_SetBit(E_GPA,12); // GPA12 = Blue,  0 : on, 1 : off
    DrvGPIO_SetBit(E_GPA,13); 
    DrvGPIO_SetBit(E_GPA,14); 

    // turn on pin 14 LED
    DrvGPIO_SetBit(E_GPA,12);		
    DrvGPIO_SetBit(E_GPA,13);		
    DrvGPIO_ClrBit(E_GPA,14);		
    DrvSYS_Delay(50000);
    // turn off all
    DrvGPIO_SetBit(E_GPA,12); // GPA12 = Blue,  0 : on, 1 : off
    DrvGPIO_SetBit(E_GPA,13); 
    DrvGPIO_SetBit(E_GPA,14); 

    // turn on all pin LED
    DrvGPIO_ClrBit(E_GPA,12);		
    DrvGPIO_ClrBit(E_GPA,13);	
    DrvGPIO_ClrBit(E_GPA,14);		
    DrvSYS_Delay(200000);
    // turn off all
    DrvGPIO_SetBit(E_GPA,12); // GPA12 = Blue,  0 : on, 1 : off
    DrvGPIO_SetBit(E_GPA,13); 
    DrvGPIO_SetBit(E_GPA,14); 
}

void LED()
{
    // turn on pin 12 LED
    DrvGPIO_ClrBit(E_GPC,12);		
    DrvGPIO_SetBit(E_GPC,13);		
    DrvGPIO_SetBit(E_GPC,14);		
    DrvGPIO_SetBit(E_GPC,15);	
    DrvSYS_Delay(50000);
    // turn off all
    DrvGPIO_SetBit(E_GPC,12); // GPA12 = Blue,  0 : on, 1 : off
    DrvGPIO_SetBit(E_GPC,13); 
    DrvGPIO_SetBit(E_GPC,14); 
    DrvGPIO_SetBit(E_GPC,15);	

    // turn on pin 13 LED
    DrvGPIO_SetBit(E_GPC,12);		
    DrvGPIO_ClrBit(E_GPC,13);		
    DrvGPIO_SetBit(E_GPC,14);		
    DrvGPIO_SetBit(E_GPC,15);	
    DrvSYS_Delay(50000);
    // turn off all
    DrvGPIO_SetBit(E_GPC,12); // GPA12 = Blue,  0 : on, 1 : off
    DrvGPIO_SetBit(E_GPC,13); 
    DrvGPIO_SetBit(E_GPC,14); 
    DrvGPIO_SetBit(E_GPC,15);	

    // turn on pin 14 LED
    DrvGPIO_SetBit(E_GPC,12);		
    DrvGPIO_SetBit(E_GPC,13);		
    DrvGPIO_ClrBit(E_GPC,14);		
    DrvGPIO_SetBit(E_GPC,15);	
    DrvSYS_Delay(50000);
    // turn off all
    DrvGPIO_SetBit(E_GPC,12); // GPA12 = Blue,  0 : on, 1 : off
    DrvGPIO_SetBit(E_GPC,13); 
    DrvGPIO_SetBit(E_GPC,14); 
    DrvGPIO_SetBit(E_GPC,15);	

    // turn on pin 15 LED
    DrvGPIO_SetBit(E_GPC,12);		
    DrvGPIO_SetBit(E_GPC,13);	
    DrvGPIO_SetBit(E_GPC,14);		
    DrvGPIO_ClrBit(E_GPC,15);
    DrvSYS_Delay(50000);
    // turn off all
    DrvGPIO_SetBit(E_GPC,12); // GPA12 = Blue,  0 : on, 1 : off
    DrvGPIO_SetBit(E_GPC,13); 
    DrvGPIO_SetBit(E_GPC,14); 
    DrvGPIO_SetBit(E_GPC,15);
	
    // turn on all pin LED
    DrvGPIO_ClrBit(E_GPC,12);		
    DrvGPIO_ClrBit(E_GPC,13);	
    DrvGPIO_ClrBit(E_GPC,14);		
    DrvGPIO_ClrBit(E_GPC,15);
    DrvSYS_Delay(200000);
    // turn off all
    DrvGPIO_SetBit(E_GPC,12); // GPA12 = Blue,  0 : on, 1 : off
    DrvGPIO_SetBit(E_GPC,13); 
    DrvGPIO_SetBit(E_GPC,14); 
    DrvGPIO_SetBit(E_GPC,15);
} 

void Buzz(int number)
{
    
		DrvGPIO_Open(E_GPB, 11, E_IO_OUTPUT);

    for (int i = 0; i < number; i++) {
        DrvGPIO_ClrBit(E_GPB,11); 
        DrvSYS_Delay(200000);
        DrvGPIO_SetBit(E_GPB,11); 
        DrvSYS_Delay(200000); 
    }
}

void EINT1_IRQHandler(void){
	unsigned int *isrc;
	isrc = (unsigned int *)(GP_BA + 0x060);
	if(*isrc & (1<<15)){
		Buzz(5);
	}
	*isrc = (1<<15);
}

int main (void)
{	
	Init_LED();
	DrvGPIO_Open(E_GPB, 15, E_IO_INPUT);
	DrvGPIO_IMD(E_GPB, 15, E_trigger);
	DrvGPIO_IEN(E_GPB, 15, GPIO_EDGE_FALLING);
	NVIC_EnableIRQ(EINT1);
	while(1){
		LED();
	}
}
