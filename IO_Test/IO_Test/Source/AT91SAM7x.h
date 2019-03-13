#define U8		unsigned char
#define U16		unsigned short
#define U32		unsigned int
#define	ULONG	unsigned long
#define	S32		int
#define	S8		char

// Peripheral Timer/Counter 0,1,2
#define rTC_CCR0      *(volatile U32 *)(0xFFFA0000)
#define rTC_CMR0      *(volatile U32 *)(0xFFFA0004)
#define rTC_CV0       *(volatile U32 *)(0xFFFA0010)
#define rTC_RA0       *(volatile U32 *)(0xFFFA0014)
#define rTC_RB0       *(volatile U32 *)(0xFFFA0018)
#define rTC_RC0       *(volatile U32 *)(0xFFFA001C)
#define rTC_SR0       *(volatile U32 *)(0xFFFA0020)
#define rTC_IER0      *(volatile U32 *)(0xFFFA0024)
#define rTC_IDR0      *(volatile U32 *)(0xFFFA0028)
#define rTC_IMR0      *(volatile U32 *)(0xFFFA002C)

#define rTC_CCR1      *(volatile U32 *)(0xFFFA0040)
#define rTC_CMR1      *(volatile U32 *)(0xFFFA0044)
#define rTC_CV1       *(volatile U32 *)(0xFFFA0050)
#define rTC_RA1       *(volatile U32 *)(0xFFFA0054)
#define rTC_RB1       *(volatile U32 *)(0xFFFA0058)
#define rTC_RC1       *(volatile U32 *)(0xFFFA005C)
#define rTC_SR1       *(volatile U32 *)(0xFFFA0060)
#define rTC_IER1      *(volatile U32 *)(0xFFFA0064)
#define rTC_IDR1      *(volatile U32 *)(0xFFFA0068)
#define rTC_IMR1      *(volatile U32 *)(0xFFFA006C)

#define rTC_CCR2      *(volatile U32 *)(0xFFFA0080)
#define rTC_CMR2      *(volatile U32 *)(0xFFFA0084)
#define rTC_CV2       *(volatile U32 *)(0xFFFA0090)
#define rTC_RA2       *(volatile U32 *)(0xFFFA0094)
#define rTC_RB2       *(volatile U32 *)(0xFFFA0098)
#define rTC_RC2       *(volatile U32 *)(0xFFFA009C)
#define rTC_SR2       *(volatile U32 *)(0xFFFA00A0)
#define rTC_IER2      *(volatile U32 *)(0xFFFA00A4)
#define rTC_IDR2      *(volatile U32 *)(0xFFFA00A8)
#define rTC_IMR2      *(volatile U32 *)(0xFFFA00AC)

#define rTC_BCR       *(volatile U32 *)(0xFFFA00C0)
#define rTC_BMR       *(volatile U32 *)(0xFFFA00C4)

// Peripheral USB Device Port
#define rUSB_FRM_NUM  *(volatile U32 *)(0xFFFB0000)
#define rUSB_GLB_STAT *(volatile U32 *)(0xFFFB0004)
#define rUSB_FADDR    *(volatile U32 *)(0xFFFB0008)
#define rUSB_IER      *(volatile U32 *)(0xFFFB0010)
#define rUSB_IDR      *(volatile U32 *)(0xFFFB0014)
#define rUSB_IMR      *(volatile U32 *)(0xFFFB0018)
#define rUSB_ISR      *(volatile U32 *)(0xFFFB001C)
#define rUSB_ICR      *(volatile U32 *)(0xFFFB0020)
#define rUSB_RST_EP   *(volatile U32 *)(0xFFFB0028)
#define rUSB_CSR0     *(volatile U32 *)(0xFFFB0030)
#define rUSB_CSR1     *(volatile U32 *)(0xFFFB0034)
#define rUSB_CSR2     *(volatile U32 *)(0xFFFB0038)
#define rUSB_CSR3     *(volatile U32 *)(0xFFFB003C)
#define rUSB_FDR0     *(volatile U32 *)(0xFFFB0050)
#define rUSB_FDR1     *(volatile U32 *)(0xFFFB0054)
#define rUSB_FDR2     *(volatile U32 *)(0xFFFB0058)
#define rUSB_FDR3     *(volatile U32 *)(0xFFFB005C)
#define rUSB_TXVC     *(volatile U32 *)(0xFFFB0074)

