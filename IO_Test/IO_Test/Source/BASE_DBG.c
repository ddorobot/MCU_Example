
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
*  전달인자  : void.
*
*  리턴값    : void.
*
*  설명      : SAM7S의 DBG Port을 초기화 한다. 
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
*  전달인자  : char buffer - DBG로 출력할 Data.
*
*  리턴값    : void.
*
*  설명      : DBG Port로 1byte 출력한다. 
*
*************************************************************************************************/
void DBG_TX( char buffer )
{
  while (!AT91F_US_TxReady((AT91PS_USART)AT91C_BASE_DBGU));   /* 다 나갔니? */
  AT91F_US_PutChar((AT91PS_USART)AT91C_BASE_DBGU, buffer);    /* 인제 나간다 ~ */
}



/*************************************************************************************************
*
*  Function  : DBG_RX_EMPTY
*  전달인자  : void.
*
*  리턴값    : BOOLEAN  1 - DBG RX Data가 없음.
*                       0 - DBG RX Data가 있음.
*
*  설명      : DBG Port로 Rx가 되었는지 검사한다. 
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
*  전달인자  : void.
*
*  리턴값    : INT8U - DBG Port로 입력된 1byte의 data을 넘겨준다.
*
*  설명      : DBG Port로 입력된 1byte의 data을 넘겨준다.
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
*  전달인자  : char *str - DBG Port로 출력할 str의 시작 ptr.
*
*  리턴값    : void.
*
*  설명      : DBG Port로 string을 출력한다. 
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
*  전달인자  : INT16U data - 16bit data.
*
*  리턴값    : void.
*
*  설명      : 16bit의 data을 10진 ascii code로 변환해서 출력한다.
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
*  전달인자  : INT16U data - 16bit data.
*
*  리턴값    : void.
*
*  설명      : 16bit data을 hex ascii code로 변환해서 출력한다.
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
*  전달인자  : INT8U data - 8bit data.
*
*  리턴값    : void.
*
*  설명      : 8bit data을 hex ascii code로 변환해서 출력한다.
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
*  전달인자  : unsigned long data - 32bit data
*
*  리턴값    : void.
*
*  설명      : 32bit data을 hex ascii code로 변환해서 출력한다.. 
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
*  전달인자  : char *ascii - DBG Port 로 입력된 ascii code값.
*              INT8U *decimal - DBG Port 로 입력된 binary code값.
*
*  리턴값    : void.
*
*  설명      : DBG Port로 ascii code가 입력되면
*              *ascii에는 ascii code가
*              *decimal에는 ascii code을 decimal로 변환한 data가 입력된다. 
*
*************************************************************************************************/
void KeyInput(char *ascii, INT8U *decimal )
{
  //setlocale(LC_ALL, "C");
  
  while( DBG_RX_EMPTY() );

  *ascii = DBG_RX();            /* ascii code '1'이 입력되었으면 */
  //*decimal = atoi( (ascii) );   /*  decimal 1이 입력 */
  *decimal= _atoi( *ascii  );
}



/*************************************************************************************************
*
*  Function  : Byte2Asc
*  전달인자  : INT8U data - 8bit data.
*
*  리턴값    : void.
*
*  설명      : binary을 ascii로 변환한다. 
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
*  전달인자  : int ch - ADS 내부 LIB 이용함.
*              FILE *f - ADS 내부 LIB 이용함.
*
*  리턴값    : int
*
*  설명      : DBG Port을 이용하여 printf함수 구현.
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
*  전달인자  : FILE *f - ADS 내부 LIB 이용함.
*
*  리턴값    : int
*
*  설명      : .
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
*  전달인자  : FILE *f - ADS 내부 LIB 이용함.
*
*  리턴값    : int
*
*  설명      : scanf함수을 사용가능하게 함.
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

