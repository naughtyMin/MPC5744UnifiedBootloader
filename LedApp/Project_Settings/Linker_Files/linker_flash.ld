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

/* Define FLASH */
FLASH_BASE_ADDR = DEFINED(__flash_base_addr__) ? __flash_base_addr__ : 0x01000000;
FLASH_SIZE =  DEFINED(__flash_size__) ? __flash_size__ : 2048K;

/* Define SRAM */
SRAM_BASE_ADDR = DEFINED(__sram_base_addr__) ? __sram_base_addr__ : 0x40000000;
SRAM_SIZE = DEFINED(__sram_size__) ? __sram_size__ : 384k;/*0x5FF80;*/

/* Define local data memory */
LOCAL_DMEM_BASE_ADDR = DEFINED(__local_dmem_base_addr__) ? __local_dmem_base_addr__ : 0x50800000;
LOCAL_DMEM_SIZE =  DEFINED(__local_dmem_size__) ? __local_dmem_size__ : 64K;

APPUP_BOOT_FLAG_LEN = 0x00000010;

MEMORY
{
	/* Flash */
    flash_rchw : org = 0x01000000,   len = 0x4
    cpu0_reset_vec : org = 0x01000004,   len = 0x4
        
    m_text :	org = 0x01000400, len = 2047K  

    /* SRAM */
    m_data : org = 0x40000000, len = 0x5FFF0
    appup_boot_flag : org = 0x4005FFF0, len = APPUP_BOOT_FLAG_LEN
    
    /* DMEM */
    local_dmem : org = LOCAL_DMEM_BASE_ADDR, len = LOCAL_DMEM_SIZE
}


SECTIONS
{
    .rchw :
    {
        KEEP(*(.rchw))
    } > flash_rchw

    .cpu0_reset_vector :
    {
        KEEP(*(.cpu0_reset_vector))
    } > cpu0_reset_vec

    /* Note: if you move the 'startup' section shall modify the RCHW2_2 value for the corresponding core in the flashrchw.c file. */
    .startup : ALIGN(0x400)
    {
        __start = .;
        *(.startup)
    } > m_text

    .core_exceptions_table : ALIGN(4096)
    {
        __IVPR_VALUE = .;
        *(.core_exceptions_table)
    } > m_text

    .intc_vector_table : ALIGN(4096)
    {
        __VECTOR_TABLE = .;
        __interrupts_start__ = .;
        KEEP(*(.intc_vector_table)) /* Startup code */
        __interrupts_end__ = .;
    } > m_text
    __RAM_VECTOR_TABLE_SIZE = 0xC00;
    __VECTOR_TABLE_COPY_END = __VECTOR_TABLE + __RAM_VECTOR_TABLE_SIZE;

    .text :
    {
        *(.text.startup)
        *(.text)
        *(.text.*)
        KEEP(*(.init))
        KEEP(*(.fini))
        . = ALIGN(16);
    } > m_text
    .sdata2 :
    {
        . = ALIGN(4);
        __sdata2_start__ = .; /* Create a global symbol at sdata2 start. */
        *(.sdata2)
        *(.sdata2.*)
        . = ALIGN(4);
        __sdata2_end__ = .; /* Define a global symbol at sdata2 end. */
    } > m_text
    .got2 :
    {
        *(.got2*)
    } > m_text
/* migration to version v1.2
   define section PREINIT_ARRAY */

.preinit_array :
  {
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP (*(.preinit_array))
    PROVIDE_HIDDEN (__preinit_array_end = .);
  } > m_text

/* end section PREINIT_ARRAY */
/*  migration to version v1.2
    define section INIT_ARRAY*/

  .init_array :
  {
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT(.init_array.*)))
    KEEP (*(.init_array ))
    PROVIDE_HIDDEN (__init_array_end = .);
  } > m_text

/* end section INIT_ARRAY */

/* migration to version v1.2
   define section DTORS */

  .dtors :
  {
    KEEP (*crtbegin.o(.dtors))
    KEEP (*crtbegin?.o(.dtors))
    KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .dtors))
    KEEP (*(SORT(.dtors.*)))
    KEEP (*(.dtors))
  } > m_text

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
  } > m_text

/* end section CTORS */