// Peripheral Two-Wire Interface
#define rTWI_CR       *(volatile U32 *)(0xFFFB8000)
#define rTWI_MMR      *(volatile U32 *)(0xFFFB8004)
#define rTWI_IADR     *(volatile U32 *)(0xFFFB800C)
#define rTWI_CWGR     *(volatile U32 *)(0xFFFB8010)
#define rTWI_SR       *(volatile U32 *)(0xFFFB8020)
#define rTWI_IER      *(volatile U32 *)(0xFFFB8024)
#define rTWI_IDR      *(volatile U32 *)(0xFFFB8028)
#define rTWI_IMR      *(volatile U32 *)(0xFFFB802C)
#define rTWI_RHR      *(volatile U32 *)(0xFFFB8030)
#define rTWI_THR      *(volatile U32 *)(0xFFFB8034)

// Peripheral Universal Synchronous Asynchronous Receiver Transmitter 0
#define rUS_CR0       *(volatile U32 *)(0xFFFC0000)
#define rUS_MR0       *(volatile U32 *)(0xFFFC0004)
#define rUS_IER0      *(volatile U32 *)(0xFFFC0008)
#define rUS_IDR0      *(volatile U32 *)(0xFFFC000C)
#define rUS_IMR0      *(volatile U32 *)(0xFFFC0010)
#define rUS_CSR0      *(volatile U32 *)(0xFFFC0014)
#define rUS_RHR0      *(volatile U32 *)(0xFFFC0018)
#define rUS_THR0      *(volatile U32 *)(0xFFFC001C)
#define rUS_BRGR0     *(volatile U32 *)(0xFFFC0020)
#define rUS_RTOR0     *(volatile U32 *)(0xFFFC0024)
#define rUS_TTGR0     *(volatile U32 *)(0xFFFC0028)
#define rUS_FIDI0     *(volatile U32 *)(0xFFFC0040)
#define rUS_NER0      *(volatile U32 *)(0xFFFC0044)
#define rUS_IF0       *(volatile U32 *)(0xFFFC004C)

// Peripheral Universal Synchronous Asynchronous Receiver Transmitter 1
#define rUS_CR1       *(volatile U32 *)(0xFFFC4000)
#define rUS_MR1       *(volatile U32 *)(0xFFFC4004)
#define rUS_IER1      *(volatile U32 *)(0xFFFC4008)
#define rUS_IDR1      *(volatile U32 *)(0xFFFC400C)
#define rUS_IMR1      *(volatile U32 *)(0xFFFC4010)
#define rUS_CSR1      *(volatile U32 *)(0xFFFC4014)
#define rUS_RHR1      *(volatile U32 *)(0xFFFC4018)
#define rUS_THR1      *(volatile U32 *)(0xFFFC401C)
#define rUS_BRGR1     *(volatile U32 *)(0xFFFC4020)
#define rUS_RTOR1     *(volatile U32 *)(0xFFFC4024)
#define rUS_TTGR1     *(volatile U32 *)(0xFFFC4028)
#define rUS_FIDI1     *(volatile U32 *)(0xFFFC4040)
#define rUS_NER1      *(volatile U32 *)(0xFFFC4044)
#define rUS_IF1       *(volatile U32 *)(0xFFFC404C)

