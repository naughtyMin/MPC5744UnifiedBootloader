################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/platform/drivers/src/interrupt/interrupt_manager_MPC57xx.c 

OBJS += \
./SDK/platform/drivers/src/interrupt/interrupt_manager_MPC57xx.o 

C_DEPS += \
./SDK/platform/drivers/src/interrupt/interrupt_manager_MPC57xx.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/drivers/src/interrupt/%.o: ../SDK/platform/drivers/src/interrupt/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@SDK/platform/drivers/src/interrupt/interrupt_manager_MPC57xx.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


