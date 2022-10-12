/*
** ###################################################################
**     Processor:           MPC5744P with 384 KB SRAM
**     Compiler:            GNU C Compiler
**
**     Abstract:
**         Linker file for the GNU C Compiler
**
**     Copyright 2017-2019 NXP
**     All rights reserved.
**
**     THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
**     IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
**     OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
**     IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
**     INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
**     SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
**     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
**     STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
**     IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
**     THE POSSIBILITY OF SUCH DAMAGE.
**
**     http:                 www.nxp.com
**
** ###################################################################
*/


/* Entry Point */
ENTRY(_start)

/* define heap and stack size */
__HEAP_SIZE = DEFINED(__heap_size__) ? __heap_size__ : 0x00000000;
__STACK_SIZE = DEFINED(__stack_size__) ? __stack_size__ : 0x00001000;

/* Define SRAM */
SRAM_BASE_ADDR = DEFINED(__sram_base_addr__) ? __sram_base_addr__ : 0x40000000;
SRAM_SIZE = DEFINED(__sram_size__) ? __sram_size__ : 384K;

/* Define local data memory */
LOCAL_DMEM_BASE_ADDR = DEFINED(__local_dmem_base_addr__) ? __local_dmem_base_addr__ : 0x50800000;
LOCAL_DMEM_SIZE =  DEFINED(__local_dmem_size__) ? __local_dmem_size__ : 64K;

MEMORY
{
    SRAM : org = SRAM_BASE_ADDR, len = SRAM_SIZE
    local_dmem : org = LOCAL_DMEM_BASE_ADDR, len = LOCAL_DMEM_SIZE
}


SECTIONS
{
    /*========================== Text ==========================*/
    .startup : ALIGN(0x400)
    {
        __start = . ;
        *(.startup)
    } > SRAM

    .core_exceptions_table : ALIGN(4096)
    {
        __IVPR_VALUE = .;
        *(.core_exceptions_table)
    } > SRAM

    .intc_vector_table : ALIGN(4096)
    {
        __VECTOR_TABLE = .;
        __VECTOR_RAM = .;
        __interrupts_start__ = .;
        KEEP(*(.intc_vector_table)) /* Startup code */
        __interrupts_end__ = .;
    } > SRAM
    __RAM_VECTOR_TABLE_SIZE = 0x0; /* No copy */
    __VECTOR_TABLE_COPY_END = __VECTOR_TABLE + __RAM_VECTOR_TABLE_SIZE;

    __CUSTOM_ROM = 0;
    __CUSTOM_END = 0; /* No copy */
    .customSectionBlock :
    {
        . = ALIGN(4);
        __CUSTOM_RAM = .;
        __customSectionStart = .;
        __customSection_start__ = .;
        KEEP(*(.customSection)) /* Keep section even if not referenced. */
        __customSection_end__ = .;
        __customSectionEnd = .;
    } > SRAM

    .text :
    {
        *(.text.startup)
        *(.text)
        *(.text.*)
        KEEP(*(.init))
        KEEP(*(.fini))
        /* discard boot header in RAM target.*/
        *(.rchw)
        *(.cpu0_reset_vector)
        . = ALIGN(16);
    } > SRAM
    .sdata2 :
    {
        . = ALIGN(4);
        __sdata2_start__ = .; /* Create a global symbol at sdata2 start. */
        *(.sdata2)
        *(.sdata2.*)
        . = ALIGN(4);
        __sdata2_end__ = .; /* Define a global symbol at sdata2 end. */
    } > SRAM

/* migration to version v1.2
   define section PREINIT_ARRAY */

.preinit_array :
  {
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP (*(.preinit_array))
    PROVIDE_HIDDEN (__preinit_array_end = .);
  } > SRAM


/* end section PREINIT_ARRAY */
/*  migration to version v1.2
    define section INIT_ARRAY*/

  .init_array :
  {
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT(.init_array.*)))
    KEEP (*(.init_array ))
    PROVIDE_HIDDEN (__init_array_end = .);
  } > SRAM

/* end section INIT_ARRAY */

/* migration to version v1.2
   define section FINI_ARRAY */

  .fini_array :
  {
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(SORT(.fini_array.*)))
    KEEP (*(.fini_array ))
    PROVIDE_HIDDEN (__fini_array_end = .);
  } > SRAM

/* end  section FINI_ARRAY */
/* migration to version v1.2
   define section DTORS */

  .dtors :
  {
    KEEP (*crtbegin.o(.dtors))
    KEEP (*crtbegin?.o(.dtors))
    KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .dtors))
    KEEP (*(SORT(.dtors.*)))
    KEEP (*(.dtors))
  } > SRAM