// Peripheral PWM Controller
#define rPWM_MR       *(volatile U32 *)(0xFFFCC000)   //
#define rPWM_ENA      *(volatile U32 *)(0xFFFCC004)   //
#define rPWM_DIS      *(volatile U32 *)(0xFFFCC008)   //
#define rPWM_SR       *(volatile U32 *)(0xFFFCC00C)   //
#define rPWM_IER      *(volatile U32 *)(0xFFFCC010)   //
#define rPWM_IDR      *(volatile U32 *)(0xFFFCC014)   //
#define rPWM_IMR      *(volatile U32 *)(0xFFFCC018)   //
#define rPWM_ISR      *(volatile U32 *)(0xFFFCC01C)   //
#define rPWM_CMR0     *(volatile U32 *)(0xFFFCC200)   //
#define rPWM_CDTY0    *(volatile U32 *)(0xFFFCC204)   //
#define rPWM_CPRD0    *(volatile U32 *)(0xFFFCC208)   //
#define rPWM_CCNT0    *(volatile U32 *)(0xFFFCC20C)   //
#define rPWM_CUPD0    *(volatile U32 *)(0xFFFCC210)   //
#define rPWM_CMR1     *(volatile U32 *)(0xFFFCC220)   //
#define rPWM_CDTY1    *(volatile U32 *)(0xFFFCC224)   //
#define rPWM_CPRD1    *(volatile U32 *)(0xFFFCC228)   //
#define rPWM_CCNT1    *(volatile U32 *)(0xFFFCC22C)   //
#define rPWM_CUPD1    *(volatile U32 *)(0xFFFCC230)   //
#define rPWM_CMR2     *(volatile U32 *)(0xFFFCC240)   //
#define rPWM_CDTY2    *(volatile U32 *)(0xFFFCC244)   //
#define rPWM_CPRD2    *(volatile U32 *)(0xFFFCC248)   //
#define rPWM_CCNT2    *(volatile U32 *)(0xFFFCC24C)   //
#define rPWM_CUPD2    *(volatile U32 *)(0xFFFCC250)   //
#define rPWM_CMR3     *(volatile U32 *)(0xFFFCC260)   //
#define rPWM_CDTY3    *(volatile U32 *)(0xFFFCC264)   //
#define rPWM_CPRD3    *(volatile U32 *)(0xFFFCC268)   //
#define rPWM_CCNT3    *(volatile U32 *)(0xFFFCC26C)   //
#define rPWM_CUPD3    *(volatile U32 *)(0xFFFCC270)   //

// Peripheral Serial Synchronous Controller
#define rSSC_CR       *(volatile U32 *)(0xFFFD4000) 
#define rSSC_CMR      *(volatile U32 *)(0xFFFD4004) 
#define rSSC_RCMR     *(volatile U32 *)(0xFFFD4010) 
#define rSSC_RFMR     *(volatile U32 *)(0xFFFD4014) 
#define rSSC_TCMR     *(volatile U32 *)(0xFFFD4018) 
#define rSSC_TFMR     *(volatile U32 *)(0xFFFD401C) 
#define rSSC_RHR      *(volatile U32 *)(0xFFFD4020) 
#define rSSC_THR      *(volatile U32 *)(0xFFFD4024) 
#define rSSC_RSHR     *(volatile U32 *)(0xFFFD4030) 
#define rSSC_TSHR     *(volatile U32 *)(0xFFFD4034) 
#define rSSC_SR       *(volatile U32 *)(0xFFFD4040) 
#define rSSC_IER      *(volatile U32 *)(0xFFFD4044) 
#define rSSC_IDR      *(volatile U32 *)(0xFFFD4048) 
#define rSSC_IMR      *(volatile U32 *)(0xFFFD404C) 

