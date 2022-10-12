################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/APP_bootloader_exchange_info/UDS_stack/TP/src/CAN_TP/can_tp.c \
../Sources/APP_bootloader_exchange_info/UDS_stack/TP/src/CAN_TP/can_tp_cfg.c 

OBJS += \
./Sources/APP_bootloader_exchange_info/UDS_stack/TP/src/CAN_TP/can_tp.o \
./Sources/APP_bootloader_exchange_info/UDS_stack/TP/src/CAN_TP/can_tp_cfg.o 

C_DEPS += \
./Sources/APP_bootloader_exchange_info/UDS_stack/TP/src/CAN_TP/can_tp.d \
./Sources/APP_bootloader_exchange_info/UDS_stack/TP/src/CAN_TP/can_tp_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/APP_bootloader_exchange_info/UDS_stack/TP/src/CAN_TP/%.o: ../Sources/APP_bootloader_exchange_info/UDS_stack/TP/src/CAN_TP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@Sources/APP_bootloader_exchange_info/UDS_stack/TP/src/CAN_TP/can_tp.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


