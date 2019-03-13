#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "AT91SAM7x.h"
#include "myLIB.h"


void Delay(unsigned int time)				// resolution=0.1ms
{
	volatile int i;
	
	for(i=0;i<time;i++)
	{

	}
}


int  random(int val)
{
     return rand()%val; 
}	

void Uart_Init(int baudrate)
{
	rDBGU_CR=(1<<3)+(1<<2);					                    // Reset TXD/RXD
	rDBGU_MR=(0<<14)+(4<<9);					                  // Normal, No Parity
	rDBGU_BRGR=((48000000L/16/baudrate)<<0);            // MCK=48MHz
	//rDBGU_BRGR=((18432000L/16/baudrate)<<0);            // MCK=18.432MHz
	rDBGU_CR=(1<<6)+(1<<4);					                    // Enable TXD/RXD
}    	
	
char Uart_Getch(void)
{
     while(!(rDBGU_SR & 0x1)); 				// Receive data read
     return rDBGU_RHR;
}

char Uart_Getkey(void)
{
char	Data=0;
     if(rDBGU_SR & 0x1) 				      // Receive data read
     Data=rDBGU_RHR;
     else
     Data=0x00;
     return	Data;
}

void Uart_Putch(char data)
{
     rDBGU_THR=data;	
     while(!(rDBGU_SR & 0x2)); 				// Wait until THR is empty.
}	
void Uart_SendByte(int data)
{
    if(data=='\n')
    {
		rDBGU_THR='\r';
		while(!(rDBGU_SR & 0x2)); 				// Wait until THR is empty.
    }
		rDBGU_THR=data;
		while(!(rDBGU_SR & 0x2)); 				// Wait until THR is empty.


}
void Uart_PutStr(char *pt)
{
    while(*pt) Uart_Putch(*pt++);
}


void Uart_Printf(char *fmt,...)
{
    va_list ap;
    char string[256];

    va_start(ap,fmt);
    vsprintf(string,fmt,ap);
    Uart_PutStr(string);
    va_end(ap);
}

void Sound(int freq)
{

     rPWM_CPRD0=(18432000L/freq);
     rPWM_CDTY0=rPWM_CPRD0/2; 
     rPWM_ENA=(1<<0);  

}

void Nosound(void)
{
     rPWM_DIS=(1<<0);      
}    


