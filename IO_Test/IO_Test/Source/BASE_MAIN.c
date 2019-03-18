#include "board.h"
#include "AT91SAM7x.h"
#include "myLIB.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <pio/pio.h>
#include <aic/aic.h>
#include <utility\trace.h>
#include <cs8900a/cs8900a.h>

unsigned char 	Dot_Font[10][8]={{0x00, 0x7c, 0x8a, 0x92, 0xa2, 0x7c, 0x00, 0x00},//0
							 {0x00, 0x00, 0x80,	0xfe, 0x84, 0x00, 0x00, 0x00},//1
							 {0x00, 0x8c, 0x92, 0xa2, 0xc2, 0x84, 0x00, 0x00},//2
							 {0x00, 0x62, 0x96, 0x8a, 0x82, 0x42, 0x00, 0x00},//3
							 {0x00, 0x20, 0xfe, 0x24, 0x28, 0x30, 0x00, 0x00},//4
							 {0x00, 0x72, 0x8a, 0x8a, 0x8a, 0x4e, 0x00, 0x00},//5
							 {0x00, 0x60, 0x92, 0x92, 0x94, 0x78, 0x00, 0x00},//6
							 {0x00, 0x06, 0x0a, 0x12, 0xe2, 0x02, 0x00, 0x00},//7
							 {0x00, 0x6c, 0x92, 0x92, 0x92, 0x6c, 0x00, 0x00},//8
							 {0x00, 0x3c, 0x52, 0x92, 0x92, 0x0c, 0x00, 0x00}};//9
							 
void Port_Setup(void)
{
	AT91F_PMC_EnablePeriphClock ( AT91C_BASE_PMC, 1 << AT91C_ID_PIOA );
	
	AT91F_PIO_CfgOutput( AT91C_BASE_PIOA, COL_DATA|ROW_DATA);
	AT91F_PIO_CfgPullup( AT91C_BASE_PIOA, COL_DATA );
}

int main()
{ 
	const int display_min_number = 0 ;
	const int display_max_number = 9 ;
	
	int nDotLine = 0 ;
	int nDisplay = 0 ;
	int nDelay = 0 ;
	
  	Port_Setup();

	//Serial 
	DBG_Init();

	Uart_Printf("Example : Dot Matrix\n\r");

	//Port Clear
	rPIO_CODR_A |=COL_DATA;
	rPIO_CODR_A |=ROW_DATA;
	
	while(1) 
	{
		for( nDisplay=display_min_number ; nDisplay<=display_max_number ; nDisplay++ )
		{
			Uart_Printf("Dot Matrix Display = %d\n\r", nDisplay);

			for( nDelay=0 ; nDelay<2500 ; nDelay++ )	//(8*50)*2500 = 1000000 <- 1sec
			{
				for( nDotLine=0 ; nDotLine<8 ; nDotLine++ )
				{
					rPIO_CODR_A |=COL_DATA;
					rPIO_SODR_A |=Dot_Font[nDisplay][nDotLine];

					//
					rPIO_CODR_A |=(1<<(8+nDotLine));
					Delay(50);
					rPIO_SODR_A |=(1<<(8+nDotLine));
				}
			}
		}

	};

	
}
