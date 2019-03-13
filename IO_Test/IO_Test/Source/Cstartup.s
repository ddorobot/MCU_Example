;------------------------------------------------------------------------------
;-         ATMEL Microcontroller Software Support  -  ROUSSET  -
;------------------------------------------------------------------------------
; The software is delivered "AS IS" without warranty or condition of any
; kind, either express, implied or statutory. This includes without
; limitation any warranty or condition with respect to merchantability or
; fitness for any particular purpose, or against the infringements of
; intellectual property rights of others.
;-----------------------------------------------------------------------------
;- File source          : Cstartup.arm
;- Object               : Generic CStartup for ARM ADS 1.2 and SAM7
;- Compilation flag     : None
;-
;- 1.0 12/Jul/04 JPP    : Creation
;- 1.1 10/Sep/04 JPP    : Change Irq Managment
;- 1.1 01/Apr/05 JPP    : save SPSR 
;------------------------------------------------------------------------------


		INCLUDE		AT91SAM7X512.inc

;--------------------------------
;- ARM Core Mode and Status Bits
;--------------------------------

ARM_MODE_USER           EQU     0x10
ARM_MODE_FIQ            EQU     0x11
ARM_MODE_IRQ            EQU     0x12
ARM_MODE_SVC            EQU     0x13
ARM_MODE_ABORT          EQU     0x17
ARM_MODE_UNDEF          EQU     0x1B
ARM_MODE_SYS            EQU     0x1F

I_BIT                   EQU     0x80
F_BIT                   EQU     0x40
T_BIT                   EQU     0x20



;------------------------------------------------------------------------------
;- Area Definition
;------------------------------------------------------------------------------

                AREA        reset, CODE, READONLY
                ENTRY
				EXPORT		entry
entry
;------------------------------------------------------------------------------
;- Exception vectors 
;--------------------
;- These vectors can be read at address 0 or at RAM address
;- They ABSOLUTELY requires to be in relative addresssing mode in order to
;- guarantee a valid jump. For the moment, all are just looping.
;- If an exception occurs before remap, this would result in an infinite loop.
;- To ensure if a exeption occurs before start application to infinite loop.
;------------------------------------------------------------------------------

                B           InitReset           ; 0x00 Reset handler
undefvec
                B           undefvec            ; 0x04 Undefined Instruction
swivec
                B           swivec              ; 0x08 Software Interrupt
pabtvec
                B           pabtvec             ; 0x0C Prefetch Abort
dabtvec
                B           dabtvec             ; 0x10 Data Abort
rsvdvec
                B           rsvdvec             ; 0x14 reserved
irqvec
                B           IRQ_Handler_Entry   ; 0x18 IRQ
fiqvec               				; 0x1c FIQ
;------------------------------------------------------------------------------
;- Function             : FIQ_Handler_Entry
;- Treatments           : FIQ Controller Interrupt Handler.
;- Called Functions     : AIC_FVR[interrupt] 
;------------------------------------------------------------------------------
FIQ_Handler_Entry

;- Switch in SVC/User Mode to allow User Stack access for C code 
; because the FIQ is not yet acknowledged

