// ---------------------------------------------------------------------------------------
//  @file:    interrupt_vectors.s
//  @purpose: GNU Compiler Collection Startup File
//            MPC5744P
//  @version: 1.0
//  @date:    2017-3-22
//  @build:   #
// ---------------------------------------------------------------------------------------
//
// Copyright 2017, 2019 NXP
// All rights reserved.
//
// THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
// IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.
//****************************************************************************

    .globl VTABLE
    .globl IVOR0_Vector
    .globl IVOR1_Vector
    .globl IVOR2_Vector
    .globl IVOR3_Vector
    .globl IVOR4_Vector
    .globl IVOR5_Vector
    .globl IVOR6_Vector
    .globl IVOR8_Vector
    .globl IVOR15_Vector
    .globl IVOR33_Vector
    .globl IVOR34_Vector
    .globl IVOR35_Vector

/*
 * The USING_OS_FREERTOS must be defined in defined symbol list in case FreeRTOS is used
 * Note: In Design Studio the Symbol List for Assembly files is separate from C files
 */
#ifdef USING_OS_FREERTOS
    .extern vPortISRHandler
    .extern xPortSyscall
#else
    .extern     IVOR4_Handler
#endif
    .extern     IVOR0_Handler
    .extern     IVOR1_Handler
    .extern     IVOR2_Handler
    .extern     IVOR3_Handler
    .extern     IVOR5_Handler
    .extern     IVOR6_Handler
    .extern     IVOR8_Handler
    .extern     IVOR15_Handler
    .extern     IVOR33_Handler
    .extern     IVOR34_Handler
    .extern     IVOR35_Handler

    .section    .core_exceptions_table, "axv"
    .align 4
VTABLE:
/* Critical Input Interrupt (offset 0x00) */
IVOR0_Vector:
    e_b   IVOR0_Handler

/* Machine Check Interrupt (offset 0x10) */
    .align 4
IVOR1_Vector:
    e_b   IVOR1_Handler

/* Data Storage Interrupt (offset 0x20) */
    .align 4
IVOR2_Vector:
    e_b   IVOR2_Handler

/* Instruction Storage Interrupt (offset 0x30) */
    .align 4
IVOR3_Vector:
    e_b   IVOR3_Handler

/* External Input Interrupt (offset 0x40) */
    .align 4
IVOR4_Vector:
#ifdef USING_OS_FREERTOS
    e_b vPortISRHandler
#else
    e_b   IVOR4_Handler
#endif

/* Alignment Interrupt (offset 0x50) */
    .align 4
IVOR5_Vector:
    e_b   IVOR5_Handler

/* Program Interrupt (offset 0x60) */
    .align 4
IVOR6_Vector:
    e_b   IVOR6_Handler

/* Performance Monitor Interrupt (offset 0x70) */
    .align 4
IVOR35_Vector:
    e_b   IVOR35_Handler

/* System Call Interrupt (offset 0x80) */
    .align 4
IVOR8_Vector:
#ifdef USING_OS_FREERTOS
    e_b xPortSyscall
#else
#ifndef SEMIHOSTING
    e_b   IVOR8_Handler
#else
    se_illegal  /* for semihosting support  */
    se_rfi
#endif
#endif

/* Debug Interrupt (offset 0x90) */
    .align 4
IVOR15_Vector:
    e_b   IVOR15_Handler

/* Embedded Floating-point Data Interrupt (offset 0xA0) */
    .align 4
IVOR33_Vector:
    e_b   IVOR33_Handler

/* Embedded Floating-point Round Interrupt (offset 0xB0) */
    .align 4
IVOR34_Vector:
    e_b   IVOR34_Handler
