
/* ============================================================================

  [ Module Name ]
  BASE_DBG.H

  [ Description ]


  Copyright (c) 2005 FirePooh, Inc. All Rights Reserved.

============================================================================ */

/* ============================================================================

  [ History ]

  when       who          what, where, why 
  ---------- ------------ ---------------------------------------------------
  2005/10/21 FIREPOOH     Initial release

============================================================================ */

#ifndef BASE_DBG_h
#define BASE_DBG_h


/**** DEFINE ****/

#define USE_SYSTEM_PRINTF 1

/******************************************************************/



/**** Function List ****/

extern void DBG_Init( void );
extern void KeyInput(char* ascii, INT8U* decimal );
extern char Byte2Asc( INT8U data );
extern BOOLEAN DBG_RX_EMPTY( void );
extern INT8U DBG_RX( void );
extern void DBG_TX_Str( char *str );
extern void DBG_TX_WordHex( INT16U data );
extern void DBG_TX_ByteHex( INT8U data );
extern void DBG_TX( char buffer );
extern char _atoi(char	s);

/******************************************************************/


#endif