;- Save and r0 in FIQ_Register 
        mov         r9,r0
	    ldr         r0 , [r8, #AIC_FVR]
        msr        CPSR_c,#I_BIT :OR: F_BIT :OR: ARM_MODE_SVC

;- Save scratch/used registers and LR in User Stack
        stmfd       sp!, { r1-r3, r12, lr}

;- Branch to the routine pointed by the AIC_FVR
        mov         r14, pc
        bx          r0

;- Restore scratch/used registers and LR from User Stack
        ldmia       sp!, { r1-r3, r12, lr}

;- Leave Interrupts disabled and switch back in FIQ mode
        msr         CPSR_c, #I_BIT :OR: F_BIT :OR: ARM_MODE_FIQ

;- Restore the R0 ARM_MODE_SVC register 
        mov         r0,r9

;- Restore the Program Counter using the LR_fiq directly in the PC
        subs        pc,lr,#4

;--------------------
;- The reset handler
;--------------------
InitReset
;------------------------------------------------------------------------------
;- Low level Init (APMC, AIC, EBI, ....) by C function AT91F_LowLevelInit
;------------------------------------------------------------------------------
            IMPORT   AT91F_LowLevelInit

;- minimum  C initialization

            ldr     r13,=0x00204000    ; temporary stack in internal Ram
	    	ldr	    r0,=AT91F_LowLevelInit
            mov     lr, pc
	    	bx	    r0

;------------------------------------------------------------------------------
;- Stack Sizes Definition
;------------------------
;- Interrupt Stack requires 2 words x 8 priority level x 4 bytes when using
;- the vectoring. This assume that the IRQ_ENTRY/IRQ_EXIT macro are used.
;- The Interrupt Stack must be adjusted depending on the interrupt handlers.
;- Fast Interrupt not requires stack If in your application it required you must
;- be define here.
;- Other stacks are defined by default to save one word each.
;- The System stack size is not defined and is limited by the free internal
;- SRAM.
;- User stack size is not defined and is limited by the free external SRAM.
;------------------------------------------------------------------------------

IRQ_STACK_SIZE      EQU     (3*8*4)     ; 2 words per interrupt priority level


;------------------------------------------------------------------------------
;- Setup the stack for each mode
;-------------------------------
                ldr     r0, =0x00210000

;- Set up Fast Interrupt Mode and set FIQ Mode Stack
                msr     CPSR_c, #ARM_MODE_FIQ:OR:I_BIT:OR:F_BIT
;- Init the FIQ register
            	ldr     r8, =AT91C_BASE_AIC

;- Set up Interrupt Mode and set IRQ Mode Stack
                msr     CPSR_c, #ARM_MODE_IRQ:OR:I_BIT:OR:F_BIT
                mov     r13, r0                     ; Init stack IRQ
                sub     r0, r0, #IRQ_STACK_SIZE

;- Set up Supervisor Mode and set Supervisor Mode Stack
                msr     CPSR_c, #ARM_MODE_SVC
                mov     r13, r0                     ; Init stack Sup


;------------------------------------------------------------------------------
;- Branch on C code Main function (with interworking)
;----------------------------------------------------
;- Branch must be performed by an interworking call as either an ARM or Thumb
;- main C function must be supported. This makes the code not position-
;- independent. A Branch with link would generate errors
;------------------------------------------------------------------------------
                IMPORT      __main

                ldr         r0, =__main
                mov         lr, pc
                bx          r0

;------------------------------------------------------------------------------
;- Loop for ever
;---------------
;- End of application. Normally, never occur.
;- Could jump on Software Reset ( B 0x0 ).
;------------------------------------------------------------------------------
End
            b           End

;------------------------------------------------------------------------------
;- Manage exception
;---------------
;- This module The exception must be ensure in ARM mode
;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
;- Function             : IRQ_Handler_Entry
;- Treatments           : IRQ Controller Interrupt Handler.
;- Called Functions     : AIC_IVR[interrupt] 
;------------------------------------------------------------------------------
IRQ_Handler_Entry

;- Manage Exception Entry
;- Adjust and save LR_irq in IRQ stack
            sub         lr, lr, #4
            stmfd       sp!, {lr}

;- Save SPSR need to be saved for nested interrupt
            mrs         r14, SPSR
            stmfd       sp!, {r14}

;- Save and r0 in IRQ stack
            stmfd       sp!, {r0}

;- Write in the IVR to support Protect Mode
;- No effect in Normal Mode
;- De-assert the NIRQ and clear the source in Protect Mode
            ldr         r14, =AT91C_BASE_AIC
	    ldr         r0 , [r14, #AIC_IVR]
	    str         r14, [r14, #AIC_IVR]

;- Enable Interrupt and Switch in Supervisor Mode
           msr         CPSR_c, #ARM_MODE_SVC

;- Save scratch/used registers and LR in User Stack
            stmfd       sp!, { r1-r3, r12, r14}

;- Branch to the routine pointed by the AIC_IVR
            mov         r14, pc
            bx          r0

;- Restore scratch/used registers and LR from User Stack
            ldmia       sp!, { r1-r3, r12, r14}

;- Disable Interrupt and switch back in IRQ mode
            msr         CPSR_c, #I_BIT :OR: ARM_MODE_IRQ

;- Mark the End of Interrupt on the AIC
            ldr         r14, =AT91C_BASE_AIC
            str         r14, [r14, #AIC_EOICR]

;- Restore SPSR_irq and r0 from IRQ stack
            ldmia       sp!, {r0}

;- Restore SPSR_irq and r0 from IRQ stack
            ldmia       sp!, {r14}
            msr         SPSR_cxsf, r14

;- Restore adjusted  LR_irq from IRQ stack directly in the PC
            ldmia       sp!, {pc}^
;------------------------------------------------------------------------------
;- Manage exception
;---------------
;- The exception must be ensure in ARM mode
;------------------------------------------------------------------------------

            EXPORT AT91F_Default_FIQ_handler
AT91F_Default_FIQ_handler
            b     AT91F_Default_FIQ_handler


    		EXPORT AT91F_Default_IRQ_handler
AT91F_Default_IRQ_handler
            b     AT91F_Default_IRQ_handler

	         EXPORT AT91F_Spurious_handler
AT91F_Spurious_handler
            b     AT91F_Spurious_handler

    END

