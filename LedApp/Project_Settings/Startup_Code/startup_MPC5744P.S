/* ---------------------------------------------------------------------------------------*/
/*  @file:    startup_MPC5744P.S                                                          */
/*  @purpose: GNU Compiler Collection Startup File                                        */
/*            MPC5744P                                                                    */
/*  @version: 1.0                                                                         */
/*  @date:    2017-2-9                                                                    */
/*  @build:   #                                                                           */
/* ---------------------------------------------------------------------------------------*/
/*                                                                                        */
/* Copyright 2017-2019 NXP                                                                */
/* All rights reserved.                                                                   */
/*                                                                                        */
/* THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR                          */
/* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES              */
/* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.                */
/* IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,                    */
/* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES                     */
/* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR                     */
/* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)                     */
/* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,                    */
/* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING                  */
/* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF                         */
/* THE POSSIBILITY OF SUCH DAMAGE.                                                        */
/*****************************************************************************/
/* Version: GNU Compiler Collection                                          */

/* ----------------------------------------------------------------------------
   -- Boot header configuration
   ---------------------------------------------------------------------------- */
#define MPC57xx_ID    0x005A0000
#define RCHW_VAL MPC57xx_ID

#ifndef ICACHE_ENABLE
#define ICACHE_ENABLE 0
#endif
#ifndef DCACHE_ENABLE
#define DCACHE_ENABLE 0
#endif

#ifndef DISABLE_WDOG
#define DISABLE_WDOG  1
#endif
#ifndef SWT_COUNT
#define SWT_COUNT     1
#endif
#ifndef SWT_BASE_ADDR
#define SWT_BASE_ADDR   0xFC050000
#endif

/* Init table */
    .section .init_table, "a"
    .long 5
    .long __VECTOR_TABLE
    .long __VECTOR_RAM
    .long __VECTOR_TABLE_COPY_END
    .long __CUSTOM_ROM
    .long __CUSTOM_RAM
    .long __CUSTOM_END
    .long __DATA_ROM
    .long __DATA_RAM
    .long __DATA_END
    .long __SDATA_ROM
    .long __SDATA_RAM
    .long __SDATA_END
    .long __CODE_ROM
    .long __CODE_RAM
    .long __CODE_END
/* Zero table */
    .section .zero_table, "a"
    .long 2
    .long __SBSS_START
    .long __SBSS_END
    .long __BSS_START
    .long __BSS_END

    .section .cpu0_reset_vector, "a"
    .long       __start

    .section .rchw, "a"
        .long RCHW_VAL

    .section .startup, "ax"

    .globl    _start
    .globl    Reset_Handler

Reset_Handler:
_start:
    wrteei 0    ;# Disable interrupts


;#**************************** Init Core Registers ****************************
;# The E200Z4 core needs its registers initialising before they are used
;# otherwise in Lock Step mode the two cores will contain different random data.
;# If this is stored to memory (e.g. stacked) it will cause a Lock Step error.

;# GPRs 0-31
    e_li    r0, 0
    e_li    r1, 0
    e_li    r2, 0
    e_li    r3, 0
    e_li    r4, 0
    e_li    r5, 0
    e_li    r6, 0
    e_li    r7, 0
    e_li    r8, 0
    e_li    r9, 0
    e_li    r10, 0
    e_li    r11, 0
    e_li    r12, 0
    e_li    r13, 0
    e_li    r14, 0
    e_li    r15, 0
    e_li    r16, 0
    e_li    r17, 0
    e_li    r18, 0
    e_li    r19, 0
    e_li    r20, 0
    e_li    r21, 0
    e_li    r22, 0
    e_li    r23, 0
    e_li    r24, 0
    e_li    r25, 0
    e_li    r26, 0
    e_li    r27, 0
    e_li    r28, 0
    e_li    r29, 0
    e_li    r30, 0
    e_li    r31, 0

;# Init any other CPU register which might be stacked (before being used).

    mtspr    1, r1          ;#XER
    mtcrf    0xFF, r1
    mtspr    CTR, r1
    mtspr    272, r1        ;#SPRG0
    mtspr    273, r1        ;#SPRG1
    mtspr    274, r1        ;#SPRG2
    mtspr    275, r1        ;#SPRG3
    mtspr    58, r1         ;#CSRR0
    mtspr    59, r1         ;#CSRR1
    mtspr    570, r1        ;#MCSRR0
    mtspr    571, r1        ;#MCSRR1
    mtspr    61, r1         ;#DEAR
    mtspr    63, r1         ;#IVPR
#    mtspr    256, r1        ;#USPRG0
    mtspr    62, r1         ;#ESR
    mtspr    8, r31          ;#LR

;#***************************** DISABLE WATCHDOG *****************************
#if DISABLE_WDOG
    e_lis   r4, SWT_BASE_ADDR@h   ;# Initialize the base address of SWT_0
    e_or2i  r4, SWT_BASE_ADDR@l

    e_li    r5, SWT_COUNT@l
    mtctr   r5                    ;# Move to counter number of SWT instances

disable_swt:
    e_li    r3, 0xC520
    e_stw   r3, 0x10(r4)          ;# Write the watchdog unlock value 0xc520

    e_li    r3, 0xD928
    e_stw   r3, 0x10(r4)          ;# Write the watchdog unlock value 0xD928

    e_lis   r3, 0xFF00
    e_or2i  r3, 0x0102
    e_stw   r3, 0(r4)             

    e_addi  r4,r4, 0x4000         ;# Increase the pointer to the next instance of SWT
    e_bdnz  disable_swt           ;# Loop for all instance of SWT
#endif

;#***************************** Initialise SRAM ECC **************************
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lis       r5, __SRAM_SIZE@h  # Initialize r5 to size of SRAM (Bytes)
    e_or2i      r5, __SRAM_SIZE@l
    e_srwi      r5, r5, 0x7         ;# Divide SRAM size by 128
    mtctr       r5                  ;# Move to counter for use with "bdnz"

;# Base Address of the internal SRAM
    e_lis       r5, __SRAM_BASE_ADDR@h
    e_or2i      r5, __SRAM_BASE_ADDR@l

;# Fill SRAM with writes of 32GPRs
sram_loop:
    e_stmw      r0, 0(r5)           ;# Write all 32 registers to SRAM
    e_addi      r5, r5, 128         ;# Increment the RAM pointer to next 128bytes
    e_bdnz      sram_loop           ;# Loop for all of SRAM

;#************************ Initialise Local Data SRAM ECC *********************
;# Store number of 128Byte (32GPRs) segments in Counter
 e_lis       r5, __LOCAL_DMEM_SIZE@h  ;#Initialize r5 to size of SRAM (Bytes)
 e_or2i      r5, __LOCAL_DMEM_SIZE@l
 e_srwi      r5, r5, 0x7            ;#Divide SRAM size by 128
 mtctr       r5                     ;#Move to counter for use with "bdnz"

;# Base Address of the Local SRAM
 e_lis       r5, __LOCAL_DMEM_BASE_ADDR@h
 e_or2i      r5, __LOCAL_DMEM_BASE_ADDR@l
;# Fill Local SRAM with writes of 32GPRs
ldmem_loop:
    e_stmw      r0,0(r5)             ;# Write all 32 registers to SRAM
    e_addi      r5,r5,128            ;#Increment the RAM pointer to next 128bytes
    e_bdnz      ldmem_loop           ;# Loop for all of SRAM

;#********************************* Enable BTB ********************************
;# Flush & Enable BTB - Set BBFI bit in BUCSR
    e_li      r3, 0x201
    mtspr     1013, r3
    se_isync

;#******************** Clear reservations on external interrupt *****************
;# Set ICR in HID0
    e_lis     r3, 0x2
    mtspr     1008, r3
    se_isync

;#*************************** Enable ME Bit in MSR *****************************
    mfmsr    r6
    e_or2i   r6, 0x1000
    mtmsr    r6

#if defined(I_CACHE) && (ICACHE_ENABLE == 1)
;#****************** Invalidate and Enable the Instruction cache **************
__icache_cfg:
    e_li     r5, 0x2
    mtspr    1011, r5

    e_li     r7, 0x4
    e_li     r8, 0x2
    e_lis    r11, 0xFFFF
    e_or2i   r11, 0xFFFB

__icache_inv:
    mfspr    r9, 1011
    and.     r10, r7, r9
    e_beq    __icache_no_abort
    and.     r10, r11, r9
    mtspr    1011, r10
    e_b      __icache_cfg

__icache_no_abort:
    and.     r10, r8, r9
    e_bne    __icache_inv

    mfspr    r5, 1011
    e_ori    r5, r5, 0x0001
    se_isync
    mtspr    1011, r5
#endif

#if defined(D_CACHE) && (DCACHE_ENABLE == 1)
;#****************** Invalidate and Enable the Data cache **************
__dcache_cfg:
    e_li r5, 0x2
    mtspr 1010, r5

    e_li r7, 0x4
    e_li r8, 0x2
    e_lis    r11, 0xFFFF
    e_or2i   r11, 0xFFFB

__dcache_inv:
    mfspr r9, 1010
    and.  r10, r7, r9
    e_beq   __dcache_no_abort
    and.  r10, r11, r9
    mtspr 1010, r10
    e_b __dcache_cfg

__dcache_no_abort:
    and.  r10, r8, r9
    e_bne __dcache_inv

    mfspr r5, 1010
    e_ori   r5, r5, 0x0001
    se_isync
    msync
    mtspr 1010, r5
#endif


;#****************************** Configure Stack *****************************
    e_lis       r1, __SP_INIT@h         ;# Initialize stack pointer r1 to
    e_or2i      r1, __SP_INIT@l         ;# value in linker command file.

    e_lis       r13, _SDA_BASE_@h       ;# Initialize r13 to sdata base
    e_or2i      r13, _SDA_BASE_@l       ;# (provided by linker).

    e_lis       r2, _SDA2_BASE_@h       ;# Initialize r2 to sdata2 base
    e_or2i      r2, _SDA2_BASE_@l       ;# (provided by linker).

    e_stwu      r0, -64(r1)             ;# Terminate stack.

#ifndef __NO_SYSTEM_INIT
;# Call the system init routine
    e_bl   SystemInit
#endif
;# Init .data and .bss sections
    e_bl   init_data_bss
    wrteei 1    ;# Enable interrupts
;# Call custom init function
;# This symbol must be defined in the ASM preprocessor e.g -DCUSTOM_INIT=my_func, 
;# where my_func is a void function that does not take any parameters and it is defined in the application code
#ifdef CUSTOM_INIT
    e_bl CUSTOM_INIT
#endif

;# Jump to Main
    e_bl        main

    .section .intc_vector_table, "a"
    .align 2
    .globl __isr_vector
