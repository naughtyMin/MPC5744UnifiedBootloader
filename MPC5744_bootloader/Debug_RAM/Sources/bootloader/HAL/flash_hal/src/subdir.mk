################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/bootloader/HAL/flash_hal/src/flash_hal.c \
../Sources/bootloader/HAL/flash_hal/src/flash_hal_Cfg.c 

OBJS += \
./Sources/bootloader/HAL/flash_hal/src/flash_hal.o \
./Sources/bootloader/HAL/flash_hal/src/flash_hal_Cfg.o 

C_DEPS += \
./Sources/bootloader/HAL/flash_hal/src/flash_hal.d \
./Sources/bootloader/HAL/flash_hal/src/flash_hal_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/bootloader/HAL/flash_hal/src/%.o: ../Sources/bootloader/HAL/flash_hal/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@Sources/bootloader/HAL/flash_hal/src/flash_hal.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


