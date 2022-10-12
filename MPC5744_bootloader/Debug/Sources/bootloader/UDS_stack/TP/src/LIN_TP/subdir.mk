################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/bootloader/UDS_stack/TP/src/LIN_TP/LIN_tp.c \
../Sources/bootloader/UDS_stack/TP/src/LIN_TP/LIN_tp_cfg.c 

OBJS += \
./Sources/bootloader/UDS_stack/TP/src/LIN_TP/LIN_tp.o \
./Sources/bootloader/UDS_stack/TP/src/LIN_TP/LIN_tp_cfg.o 

C_DEPS += \
./Sources/bootloader/UDS_stack/TP/src/LIN_TP/LIN_tp.d \
./Sources/bootloader/UDS_stack/TP/src/LIN_TP/LIN_tp_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/bootloader/UDS_stack/TP/src/LIN_TP/%.o: ../Sources/bootloader/UDS_stack/TP/src/LIN_TP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@Sources/bootloader/UDS_stack/TP/src/LIN_TP/LIN_tp.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


