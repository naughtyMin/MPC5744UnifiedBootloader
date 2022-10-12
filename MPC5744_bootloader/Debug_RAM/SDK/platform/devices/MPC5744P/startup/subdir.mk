################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/platform/devices/MPC5744P/startup/system_MPC5744P.c 

OBJS += \
./SDK/platform/devices/MPC5744P/startup/system_MPC5744P.o 

C_DEPS += \
./SDK/platform/devices/MPC5744P/startup/system_MPC5744P.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/devices/MPC5744P/startup/%.o: ../SDK/platform/devices/MPC5744P/startup/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@SDK/platform/devices/MPC5744P/startup/system_MPC5744P.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


