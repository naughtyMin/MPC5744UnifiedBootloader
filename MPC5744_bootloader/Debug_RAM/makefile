################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Sources/bootloader/flash/src/subdir.mk
-include Sources/bootloader/boot/src/subdir.mk
-include Sources/bootloader/auto_lib/src/subdir.mk
-include Sources/bootloader/UDS_stack/UDS/src/subdir.mk
-include Sources/bootloader/UDS_stack/TP/src/LIN_TP/subdir.mk
-include Sources/bootloader/UDS_stack/TP/src/CAN_TP/subdir.mk
-include Sources/bootloader/UDS_stack/TP/src/subdir.mk
-include Sources/bootloader/HAL/watchdog_hal/src/subdir.mk
-include Sources/bootloader/HAL/timer_hal/src/subdir.mk
-include Sources/bootloader/HAL/flash_hal/src/subdir.mk
-include Sources/bootloader/HAL/crc_hal/src/subdir.mk
-include Sources/bootloader/HAL/UDS_algorithm_hal/src/subdir.mk
-include Sources/bootloader/Flash_driver/subdir.mk
-include Sources/bootloader/Flash_app/src/subdir.mk
-include Sources/bootloader/FIFO/src/subdir.mk
-include Sources/bootloader/Demo/subdir.mk
-include Sources/bootloader/Debug/src/subdir.mk
-include Sources/Test/subdir.mk
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
SECONDARY_SIZE += \
MPC5744_bootloader.siz \


# All Target
all: MPC5744_bootloader.elf secondary-outputs

# Tool invocations
MPC5744_bootloader.elf: $(OBJS) C:/Users/Jeremy/workspaceS32DS.Power.2.1/MPC5744_bootloader/Project_Settings/Linker_Files/linker_ram.ld $(OSPT) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	powerpc-eabivle-gcc -o "MPC5744_bootloader.elf" "@MPC5744_bootloader.args"  $(USER_OBJS) $(LIBS) $(OSPT)
	@echo 'Finished building target: $@'
	@echo ' '

MPC5744_bootloader.siz: MPC5744_bootloader.elf
	@echo 'Invoking: Standard S32DS Print Size'
	powerpc-eabivle-size --format=berkeley MPC5744_bootloader.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