// Peripheral Analog-to-Digital Converter
#define rADC_CR       *(volatile U32 *)(0xFFFD8000) 
#define rADC_MR       *(volatile U32 *)(0xFFFD8004) 
#define rADC_CHER     *(volatile U32 *)(0xFFFD8010) 
#define rADC_CHDR     *(volatile U32 *)(0xFFFD8014) 
#define rADC_CHSR     *(volatile U32 *)(0xFFFD8018) 
#define rADC_SR       *(volatile U32 *)(0xFFFD801C) 
#define rADC_LCDR     *(volatile U32 *)(0xFFFD8020) 
#define rADC_IER      *(volatile U32 *)(0xFFFD8024) 
#define rADC_IDR      *(volatile U32 *)(0xFFFD8028) 
#define rADC_IMR      *(volatile U32 *)(0xFFFD802C) 
#define rADC_CDR0     *(volatile U32 *)(0xFFFD8030) 
#define rADC_CDR1     *(volatile U32 *)(0xFFFD8034) 
#define rADC_CDR2     *(volatile U32 *)(0xFFFD8038) 
#define rADC_CDR3     *(volatile U32 *)(0xFFFD803C) 
#define rADC_CDR4     *(volatile U32 *)(0xFFFD8040) 
#define rADC_CDR5     *(volatile U32 *)(0xFFFD8044) 
#define rADC_CDR6     *(volatile U32 *)(0xFFFD8048) 
#define rADC_CDR7     *(volatile U32 *)(0xFFFD804C) 

// Peripheral Serial Peripheral Interface
#define rSPI_CR	      *(volatile U32 *)(0xFFFE0000)		//
#define rSPI_MR	      *(volatile U32 *)(0xFFFE0004) 	//
#define rSPI_RDR      *(volatile U32 *)(0xFFFE0008)		//
#define rSPI_TDR      *(volatile U32 *)(0xFFFE000C) 	//
#define rSPI_SR	      *(volatile U32 *)(0xFFFE0010)		//
#define rSPI_IER      *(volatile U32 *)(0xFFFE0014)		//
#define rSPI_IDR      *(volatile U32 *)(0xFFFE0018)		//
#define rSPI_IMR      *(volatile U32 *)(0xFFFE001C)		//
#define rSPI_CSR0     *(volatile U32 *)(0xFFFE0030)		//
#define rSPI_CSR1     *(volatile U32 *)(0xFFFE0034)		//
#define rSPI_CSR2     *(volatile U32 *)(0xFFFE0038)		//
#define rSPI_CSR3     *(volatile U32 *)(0xFFFE003C)		//


