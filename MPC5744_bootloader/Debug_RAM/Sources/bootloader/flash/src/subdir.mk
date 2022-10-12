################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/bootloader/flash/src/flash.c \
../Sources/bootloader/flash/src/flash_cfg.c 

OBJS += \
./Sources/bootloader/flash/src/flash.o \
./Sources/bootloader/flash/src/flash_cfg.o 

C_DEPS += \
./Sources/bootloader/flash/src/flash.d \
./Sources/bootloader/flash/src/flash_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/bootloader/flash/src/%.o: ../Sources/bootloader/flash/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@Sources/bootloader/flash/src/flash.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