__isr_vector:
    .long   DefaultISR                       /* Vector #   0 Software setable flag 0 SSCIR0[CLR0] */
    .long   DefaultISR                       /* Vector #   1 Software setable flag 1 SSCIR0[CLR1] */
    .long   DefaultISR                       /* Vector #   2 Software setable flag 2 SSCIR0[CLR2] */
    .long   DefaultISR                       /* Vector #   3 Software setable flag 3 SSCIR0[CLR3] */
    .long   DefaultISR                       /* Vector #   4 Software setable flag 4 SSCIR0[CLR4] */
    .long   DefaultISR                       /* Vector #   5 Software setable flag 5 SSCIR0[CLR5] */
    .long   DefaultISR                       /* Vector #   6 Software setable flag 6 SSCIR0[CLR6] */
    .long   DefaultISR                       /* Vector #   7 Software setable flag 7 SSCIR0[CLR7] */
    .long   DefaultISR                       /* Vector #   8 Software setable flag 8 SSCIR0[CLR8] */
    .long   DefaultISR                       /* Vector #   9 Software setable flag 9 SSCIR0[CLR9] */
    .long   DefaultISR                       /* Vector #  10 Software setable flag 10 SSCIR0[CLR10] */
    .long   DefaultISR                       /* Vector #  11 Software setable flag 11 SSCIR0[CLR11] */
    .long   DefaultISR                       /* Vector #  12 Software setable flag 12 SSCIR0[CLR12] */
    .long   DefaultISR                       /* Vector #  13 Software setable flag 13 SSCIR0[CLR13] */
    .long   DefaultISR                       /* Vector #  14 Software setable flag 14 SSCIR0[CLR14] */
    .long   DefaultISR                       /* Vector #  15 Software setable flag 15 SSCIR0[CLR15] */
    .long   DefaultISR                       /* Vector #  16 */
    .long   DefaultISR                       /* Vector #  17 */
    .long   DefaultISR                       /* Vector #  18 */
    .long   DefaultISR                       /* Vector #  19 */
    .long   DefaultISR                       /* Vector #  20 */
    .long   DefaultISR                       /* Vector #  21 */
    .long   DefaultISR                       /* Vector #  22 */
    .long   DefaultISR                       /* Vector #  23 */
    .long   DefaultISR                       /* Vector #  24 */
    .long   DefaultISR                       /* Vector #  25 */
    .long   DefaultISR                       /* Vector #  26 */
    .long   DefaultISR                       /* Vector #  27 */
    .long   DefaultISR                       /* Vector #  28 */
    .long   DefaultISR                       /* Vector #  29 */
    .long   DefaultISR                       /* Vector #  30 */
    .long   DefaultISR                       /* Vector #  31 */
    .long   SWT0_IRQHandler                  /* Vector #  32 */
    .long   DefaultISR                       /* Vector #  33 */
    .long   DefaultISR                       /* Vector #  34 */
    .long   DefaultISR                       /* Vector #  35 */
    .long   STM0_Ch0_IRQHandler              /* Vector #  36 On-Platform periodic timer 0_0 (STM) STM_0_CIR0[CIF] */
    .long   STM0_Ch1_IRQHandler              /* Vector #  37 On-Platform periodic timer 0_1 (STM) STM_0_CIR1[CIF] */
    .long   STM0_Ch2_IRQHandler              /* Vector #  38 On-Platform periodic timer 0_2 (STM) STM_0_CIR2[CIF] */
    .long   STM0_Ch3_IRQHandler              /* Vector #  39 On-Platform periodic timer 0_3 (STM) STM_0_CIR3[CIF] */
    .long   DefaultISR                       /* Vector #  40 */
    .long   DefaultISR                       /* Vector #  41 */
    .long   DefaultISR                       /* Vector #  42 */
    .long   DefaultISR                       /* Vector #  43 */
    .long   DefaultISR                       /* Vector #  44 */
    .long   DefaultISR                       /* Vector #  45 */
    .long   DefaultISR                       /* Vector #  46 */
    .long   DefaultISR                       /* Vector #  47 */
    .long   DefaultISR                       /* Vector #  48 */
    .long   DefaultISR                       /* Vector #  49 */
    .long   DefaultISR                       /* Vector #  50 */
    .long   DefaultISR                       /* Vector #  51 */
    .long   DMA0_Ch0_Ch31_Error_IRQHandler   /* Vector #  52 eDMA0 Combined Error eDMA0 Channel Error Flags 0-31 */
    .long   DMA0_Ch0_IRQHandler              /* Vector #  53 eDMA0 Channel 0 DMA_INTL[INT0] */
    .long   DMA0_Ch1_IRQHandler              /* Vector #  54 eDMA0 Channel 1 DMA_INTL[INT1] */
    .long   DMA0_Ch2_IRQHandler              /* Vector #  55 eDMA0 Channel 2 DMA_INTL[INT2] */
    .long   DMA0_Ch3_IRQHandler              /* Vector #  56 eDMA0 Channel 3 DMA_INTL[INT3] */
    .long   DMA0_Ch4_IRQHandler              /* Vector #  57 eDMA0 Channel 4 DMA_INTL[INT4] */
    .long   DMA0_Ch5_IRQHandler              /* Vector #  58 eDMA0 Channel 5 DMA_INTL[INT5] */
    .long   DMA0_Ch6_IRQHandler              /* Vector #  59 eDMA0 Channel 6 DMA_INTL[INT6] */
    .long   DMA0_Ch7_IRQHandler              /* Vector #  60 eDMA0 Channel 7 DMA_INTL[INT7] */
    .long   DMA0_Ch8_IRQHandler              /* Vector #  61 eDMA0 Channel 8 DMA_INTL[INT8] */
    .long   DMA0_Ch9_IRQHandler              /* Vector #  62 eDMA0 Channel 9 DMA_INTL[INT9] */
    .long   DMA0_Ch10_IRQHandler             /* Vector #  63 eDMA0 Channel 10 DMA_INTL[INT10] */
    .long   DMA0_Ch11_IRQHandler             /* Vector #  64 eDMA0 Channel 11 DMA_INTL[INT11] */
    .long   DMA0_Ch12_IRQHandler             /* Vector #  65 eDMA0 Channel 12 DMA_INTL[INT12] */
    .long   DMA0_Ch13_IRQHandler             /* Vector #  66 eDMA0 Channel 13 DMA_INTL[INT13] */
    .long   DMA0_Ch14_IRQHandler             /* Vector #  67 eDMA0 Channel 14 DMA_INTL[INT14] */
    .long   DMA0_Ch15_IRQHandler             /* Vector #  67 eDMA0 Channel 15 DMA_INTL[INT15] */
    .long   DMA0_Ch16_IRQHandler             /* Vector #  69 eDMA0 Channel 16 DMA_INTL[INT16] */
    .long   DMA0_Ch17_IRQHandler             /* Vector #  70 eDMA0 Channel 17 DMA_INTL[INT17] */
    .long   DMA0_Ch18_IRQHandler             /* Vector #  71 eDMA0 Channel 18 DMA_INTL[INT18] */
    .long   DMA0_Ch19_IRQHandler             /* Vector #  72 eDMA0 Channel 19 DMA_INTL[INT19] */
    .long   DMA0_Ch20_IRQHandler             /* Vector #  73 eDMA0 Channel 20 DMA_INTL[INT20] */
    .long   DMA0_Ch21_IRQHandler             /* Vector #  74 eDMA0 Channel 21 DMA_INTL[INT21] */
    .long   DMA0_Ch22_IRQHandler             /* Vector #  75 eDMA0 Channel 22 DMA_INTL[INT22] */
    .long   DMA0_Ch23_IRQHandler             /* Vector #  76 eDMA0 Channel 23 DMA_INTL[INT23] */
    .long   DMA0_Ch24_IRQHandler             /* Vector #  77 eDMA0 Channel 24 DMA_INTL[INT24] */
    .long   DMA0_Ch25_IRQHandler             /* Vector #  78 eDMA0 Channel 25 DMA_INTL[INT25] */
    .long   DMA0_Ch26_IRQHandler             /* Vector #  79 eDMA0 Channel 26 DMA_INTL[INT26] */
    .long   DMA0_Ch27_IRQHandler             /* Vector #  80 eDMA0 Channel 27 DMA_INTL[INT27] */
    .long   DMA0_Ch28_IRQHandler             /* Vector #  81 eDMA0 Channel 28 DMA_INTL[INT28] */
    .long   DMA0_Ch29_IRQHandler             /* Vector #  82 eDMA0 Channel 29 DMA_INTL[INT29] */
    .long   DMA0_Ch30_IRQHandler             /* Vector #  83 eDMA0 Channel 30 DMA_INTL[INT30] */
    .long   DMA0_Ch31_IRQHandler             /* Vector #  84 eDMA0 Channel 31 DMA_INTL[INT31] */
    .long   DefaultISR                       /* Vector #  85 */
    .long   DefaultISR                       /* Vector #  86 */
    .long   DefaultISR                       /* Vector #  87 */
    .long   DefaultISR                       /* Vector #  88 */
    .long   DefaultISR                       /* Vector #  89 */
    .long   DefaultISR                       /* Vector #  90 */
    .long   DefaultISR                       /* Vector #  91 */
    .long   DefaultISR                       /* Vector #  92 */
    .long   DefaultISR                       /* Vector #  93 */
    .long   DefaultISR                       /* Vector #  94 */
    .long   DefaultISR                       /* Vector #  95 */
    .long   DefaultISR                       /* Vector #  96 */
    .long   DefaultISR                       /* Vector #  97 */
    .long   DefaultISR                       /* Vector #  98 */
    .long   DefaultISR                       /* Vector #  99 */
    .long   DefaultISR                       /* Vector # 100 */
    .long   DefaultISR                       /* Vector # 101 */
    .long   DefaultISR                       /* Vector # 102 */
    .long   DefaultISR                       /* Vector # 103 */
    .long   DefaultISR                       /* Vector # 104 */
    .long   DefaultISR                       /* Vector # 105 */
    .long   DefaultISR                       /* Vector # 106 */
    .long   DefaultISR                       /* Vector # 107 */
    .long   DefaultISR                       /* Vector # 108 */
    .long   DefaultISR                       /* Vector # 109 */
    .long   DefaultISR                       /* Vector # 110 */
    .long   DefaultISR                       /* Vector # 111 */
    .long   DefaultISR                       /* Vector # 112 */
    .long   DefaultISR                       /* Vector # 113 */
    .long   DefaultISR                       /* Vector # 114 */
    .long   DefaultISR                       /* Vector # 115 */
    .long   DefaultISR                       /* Vector # 116 */
    .long   DefaultISR                       /* Vector # 117 */
    .long   DefaultISR                       /* Vector # 118 */
    .long   DefaultISR                       /* Vector # 119 */
    .long   DefaultISR                       /* Vector # 120 */
    .long   DefaultISR                       /* Vector # 121 */
    .long   DefaultISR                       /* Vector # 122 */
    .long   DefaultISR                       /* Vector # 123 */
    .long   DefaultISR                       /* Vector # 124 */
    .long   DefaultISR                       /* Vector # 125 */
    .long   DefaultISR                       /* Vector # 126 */
    .long   DefaultISR                       /* Vector # 127 */
    .long   DefaultISR                       /* Vector # 128 */
    .long   DefaultISR                       /* Vector # 129 */
    .long   DefaultISR                       /* Vector # 130 */
    .long   DefaultISR                       /* Vector # 131 */
    .long   DefaultISR                       /* Vector # 132 */
    .long   DefaultISR                       /* Vector # 133 */
    .long   DefaultISR                       /* Vector # 134 */
    .long   DefaultISR                       /* Vector # 135 */
    .long   DefaultISR                       /* Vector # 136 */
    .long   DefaultISR                       /* Vector # 137 */
    .long   DefaultISR                       /* Vector # 138 */
    .long   DefaultISR                       /* Vector # 139 */
    .long   DefaultISR                       /* Vector # 140 */
    .long   DefaultISR                       /* Vector # 141 */
    .long   DefaultISR                       /* Vector # 142 */
    .long   DefaultISR                       /* Vector # 143 */
    .long   DefaultISR                       /* Vector # 144 */
    .long   DefaultISR                       /* Vector # 145 */
    .long   DefaultISR                       /* Vector # 146 */
    .long   DefaultISR                       /* Vector # 147 */
    .long   DefaultISR                       /* Vector # 148 */
    .long   DefaultISR                       /* Vector # 149 */
    .long   DefaultISR                       /* Vector # 150 */
    .long   DefaultISR                       /* Vector # 151 */
    .long   DefaultISR                       /* Vector # 152 */
    .long   DefaultISR                       /* Vector # 153 */
    .long   DefaultISR                       /* Vector # 154 */
    .long   DefaultISR                       /* Vector # 155 */
    .long   DefaultISR                       /* Vector # 156 */
    .long   DefaultISR                       /* Vector # 157 */
    .long   DefaultISR                       /* Vector # 158 */
    .long   DefaultISR                       /* Vector # 159 */
    .long   DefaultISR                       /* Vector # 160 */
    .long   DefaultISR                       /* Vector # 161 */
    .long   DefaultISR                       /* Vector # 162 */
    .long   DefaultISR                       /* Vector # 163 */
    .long   DefaultISR                       /* Vector # 164 */
    .long   DefaultISR                       /* Vector # 165 */
    .long   DefaultISR                       /* Vector # 166 */
    .long   DefaultISR                       /* Vector # 167 */
    .long   DefaultISR                       /* Vector # 168 */
    .long   DefaultISR                       /* Vector # 169 */
    .long   DefaultISR                       /* Vector # 170 */
    .long   DefaultISR                       /* Vector # 171 */
    .long   DefaultISR                       /* Vector # 172 */
    .long   DefaultISR                       /* Vector # 173 */
    .long   DefaultISR                       /* Vector # 174 */
    .long   DefaultISR                       /* Vector # 175 */
    .long   DefaultISR                       /* Vector # 176 */
    .long   DefaultISR                       /* Vector # 177 */
    .long   DefaultISR                       /* Vector # 178 */
    .long   DefaultISR                       /* Vector # 179 */
    .long   DefaultISR                       /* Vector # 180 */
    .long   DefaultISR                       /* Vector # 181 */
    .long   DefaultISR                       /* Vector # 182 */
    .long   DefaultISR                       /* Vector # 183 */
    .long   DefaultISR                       /* Vector # 184 */
    .long   FLASH_Done_IRQHandler            /* Vector # 185 Flash controller Prog/Erase/Suspend IRQ_0 MCR[DONE] */
    .long   DefaultISR                       /* Vector # 186 */
    .long   DefaultISR                       /* Vector # 187 */
    .long   DefaultISR                       /* Vector # 188 */
    .long   DefaultISR                       /* Vector # 189 */
    .long   DefaultISR                       /* Vector # 190 */
    .long   DefaultISR                       /* Vector # 191 */
    .long   DefaultISR                       /* Vector # 192 */
    .long   DefaultISR                       /* Vector # 193 */
    .long   DefaultISR                       /* Vector # 194 */
    .long   DefaultISR                       /* Vector # 195 */
    .long   DefaultISR                       /* Vector # 196 */
    .long   DefaultISR                       /* Vector # 197 */
    .long   DefaultISR                       /* Vector # 198 */
    .long   DefaultISR                       /* Vector # 199 */
    .long   DefaultISR                       /* Vector # 200 */
    .long   DefaultISR                       /* Vector # 201 */
    .long   DefaultISR                       /* Vector # 202 */
    .long   DefaultISR                       /* Vector # 203 */
    .long   DefaultISR                       /* Vector # 204 */
    .long   DefaultISR                       /* Vector # 205 */
    .long   DefaultISR                       /* Vector # 206 */
    .long   DefaultISR                       /* Vector # 207 */
    .long   DefaultISR                       /* Vector # 208 */
    .long   DefaultISR                       /* Vector # 209 */
    .long   DefaultISR                       /* Vector # 210 */
    .long   DefaultISR                       /* Vector # 211 */
    .long   DefaultISR                       /* Vector # 212 */
    .long   DefaultISR                       /* Vector # 213 */
    .long   DefaultISR                       /* Vector # 214 */
    .long   DefaultISR                       /* Vector # 215 */
    .long   ENET0_Timer_IRQHandler           /* Vector # 216 Timer IRQ Ethernet 0 */
    .long   ENET0_Tx_IRQHandler              /* Vector # 217 TX IRQ Ethernet 0 */
    .long   ENET0_Rx_IRQHandler              /* Vector # 218 RX IRQ Ethernet 0 */
    .long   ENET0_Err_IRQHandler             /* Vector # 219 Error/Generic IRQ1 Ethernet 0 */
    .long   DefaultISR                       /* Vector # 220 */
    .long   DefaultISR                       /* Vector # 221 */
    .long   DefaultISR                       /* Vector # 222 */
    .long   DefaultISR                       /* Vector # 223 */
    .long   DefaultISR                       /* Vector # 224 */
    .long   DefaultISR                       /* Vector # 225 */
    .long   PIT_Ch0_IRQHandler               /* Vector # 226 PIT channel 0 overflow interrupt */
    .long   PIT_Ch1_IRQHandler               /* Vector # 227 PIT channel 1 overflow interrupt */
    .long   PIT_Ch2_IRQHandler               /* Vector # 228 PIT channel 2 overflow interrupt */
    .long   PIT_Ch3_IRQHandler               /* Vector # 229 PIT channel 3 overflow interrupt */
    .long   DefaultISR                       /* Vector # 230 */
    .long   DefaultISR                       /* Vector # 231 */
    .long   DefaultISR                       /* Vector # 232 */
    .long   DefaultISR                       /* Vector # 233 */
    .long   DefaultISR                       /* Vector # 234 */
    .long   DefaultISR                       /* Vector # 235 */
    .long   DefaultISR                       /* Vector # 236 */
    .long   DefaultISR                       /* Vector # 237 */
    .long   DefaultISR                       /* Vector # 238 */
    .long   DefaultISR                       /* Vector # 239 */
    .long   DefaultISR                       /* Vector # 240 */
    .long   DefaultISR                       /* Vector # 241 */
    .long   DefaultISR                       /* Vector # 242 */
    .long   SIUL_EIRQ_00_07_IRQHandler       /* Vector # 243 SIUL EIRQ [0-7] - SIUL Combined External Interrupt */
    .long   SIUL_EIRQ_08_15_IRQHandler       /* Vector # 244 SIUL EIRQ [8-15] - SIUL Combined External Interrupt */
    .long   SIUL_EIRQ_16_23_IRQHandler       /* Vector # 245 SIUL EIRQ [16-23] - SIUL Combined External Interrupt */
    .long   SIUL_EIRQ_24_31_IRQHandler       /* Vector # 246 SIUL EIRQ [24-31] - SIUL Combined External Interrupt */
    .long   DefaultISR                       /* Vector # 247 */
    .long   DefaultISR                       /* Vector # 248 */
    .long   DefaultISR                       /* Vector # 249 */
    .long   DefaultISR                       /* Vector # 250 */
    .long   DefaultISR                       /* Vector # 251 */
    .long   DefaultISR                       /* Vector # 252 */
    .long   DefaultISR                       /* Vector # 253 */
    .long   DefaultISR                       /* Vector # 254 */
    .long   DefaultISR                       /* Vector # 255 */
    .long   DefaultISR                       /* Vector # 256 */
    .long   DefaultISR                       /* Vector # 257 */
    .long   DefaultISR                       /* Vector # 258 */
    .long   DSPI0_FIFO_Error_IRQHandler      /* Vector # 259 DSPI0_0 DSPI_0_SR[TFUF] | DSPI_0_SR[RFOF]| DSPI_0_SR[TFIWF] */
    .long   DefaultISR                       /* Vector # 260 DSPI0_1 DSPI_0_SR[EOQF]                                     */
    .long   DSPI0_Send_IRQHandler            /* Vector # 261 DSPI0_2 DSPI_0_SR[TFFF]                                     */
    .long   DefaultISR                       /* Vector # 262 DSPI0_3 DSPI_0_SR[TCF]                                      */
    .long   DSPI0_Receive_IRQHandler         /* Vector # 263 DSPI0_4 DSPI_0_SR[RFDF]                                     */
    .long   DefaultISR                       /* Vector # 264 DSPI0_5 DSPI_0_SR[SPITCF] | DSPI_0_SR[CMD_TCF]              */
    .long   DefaultISR                       /* Vector # 265 DSPI0_6 DSPI_0_SR[DSITCF] | DSPI_0_SR[CMDFFF]               */
    .long   DefaultISR                       /* Vector # 266 DSPI0_7 DSPI_0_SR[SPEF] | DSPI_0_SR[DPEF]                   */
    .long   DefaultISR                       /* Vector # 267 DSPI0_8 DSPI_0_SR[DDIF]                                     */
    .long   DSPI1_FIFO_Error_IRQHandler      /* Vector # 268 DSPI1_0 DSPI_1_SR[TFUF] | DSPI_1_SR[RFOF]| DSPI_1_SR[TFIWF] */
    .long   DefaultISR                       /* Vector # 269 DSPI1_1 DSPI_1_SR[EOQF]                                     */
    .long   DSPI1_Send_IRQHandler            /* Vector # 270 DSPI1_2 DSPI_1_SR[TFFF]                                     */
    .long   DefaultISR                       /* Vector # 271 DSPI1_3 DSPI_1_SR[TCF]                                      */
    .long   DSPI1_Receive_IRQHandler         /* Vector # 272 DSPI1_4 DSPI_1_SR[RFDF]                                     */
    .long   DefaultISR                       /* Vector # 273 DSPI1_5 DSPI_1_SR[SPITCF] | DSPI_1_SR[CMD_TCF]              */
    .long   DefaultISR                       /* Vector # 274 DSPI1_6 DSPI_1_SR[DSITCF] | DSPI_1_SR[CMDFFF]               */
    .long   DefaultISR                       /* Vector # 275 DSPI1_7 DSPI_1_SR[SPEF] | DSPI_1_SR[DPEF]                   */
    .long   DefaultISR                       /* Vector # 276 DSPI1_8 DSPI_1_SR[DDIF]                                     */
    .long   DSPI2_FIFO_Error_IRQHandler      /* Vector # 277 DSPI2_0 DSPI_2_SR[TFUF] | DSPI_2_SR[RFOF]| DSPI_2_SR[TFIWF] */
    .long   DefaultISR                       /* Vector # 278 DSPI2_1 DSPI_2_SR[EOQF]                                     */
    .long   DSPI2_Send_IRQHandler            /* Vector # 279 DSPI2_2 DSPI_2_SR[TFFF]                                     */
    .long   DefaultISR                       /* Vector # 280 DSPI2_3 DSPI_2_SR[TCF]                                      */
    .long   DSPI2_Receive_IRQHandler         /* Vector # 281 DSPI2_4 DSPI_2_SR[RFDF]                                     */
    .long   DefaultISR                       /* Vector # 282 DSPI2_5 DSPI_2_SR[SPITCF] | DSPI_2_SR[CMD_TCF]              */
    .long   DefaultISR                       /* Vector # 283 DSPI2_6 DSPI_2_SR[DSITCF] | DSPI_2_SR[CMDFFF]               */
    .long   DefaultISR                       /* Vector # 284 DSPI2_7 DSPI_2_SR[SPEF] | DSPI_2_SR[DPEF]                   */
    .long   DefaultISR                       /* Vector # 285 DSPI2_8 DSPI_2_SR[DDIF]                                     */
    .long   DSPI3_FIFO_Error_IRQHandler      /* Vector # 286 DSPI3_0 DSPI_3_SR[TFUF] | DSPI_3_SR[RFOF]| DSPI_3_SR[TFIWF] */
    .long   DefaultISR                       /* Vector # 287 DSPI3_1 DSPI_3_SR[EOQF]                                     */
    .long   DSPI3_Send_IRQHandler            /* Vector # 288 DSPI3_2 DSPI_3_SR[TFFF]                                     */
    .long   DefaultISR                       /* Vector # 289 DSPI3_3 DSPI_3_SR[TCF]                                      */
    .long   DSPI3_Receive_IRQHandler         /* Vector # 290 DSPI3_4 DSPI_3_SR[RFDF]                                     */
    .long   DefaultISR                       /* Vector # 291 */
    .long   DefaultISR                       /* Vector # 292 */
    .long   DefaultISR                       /* Vector # 293 */
    .long   DefaultISR                       /* Vector # 294 */
    .long   DefaultISR                       /* Vector # 295 */
    .long   DefaultISR                       /* Vector # 296 */
    .long   DefaultISR                       /* Vector # 297 */
    .long   DefaultISR                       /* Vector # 298 */
    .long   DefaultISR                       /* Vector # 299 */
    .long   DefaultISR                       /* Vector # 300 */
    .long   DefaultISR                       /* Vector # 301 */
    .long   DefaultISR                       /* Vector # 302 */
    .long   DefaultISR                       /* Vector # 303 */
    .long   DefaultISR                       /* Vector # 304 */
    .long   DefaultISR                       /* Vector # 305 */
    .long   DefaultISR                       /* Vector # 306 */
    .long   DefaultISR                       /* Vector # 307 */
    .long   DefaultISR                       /* Vector # 308 */
    .long   DefaultISR                       /* Vector # 309 */
    .long   DefaultISR                       /* Vector # 310 */
    .long   DefaultISR                       /* Vector # 311 */
    .long   DefaultISR                       /* Vector # 312 */
    .long   DefaultISR                       /* Vector # 313 */
    .long   DefaultISR                       /* Vector # 314 */
    .long   DefaultISR                       /* Vector # 315 */
    .long   DefaultISR                       /* Vector # 316 */
    .long   DefaultISR                       /* Vector # 317 */
    .long   DefaultISR                       /* Vector # 318 */
    .long   DefaultISR                       /* Vector # 319 */
    .long   DefaultISR                       /* Vector # 320 */
    .long   DefaultISR                       /* Vector # 321 */
    .long   DefaultISR                       /* Vector # 322 */
    .long   DefaultISR                       /* Vector # 323 */
    .long   DefaultISR                       /* Vector # 324 */
    .long   DefaultISR                       /* Vector # 325 */
    .long   DefaultISR                       /* Vector # 326 */
    .long   DefaultISR                       /* Vector # 327 */
    .long   DefaultISR                       /* Vector # 328 */
    .long   DefaultISR                       /* Vector # 329 */
    .long   DefaultISR                       /* Vector # 330 */
    .long   DefaultISR                       /* Vector # 331 */
    .long   DefaultISR                       /* Vector # 332 */
    .long   DefaultISR                       /* Vector # 333 */
    .long   DefaultISR                       /* Vector # 334 */
    .long   DefaultISR                       /* Vector # 335 */
    .long   DefaultISR                       /* Vector # 336 */
    .long   DefaultISR                       /* Vector # 337 */
    .long   DefaultISR                       /* Vector # 338 */
    .long   DefaultISR                       /* Vector # 339 */
    .long   DefaultISR                       /* Vector # 340 */
    .long   DefaultISR                       /* Vector # 341 */
    .long   DefaultISR                       /* Vector # 342 */
    .long   DefaultISR                       /* Vector # 343 */
    .long   DefaultISR                       /* Vector # 344 */
    .long   DefaultISR                       /* Vector # 345 */
    .long   DefaultISR                       /* Vector # 346 */
    .long   DefaultISR                       /* Vector # 347 */
    .long   DefaultISR                       /* Vector # 348 */
    .long   DefaultISR                       /* Vector # 349 */
    .long   DefaultISR                       /* Vector # 350 */
    .long   DefaultISR                       /* Vector # 351 */
    .long   DefaultISR                       /* Vector # 352 */
    .long   DefaultISR                       /* Vector # 353 */
    .long   DefaultISR                       /* Vector # 354 */
    .long   DefaultISR                       /* Vector # 355 */
    .long   DefaultISR                       /* Vector # 356 */
    .long   DefaultISR                       /* Vector # 357 */
    .long   DefaultISR                       /* Vector # 358 */
    .long   DefaultISR                       /* Vector # 359 */
    .long   DefaultISR                       /* Vector # 360 */
    .long   DefaultISR                       /* Vector # 361 */
    .long   DefaultISR                       /* Vector # 362 */
    .long   DefaultISR                       /* Vector # 363 */
    .long   DefaultISR                       /* Vector # 364 */
    .long   DefaultISR                       /* Vector # 365 */
    .long   DefaultISR                       /* Vector # 366 */
    .long   DefaultISR                       /* Vector # 367 */
    .long   DefaultISR                       /* Vector # 368 */
    .long   DefaultISR                       /* Vector # 369 */
    .long   DefaultISR                       /* Vector # 370 */
    .long   DefaultISR                       /* Vector # 371 */
    .long   DefaultISR                       /* Vector # 372 */
    .long   DefaultISR                       /* Vector # 373 */
    .long   DefaultISR                       /* Vector # 374 */
    .long   DefaultISR                       /* Vector # 375 */
    .long   LINFLEXD0_UART_RxIRQHandler      /* Vector # 376 LinFlex_0_RXI */
    .long   LINFLEXD0_UART_TxIRQHandler      /* Vector # 377 LinFlex_0_TXI */
    .long   LINFLEXD0_UART_ErrIRQHandler     /* Vector # 378 LinFlex_0_ERR */
    .long   DefaultISR                       /* Vector # 379 */
    .long   LINFLEXD1_UART_RxIRQHandler      /* Vector # 380 LinFlex_1_RXI */
    .long   LINFLEXD1_UART_TxIRQHandler      /* Vector # 381 LinFlex_1_TXI */
    .long   LINFLEXD1_UART_ErrIRQHandler     /* Vector # 382 LinFlex_1_ERR */
    .long   DefaultISR                       /* Vector # 383 */
    .long   DefaultISR                       /* Vector # 384 */
    .long   DefaultISR                       /* Vector # 385 */
    .long   DefaultISR                       /* Vector # 386 */
    .long   DefaultISR                       /* Vector # 387 */
    .long   DefaultISR                       /* Vector # 388 */
    .long   DefaultISR                       /* Vector # 389 */
    .long   DefaultISR                       /* Vector # 390 */
    .long   DefaultISR                       /* Vector # 391 */
    .long   DefaultISR                       /* Vector # 392 */
    .long   DefaultISR                       /* Vector # 393 */
    .long   DefaultISR                       /* Vector # 394 */
    .long   DefaultISR                       /* Vector # 395 */
    .long   DefaultISR                       /* Vector # 396 */
    .long   DefaultISR                       /* Vector # 397 */
    .long   DefaultISR                       /* Vector # 398 */
    .long   DefaultISR                       /* Vector # 399 */
    .long   DefaultISR                       /* Vector # 400 */
    .long   DefaultISR                       /* Vector # 401 */
    .long   DefaultISR                       /* Vector # 402 */
    .long   DefaultISR                       /* Vector # 403 */
    .long   DefaultISR                       /* Vector # 404 */
    .long   DefaultISR                       /* Vector # 405 */
    .long   DefaultISR                       /* Vector # 406 */
    .long   DefaultISR                       /* Vector # 407 */
    .long   DefaultISR                       /* Vector # 408 */
    .long   DefaultISR                       /* Vector # 409 */
    .long   DefaultISR                       /* Vector # 410 */
    .long   DefaultISR                       /* Vector # 411 */
    .long   DefaultISR                       /* Vector # 412 */
    .long   DefaultISR                       /* Vector # 413 */
    .long   DefaultISR                       /* Vector # 414 */
    .long   DefaultISR                       /* Vector # 415 */
    .long   DefaultISR                       /* Vector # 416 */
    .long   DefaultISR                       /* Vector # 417 */
    .long   DefaultISR                       /* Vector # 418 */
    .long   DefaultISR                       /* Vector # 419 */
    .long   DefaultISR                       /* Vector # 420 */
    .long   DefaultISR                       /* Vector # 421 */
    .long   DefaultISR                       /* Vector # 422 */
    .long   DefaultISR                       /* Vector # 423 */
    .long   DefaultISR                       /* Vector # 424 */
    .long   DefaultISR                       /* Vector # 425 */
    .long   DefaultISR                       /* Vector # 426 */
    .long   DefaultISR                       /* Vector # 427 */
    .long   DefaultISR                       /* Vector # 428 */
    .long   DefaultISR                       /* Vector # 429 */
    .long   DefaultISR                       /* Vector # 430 */
    .long   DefaultISR                       /* Vector # 431 */
    .long   DefaultISR                       /* Vector # 432 */
    .long   DefaultISR                       /* Vector # 433 */
    .long   DefaultISR                       /* Vector # 434 */
    .long   DefaultISR                       /* Vector # 435 */
    .long   DefaultISR                       /* Vector # 436 */
    .long   DefaultISR                       /* Vector # 437 */
    .long   DefaultISR                       /* Vector # 438 */
    .long   DefaultISR                       /* Vector # 439 */
    .long   DefaultISR                       /* Vector # 440 */
    .long   DefaultISR                       /* Vector # 441 */
    .long   DefaultISR                       /* Vector # 442 */
    .long   DefaultISR                       /* Vector # 443 */
    .long   DefaultISR                       /* Vector # 444 */
    .long   DefaultISR                       /* Vector # 445 */
    .long   DefaultISR                       /* Vector # 446 */
    .long   DefaultISR                       /* Vector # 447 */
    .long   DefaultISR                       /* Vector # 448 */
    .long   DefaultISR                       /* Vector # 449 */
    .long   DefaultISR                       /* Vector # 450 */
    .long   DefaultISR                       /* Vector # 451 */
    .long   DefaultISR                       /* Vector # 452 */
    .long   DefaultISR                       /* Vector # 453 */
    .long   DefaultISR                       /* Vector # 454 */
    .long   DefaultISR                       /* Vector # 455 */
    .long   DefaultISR                       /* Vector # 456 */
    .long   DefaultISR                       /* Vector # 457 */
    .long   DefaultISR                       /* Vector # 458 */
    .long   DefaultISR                       /* Vector # 459 */
    .long   DefaultISR                       /* Vector # 460 */
    .long   DefaultISR                       /* Vector # 461 */
    .long   DefaultISR                       /* Vector # 462 */
    .long   DefaultISR                       /* Vector # 463 */
    .long   DefaultISR                       /* Vector # 464 */
    .long   DefaultISR                       /* Vector # 465 */
    .long   DefaultISR                       /* Vector # 466 */
    .long   DefaultISR                       /* Vector # 467 */
    .long   DefaultISR                       /* Vector # 468 */
    .long   DefaultISR                       /* Vector # 469 */
    .long   DefaultISR                       /* Vector # 470 */
    .long   DefaultISR                       /* Vector # 471 */
    .long   DefaultISR                       /* Vector # 472 */
    .long   DefaultISR                       /* Vector # 473 */
    .long   DefaultISR                       /* Vector # 474 */
    .long   DefaultISR                       /* Vector # 475 */
    .long   DefaultISR                       /* Vector # 476 */
    .long   DefaultISR                       /* Vector # 477 */
    .long   DefaultISR                       /* Vector # 478 */
    .long   DefaultISR                       /* Vector # 479 */
    .long   DefaultISR                       /* Vector # 480 */
    .long   DefaultISR                       /* Vector # 481 */
    .long   DefaultISR                       /* Vector # 482 */
    .long   DefaultISR                       /* Vector # 483 */
    .long   DefaultISR                       /* Vector # 484 */
    .long   DefaultISR                       /* Vector # 485 */
    .long   DefaultISR                       /* Vector # 486 */
    .long   DefaultISR                       /* Vector # 487 */
    .long   FCCU0_IRQ_Handler                /* Vector # 488 FCCU Interrupt request (ALARM state) */
    .long   FCCU0_IRQ_Handler                /* Vector # 489 FCCU Interrupt request (miscellaneous conditions) */
    .long   DefaultISR                       /* Vector # 490 */
    .long   DefaultISR                       /* Vector # 491 */
    .long   DefaultISR                       /* Vector # 492 */
    .long   DefaultISR                       /* Vector # 493 */
    .long   DefaultISR                       /* Vector # 494 */
    .long   DefaultISR                       /* Vector # 495 */
    .long   ADC0_EOC_IRQHandler              /* Vector # 496 ADC_0_EOC ADC_0_EOC */
    .long   ADC0_ER_IRQHandler               /* Vector # 497 ADC_0_ER ADC_0_ER */
    .long   ADC0_WD_IRQHandler               /* Vector # 498 ADC_0_WD ADC_0_WD */
    .long   DefaultISR                       /* Vector # 499 */
    .long   ADC1_EOC_IRQHandler              /* Vector # 500 ADC_1_EOC ADC_1_EOC */
    .long   ADC1_ER_IRQHandler               /* Vector # 501 ADC_1_ER ADC_1_ER */
    .long   ADC1_WD_IRQHandler               /* Vector # 502 ADC_1_WD ADC_1_WD */
    .long   DefaultISR                       /* Vector # 503 */
    .long   ADC2_EOC_IRQHandler              /* Vector # 504 ADC_2_EOC ADC_2_EOC */
    .long   ADC2_ER_IRQHandler               /* Vector # 505 ADC_2_ER ADC_2_ER */
    .long   ADC2_WD_IRQHandler               /* Vector # 506 ADC_2_WD ADC_2_WD */
    .long   DefaultISR                       /* Vector # 507 */
    .long   ADC3_EOC_IRQHandler              /* Vector # 508 ADC_3_EOC ADC_3_EOC */
    .long   ADC3_ER_IRQHandler               /* Vector # 509 ADC_3_ER ADC_3_ER */
    .long   ADC3_WD_IRQHandler               /* Vector # 510 ADC_3_WD ADC_3_WD */
    .long   DefaultISR                       /* Vector # 511 */
    .long   DefaultISR                       /* Vector # 512 */
    .long   DefaultISR                       /* Vector # 513 */
    .long   DefaultISR                       /* Vector # 514 */
    .long   DefaultISR                       /* Vector # 515 */
    .long   DefaultISR                       /* Vector # 516 */
    .long   DefaultISR                       /* Vector # 517 */
    .long   DefaultISR                       /* Vector # 518 */
    .long   DefaultISR                       /* Vector # 519 */
    .long   CAN0_Error_IRQHandler            /* Vector # 520 FLEXCAN_0_ESR[ERR_INT] */
    .long   CAN0_ORed_IRQHandler             /* Vector # 521 FLEXCAN_0_ESR_BOFF | FLEXCAN_0_Transmit_Warning | FLEXCAN_0_Receive_Warning */
    .long   CAN0_ORed_00_03_MB_IRQHandler    /* Vector # 522 FlexCAN0_BUF_00_03 */
    .long   CAN0_ORed_04_07_MB_IRQHandler    /* Vector # 523 FlexCAN0_BUF_04_07 */
    .long   CAN0_ORed_08_11_MB_IRQHandler    /* Vector # 524 FlexCAN0_BUF_08_11 */
    .long   CAN0_ORed_12_15_MB_IRQHandler    /* Vector # 525 FlexCAN0_BUF_12_15 */
    .long   CAN0_ORed_16_31_MB_IRQHandler    /* Vector # 526 FlexCAN0_BUF_16_31 */
    .long   CAN0_ORed_32_39_MB_IRQHandler    /* Vector # 527 FlexCAN0_BUF_32_39 */
    .long   CAN0_ORed_40_47_MB_IRQHandler    /* Vector # 528 FlexCAN0_BUF_40_47 */
    .long   CAN0_ORed_48_55_MB_IRQHandler    /* Vector # 529 FlexCAN0_BUF_48_55 */
    .long   CAN0_ORed_56_63_MB_IRQHandler    /* Vector # 530 FlexCAN0_BUF_56_53 */
    .long   DefaultISR                       /* Vector # 531 */
    .long   DefaultISR                       /* Vector # 532 */
    .long   CAN1_Error_IRQHandler            /* Vector # 533 FLEXCAN_1_ESR[ERR_INT] */
    .long   CAN1_ORed_IRQHandler             /* Vector # 534 FLEXCAN_1_ESR_BOFF | FLEXCAN_1_Transmit_Warning | FLEXCAN_1_Receive_Warning */
    .long   CAN1_ORed_00_03_MB_IRQHandler    /* Vector # 535 FlexCAN1_BUF_00_03 */
    .long   CAN1_ORed_04_07_MB_IRQHandler    /* Vector # 536 FlexCAN1_BUF_04_07 */
    .long   CAN1_ORed_08_11_MB_IRQHandler    /* Vector # 537 FlexCAN1_BUF_08_11 */
    .long   CAN1_ORed_12_15_MB_IRQHandler    /* Vector # 538 FlexCAN1_BUF_12_15 */
    .long   CAN1_ORed_16_31_MB_IRQHandler    /* Vector # 539 FlexCAN1_BUF_16_31 */
    .long   CAN1_ORed_32_39_MB_IRQHandler    /* Vector # 540 FlexCAN1_BUF_32_39 */
    .long   CAN1_ORed_40_47_MB_IRQHandler    /* Vector # 541 FlexCAN1_BUF_40_47 */
    .long   CAN1_ORed_48_55_MB_IRQHandler    /* Vector # 542 FlexCAN1_BUF_48_55 */
    .long   CAN1_ORed_56_63_MB_IRQHandler    /* Vector # 543 FlexCAN1_BUF_56_53 */
    .long   DefaultISR                       /* Vector # 544 */
    .long   DefaultISR                       /* Vector # 545 */
    .long   CAN2_Error_IRQHandler            /* Vector # 546 FLEXCAN_2_ESR[ERR_INT] */
    .long   CAN2_ORed_IRQHandler             /* Vector # 547 FLEXCAN_2_ESR_BOFF | FLEXCAN_2_Transmit_Warning | FLEXCAN_2_Receive_Warning */
    .long   CAN2_ORed_00_03_MB_IRQHandler    /* Vector # 548 FlexCAN2_BUF_00_03 */
    .long   CAN2_ORed_04_07_MB_IRQHandler    /* Vector # 549 FlexCAN2_BUF_04_07 */
    .long   CAN2_ORed_08_11_MB_IRQHandler    /* Vector # 550 FlexCAN2_BUF_08_11 */
    .long   CAN2_ORed_12_15_MB_IRQHandler    /* Vector # 551 FlexCAN2_BUF_12_15 */
    .long   CAN2_ORed_16_31_MB_IRQHandler    /* Vector # 552 FlexCAN2_BUF_16_31 */
    .long   CAN2_ORed_32_39_MB_IRQHandler    /* Vector # 553 FlexCAN2_BUF_32_39 */
    .long   CAN2_ORed_40_47_MB_IRQHandler    /* Vector # 554 FlexCAN2_BUF_40_47 */
    .long   CAN2_ORed_48_55_MB_IRQHandler    /* Vector # 555 FlexCAN2_BUF_48_55 */
    .long   CAN2_ORed_56_63_MB_IRQHandler    /* Vector # 556 FlexCAN2_BUF_56_63 */
    .long   DefaultISR                       /* Vector # 557 */
    .long   DefaultISR                       /* Vector # 558 */
    .long   DefaultISR                       /* Vector # 559 */
    .long   DefaultISR                       /* Vector # 560 */
    .long   DefaultISR                       /* Vector # 561 */
    .long   DefaultISR                       /* Vector # 562 */
    .long   DefaultISR                       /* Vector # 563 */
    .long   DefaultISR                       /* Vector # 564 */
    .long   DefaultISR                       /* Vector # 565 */
    .long   DefaultISR                       /* Vector # 566 */
    .long   DefaultISR                       /* Vector # 567 */
    .long   DefaultISR                       /* Vector # 568 */
    .long   DefaultISR                       /* Vector # 569 */
    .long   SENT0_Fast_0_IRQHandler          /* Vector # 570 SENT0_Fast_0 */
    .long   SENT0_Slow_0_IRQHandler          /* Vector # 571 SENT0_Slow_0 */
    .long   SENT0_RxErr_0_IRQHandler         /* Vector # 572 SENT0_RxErr_0 */
    .long   SENT0_Fast_1_IRQHandler          /* Vector # 573 SENT0_Fast_1 */
    .long   SENT0_Slow_1_IRQHandler          /* Vector # 574 SENT0_Slow_1 */
    .long   SENT0_RxErr_1_IRQHandler         /* Vector # 575 SENT0_RxErr_1 */
    .long   DefaultISR                       /* Vector # 576 */
    .long   DefaultISR                       /* Vector # 577 */
    .long   DefaultISR                       /* Vector # 578 */
    .long   DefaultISR                       /* Vector # 579 */
    .long   DefaultISR                       /* Vector # 580 */
    .long   DefaultISR                       /* Vector # 581 */
    .long   SENT1_Fast_0_IRQHandler          /* Vector # 582 SENT1_Fast_0 */
    .long   SENT1_Slow_0_IRQHandler          /* Vector # 583 SENT1_Slow_0 */
    .long   SENT1_RxErr_0_IRQHandler         /* Vector # 584 SENT1_RxErr_0 */
    .long   SENT1_Fast_1_IRQHandler          /* Vector # 585 SENT1_Fast_1 */
    .long   SENT1_Slow_1_IRQHandler          /* Vector # 586 SENT1_Slow_1 */
    .long   SENT1_RxErr_1_IRQHandler         /* Vector # 587 SENT1_RxErr_1 */
    .long   DefaultISR                       /* Vector # 588 */
    .long   DefaultISR                       /* Vector # 589 */
    .long   DefaultISR                       /* Vector # 590 */
    .long   DefaultISR                       /* Vector # 591 */
    .long   DefaultISR                       /* Vector # 592 */
    .long   DefaultISR                       /* Vector # 593 */
    .long   DefaultISR                       /* Vector # 594 */
    .long   DefaultISR                       /* Vector # 595 */
    .long   DefaultISR                       /* Vector # 596 */
    .long   DefaultISR                       /* Vector # 597 */
    .long   DefaultISR                       /* Vector # 598 */
    .long   DefaultISR                       /* Vector # 599 */
    .long   DefaultISR                       /* Vector # 600 */
    .long   DefaultISR                       /* Vector # 601 */
    .long   DefaultISR                       /* Vector # 602 */
    .long   DefaultISR                       /* Vector # 603 */
    .long   DefaultISR                       /* Vector # 604 */
    .long   DefaultISR                       /* Vector # 605 */
    .long   DefaultISR                       /* Vector # 606 */
    .long   DefaultISR                       /* Vector # 607 */
    .long   DefaultISR                       /* Vector # 608 */
    .long   DefaultISR                       /* Vector # 609 */
    .long   DefaultISR                       /* Vector # 610 */
    .long   ETIMER0_TC0IR_IRQHandler         /* Vector # 611 ETIMER0_TC0IR */
    .long   ETIMER0_TC1IR_IRQHandler         /* Vector # 612 ETIMER0_TC1IR */
    .long   ETIMER0_TC2IR_IRQHandler         /* Vector # 613 ETIMER0_TC2IR */
    .long   ETIMER0_TC3IR_IRQHandler         /* Vector # 614 ETIMER0_TC3IR */
    .long   ETIMER0_TC4IR_IRQHandler         /* Vector # 615 ETIMER0_TC4IR */
    .long   ETIMER0_TC5IR_IRQHandler         /* Vector # 616 ETIMER0_TC5IR */
    .long   DefaultISR                       /* Vector # 617 */
    .long   DefaultISR                       /* Vector # 618 */
    .long   ETIMER0_WTIF_IRQHandler          /* Vector # 619 ETIMER0_WTIF */
    .long   DefaultISR                       /* Vector # 620 */
    .long   ETIMER0_RCF_IRQHandler           /* Vector # 621 ETIMER0_RCF */
    .long   ETIMER1_TC0IR_IRQHandler         /* Vector # 622 ETIMER1_TC0IR */
    .long   ETIMER1_TC1IR_IRQHandler         /* Vector # 623 ETIMER1_TC1IR */
    .long   ETIMER1_TC2IR_IRQHandler         /* Vector # 624 ETIMER1_TC2IR */
    .long   ETIMER1_TC3IR_IRQHandler         /* Vector # 625 ETIMER1_TC3IR */
    .long   ETIMER1_TC4IR_IRQHandler         /* Vector # 626 ETIMER1_TC4IR */
    .long   ETIMER1_TC5IR_IRQHandler         /* Vector # 627 ETIMER1_TC5IR */
    .long   DefaultISR                       /* Vector # 628 */
    .long   DefaultISR                       /* Vector # 629 */
    .long   DefaultISR                       /* Vector # 630 */
    .long   DefaultISR                       /* Vector # 631 */
    .long   ETIMER1_RCF_IRQHandler           /* Vector # 632 ETIMER1_RCF */
    .long   ETIMER2_TC0IR_IRQHandler         /* Vector # 633 ETIMER2_TC0IR */
    .long   ETIMER2_TC1IR_IRQHandler         /* Vector # 634 ETIMER2_TC1IR */
    .long   ETIMER2_TC2IR_IRQHandler         /* Vector # 635 ETIMER2_TC2IR */
    .long   ETIMER2_TC3IR_IRQHandler         /* Vector # 636 ETIMER2_TC3IR */
    .long   ETIMER2_TC4IR_IRQHandler         /* Vector # 637 ETIMER2_TC4IR */
    .long   ETIMER2_TC5IR_IRQHandler         /* Vector # 638 ETIMER2_TC5IR */
    .long   DefaultISR                       /* Vector # 639 */
    .long   DefaultISR                       /* Vector # 640 */
    .long   DefaultISR                       /* Vector # 641 */
    .long   DefaultISR                       /* Vector # 642 */
    .long   ETIMER2_RCF_IRQHandler           /* Vector # 643 ETIMER2_RCF */
    .long   DefaultISR                       /* Vector # 644 */
    .long   DefaultISR                       /* Vector # 645 */
    .long   DefaultISR                       /* Vector # 646 */
    .long   DefaultISR                       /* Vector # 647 */
    .long   DefaultISR                       /* Vector # 648 */
    .long   DefaultISR                       /* Vector # 649 */
    .long   DefaultISR                       /* Vector # 650 */
    .long   DefaultISR                       /* Vector # 651 */
    .long   DefaultISR                       /* Vector # 652 */
    .long   DefaultISR                       /* Vector # 653 */
    .long   DefaultISR                       /* Vector # 654 */
    .long   FlexPWM_0_RF0_IRQHandler         /* Vector # 655 FlexPWM_0_RF0      */
    .long   FlexPWM_0_COF0_IRQHandler        /* Vector # 656 FlexPWM_0_COF0     */
    .long   FlexPWM_0_CAF0_IRQHandler        /* Vector # 657 FlexPWM_0_CAF0     */
    .long   FlexPWM_0_RF1_IRQHandler         /* Vector # 658 FlexPWM_0_RF1      */
    .long   FlexPWM_0_COF1_IRQHandler        /* Vector # 659 FlexPWM_0_COF1     */
    .long   FlexPWM_0_CAF1_IRQHandler        /* Vector # 660 FlexPWM_0_CAF1     */
    .long   FlexPWM_0_RF2_IRQHandler         /* Vector # 661 FlexPWM_0_RF2      */
    .long   FlexPWM_0_COF2_IRQHandler        /* Vector # 662 FlexPWM_0_COF2     */
    .long   FlexPWM_0_CAF2_IRQHandler        /* Vector # 663 FlexPWM_0_CAF2     */
    .long   FlexPWM_0_RF3_IRQHandler         /* Vector # 664 FlexPWM_0_RF3      */
    .long   FlexPWM_0_COF3_IRQHandler        /* Vector # 665 FlexPWM_0_COF3     */
    .long   FlexPWM_0_CAF3_IRQHandler        /* Vector # 666 FlexPWM_0_CAF3     */
    .long   FlexPWM_0_FFLAG_IRQHandler       /* Vector # 667 FlexPWM_0_FFLAG    */
    .long   FlexPWM_0_REF_IRQHandler         /* Vector # 668 FlexPWM_0_REF      */
    .long   DefaultISR                       /* Vector # 669 */
    .long   FlexPWM_1_RF0_IRQHandler         /* Vector # 670 FlexPWM_1_RF0      */
    .long   FlexPWM_1_COF0_IRQHandler        /* Vector # 671 FlexPWM_1_COF0     */
    .long   FlexPWM_1_CAF0_IRQHandler        /* Vector # 672 FlexPWM_1_CAF0     */
    .long   FlexPWM_1_RF1_IRQHandler         /* Vector # 673 FlexPWM_1_RF1      */
    .long   FlexPWM_1_COF1_IRQHandler        /* Vector # 674 FlexPWM_1_COF1     */
    .long   FlexPWM_1_CAF1_IRQHandler        /* Vector # 675 FlexPWM_1_CAF1     */
    .long   FlexPWM_1_RF2_IRQHandler         /* Vector # 676 FlexPWM_1_RF2      */
    .long   FlexPWM_1_COF2_IRQHandler        /* Vector # 677 FlexPWM_1_COF2     */
    .long   FlexPWM_1_CAF2_IRQHandler        /* Vector # 678 FlexPWM_1_CAF2     */
    .long   FlexPWM_1_RF3_IRQHandler         /* Vector # 679 FlexPWM_1_RF3      */
    .long   FlexPWM_1_COF3_IRQHandler        /* Vector # 680 FlexPWM_1_COF3     */
    .long   FlexPWM_1_CAF3_IRQHandler        /* Vector # 681 FlexPWM_1_CAF3     */
    .long   FlexPWM_1_FFLAG_IRQHandler       /* Vector # 682 FlexPWM_1_FFLAG    */
    .long   FlexPWM_1_REF_IRQHandler         /* Vector # 683 FlexPWM_1_REF      */
    .long   DefaultISR                       /* Vector # 684 */
    .long   DefaultISR                       /* Vector # 685 */
    .long   DefaultISR                       /* Vector # 686 */
    .long   DefaultISR                       /* Vector # 687 */
    .long   DefaultISR                       /* Vector # 688 */
    .long   DefaultISR                       /* Vector # 689 */
    .long   DefaultISR                       /* Vector # 690 */
    .long   DefaultISR                       /* Vector # 691 */
    .long   DefaultISR                       /* Vector # 692 */
    .long   DefaultISR                       /* Vector # 693 */
    .long   DefaultISR                       /* Vector # 694 */
    .long   DefaultISR                       /* Vector # 695 */
    .long   DefaultISR                       /* Vector # 696 */
    .long   DefaultISR                       /* Vector # 697 */
    .long   DefaultISR                       /* Vector # 698 */
    .long   DefaultISR                       /* Vector # 699 */
    .long   CTU0_MRS_IRQHandler              /* Vector # 700 CTU 0 Master Reload Signal interrupt */
    .long   CTU0_T0_IRQHandler               /* Vector # 701 CTU 0 Trigger 0 interrupt */
    .long   CTU0_T1_IRQHandler               /* Vector # 702 CTU 0 Trigger 1 interrupt */
    .long   CTU0_T2_IRQHandler               /* Vector # 703 CTU 0 Trigger 2 interrupt */
    .long   CTU0_T3_IRQHandler               /* Vector # 704 CTU 0 Trigger 3 interrupt */
    .long   CTU0_T4_IRQHandler               /* Vector # 705 CTU 0 Trigger 4 interrupt */
    .long   CTU0_T5_IRQHandler               /* Vector # 706 CTU 0 Trigger 5 interrupt */
    .long   CTU0_T6_IRQHandler               /* Vector # 707 CTU 0 Trigger 6 interrupt */
    .long   CTU0_T7_IRQHandler               /* Vector # 708 CTU 0 Trigger 7 interrupt */
    .long   CTU0_FIFO0_IRQHandler            /* Vector # 709 CTU 0 FIFO 0 interrupt */
    .long   CTU0_FIFO1_IRQHandler            /* Vector # 710 CTU 0 FIFO 1 interrupt */
    .long   CTU0_FIFO2_IRQHandler            /* Vector # 711 CTU 0 FIFO 2 interrupt */
    .long   CTU0_FIFO3_IRQHandler            /* Vector # 712 CTU 0 FIFO 3 interrupt */
    .long   CTU0_ADC_IRQHandler              /* Vector # 713 CTU 0 ADC interrupt */
    .long   CTU0_ERR_IRQHandler              /* Vector # 714 CTU 0 Error interrupt */
    .long   DefaultISR                       /* Vector # 715 */
    .long   CTU1_MRS_IRQHandler              /* Vector # 716 CTU 1 Master Reload Signal interrupt */
    .long   CTU1_T0_IRQHandler               /* Vector # 717 CTU 1 Trigger 0 interrupt */
    .long   CTU1_T1_IRQHandler               /* Vector # 718 CTU 1 Trigger 1 interrupt */
    .long   CTU1_T2_IRQHandler               /* Vector # 719 CTU 1 Trigger 2 interrupt */
    .long   CTU1_T3_IRQHandler               /* Vector # 720 CTU 1 Trigger 3 interrupt */
    .long   CTU1_T4_IRQHandler               /* Vector # 721 CTU 1 Trigger 4 interrupt */
    .long   CTU1_T5_IRQHandler               /* Vector # 722 CTU 1 Trigger 5 interrupt */
    .long   CTU1_T6_IRQHandler               /* Vector # 723 CTU 1 Trigger 6 interrupt */
    .long   CTU1_T7_IRQHandler               /* Vector # 724 CTU 1 Trigger 7 interrupt */
    .long   CTU1_FIFO0_IRQHandler            /* Vector # 725 CTU 1 FIFO 0 interrupt */
    .long   CTU1_FIFO1_IRQHandler            /* Vector # 726 CTU 1 FIFO 1 interrupt */
    .long   CTU1_FIFO2_IRQHandler            /* Vector # 727 CTU 1 FIFO 2 interrupt */
    .long   CTU1_FIFO3_IRQHandler            /* Vector # 728 CTU 1 FIFO 3 interrupt */
    .long   CTU1_ADC_IRQHandler              /* Vector # 729 CTU 1 ADC interrupt */
    .long   CTU1_ERR_IRQHandler              /* Vector # 730 CTU 1 Error interrupt */
    .long   DefaultISR                       /* Vector # 731 */
    .long   DefaultISR                       /* Vector # 732 */
    .long   DefaultISR                       /* Vector # 733 */
    .long   DefaultISR                       /* Vector # 734 */
    .long   DefaultISR                       /* Vector # 735 */
    .long   DefaultISR                       /* Vector # 736 */
    .long   DefaultISR                       /* Vector # 737 */
    .long   DefaultISR                       /* Vector # 738 */
    .long   DefaultISR                       /* Vector # 739 */
    .long   DefaultISR                       /* Vector # 740 */
    .long   DefaultISR                       /* Vector # 741 */
    .long   DefaultISR                       /* Vector # 742 */
    .long   DefaultISR                       /* Vector # 743 */
    .long   DefaultISR                       /* Vector # 744 */
    .long   DefaultISR                       /* Vector # 745 */
    .long   DefaultISR                       /* Vector # 746 */
    .long   DefaultISR                       /* Vector # 747 */
    .long   DefaultISR                       /* Vector # 748 */
    .long   DefaultISR                       /* Vector # 749 */
    .long   DefaultISR                       /* Vector # 750 */
    .long   DefaultISR                       /* Vector # 751 */
    .long   DefaultISR                       /* Vector # 752 */
    .long   DefaultISR                       /* Vector # 753 */

    .align  2
    .weak DefaultISR
    .type DefaultISR, %function