// System Advanced Interrupt Controller
#define rAIC_SMR0     *(volatile U32 *)(0xFFFFF000)
#define rAIC_SMR1     *(volatile U32 *)(0xFFFFF004)
#define rAIC_SMR2     *(volatile U32 *)(0xFFFFF008)
#define rAIC_SMR3     *(volatile U32 *)(0xFFFFF00C)
#define rAIC_SMR4     *(volatile U32 *)(0xFFFFF010)
#define rAIC_SMR5     *(volatile U32 *)(0xFFFFF014)
#define rAIC_SMR6     *(volatile U32 *)(0xFFFFF018)
#define rAIC_SMR7     *(volatile U32 *)(0xFFFFF01C)
#define rAIC_SMR8     *(volatile U32 *)(0xFFFFF020)
#define rAIC_SMR9     *(volatile U32 *)(0xFFFFF024)
#define rAIC_SMR10    *(volatile U32 *)(0xFFFFF028)
#define rAIC_SMR11    *(volatile U32 *)(0xFFFFF02C)
#define rAIC_SMR12    *(volatile U32 *)(0xFFFFF030)
#define rAIC_SMR13    *(volatile U32 *)(0xFFFFF034)
#define rAIC_SMR14    *(volatile U32 *)(0xFFFFF038)
#define rAIC_SMR15    *(volatile U32 *)(0xFFFFF03C)
#define rAIC_SMR16    *(volatile U32 *)(0xFFFFF040)
#define rAIC_SMR17    *(volatile U32 *)(0xFFFFF044)
#define rAIC_SMR18    *(volatile U32 *)(0xFFFFF048)
#define rAIC_SMR19    *(volatile U32 *)(0xFFFFF04C)
#define rAIC_SMR20    *(volatile U32 *)(0xFFFFF050)
#define rAIC_SMR21    *(volatile U32 *)(0xFFFFF054)
#define rAIC_SMR22    *(volatile U32 *)(0xFFFFF058)
#define rAIC_SMR23    *(volatile U32 *)(0xFFFFF05C)
#define rAIC_SMR24    *(volatile U32 *)(0xFFFFF060)
#define rAIC_SMR25    *(volatile U32 *)(0xFFFFF064)
#define rAIC_SMR26    *(volatile U32 *)(0xFFFFF068)
#define rAIC_SMR27    *(volatile U32 *)(0xFFFFF06C)
#define rAIC_SMR28    *(volatile U32 *)(0xFFFFF070)
#define rAIC_SMR29    *(volatile U32 *)(0xFFFFF074)
#define rAIC_SMR30    *(volatile U32 *)(0xFFFFF078)
#define rAIC_SMR31    *(volatile U32 *)(0xFFFFF07C)
#define rAIC_SVR0     *(volatile U32 *)(0xFFFFF080)
#define rAIC_SVR1     *(volatile U32 *)(0xFFFFF084)
#define rAIC_SVR2     *(volatile U32 *)(0xFFFFF088)
#define rAIC_SVR3     *(volatile U32 *)(0xFFFFF08C)
#define rAIC_SVR4     *(volatile U32 *)(0xFFFFF090)
#define rAIC_SVR5     *(volatile U32 *)(0xFFFFF094)
#define rAIC_SVR6     *(volatile U32 *)(0xFFFFF098)
#define rAIC_SVR7     *(volatile U32 *)(0xFFFFF09C)
#define rAIC_SVR8     *(volatile U32 *)(0xFFFFF0A0)
#define rAIC_SVR9     *(volatile U32 *)(0xFFFFF0A4)
#define rAIC_SVR10    *(volatile U32 *)(0xFFFFF0A8)
#define rAIC_SVR11    *(volatile U32 *)(0xFFFFF0AC)
#define rAIC_SVR12    *(volatile U32 *)(0xFFFFF0B0)
#define rAIC_SVR13    *(volatile U32 *)(0xFFFFF0B4)
#define rAIC_SVR14    *(volatile U32 *)(0xFFFFF0B8)
#define rAIC_SVR15    *(volatile U32 *)(0xFFFFF0BC)
#define rAIC_SVR16    *(volatile U32 *)(0xFFFFF0C0)
#define rAIC_SVR17    *(volatile U32 *)(0xFFFFF0C4)
#define rAIC_SVR18    *(volatile U32 *)(0xFFFFF0C8)
#define rAIC_SVR19    *(volatile U32 *)(0xFFFFF0CC)
#define rAIC_SVR20    *(volatile U32 *)(0xFFFFF0D0)
#define rAIC_SVR21    *(volatile U32 *)(0xFFFFF0D4)
#define rAIC_SVR22    *(volatile U32 *)(0xFFFFF0D8)
#define rAIC_SVR23    *(volatile U32 *)(0xFFFFF0DC)
#define rAIC_SVR24    *(volatile U32 *)(0xFFFFF0E0)
#define rAIC_SVR25    *(volatile U32 *)(0xFFFFF0E4)
#define rAIC_SVR26    *(volatile U32 *)(0xFFFFF0E8)
#define rAIC_SVR27    *(volatile U32 *)(0xFFFFF0EC)
#define rAIC_SVR28    *(volatile U32 *)(0xFFFFF0F0)
#define rAIC_SVR29    *(volatile U32 *)(0xFFFFF0F4)
#define rAIC_SVR30    *(volatile U32 *)(0xFFFFF0F8)
#define rAIC_SVR31    *(volatile U32 *)(0xFFFFF0FC)
#define rAIC_IVR      *(volatile U32 *)(0xFFFFF100)
#define rAIC_FVR      *(volatile U32 *)(0xFFFFF104)
#define rAIC_ISR      *(volatile U32 *)(0xFFFFF108)
#define rAIC_IPR      *(volatile U32 *)(0xFFFFF10C)
#define rAIC_IMR      *(volatile U32 *)(0xFFFFF110)
#define rAIC_CISR     *(volatile U32 *)(0xFFFFF114)
#define rAIC_IECR     *(volatile U32 *)(0xFFFFF120)
#define rAIC_IDCR     *(volatile U32 *)(0xFFFFF124)
#define rAIC_ICCR     *(volatile U32 *)(0xFFFFF128)
#define rAIC_ISCR     *(volatile U32 *)(0xFFFFF12C)
#define rAIC_EOICR    *(volatile U32 *)(0xFFFFF130)
#define rAIC_SPU      *(volatile U32 *)(0xFFFFF134)
#define rAIC_DCR      *(volatile U32 *)(0xFFFFF138)
#define rAIC_FFER     *(volatile U32 *)(0xFFFFF140)
#define rAIC_FFDR     *(volatile U32 *)(0xFFFFF144)
#define rAIC_FFSR     *(volatile U32 *)(0xFFFFF148)