/* migration to version v1.2
   define section FINI_ARRAY */

  .fini_array :
  {
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(SORT(.fini_array.*)))
    KEEP (*(.fini_array ))
    PROVIDE_HIDDEN (__fini_array_end = .);
  } > m_text

/* end  section FINI_ARRAY */

    .rodata :
    {
        *(.rodata)
        *(.rodata.*)
    } > m_text

    .eh_frame_hdr : { *(.eh_frame_hdr) } > m_text
    .eh_frame : { KEEP (*(.eh_frame)) } > m_text

    /* Sections used by startup for data initialization. */
    .init_table :
    {
        . = ALIGN(4);
        __COPY_TABLE = .;
        KEEP(*(.init_table))
    } > m_text
    .zero_table :
    {
        . = ALIGN(4);
        __ZERO_TABLE = .;
        KEEP(*(.zero_table))
    } > m_text

    __TEXT_END = .; /* Define a global symbol at end of code. */

    .interrupts_ram : ALIGN(4096)
    {
        __VECTOR_RAM = .;
        *(.m_interrupts_ram)
        . += __RAM_VECTOR_TABLE_SIZE;
    } > m_data

    __CUSTOM_ROM = __TEXT_END; /* Symbol is used by startup for custom initialization. */
    .customSectionBlock : AT (__CUSTOM_ROM)
    {
        . = ALIGN(4);
        __CUSTOM_RAM = .;
        __customSectionStart = .;
        __customSection_start__ = .;
        KEEP(*(.customSection)) /* Keep section even if not referenced. */
        . = ALIGN(4);
        __customSection_end__ = .;
        __customSectionEnd = .;
    } > m_data
    __CUSTOM_END = __CUSTOM_ROM + (__customSection_end__ - __customSection_start__);

    __DATA_ROM = __CUSTOM_END; /* Symbol is used by startup for data initialization. */
    .data : AT (__DATA_ROM)
    {
        . = ALIGN(4);
        __DATA_RAM = .;
        __data_start__ = .; /* Create a global symbol at data start. */
        *(.data)
        *(.data.*)
        . = ALIGN(4);
        __data_end__ = .; /* Define a global symbol at data end. */
    } > m_data
    __DATA_END = __DATA_ROM + (__data_end__ - __data_start__);

    __SDATA_ROM = __DATA_END; /* Symbol is used by startup for sdata initialization. */
    .sdata : AT (__SDATA_ROM)
    {
        . = ALIGN(4);
        __SDATA_RAM = .;
        __sdata_start__ = .; /* Create a global symbol at sdata start. */
        *(.sdata)
        *(.sdata.*)
        . = ALIGN(4);
        __sdata_end__ = .; /* Define a global symbol at sdata end. */
    } > m_data
    __SDATA_END = __SDATA_ROM + (__sdata_end__ - __sdata_start__);

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
    } > m_data

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
    } > m_data

    __CODE_ROM = __SDATA_END; /* Symbol is used by code initialization. */
    .code : AT (__CODE_ROM)
    {
        . = ALIGN(4);
        __CODE_RAM = .;
        __code_start__ = .; /* Create a global symbol at code start. */
        __code_ram_start__ = .;
        KEEP(*(.code_ram)) /* Custom section for storing code in RAM */
        . = ALIGN(4);
        __code_ram_end__ = .;
        __code_end__ = .; /* Define a global symbol at code end. */
    } > m_data
    __CODE_END = __CODE_ROM + (__code_end__ - __code_start__);

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
    
  	.flag :
  	{
  		__APP_UPDATE_ADDR = .;
  		. += 0x01;
  		__BOOTLOADER_REQUEST_ADDR = .;
	  	. += APPUP_BOOT_FLAG_LEN - 0x01;
	  	*(.flag_ram);
	} > appup_boot_flag

/*-------- LABELS USED IN CODE -------------------------------*/

/* Labels Used for Initialising SRAM ECC */
__SRAM_SIZE = SRAM_SIZE;
__SRAM_BASE_ADDR = SRAM_BASE_ADDR;
/* Labels Used for Initialising DMEM */
__LOCAL_DMEM_SIZE = LOCAL_DMEM_SIZE;
__LOCAL_DMEM_BASE_ADDR = LOCAL_DMEM_BASE_ADDR;

__BSS_SIZE    = __BSS_END - __BSS_START;

}
