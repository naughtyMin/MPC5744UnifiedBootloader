################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/bootloader/FIFO/src/multi_cyc_fifo.c 

OBJS += \
./Sources/bootloader/FIFO/src/multi_cyc_fifo.o 

C_DEPS += \
./Sources/bootloader/FIFO/src/multi_cyc_fifo.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/bootloader/FIFO/src/%.o: ../Sources/bootloader/FIFO/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@Sources/bootloader/FIFO/src/multi_cyc_fifo.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