// System Debug Unit
#define rDBGU_CR	    *(volatile U32 *)(0xFFFFF200)		// DBGU Control Register
#define rDBGU_MR	    *(volatile U32 *)(0xFFFFF204)		// DBGU Mode Register
#define rDBGU_IER	    *(volatile U32 *)(0xFFFFF208)		// DBGU Interrupt Enable Register
#define rDBGU_IDR	    *(volatile U32 *)(0xFFFFF20C)		// DBGU Interrupt Disable Register
#define rDBGU_IMR	    *(volatile U32 *)(0xFFFFF210)		// DBGU Interrupt Mask Register
#define rDBGU_SR	    *(volatile U32 *)(0xFFFFF214)		// DBGU Interrupt Status Register
#define rDBGU_RHR	    *(volatile U32 *)(0xFFFFF218)		// DBGU Receive Holding Register
#define rDBGU_THR	    *(volatile U32 *)(0xFFFFF21C)		// DBGU Transmit Holding Register
#define rDBGU_BRGR	  *(volatile U32 *)(0xFFFFF220)		// DBGU Baudrate Generator Register
#define rDBGU_CIDR	  *(volatile U32 *)(0xFFFFF240)		// Chip ID Register
#define rDBGU_EXID	  *(volatile U32 *)(0xFFFFF244)		// Chip ID Extension Register
#define rDBGU_FNR	    *(volatile U32 *)(0xFFFFF248)		// Force NTRST Register

// System PIO Controller A
#define rPIO_PER_A	    *(volatile U32 *)(0xFFFFF400)
#define rPIO_PDR_A	    *(volatile U32 *)(0xFFFFF404)	
#define rPIO_PSR_A	    *(volatile U32 *)(0xFFFFF408)	

#define rPIO_OER_A	    *(volatile U32 *)(0xFFFFF410)	 
#define rPIO_ODR_A	    *(volatile U32 *)(0xFFFFF414)	
#define rPIO_OSR_A	    *(volatile U32 *)(0xFFFFF418)

#define rPIO_IFER_A	    *(volatile U32 *)(0xFFFFF420)	
#define rPIO_IFDR_A	    *(volatile U32 *)(0xFFFFF424)	
#define rPIO_IFSR_A	    *(volatile U32 *)(0xFFFFF428)	

#define rPIO_SODR_A	    *(volatile U32 *)(0xFFFFF430)	 
#define rPIO_CODR_A	    *(volatile U32 *)(0xFFFFF434)	
#define rPIO_ODSR_A   	*(volatile U32 *)(0xFFFFF438)	

#define rPIO_PDSR_A     *(volatile U32 *)(0xFFFFF43C)
#define rPIO_IER_A      *(volatile U32 *)(0xFFFFF440)
#define rPIO_IDR_A      *(volatile U32 *)(0xFFFFF444)

#define rPIO_IMR_A      *(volatile U32 *)(0xFFFFF448)
#define rPIO_ISR_A      *(volatile U32 *)(0xFFFFF44C)

