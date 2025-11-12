#define GP_BA 0x50004000
#define SCS_BA 0xE000E000

// Register Map
#define GP_PMD 		0x000
#define GP_OFFD 	0x004
#define GP_DOUT 	0x008
#define GP_DMASK 	0x00C
#define GP_PIN 		0x010
#define GP_DBEN 	0x014
#define GP_IMD 		0x018
#define GP_IEN 		0x01C
#define GP_ISRC 	0x020

// NVIC
#define NVIC_ISER   0x100   
#define NVIC_ICER   0x180   
#define NVIC_ISPR   0x200   
#define NVIC_ICPR   0x280   
#define NVIC_IPR0   0x400   
#define NVIC_IPR1   0x404   
#define NVIC_IPR2   0x408   
#define NVIC_IPR3   0x40C   
#define NVIC_IPR4   0x410   
#define NVIC_IPR5   0x414   
#define NVIC_IPR6   0x418   
#define NVIC_IPR7   0x41C   


typedef enum
{
    BOD_OUT      = 0,
    WDT_INT      = 1,
    EINT0        = 2,
    EINT1        = 3,
    GPAB_INT     = 4,
    GPCDE_INT    = 5,
    PWMA_INT     = 6,
    PWMB_INT     = 7,
    TMR0_INT     = 8,
    TMR1_INT     = 9,
    TMR2_INT     = 10,
    TMR3_INT     = 11,
    UART02_INT   = 12,
    UART1_INT    = 13,
    SPI0_INT     = 14,
    SPI1_INT     = 15,
    SPI2_INT     = 16,
    SPI3_INT     = 17,
    I2C0_INT     = 18,
    I2C1_INT     = 19,
    CAN0_INT     = 20,
    USB_INT      = 23,
    PS2_INT      = 24,
    ACMP_INT     = 25,
    PDMA_INT     = 26,
    I2S_INT      = 27,
    PWRWU_INT    = 28,
    ADC_INT      = 29,
    RTC_INT      = 31
} Interrupt_Name;



/* pin
#define E_GPA 0
#define E_GPB 1
#define E_GPC 2
#define E_GPD 3
#define E_GPE 4
*/
typedef enum
{
	E_GPA = 0,
	E_GPB,
	E_GPC,
	E_GPD,
	E_GPE,
}E_DrvGPIO_PORT;

/* mode 
#define E_IO_INPUT 0
#define E_IO_OUTPUT 1
#define E_IO_Open_Drain 2
#define E_IO_Quasi_bidiretional 3
*/
typedef enum
{
	E_IO_INPUT = 0,
	E_IO_OUTPUT,
	E_IO_Open_Drain,
	E_IO_Quasi_bidiretional
}E_DrvGPIO_IO;

/*IMD
#define E_trigger 0
#define L_trigger 1
*/
typedef enum
{
	E_trigger = 0,
	L_trigger = 1
}E_DrvGPIO_TIG;

typedef enum {
    GPIO_EDGE_FALLING = 0,
    GPIO_EDGE_RISING  = 1  
} E_DrvGPIO_Edge;

void DrvGPIO_Open (E_DrvGPIO_PORT port, unsigned int num, E_DrvGPIO_IO mode);
void DrvGPIO_ClrBit (E_DrvGPIO_PORT port, unsigned int num);
void DrvGPIO_SetBit (E_DrvGPIO_PORT port, unsigned int num);

void DrvGPIO_Bounce(E_DrvGPIO_PORT port, unsigned int num);
unsigned int DrvGPIO_GetBit(E_DrvGPIO_PORT port);

void DrvSYS_Delay (unsigned int n);

void DrvGPIO_IMD (E_DrvGPIO_PORT port, unsigned int num, E_DrvGPIO_TIG mode);
void DrvGPIO_IEN (E_DrvGPIO_PORT port, unsigned int num, E_DrvGPIO_Edge edge);
void NVIC_EnableIRQ(unsigned int num);

unsigned int scan_KeyBOARD(void);