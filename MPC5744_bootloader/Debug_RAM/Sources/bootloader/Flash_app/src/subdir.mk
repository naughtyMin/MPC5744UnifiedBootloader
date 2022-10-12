################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/bootloader/Flash_app/src/fls_app.c 

OBJS += \
./Sources/bootloader/Flash_app/src/fls_app.o 

C_DEPS += \
./Sources/bootloader/Flash_app/src/fls_app.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/bootloader/Flash_app/src/%.o: ../Sources/bootloader/Flash_app/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@Sources/bootloader/Flash_app/src/fls_app.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