#define rPIO_MDER_A     *(volatile U32 *)(0xFFFFF450)
#define rPIO_MDDR_A     *(volatile U32 *)(0xFFFFF454)
#define rPIO_MDSR_A     *(volatile U32 *)(0xFFFFF458)

#define rPIO_PUDR_A     *(volatile U32 *)(0xFFFFF460)
#define rPIO_PUER_A     *(volatile U32 *)(0xFFFFF464)
#define rPIO_PUSR_A     *(volatile U32 *)(0xFFFFF468)

#define rPIO_ASR_A      *(volatile U32 *)(0xFFFFF470)
#define rPIO_BSR_A      *(volatile U32 *)(0xFFFFF474)
#define rPIO_ABSR_A     *(volatile U32 *)(0xFFFFF478)

#define rPIO_OWER_A     *(volatile U32 *)(0xFFFFF4A0)
#define rPIO_OWDR_A     *(volatile U32 *)(0xFFFFF4A4)
#define rPIO_OWSR_A     *(volatile U32 *)(0xFFFFF4A8)

// System PIO Controller B
#define rPIO_PER_B	    *(volatile U32 *)(0xFFFFF600)
#define rPIO_PDR_B	    *(volatile U32 *)(0xFFFFF604)	
#define rPIO_PSR_B	    *(volatile U32 *)(0xFFFFF608)	

#define rPIO_OER_B	    *(volatile U32 *)(0xFFFFF610)	 
#define rPIO_ODR_B	    *(volatile U32 *)(0xFFFFF614)	
#define rPIO_OSR_B	    *(volatile U32 *)(0xFFFFF618)

#define rPIO_IFER_B	    *(volatile U32 *)(0xFFFFF620)	
#define rPIO_IFDR_B	    *(volatile U32 *)(0xFFFFF624)	
#define rPIO_IFSR_B	    *(volatile U32 *)(0xFFFFF628)	

#define rPIO_SODR_B	    *(volatile U32 *)(0xFFFFF630)	 
#define rPIO_CODR_B	    *(volatile U32 *)(0xFFFFF634)	
#define rPIO_ODSR_B   	*(volatile U32 *)(0xFFFFF638)	

#define rPIO_PDSR_B     *(volatile U32 *)(0xFFFFF63C)
#define rPIO_IER_B      *(volatile U32 *)(0xFFFFF640)
#define rPIO_IDR_B      *(volatile U32 *)(0xFFFFF644)

#define rPIO_IMR_B      *(volatile U32 *)(0xFFFFF648)
#define rPIO_ISR_B      *(volatile U32 *)(0xFFFFF64C)

#define rPIO_MDER_B     *(volatile U32 *)(0xFFFFF650)
#define rPIO_MDDR_B     *(volatile U32 *)(0xFFFFF654)
#define rPIO_MDSR_B     *(volatile U32 *)(0xFFFFF658)

#define rPIO_PUDR_B     *(volatile U32 *)(0xFFFFF660)
#define rPIO_PUER_B     *(volatile U32 *)(0xFFFFF664)
#define rPIO_PUSR_B     *(volatile U32 *)(0xFFFFF668)

#define rPIO_ASR_B      *(volatile U32 *)(0xFFFFF670)
#define rPIO_BSR_B      *(volatile U32 *)(0xFFFFF674)
#define rPIO_ABSR_B     *(volatile U32 *)(0xFFFFF678)

#define rPIO_OWER_B     *(volatile U32 *)(0xFFFFF6A0)
#define rPIO_OWDR_B     *(volatile U32 *)(0xFFFFF6A4)
#define rPIO_OWSR_B     *(volatile U32 *)(0xFFFFF6A8)

