#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "myLIB.h"
#include "at91sam7x512.h"
#include "cs8900a.h"
#include "../board.h"

volatile U8 *NetRxPackets[PKTBUFSRX];
//unsigned char Pin_Num[16]={0,1,2,3,4,5,6,7,18,23,24,25,26,27,28,29}; 
void Data_Bus_Out_Setting(void)
{
	AT91F_PIO_CfgOutput( AT91C_BASE_PIOB, Data_Bus );
}
void Data_Bus_Input_Setting(void)
{
	AT91F_PIO_CfgInput( AT91C_BASE_PIOB, Data_Bus );
	AT91F_PIO_CfgPullup( AT91C_BASE_PIOB, Data_Bus );

}
unsigned short get_reg_init_bus (int regno)
{
	/* force 16 bit busmode */
	volatile unsigned char c;

	c = Data_Read(CS8900_BUS16_0);
	c = Data_Read(CS8900_BUS16_1);
	c = Data_Read(CS8900_BUS16_0);
	c = Data_Read(CS8900_BUS16_1);
	c = Data_Read(CS8900_BUS16_0);

	Data_Write(CS8900_PPTR,regno);
	return Data_Read(CS8900_PDATA);
	
}
static void put_reg (S32 regno, U16 val)
{
	Data_Write(CS8900_PPTR,regno);
	Data_Write(CS8900_PDATA,val);
	
}
U16 get_reg (S32 regno)
{
	Data_Write(CS8900_PPTR,regno);
	return Data_Read(CS8900_PDATA);
}

