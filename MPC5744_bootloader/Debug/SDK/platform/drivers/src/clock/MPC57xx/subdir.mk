################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/platform/drivers/src/clock/MPC57xx/clock_MPC57xx.c 

OBJS += \
./SDK/platform/drivers/src/clock/MPC57xx/clock_MPC57xx.o 

C_DEPS += \
./SDK/platform/drivers/src/clock/MPC57xx/clock_MPC57xx.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/drivers/src/clock/MPC57xx/%.o: ../SDK/platform/drivers/src/clock/MPC57xx/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@SDK/platform/drivers/src/clock/MPC57xx/clock_MPC57xx.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