// System Power Management Controller
#define rPMC_SCER	    *(volatile U32 *)(0xFFFFFC00)	  // PMC System Clock Enable Register
#define rPMC_SCDR	    *(volatile U32 *)(0xFFFFFC04)	  // PMC System Clock Disable Register
#define rPMC_SCSR	    *(volatile U32 *)(0xFFFFFC08)	  // PMC System Clock Status Register
#define rPMC_PCER	    *(volatile U32 *)(0xFFFFFC10)	  // PMC Peripheral Clock Enable Register
#define rPMC_PCDR	    *(volatile U32 *)(0xFFFFFC14)	  // PMC Peripheral Clock Disable Register
#define rPMC_PCSR	    *(volatile U32 *)(0xFFFFFC18)	  // PMC Peripheral Clock Status Register
#define rCKGR_MOR	    *(volatile U32 *)(0xFFFFFC20)	  // Main Oscillator Register
#define rCKGR_MCFR    *(volatile U32 *)(0xFFFFFC24)	  // Main Clock Frequency Register
#define rCKGR_PLLR	  *(volatile U32 *)(0xFFFFFC2C)	  // PLL Register
#define rPMC_MCKR		  *(volatile U32 *)(0xFFFFFC30)	  // Master Clock Register
#define rPMC_PCK0		  *(volatile U32 *)(0xFFFFFC40)	  // Programmble Clock 0 Register
#define rPMC_PCK1		  *(volatile U32 *)(0xFFFFFC44)	  // Programmble Clock 1 Register
#define rPMC_IER		  *(volatile U32 *)(0xFFFFFC60)	  // Interrupt Enable Register
#define rPMC_IDR		  *(volatile U32 *)(0xFFFFFC64)	  // Interrupt Disable Register
#define rPMC_SR		    *(volatile U32 *)(0xFFFFFC68)	  // Status Register
#define rPMC_IMR	  	*(volatile U32 *)(0xFFFFFC6C)	  // Interrupt Mask Register

// System Reset Controller
#define rRSTC_CR	  	*(volatile U32 *)(0xFFFFFD00)
#define rRSTC_SR	  	*(volatile U32 *)(0xFFFFFD04)
#define rRSTC_MR	  	*(volatile U32 *)(0xFFFFFD08)

// System Real-time Timer
#define rRTT_MR	  	  *(volatile U32 *)(0xFFFFFD20)
#define rRTT_AR	  	  *(volatile U32 *)(0xFFFFFD24)
#define rRTT_VR	  	  *(volatile U32 *)(0xFFFFFD28)
#define rRTT_SR	  	  *(volatile U32 *)(0xFFFFFD2C)

// System Periodic Interval Timer
#define rPIT_MR	      *(volatile U32 *)(0xFFFFFD30)		// PIT Mode Register
#define rPIT_SR	      *(volatile U32 *)(0xFFFFFD34)		// PIT Status Register
#define rPIT_PIVR	    *(volatile U32 *)(0xFFFFFD38)		// PIT Periodic Interval Value Register
#define rPIT_PIIR	    *(volatile U32 *)(0xFFFFFD3C)		// PIT Periodic Interval Image register

// System Watchdog Timer
#define rWDT_CR	      *(volatile U32 *)(0xFFFFFD40)		// WDT Control Register
#define rWDT_MR	      *(volatile U32 *)(0xFFFFFD44)		// WDT Mode Register
#define rWDT_SR	      *(volatile U32 *)(0xFFFFFD48)		// WDT Status register

// System Voltage Regulator Mode Controller
#define rVREG_MR	    *(volatile U32 *)(0xFFFFFD60)	

// System Memory Controller
#define rMC_RCR	      *(volatile U32 *)(0xFFFFFF00)		// MC Remap Control Register
#define rMC_ASR	      *(volatile U32 *)(0xFFFFFF04)		// MC Abort Status Register
#define rMC_AASR	    *(volatile U32 *)(0xFFFFFF08)		// MC Abort Address Status Register
#define rMC_FMR	      *(volatile U32 *)(0xFFFFFF60)		// MC Flash Mode Register
#define rMC_FCR	      *(volatile U32 *)(0xFFFFFF64)		// MC Flash Command Register
#define rMC_FSR	      *(volatile U32 *)(0xFFFFFF68)		// MC Flash Status register