void eth_reset (void)
{
	S32 tmo;
	U16 us;

	/* reset NIC */
	put_reg (PP_SelfCTL, get_reg (PP_SelfCTL) | PP_SelfCTL_Reset);

	/* wait for 200ms */
	Delay (200000);
	/* Wait until the chip is reset */

	Delay (200000);
	
	//tmo = get_timer (0) + 1 * CFG_HZ;
	//while ((((us = get_reg_init_bus (PP_SelfSTAT)) & PP_SelfSTAT_InitD) == 0)
	//	   && tmo < get_timer (0))
		/*NOP*/;
}
void LAN_Port_Setup(void)
{
	AT91F_PIO_CfgOutput( AT91C_BASE_PIOB, Data_Bus );
	AT91F_PIO_CfgPullup( AT91C_BASE_PIOB, Data_Bus );
	
	AT91F_PIO_CfgOutput( AT91C_BASE_PIOB, Address_Bus );
	AT91F_PIO_CfgPullup( AT91C_BASE_PIOB, Address_Bus );
	
	AT91F_PIO_CfgInput( AT91C_BASE_PIOB, IRQ_LAN );
	AT91F_PIO_CfgPullup( AT91C_BASE_PIOB, IRQ_LAN );
	
	AT91F_PIO_CfgInput( AT91C_BASE_PIOB, LAN_nWait );
	AT91F_PIO_CfgPullup( AT91C_BASE_PIOB, LAN_nWait );
	
	AT91F_PIO_CfgOutput( AT91C_BASE_PIOB, Control );
	AT91F_PIO_SetOutput( AT91C_BASE_PIOB, nWE);
	AT91F_PIO_SetOutput( AT91C_BASE_PIOB, nRD);
	AT91F_PIO_SetOutput( AT91C_BASE_PIOB, CS);	

}
S32 eth_init (U8 *Mac_Addr)
{
	int i=0,Counter=0;
	LAN_Port_Setup();
	if (get_reg_init_bus (PP_ChipID) != 0x630e) 
	{
		Uart_Printf ("CS8900 Ethernet chip not found?! ID=%4x\n",get_reg_init_bus (PP_ChipID));
		return 0;
	}
	Uart_Printf ("CS8900 Ethernet chip found! ID=%4x\n",get_reg_init_bus (PP_ChipID));
	eth_reset ();
	/* set the ethernet address */
	/* MAC Addr is 08:00:3e:26:0a:5c */
	for(i=0;i<3;i++)
	{
		put_reg (PP_IA + 0, Mac_Addr[0] | (Mac_Addr[1] << 8));
		Delay(1000);
		put_reg (PP_IA + 2, Mac_Addr[2] | (Mac_Addr[3] << 8));
		Delay(1000);
		put_reg (PP_IA + 4, Mac_Addr[4] | (Mac_Addr[5] << 8));
		Delay(1000);
	}

	/* receive only error free packets addressed to this card */
	put_reg (PP_RxCTL, PP_RxCTL_IA | PP_RxCTL_Broadcast | PP_RxCTL_RxOK );

	/* do not generate any interrupts on receive operations */
	put_reg (PP_RxCFG, 0);

	/* do not generate any interrupts on transmit operations */
	put_reg (PP_TxCFG, 0);

	/* do not generate any interrupts on buffer operations */
	put_reg (PP_BufCFG, 0);

	/* enable transmitter/receiver mode */
	put_reg (PP_LineCTL, PP_LineCTL_Rx | PP_LineCTL_Tx );
	
	while ((get_reg (PP_LineSTAT) & PP_LineSTAT_LinkOK) == 0) 
	{
		Delay(100);
		Uart_Printf(".");
		Counter++;
		if(Counter>1000) break;

	}
	Uart_Printf("\nCS8900A Complete..!\n");

	return 0;


}
extern S32 eth_rx (volatile void *packet)
{
	S32 i;
	U16 rxlen;
	U16 *addr;
	U16 status,Data=0;

	status = get_reg (PP_RER);

	if ((status & PP_RER_RxOK) == 0)
		return 0;

	status=Data_Read(CS8900_RTDATA);
	rxlen=Data_Read(CS8900_RTDATA);
	//status = CS8900_RTDATA;		/* stat */
	//rxlen = CS8900_RTDATA;		/* len */

	if (rxlen > PKTSIZE_ALIGN + PKTALIGN) Uart_Printf ("packet too big!\n");

//	Uart_Printf("Recieve Data..Num=%d\n",rxlen);
	if(rxlen>0)
	{
		for (addr = (U16 *) packet, i = rxlen >> 1; i > 0; i--)
		{
			
			Data=Data_Read(CS8900_RTDATA);
			*(addr++) =Data;
//			Uart_Printf("%d Data=0x%x\n",i,Data);
		
			if (rxlen & 1)
			{
				Data=Data_Read(CS8900_RTDATA);
				*(addr++) =Data;
//				Uart_Printf("%d Data=0x%x\n",i,Data);
			}
		}
		
		/* Pass the packet up to the protocol layers. */
		//NetReceive (NetRxPackets[0], rxlen);
	}

	return rxlen;
}
void eth_halt (void)
{
	/* disable transmitter/receiver mode */
	put_reg (PP_LineCTL, 0);

	/* "shutdown" to show ChipID or kernel wouldn't find he cs8900 ... */
	get_reg_init_bus (PP_ChipID);
}
static void cs8900_e2prom_ready(void)
{
	while(get_reg(PP_SelfST) & SI_BUSY);
}

