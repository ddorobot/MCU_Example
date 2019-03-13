
/* ============================================================================

  [ Module Name ]
  BASE_MAIN.H

  [ Description ]


  Copyright (c) 2005 FirePooh, Inc. All Rights Reserved.

============================================================================ */

/* ============================================================================

  [ History ]

  when       who          what, where, why 
  ---------- ------------ ---------------------------------------------------
  2005/10/21 FIREPOOH     Initial release

============================================================================ */

#ifndef BASE_MAIN_h
#define BASE_MAIN_h


/**** Typedef List ****/

typedef struct
{
  void (*func_ptr)(void); 
}FunctionPTR;

/************************************************************************************************/



/**** Function List ****/

//extern void MAIN_Menu1(void);
extern char _atoi(char	s);

/************************************************************************************************/

#endif
