################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/bootloader/auto_lib/src/autolibc.c 

OBJS += \
./Sources/bootloader/auto_lib/src/autolibc.o 

C_DEPS += \
./Sources/bootloader/auto_lib/src/autolibc.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/bootloader/auto_lib/src/%.o: ../Sources/bootloader/auto_lib/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@Sources/bootloader/auto_lib/src/autolibc.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


