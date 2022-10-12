################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/APP_bootloader_exchange_info/FIFO/src/multi_cyc_fifo.c 

OBJS += \
./Sources/APP_bootloader_exchange_info/FIFO/src/multi_cyc_fifo.o 

C_DEPS += \
./Sources/APP_bootloader_exchange_info/FIFO/src/multi_cyc_fifo.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/APP_bootloader_exchange_info/FIFO/src/%.o: ../Sources/APP_bootloader_exchange_info/FIFO/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@Sources/APP_bootloader_exchange_info/FIFO/src/multi_cyc_fifo.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


