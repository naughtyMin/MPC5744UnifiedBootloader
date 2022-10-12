################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Sources/APP_bootloader_exchange_info/boot/src/subdir.mk
-include Sources/APP_bootloader_exchange_info/auto_lib/src/subdir.mk
-include Sources/APP_bootloader_exchange_info/UDS_stack/UDS/src/subdir.mk
-include Sources/APP_bootloader_exchange_info/UDS_stack/TP/src/LIN_TP/subdir.mk
-include Sources/APP_bootloader_exchange_info/UDS_stack/TP/src/CAN_TP/subdir.mk
-include Sources/APP_bootloader_exchange_info/UDS_stack/TP/src/subdir.mk
-include Sources/APP_bootloader_exchange_info/Simulink/subdir.mk
-include Sources/APP_bootloader_exchange_info/HAL/watchdog_hal/src/subdir.mk
-include Sources/APP_bootloader_exchange_info/HAL/timer_hal/src/subdir.mk
-include Sources/APP_bootloader_exchange_info/HAL/crc_hal/src/subdir.mk
-include Sources/APP_bootloader_exchange_info/FIFO/src/subdir.mk
-include Sources/APP_bootloader_exchange_info/Debug/src/subdir.mk
-include Sources/APP_bootloader_exchange_info/APP_Demo/subdir.mk
-include Sources/subdir.mk
-include SDK/rtos/osif/subdir.mk
-include SDK/platform/pal/src/wdg/subdir.mk
-include SDK/platform/pal/src/uart/subdir.mk
-include SDK/platform/drivers/src/swt/subdir.mk
-include SDK/platform/drivers/src/pins/siul2/subdir.mk
-include SDK/platform/drivers/src/linflexd/subdir.mk
-include SDK/platform/drivers/src/interrupt/subdir.mk
-include SDK/platform/drivers/src/flexcan/subdir.mk
-include SDK/platform/drivers/src/fccu/subdir.mk
-include SDK/platform/drivers/src/etimer/subdir.mk
-include SDK/platform/drivers/src/edma/subdir.mk
-include SDK/platform/drivers/src/clock/MPC57xx/subdir.mk
-include SDK/platform/devices/MPC5744P/startup/subdir.mk
-include SDK/platform/devices/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include Generated_Code/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
LedApp.bin \

SECONDARY_SIZE += \
LedApp.siz \


# All Target
all: LedApp.elf secondary-outputs

# Tool invocations
LedApp.elf: $(OBJS) C:/Users/Jeremy/workspaceS32DS.Power.2.1/LedApp/Project_Settings/Linker_Files/linker_flash.ld $(OSPT) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	powerpc-eabivle-gcc -o "LedApp.elf" "@LedApp.args"  $(USER_OBJS) $(LIBS) $(OSPT)
	@echo 'Finished building target: $@'
	@echo ' '

LedApp.bin: LedApp.elf
	@echo 'Invoking: Standard S32DS Create Flash Image'
	powerpc-eabivle-objcopy -O binary LedApp.elf  "LedApp.bin"
	@echo 'Finished building: $@'
	@echo ' '

LedApp.siz: LedApp.elf
	@echo 'Invoking: Standard S32DS Print Size'
	powerpc-eabivle-size --format=berkeley LedApp.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
