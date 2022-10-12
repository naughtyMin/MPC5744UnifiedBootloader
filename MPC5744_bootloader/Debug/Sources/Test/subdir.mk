################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Test/test.c 

OBJS += \
./Sources/Test/test.o 

C_DEPS += \
./Sources/Test/test.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Test/%.o: ../Sources/Test/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@Sources/Test/test.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


