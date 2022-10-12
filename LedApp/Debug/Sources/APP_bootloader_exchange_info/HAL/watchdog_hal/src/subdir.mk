################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/APP_bootloader_exchange_info/HAL/watchdog_hal/src/watchdog_hal.c 

OBJS += \
./Sources/APP_bootloader_exchange_info/HAL/watchdog_hal/src/watchdog_hal.o 

C_DEPS += \
./Sources/APP_bootloader_exchange_info/HAL/watchdog_hal/src/watchdog_hal.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/APP_bootloader_exchange_info/HAL/watchdog_hal/src/%.o: ../Sources/APP_bootloader_exchange_info/HAL/watchdog_hal/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@Sources/APP_bootloader_exchange_info/HAL/watchdog_hal/src/watchdog_hal.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


