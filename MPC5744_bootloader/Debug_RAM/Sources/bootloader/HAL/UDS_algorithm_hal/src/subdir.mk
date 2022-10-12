################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/bootloader/HAL/UDS_algorithm_hal/src/AES.c \
../Sources/bootloader/HAL/UDS_algorithm_hal/src/UDS_alg_hal.c 

OBJS += \
./Sources/bootloader/HAL/UDS_algorithm_hal/src/AES.o \
./Sources/bootloader/HAL/UDS_algorithm_hal/src/UDS_alg_hal.o 

C_DEPS += \
./Sources/bootloader/HAL/UDS_algorithm_hal/src/AES.d \
./Sources/bootloader/HAL/UDS_algorithm_hal/src/UDS_alg_hal.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/bootloader/HAL/UDS_algorithm_hal/src/%.o: ../Sources/bootloader/HAL/UDS_algorithm_hal/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@Sources/bootloader/HAL/UDS_algorithm_hal/src/AES.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


