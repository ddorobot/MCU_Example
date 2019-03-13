
/* ============================================================================

  [ Module Name ]
  BASE_DBG.C

  [ Description ]


  Copyright (c) 2005 FirePooh, Inc. All Rights Reserved.

============================================================================ */

/* ============================================================================

  [ History ]

  when       who          what, where, why 
  ---------- ------------ ---------------------------------------------------
  2005/10/21 FIREPOOH     Initial release

============================================================================ */


/*
*********************************************************************************************************
*                                   INCLUDES
*********************************************************************************************************
*/

#include "Board.h"
#include "base_dbg.h"




/*************************************************************************************************
*
*  Function  : DBG_Init
*  ��������  : void.
*
*  ���ϰ�    : void.
*
*  ����      : SAM7S�� DBG Port�� �ʱ�ȭ �Ѵ�. 
*
*************************************************************************************************/
void DBG_Init(void)
{
  //* Open PIO for DBGU
  AT91F_DBGU_CfgPIO();

  //* Configure DBGU
  AT91F_US_Configure (
    (AT91PS_USART) AT91C_BASE_DBGU,       // DBGU base address
    MCK,
    AT91C_US_ASYNC_MODE ,                 // Mode Register to be programmed
    AT91C_DBGU_BAUD ,                     // Baudrate to be programmed
    0);                                   // Timeguard to be programmed

  //* Enable Transmitter & receiver
  ((AT91PS_USART)AT91C_BASE_DBGU)->US_CR = AT91C_US_RXEN | AT91C_US_TXEN;  

}



/*************************************************************************************************
*
*  Function  : DBG_TX
*  ��������  : char buffer - DBG�� ����� Data.
*
*  ���ϰ�    : void.
*
*  ����      : DBG Port�� 1byte ����Ѵ�. 
*
*************************************************************************************************/
void DBG_TX( char buffer )
{
  while (!AT91F_US_TxReady((AT91PS_USART)AT91C_BASE_DBGU));   /* �� ������? */
  AT91F_US_PutChar((AT91PS_USART)AT91C_BASE_DBGU, buffer);    /* ���� ������ ~ */
}



/*************************************************************************************************
*
*  Function  : DBG_RX_EMPTY
*  ��������  : void.
*
*  ���ϰ�    : BOOLEAN  1 - DBG RX Data�� ����.
*                       0 - DBG RX Data�� ����.
*
*  ����      : DBG Port�� Rx�� �Ǿ����� �˻��Ѵ�. 
*
*************************************************************************************************/
BOOLEAN DBG_RX_EMPTY( void )
{
 if ((AT91F_US_RxReady((AT91PS_USART)AT91C_BASE_DBGU)) == 0) 
 {
   return (TRUE);   /* data empty */
 }else
   {
     return (FALSE);  /* data in */
   }
}



/*************************************************************************************************
*
*  Function  : DBG_RX
*  ��������  : void.
*
*  ���ϰ�    : INT8U - DBG Port�� �Էµ� 1byte�� data�� �Ѱ��ش�.
*
*  ����      : DBG Port�� �Էµ� 1byte�� data�� �Ѱ��ش�.
*
*************************************************************************************************/
INT8U DBG_RX( void )
{
  //BUZZ_On( 2 );
  return( AT91F_US_GetChar((AT91PS_USART)AT91C_BASE_DBGU) );
}



/*************************************************************************************************
*
*  Function  : DBG_TX_Str
*  ��������  : char *str - DBG Port�� ����� str�� ���� ptr.
*
*  ���ϰ�    : void.
*
*  ����      : DBG Port�� string�� ����Ѵ�. 
*
*************************************************************************************************/
void DBG_TX_Str( char *str )
{
  INT16U i;

  for( i = 0; str[ i ] ; i++ )
  {
    if( str[ i ] == '\n')
    {
      DBG_TX('\r');
      DBG_TX('\n');
      continue;
    }
  	DBG_TX( str[ i ] );
  }
}



/*************************************************************************************************
*
*  Function  : DBG_TX_Word2Dec
*  ��������  : INT16U data - 16bit data.
*
*  ���ϰ�    : void.
*
*  ����      : 16bit�� data�� 10�� ascii code�� ��ȯ�ؼ� ����Ѵ�.
*
*************************************************************************************************/
void DBG_TX_Word2Dec( INT16U data )
{
  DBG_TX( Byte2Asc( (INT8U)(data / 10000) ) );
  data %= 10000;
         
  DBG_TX( Byte2Asc( (INT8U)(data / 1000) ) );
  data %= 1000;
         
  DBG_TX( Byte2Asc( (INT8U)(data / 100) ) );
  data %= 100;
         
  DBG_TX( Byte2Asc( (INT8U)(data / 10) ) );
  data %= 10;
         
  DBG_TX( Byte2Asc( (INT8U)(data) ) );
}



