//*----------------------------------------------------------------------------
//*         ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : retarget.c
//* Object              : ADS basic definition for no semihosting
//*
//* 1.1 28/06/01 JPP    : Creation
//*----------------------------------------------------------------------------


//* Semihosting Flag
//#ifndef SEMIHOSTING

#include <rt_misc.h>

// define the heap size

//       RAM:
//                             ---------------
//           SP -> top of RAM |   0x20x0000   |
//                            |               |
//           Heap base        | SP - HEAP_SIZE|
//                             ---------------
//                            |               |
//           text(code)       |   0x2000000   |
//                            |  reset + size |
//                             ---------------
//                            |   0x2000000   | Entry point
//           reset(code)       ---------------

#define HEAP_SIZE 	(64 *1024)

//*----------------------------------------------------------------------------
//* Function Name       : _sys_exit
//* Object              : Wait for error system return main. Called, eventually,
//*						  by all exits from the library.
//* Input Parameters    : return_code
//* Output Parameters   : none
//* Functions called    : none
//*----------------------------------------------------------------------------
void _sys_exit(int return_code)
{
  while(1); //* endless loop
}

//*----------------------------------------------------------------------------
//* Function Name       : _ttywrch
//* Object              : This function writes a character to the console. The
//*						console might have been redirected. You can use this
//*  					function as a last resort error handling routine.
//* Input Parameters    : ch
//* Output Parameters   : none
//* Functions called    : none
//*----------------------------------------------------------------------------

void _ttywrch(int ch)
{

}

//*----------------------------------------------------------------------------
//* Function Name       : __user_initial_stackheap
//* Object              : Returns the locations of the initial stack and heap.
//* Input Parameters    :
//* Output Parameters   :The values returned in r0 to r3 depend on whether you
//*						are using the one or two region model:
//*			One region (r0,r1) is the single stack and heap region. r1 is
//*			greater than r0. r2 and r3 are ignored.
//*			Two regions (r0, r2) is the initial heap and (r3, r1) is the initial
//*			stack. r2 is greater than or equal to r0. r3 is less than r1.
//* Functions called    : none
//*----------------------------------------------------------------------------

__value_in_regs struct __initial_stackheap __user_initial_stackheap(
        unsigned R0, unsigned SP, unsigned R2, unsigned SL)
{
    struct __initial_stackheap config;

    config.heap_base = SP - HEAP_SIZE;
    config.stack_base = SP;

    return config;
}


//#endif // SEMIHOSTING