/* end section DTORS */
/* migration to version v1.2
   define section CTORS */

  .ctors :
  {
    /* gcc uses crtbegin.o to find the start of
       the constructors, so we make sure it is
       first.  Because this is a wildcard, it
       doesn't matter if the user does not
       actually link against crtbegin.o; the
       linker won't look for a file to match a
       wildcard.  The wildcard also means that it
       doesn't matter which directory crtbegin.o
       is in.  */
    KEEP (*crtbegin.o(.ctors))
    KEEP (*crtbegin?.o(.ctors))
    /* We don't want to include the .ctor section from
       the crtend.o file until after the sorted ctors.
       The .ctor section from the crtend file contains the
       end of ctors marker and it must be last */
    KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .ctors))
    KEEP (*(SORT(.ctors.*)))
    KEEP (*(.ctors))
  } > SRAM

/* end section CTORS */

    /* Section for storing functions that needs to execute from RAM */
    __CODE_ROM = 0;
    __CODE_END = 0; /* No copy */
    .code_ram :
    {
        . = ALIGN(4);
        __CODE_RAM = .;
        __code_ram_start__ = .;
        KEEP(*(.code_ram)) /* Custom section for storing code in RAM */
        __code_ram_end__ = .;
        . = ALIGN(4);
    } > SRAM

    .rodata :
    {
        *(.rodata)
        *(.rodata.*)
    } > SRAM

    .eh_frame_hdr : { *(.eh_frame_hdr) } > SRAM
    .eh_frame : { KEEP (*(.eh_frame)) } > SRAM

    /* Sections used by startup for data initialization. */
    .init_table :
    {
        . = ALIGN(4);
        __COPY_TABLE = .;
        KEEP(*(.init_table))
    } > SRAM
    .zero_table :
    {
        . = ALIGN(4);
        __ZERO_TABLE = .;
        KEEP(*(.zero_table))
    } > SRAM

    __TEXT_END = .; /* Define a global symbol at end of code. */

    /*========================== DATA ==========================*/
    __DATA_ROM = 0;
    __DATA_END = 0; /* No copy */
    .data :
    {
        . = ALIGN(4);
        __DATA_RAM = .;
        __data_start__ = .; /* Create a global symbol at data start. */
        *(.data)
        *(.data.*)
        . = ALIGN(4);
        __data_end__ = .; /* Define a global symbol at data end. */
    }  > SRAM

    __SDATA_ROM = 0;
    __SDATA_END = 0; /* No copy */
    .sdata :
    {
        . = ALIGN(4);
        __SDATA_RAM = .;
        __sdata_start__ = .; /* Create a global symbol at sdata start. */
        *(.sdata)
        *(.sdata.*)
        . = ALIGN(4);
        __sdata_end__ = .; /* Define a global symbol at sdata end. */
    } > SRAM

    .sbss (NOLOAD) :
    {
        . = ALIGN(4);
        __SBSS_START = .;
        __sbss_start__ = .; /* Create a global symbol at sbss start. */
        *(.sbss)
        *(.sbss.*)
        . = ALIGN(4);
        __sbss_end__ = .; /* Define a global symbol at sbss end. */
        __SBSS_END = .;
    } > SRAM

    .bss (NOLOAD) :
    {
        . = ALIGN(4);
        __BSS_START = .;
        __bss_start__ = .; /* Create a global symbol at bss start. */
        *(.bss)
        *(.bss.*)
        *(COMMON)
        . = ALIGN(4);
        __bss_end__ = .; /* Define a global symbol at bss end. */
        __BSS_END = .;
    } > SRAM

    .stack (NOLOAD) : ALIGN(16)
    {
        __HEAP = .;
        PROVIDE (_end = .);
        PROVIDE (end = .);
        . += __HEAP_SIZE;
        __HEAP_END = .;
        _stack_end = .;
        . += __STACK_SIZE;
        . = ALIGN(4);
        _stack_addr = .;
        __SP_INIT = .;
    } > local_dmem

/*-------- LABELS USED IN CODE -------------------------------*/

/* Labels Used for Initialising SRAM ECC */
__SRAM_SIZE = SRAM_SIZE - (__sdata_end__ - SRAM_BASE_ADDR);
/* Skip .sdata section*/
__SRAM_BASE_ADDR = __sdata_end__;
/* Labels Used for Initialising DMEM */
__LOCAL_DMEM_SIZE = LOCAL_DMEM_SIZE;
__LOCAL_DMEM_BASE_ADDR = LOCAL_DMEM_BASE_ADDR;

__BSS_SIZE    = __BSS_END - __BSS_START;

}
