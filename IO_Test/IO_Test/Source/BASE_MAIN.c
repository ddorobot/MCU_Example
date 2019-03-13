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

void Port_Setup(void)
{
	AT91F_PMC_EnablePeriphClock ( AT91C_BASE_PMC, 1 << AT91C_ID_PIOB );
	
	AT91F_PIO_CfgOutput( AT91C_BASE_PIOB, LED1|LED2|LED3 );
	AT91F_PIO_CfgPullup( AT91C_BASE_PIOB, LED1|LED2|LED3 );
}

int main()
{ 
	unsigned int led_data = LED1 ;
  	Port_Setup();

	//Clear	
	rPIO_CODR_B=(LED1|LED2|LED3);	//OFF

	while(1) 
	{
		//Clear	
		rPIO_CODR_B=(LED1|LED2|LED3);	//OFF
		
		rPIO_SODR_B=(led_data);	//ON
		/* wait for 1s */
		Delay (1000000);

		led_data = led_data << 1 ;

		if( led_data > LED3 )
		{
			led_data = LED1 ;
		}
	};
	
}