void cs8900_get_enetaddr (U8 * addr)
{
	int i;
	unsigned char env_enetaddr[6];
	char *tmp = getenv ("ethaddr");
	char *end;
	unsigned int Addr;

	for (i=0; i<6; i++) {
		env_enetaddr[i] = tmp ? simple_strtoul(tmp, &end, 16) : 0;
		if (tmp)
			tmp = (*end) ? end+1 : end;
	}
				
	
	if (get_reg_init_bus (PP_ChipID) != 0x630e)
		return;
	eth_reset ();
	//Uart_Printf ("\n Data1=%x \r",(get_reg (PP_SelfST) & (PP_SelfSTAT_EEPROM | PP_SelfSTAT_EEPROM_OK)));
	//Uart_Printf ("\n Data2=%x \r",(PP_SelfSTAT_EEPROM | PP_SelfSTAT_EEPROM_OK));
	
	//if ((get_reg (PP_SelfST) & (PP_SelfSTAT_EEPROM | PP_SelfSTAT_EEPROM_OK)) ==
	//		(PP_SelfSTAT_EEPROM | PP_SelfSTAT_EEPROM_OK)) 
	//{
		
		for (i = 0; i < 6 / 2; i++) {


			Addr = get_reg (PP_IA + i * 2);
			Uart_Printf ("\n Addr=%04x \r",Addr); 
			addr[i * 2] = Addr & 0xFF;
			addr[i * 2 + 1] = Addr >> 8;
		}
/*
		if (memcmp(env_enetaddr, "\0\0\0\0\0\0", 6) != 0 && memcmp(env_enetaddr, addr, 6) != 0) 
		{
			Uart_Printf ("\nWarning: MAC addresses don't match:\n");
			Uart_Printf ("\tHW MAC address:  "
				"%02X:%02X:%02X:%02X:%02X:%02X\n\r",
				addr[0], addr[1],
				addr[2], addr[3],
				addr[4], addr[5] );
		
			Uart_Printf ("\t\"ethaddr\" value: "
				"%02X:%02X:%02X:%02X:%02X:%02X\n",
				env_enetaddr[0], env_enetaddr[1],
				env_enetaddr[2], env_enetaddr[3],
				env_enetaddr[4], env_enetaddr[5]) ;
				memcpy (addr, env_enetaddr, 6);
		}

		if (!tmp) {
			char ethaddr[20];
			sprintf (ethaddr, "%02X:%02X:%02X:%02X:%02X:%02X",
				 addr[0], addr[1],
				 addr[2], addr[3],
				 addr[4], addr[5]) ;
			//setenv ("ethaddr", ethaddr);
		Uart_Printf ("\n Error \r");
	
		}
*/
	//}
}
extern S32 eth_send (volatile void *packet, S32 length)
{
	unsigned short *addr;
	int tmo;
	unsigned short s,Data=0;
		
retry:
	/* initiate a transmit sequence */
	Data_Write(CS8900_TxCMD,PP_TxCmd_TxStart_Full);
	Data_Write(CS8900_TxLEN,length);
	
//	CS8900_TxCMD = PP_TxCmd_TxStart_Full;
//	CS8900_TxLEN = length;
 		/* Test to see if the chip has allocated memory for the packet */
	if ((get_reg (PP_BusSTAT) & PP_BusSTAT_TxRDY) == 0) {
		/* Oops... this should not happen! */
		Uart_Printf ("cs: unable to send packet; retrying...\n\r");
		//for (tmo = get_timer (0) + 5 * CFG_HZ; get_timer (0) < tmo;)
			/*NOP*/;
		Delay(100);
		eth_reset ();
		goto retry;
	}

	/* Write the contents of the packet */
	/* assume even number of bytes */
	//Uart_Printf("\n\nSending Data\n");
	
//	for (addr = (U16 *) uip_buf; length > 0; length -= 2)
	for (addr = (U16 *) packet; length > 0; length -= 2)	
	{
//		CS8900_RTDATA = *addr++;
		Data=*addr++;
		Data_Write(CS8900_RTDATA,Data);
//		Uart_Printf("%d Data=0x%x\n",length,Data);
	
	}
	/* wait for transfer to succeed */
	//tmo = get_timer (0) + 5 * CFG_HZ;
	//Delay(10);
//	
	while ((s = get_reg (PP_TER) & ~0x1F) == 0) {
	//Delay(10);
	///	if (get_timer (0) >= tmo)
	//		break;
	}
	//eth_reset ();
	/* nothing */ ;
	if ((s & (PP_TER_CRS | PP_TER_TxOK)) != PP_TER_TxOK) {
		Uart_Printf ("\ntransmission error %#x\n\r", s);
	}

	return 0;
}