DefaultISR:
    e_b       DefaultISR
    .size DefaultISR, . - DefaultISR

/*    Macro to define default handlers. Default handler
 *    will be weak symbol and just dead loops. They can be
 *    overwritten by other handlers */
    .macro def_irq_handler  handler_name
    .weak \handler_name
    .set  \handler_name, DefaultISR
    .endm

/* Exception Handlers */
    def_irq_handler    IVOR0_Handler
    def_irq_handler    IVOR1_Handler
    def_irq_handler    IVOR2_Handler
    def_irq_handler    IVOR3_Handler
    def_irq_handler    IVOR4_Handler
    def_irq_handler    IVOR5_Handler
    def_irq_handler    IVOR6_Handler
    def_irq_handler    IVOR8_Handler
    def_irq_handler    IVOR15_Handler
    def_irq_handler    IVOR33_Handler
    def_irq_handler    IVOR34_Handler
    def_irq_handler    IVOR35_Handler
    def_irq_handler    IVOR0_Exception_Handler
    def_irq_handler    IVOR1_Exception_Handler
    def_irq_handler    IVOR2_Exception_Handler
    def_irq_handler    IVOR3_Exception_Handler
    def_irq_handler    IVOR5_Exception_Handler
    def_irq_handler    IVOR6_Exception_Handler
    def_irq_handler    IVOR8_Exception_Handler
    def_irq_handler    IVOR15_Exception_Handler
    def_irq_handler    IVOR33_Exception_Handler
    def_irq_handler    IVOR34_Exception_Handler
    def_irq_handler    IVOR35_Exception_Handler
    def_irq_handler    DMA0_Ch0_Ch31_Error_IRQHandler
    def_irq_handler    DMA0_Ch0_IRQHandler
    def_irq_handler    DMA0_Ch1_IRQHandler
    def_irq_handler    DMA0_Ch2_IRQHandler
    def_irq_handler    DMA0_Ch3_IRQHandler
    def_irq_handler    DMA0_Ch4_IRQHandler
    def_irq_handler    DMA0_Ch5_IRQHandler
    def_irq_handler    DMA0_Ch6_IRQHandler
    def_irq_handler    DMA0_Ch7_IRQHandler
    def_irq_handler    DMA0_Ch8_IRQHandler
    def_irq_handler    DMA0_Ch9_IRQHandler
    def_irq_handler    DMA0_Ch10_IRQHandler
    def_irq_handler    DMA0_Ch11_IRQHandler
    def_irq_handler    DMA0_Ch12_IRQHandler
    def_irq_handler    DMA0_Ch13_IRQHandler
    def_irq_handler    DMA0_Ch14_IRQHandler
    def_irq_handler    DMA0_Ch15_IRQHandler
    def_irq_handler    DMA0_Ch16_IRQHandler
    def_irq_handler    DMA0_Ch17_IRQHandler
    def_irq_handler    DMA0_Ch18_IRQHandler
    def_irq_handler    DMA0_Ch19_IRQHandler
    def_irq_handler    DMA0_Ch20_IRQHandler
    def_irq_handler    DMA0_Ch21_IRQHandler
    def_irq_handler    DMA0_Ch22_IRQHandler
    def_irq_handler    DMA0_Ch23_IRQHandler
    def_irq_handler    DMA0_Ch24_IRQHandler
    def_irq_handler    DMA0_Ch25_IRQHandler
    def_irq_handler    DMA0_Ch26_IRQHandler
    def_irq_handler    DMA0_Ch27_IRQHandler
    def_irq_handler    DMA0_Ch28_IRQHandler
    def_irq_handler    DMA0_Ch29_IRQHandler
    def_irq_handler    DMA0_Ch30_IRQHandler
    def_irq_handler    DMA0_Ch31_IRQHandler
    def_irq_handler    SWT0_IRQHandler
    def_irq_handler    STM0_Ch0_IRQHandler
    def_irq_handler    STM0_Ch1_IRQHandler
    def_irq_handler    STM0_Ch2_IRQHandler
    def_irq_handler    STM0_Ch3_IRQHandler
    def_irq_handler    ENET0_Timer_IRQHandler
    def_irq_handler    ENET0_Tx_IRQHandler
    def_irq_handler    ENET0_Rx_IRQHandler
    def_irq_handler    ENET0_Err_IRQHandler
    def_irq_handler    PIT_Ch0_IRQHandler
    def_irq_handler    PIT_Ch1_IRQHandler
    def_irq_handler    PIT_Ch2_IRQHandler
    def_irq_handler    PIT_Ch3_IRQHandler
    def_irq_handler    LINFLEXD0_UART_RxIRQHandler
    def_irq_handler    LINFLEXD0_UART_TxIRQHandler
    def_irq_handler    LINFLEXD0_UART_ErrIRQHandler
    def_irq_handler    LINFLEXD1_UART_RxIRQHandler
    def_irq_handler    LINFLEXD1_UART_TxIRQHandler
    def_irq_handler    LINFLEXD1_UART_ErrIRQHandler
    def_irq_handler    FCCU0_IRQ_Handler
    def_irq_handler    CAN0_Error_IRQHandler
    def_irq_handler    CAN0_ORed_IRQHandler
    def_irq_handler    CAN0_ORed_00_03_MB_IRQHandler
    def_irq_handler    CAN0_ORed_04_07_MB_IRQHandler
    def_irq_handler    CAN0_ORed_08_11_MB_IRQHandler
    def_irq_handler    CAN0_ORed_12_15_MB_IRQHandler
    def_irq_handler    CAN0_ORed_16_31_MB_IRQHandler
    def_irq_handler    CAN0_ORed_32_39_MB_IRQHandler
    def_irq_handler    CAN0_ORed_40_47_MB_IRQHandler
    def_irq_handler    CAN0_ORed_48_55_MB_IRQHandler
    def_irq_handler    CAN0_ORed_56_63_MB_IRQHandler
    def_irq_handler    CAN1_Error_IRQHandler
    def_irq_handler    CAN1_ORed_IRQHandler
    def_irq_handler    CAN1_ORed_00_03_MB_IRQHandler
    def_irq_handler    CAN1_ORed_04_07_MB_IRQHandler
    def_irq_handler    CAN1_ORed_08_11_MB_IRQHandler
    def_irq_handler    CAN1_ORed_12_15_MB_IRQHandler
    def_irq_handler    CAN1_ORed_16_31_MB_IRQHandler
    def_irq_handler    CAN1_ORed_32_39_MB_IRQHandler
    def_irq_handler    CAN1_ORed_40_47_MB_IRQHandler
    def_irq_handler    CAN1_ORed_48_55_MB_IRQHandler
    def_irq_handler    CAN1_ORed_56_63_MB_IRQHandler
    def_irq_handler    CAN2_Error_IRQHandler
    def_irq_handler    CAN2_ORed_IRQHandler
    def_irq_handler    CAN2_ORed_00_03_MB_IRQHandler
    def_irq_handler    CAN2_ORed_04_07_MB_IRQHandler
    def_irq_handler    CAN2_ORed_08_11_MB_IRQHandler
    def_irq_handler    CAN2_ORed_12_15_MB_IRQHandler
    def_irq_handler    CAN2_ORed_16_31_MB_IRQHandler
    def_irq_handler    CAN2_ORed_32_39_MB_IRQHandler
    def_irq_handler    CAN2_ORed_40_47_MB_IRQHandler
    def_irq_handler    CAN2_ORed_48_55_MB_IRQHandler
    def_irq_handler    CAN2_ORed_56_63_MB_IRQHandler
    def_irq_handler    FLASH_Done_IRQHandler
    def_irq_handler    ETIMER0_TC0IR_IRQHandler
    def_irq_handler    ETIMER0_TC1IR_IRQHandler
    def_irq_handler    ETIMER0_TC2IR_IRQHandler
    def_irq_handler    ETIMER0_TC3IR_IRQHandler
    def_irq_handler    ETIMER0_TC4IR_IRQHandler
    def_irq_handler    ETIMER0_TC5IR_IRQHandler
    def_irq_handler    ETIMER0_WTIF_IRQHandler
    def_irq_handler    ETIMER0_RCF_IRQHandler
    def_irq_handler    ETIMER1_TC0IR_IRQHandler
    def_irq_handler    ETIMER1_TC1IR_IRQHandler
    def_irq_handler    ETIMER1_TC2IR_IRQHandler
    def_irq_handler    ETIMER1_TC3IR_IRQHandler
    def_irq_handler    ETIMER1_TC4IR_IRQHandler
    def_irq_handler    ETIMER1_TC5IR_IRQHandler
    def_irq_handler    ETIMER1_RCF_IRQHandler
    def_irq_handler    ETIMER2_TC0IR_IRQHandler
    def_irq_handler    ETIMER2_TC1IR_IRQHandler
    def_irq_handler    ETIMER2_TC2IR_IRQHandler
    def_irq_handler    ETIMER2_TC3IR_IRQHandler
    def_irq_handler    ETIMER2_TC4IR_IRQHandler
    def_irq_handler    ETIMER2_TC5IR_IRQHandler
    def_irq_handler    ETIMER2_RCF_IRQHandler
    def_irq_handler    CTU0_MRS_IRQHandler
    def_irq_handler    CTU0_T0_IRQHandler
    def_irq_handler    CTU0_T1_IRQHandler
    def_irq_handler    CTU0_T2_IRQHandler
    def_irq_handler    CTU0_T3_IRQHandler
    def_irq_handler    CTU0_T4_IRQHandler
    def_irq_handler    CTU0_T5_IRQHandler
    def_irq_handler    CTU0_T6_IRQHandler
    def_irq_handler    CTU0_T7_IRQHandler
    def_irq_handler    CTU0_FIFO0_IRQHandler
    def_irq_handler    CTU0_FIFO1_IRQHandler
    def_irq_handler    CTU0_FIFO2_IRQHandler
    def_irq_handler    CTU0_FIFO3_IRQHandler
    def_irq_handler    CTU0_ADC_IRQHandler
    def_irq_handler    CTU0_ERR_IRQHandler
    def_irq_handler    CTU1_MRS_IRQHandler
    def_irq_handler    CTU1_T0_IRQHandler
    def_irq_handler    CTU1_T1_IRQHandler
    def_irq_handler    CTU1_T2_IRQHandler
    def_irq_handler    CTU1_T3_IRQHandler
    def_irq_handler    CTU1_T4_IRQHandler
    def_irq_handler    CTU1_T5_IRQHandler
    def_irq_handler    CTU1_T6_IRQHandler
    def_irq_handler    CTU1_T7_IRQHandler
    def_irq_handler    CTU1_FIFO0_IRQHandler
    def_irq_handler    CTU1_FIFO1_IRQHandler
    def_irq_handler    CTU1_FIFO2_IRQHandler
    def_irq_handler    CTU1_FIFO3_IRQHandler
    def_irq_handler    CTU1_ADC_IRQHandler
    def_irq_handler    CTU1_ERR_IRQHandler
    def_irq_handler    DSPI0_FIFO_Error_IRQHandler
    def_irq_handler    DSPI0_Send_IRQHandler
    def_irq_handler    DSPI0_Receive_IRQHandler
    def_irq_handler    DSPI1_FIFO_Error_IRQHandler
    def_irq_handler    DSPI1_Send_IRQHandler
    def_irq_handler    DSPI1_Receive_IRQHandler
    def_irq_handler    DSPI2_FIFO_Error_IRQHandler
    def_irq_handler    DSPI2_Send_IRQHandler
    def_irq_handler    DSPI2_Receive_IRQHandler
    def_irq_handler    DSPI3_FIFO_Error_IRQHandler
    def_irq_handler    DSPI3_Send_IRQHandler
    def_irq_handler    DSPI3_Receive_IRQHandler
    def_irq_handler    SIUL_EIRQ_00_07_IRQHandler
    def_irq_handler    SIUL_EIRQ_08_15_IRQHandler
    def_irq_handler    SIUL_EIRQ_16_23_IRQHandler
    def_irq_handler    SIUL_EIRQ_24_31_IRQHandler
    def_irq_handler    ADC0_EOC_IRQHandler
    def_irq_handler    ADC0_ER_IRQHandler
    def_irq_handler    ADC0_WD_IRQHandler
    def_irq_handler    ADC1_EOC_IRQHandler
    def_irq_handler    ADC1_ER_IRQHandler
    def_irq_handler    ADC1_WD_IRQHandler
    def_irq_handler    ADC2_EOC_IRQHandler
    def_irq_handler    ADC2_ER_IRQHandler
    def_irq_handler    ADC2_WD_IRQHandler
    def_irq_handler    ADC3_EOC_IRQHandler
    def_irq_handler    ADC3_ER_IRQHandler
    def_irq_handler    ADC3_WD_IRQHandler
    def_irq_handler    SENT0_Fast_0_IRQHandler
    def_irq_handler    SENT0_Slow_0_IRQHandler
    def_irq_handler    SENT0_RxErr_0_IRQHandler
    def_irq_handler    SENT0_Fast_1_IRQHandler
    def_irq_handler    SENT0_Slow_1_IRQHandler
    def_irq_handler    SENT0_RxErr_1_IRQHandler
    def_irq_handler    SENT1_Fast_0_IRQHandler
    def_irq_handler    SENT1_Slow_0_IRQHandler
    def_irq_handler    SENT1_RxErr_0_IRQHandler
    def_irq_handler    SENT1_Fast_1_IRQHandler
    def_irq_handler    SENT1_Slow_1_IRQHandler
    def_irq_handler    SENT1_RxErr_1_IRQHandler
    def_irq_handler    FlexPWM_0_RF0_IRQHandler
    def_irq_handler    FlexPWM_0_COF0_IRQHandler
    def_irq_handler    FlexPWM_0_CAF0_IRQHandler
    def_irq_handler    FlexPWM_0_RF1_IRQHandler
    def_irq_handler    FlexPWM_0_COF1_IRQHandler
    def_irq_handler    FlexPWM_0_CAF1_IRQHandler
    def_irq_handler    FlexPWM_0_RF2_IRQHandler
    def_irq_handler    FlexPWM_0_COF2_IRQHandler
    def_irq_handler    FlexPWM_0_CAF2_IRQHandler
    def_irq_handler    FlexPWM_0_RF3_IRQHandler
    def_irq_handler    FlexPWM_0_COF3_IRQHandler
    def_irq_handler    FlexPWM_0_CAF3_IRQHandler
    def_irq_handler    FlexPWM_0_FFLAG_IRQHandler
    def_irq_handler    FlexPWM_0_REF_IRQHandler
    def_irq_handler    FlexPWM_1_RF0_IRQHandler
    def_irq_handler    FlexPWM_1_COF0_IRQHandler
    def_irq_handler    FlexPWM_1_CAF0_IRQHandler
    def_irq_handler    FlexPWM_1_RF1_IRQHandler
    def_irq_handler    FlexPWM_1_COF1_IRQHandler
    def_irq_handler    FlexPWM_1_CAF1_IRQHandler
    def_irq_handler    FlexPWM_1_RF2_IRQHandler
    def_irq_handler    FlexPWM_1_COF2_IRQHandler
    def_irq_handler    FlexPWM_1_CAF2_IRQHandler
    def_irq_handler    FlexPWM_1_RF3_IRQHandler
    def_irq_handler    FlexPWM_1_COF3_IRQHandler
    def_irq_handler    FlexPWM_1_CAF3_IRQHandler
    def_irq_handler    FlexPWM_1_FFLAG_IRQHandler
    def_irq_handler    FlexPWM_1_REF_IRQHandler
