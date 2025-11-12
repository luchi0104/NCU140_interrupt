#include "mygpio.h"

void DrvGPIO_Open (E_DrvGPIO_PORT port, unsigned int num, E_DrvGPIO_IO mode)
{
	unsigned int  *PMD;
	PMD	= (unsigned int *)(GP_BA + (port * 0x40) + GP_PMD);
	*PMD &= ~(0x3 << (num*2));
	*PMD |= (mode << (num*2));
}

void DrvGPIO_ClrBit (E_DrvGPIO_PORT port, unsigned int num)
{
	unsigned int  *DOUT;
	DOUT = (unsigned int *)(GP_BA + (port * 0x40) + GP_DOUT);
	*DOUT &= ~(1 << num);
}

void DrvGPIO_SetBit (E_DrvGPIO_PORT port, unsigned int num)
{
	unsigned int  *DOUT;
	DOUT = (unsigned int *)(GP_BA + (port * 0x40) + GP_DOUT);
	*DOUT |= (1 << num);
}

//2025/10/30
void DrvGPIO_Bounce(E_DrvGPIO_PORT port, unsigned int num)
{
	unsigned int *BOUNCE; 
	BOUNCE = (unsigned int *)(GP_BA + (port * 0x40) + GP_DBEN);
	*BOUNCE |= (1 << num);
}

unsigned int DrvGPIO_GetBit(E_DrvGPIO_PORT port)
{
	unsigned int *PIN;
  PIN = (unsigned int *)(GP_BA + (port * 0x40) + GP_PIN);
  return *PIN;
}

//keyboard_scan
unsigned int scan_KeyBOARD(){
	unsigned int input;
	unsigned int key;
	for (int col = 0; col < 3; col++){
		DrvGPIO_SetBit(E_GPA, 0);
		DrvGPIO_SetBit(E_GPA, 1);
		DrvGPIO_SetBit(E_GPA, 2);
		DrvGPIO_ClrBit(E_GPA, col);
		
		DrvSYS_Delay(10000);
		
		input = DrvGPIO_GetBit(E_GPA) >> 3 &0x07;
		if (input != 0x07){
			for (int row = 0; row < 3; row++){
				if (!(input & (1 << row))){
					key = row *3 + col + 1;
					return key;
				}
		}
	}
 }
	return 0;
}

//INT
void DrvGPIO_IMD (E_DrvGPIO_PORT port, unsigned int num, E_DrvGPIO_TIG mode){
	unsigned int *IMD;
	IMD = (unsigned int *)(GP_BA + (port * 0x40) + GP_IMD);
	if (mode == 0){
		*IMD &= ~(1 << num);
	}
	else {
		*IMD |= (1 << num);
	}
}

void DrvGPIO_IEN (E_DrvGPIO_PORT port, unsigned int num, E_DrvGPIO_Edge edge){
	unsigned int *IEN;
	IEN = (unsigned int *)(GP_BA + (port * 0x40) + GP_IEN);
	if (edge == GPIO_EDGE_RISING)
	{
		*IEN |= (1<<(16+num));
	}
	else
	{
		*IEN |= (1<<num);
	}
}

void NVIC_EnableIRQ(unsigned int num){
	unsigned int *NVICISER;
	NVICISER = (unsigned int *)(SCS_BA + NVIC_ISER);
	*NVICISER |=(1 << num);
}
//



void DrvSYS_Delay (unsigned int n)
{
	for ( int t = 0; t < n; t++); 
}