/*************************************************************************************************
*
*  Function  : DBG_TX_WordHex
*  ��������  : INT16U data - 16bit data.
*
*  ���ϰ�    : void.
*
*  ����      : 16bit data�� hex ascii code�� ��ȯ�ؼ� ����Ѵ�.
*
*************************************************************************************************/
void DBG_TX_WordHex( INT16U data )
{
  DBG_TX( Byte2Asc( data >> 12 ) );
  DBG_TX( Byte2Asc( (( data & 0x0f00 ) >> 8 ) ));
  DBG_TX( Byte2Asc( (( data & 0x00f0 ) >> 4 ) ));
  DBG_TX( Byte2Asc( ( data & 0x000f ) ));
}



/*************************************************************************************************
*
*  Function  : DBG_TX_ByteHex
*  ��������  : INT8U data - 8bit data.
*
*  ���ϰ�    : void.
*
*  ����      : 8bit data�� hex ascii code�� ��ȯ�ؼ� ����Ѵ�.
*
*************************************************************************************************/
void DBG_TX_ByteHex( INT8U data )
{
  DBG_TX( Byte2Asc( (( data & 0xf0 ) >> 4 ) ));
  DBG_TX( Byte2Asc( ( data & 0x0f ) ));
}



/*************************************************************************************************
*
*  Function  : DBG_TX_LongHex
*  ��������  : unsigned long data - 32bit data
*
*  ���ϰ�    : void.
*
*  ����      : 32bit data�� hex ascii code�� ��ȯ�ؼ� ����Ѵ�.. 
*
*************************************************************************************************/
void DBG_TX_LongHex( unsigned long data )
{
  DBG_TX_WordHex( (INT16U)(data>>16) );
  DBG_TX_WordHex( (INT16U)(data) );
}



/*************************************************************************************************
*
*  Function  : KeyInput
*  ��������  : char *ascii - DBG Port �� �Էµ� ascii code��.
*              INT8U *decimal - DBG Port �� �Էµ� binary code��.
*
*  ���ϰ�    : void.
*
*  ����      : DBG Port�� ascii code�� �ԷµǸ�
*              *ascii���� ascii code��
*              *decimal���� ascii code�� decimal�� ��ȯ�� data�� �Էµȴ�. 
*
*************************************************************************************************/
void KeyInput(char *ascii, INT8U *decimal )
{
  //setlocale(LC_ALL, "C");
  
  while( DBG_RX_EMPTY() );

  *ascii = DBG_RX();            /* ascii code '1'�� �ԷµǾ����� */
  //*decimal = atoi( (ascii) );   /*  decimal 1�� �Է� */
  *decimal= _atoi( *ascii  );
}



/*************************************************************************************************
*
*  Function  : Byte2Asc
*  ��������  : INT8U data - 8bit data.
*
*  ���ϰ�    : void.
*
*  ����      : binary�� ascii�� ��ȯ�Ѵ�. 
*
*************************************************************************************************/
char Byte2Asc( INT8U data )
{
  if ( data < 0x0a ) data += 0x30;
  else data += 0x57;

  return data;
}



#ifdef USE_SYSTEM_PRINTF

/*************************************************************************************************
*
*  Function  : fputc
*  ��������  : int ch - ADS ���� LIB �̿���.
*              FILE *f - ADS ���� LIB �̿���.
*
*  ���ϰ�    : int
*
*  ����      : DBG Port�� �̿��Ͽ� printf�Լ� ����.
*
*************************************************************************************************/
int fputc( int ch, FILE *f )
{
  /* Place your implementation of fputc here     */
  /* e.g. write a character to a UART, or to the */
  /* debugger console with SWI WriteC            */

  if( ch == '\n')
  {
    DBG_TX('\r');
    DBG_TX('\n');
  }else
    {
      DBG_TX(ch);
    }

  return ch;
}



/*************************************************************************************************
*
*  Function  : ferror
*  ��������  : FILE *f - ADS ���� LIB �̿���.
*
*  ���ϰ�    : int
*
*  ����      : .
*
*************************************************************************************************/
int ferror( FILE *f )
{
  /* Your implementation of ferror */
  return EOF;
}



/*************************************************************************************************
*
*  Function  : fgetc
*  ��������  : FILE *f - ADS ���� LIB �̿���.
*
*  ���ϰ�    : int
*
*  ����      : scanf�Լ��� ��밡���ϰ� ��.
*
*************************************************************************************************/
int fgetc( FILE *f )
{
  INT8U data;
 
  while( DBG_RX_EMPTY() ) 
  {
    //OSTimeDly(1);
  }

  data = DBG_RX();
  printf("%c",data);

  if( data == '\r' )
  {
    return (int)('\n');
  }else 
    {
      return(data);
    }
 
}
char _atoi(char	s)
{
	int	n;
  
	if(s >= '0' && s <= '9')
		n = (s-'0');

	return(n);
}
#endif