U32 simple_strtoul(char *p, char **out_p, int base)
{
	unsigned int v = 0;
	char c;
	
	while (isspace(*p)) p++;
	
	if( ((base == 16) || (base == 0)) && ((*p == '0') && ((p[1] == 'x') || (p[1] == 'X'))))
	{
		p += 2;
		base = 16;
	}
	
	if(base == 0)
	{
		if (*p == '0') base = 8;
		else base = 10;
	}
	
	while (1)
	{
		c = *p;
		if ((c >= '0') && (c <= '9') && (c - '0' < base))
			v = (v * base) + (c - '0');
		else if ((c >= 'a') && (c <= 'z') && (c - 'a' + 10 < base))
			v = (v * base) + (c - 'a' + 10);
		else if ((c >= 'A') && (c <= 'Z') && (c - 'A' + 10 < base))
			v = (v * base) + (c - 'A' + 10);
		else
			break;
		p++;
	}

	if (out_p) *out_p = (char*)p;
	return v;
}

/***********************************************************/
/* read a 16-bit word out of the EEPROM                    */
/***********************************************************/

int cs8900_e2prom_read(unsigned char addr, unsigned short *value)
{
	cs8900_e2prom_ready();
	put_reg(PP_EECMD, EEPROM_READ_CMD | addr);
	cs8900_e2prom_ready();
	*value = get_reg(PP_EEData);

	return 0;
}


/***********************************************************/
/* write a 16-bit word into the EEPROM                     */
/***********************************************************/

int cs8900_e2prom_write(unsigned char addr, unsigned short value)
{
	cs8900_e2prom_ready();
	put_reg(PP_EECMD, EEPROM_WRITE_EN);
	cs8900_e2prom_ready();
	put_reg(PP_EEData, value);
	put_reg(PP_EECMD, EEPROM_WRITE_CMD | addr);
	cs8900_e2prom_ready();
	put_reg(PP_EECMD, EEPROM_WRITE_DIS);
	cs8900_e2prom_ready();

	return 0;
}
void Data_Write(unsigned char Address, unsigned short Data)
{
	unsigned int	Buffer=0,i=0;
	unsigned char	Low=0,High=0;
	
	Data_Bus_Out_Setting();
	
	rPIO_CODR_B |= Address_Bus;
	rPIO_SODR_B |=(Address>>1)<<25;// (Address>>1)<<19;
	
	rPIO_CODR_B |= Data_Bus;
	//Low=(unsigned char)Data;
	//High=(unsigned char)(Data>>8);
	
	//rPIO_SODR_B |= (High<<23)|(Low<<8);
	rPIO_SODR_B |= (0x0000ffff&Data);

//Control Settup
	rPIO_CODR_B|=CS;
	rPIO_CODR_B|=nWE;
	rPIO_SODR_B|=CS;
	rPIO_SODR_B|=nWE;
/*	
	AT91F_PIO_ClearOutput( AT91C_BASE_PIOB, CS);
	AT91F_PIO_ClearOutput( AT91C_BASE_PIOB, nWE);
//	Delay();
	AT91F_PIO_SetOutput( AT91C_BASE_PIOB, CS);
	AT91F_PIO_SetOutput( AT91C_BASE_PIOB, nWE);
*/
}

unsigned short Data_Read(unsigned char Address)
{
	unsigned int	Buffer=0,i=0;
	unsigned char 	Low=0,High=0;
	unsigned short 	Temp=0;
	Data_Bus_Input_Setting();

	rPIO_CODR_B |= Address_Bus;
	rPIO_SODR_B |= (Address>>1)<<25;

	AT91F_PIO_ClearOutput( AT91C_BASE_PIOB, CS);
	AT91F_PIO_ClearOutput( AT91C_BASE_PIOB, nRD);

	while( !AT91F_PIO_GetInput(AT91C_BASE_PIOB) & LAN_nWait){	}

	Buffer=AT91F_PIO_GetInput(AT91C_BASE_PIOB);
	//Uart_Printf("Raw_Read=0x%8x\n\r",Buffer);
	//Low=(unsigned char)(Buffer>>8);
	//High=(unsigned char)(Buffer>>23);
	
	AT91F_PIO_SetOutput( AT91C_BASE_PIOB, CS);
	AT91F_PIO_SetOutput( AT91C_BASE_PIOB, nRD);

	//Temp=(High<<8)|Low;//Buffer&0x0000ffff;	
	Temp=Buffer&0x0000ffff;	
	return Temp;
}
