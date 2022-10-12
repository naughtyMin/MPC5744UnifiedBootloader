################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/APP_bootloader_exchange_info/UDS_stack/TP/src/TP.c \
../Sources/APP_bootloader_exchange_info/UDS_stack/TP/src/TP_Cfg.c 

OBJS += \
./Sources/APP_bootloader_exchange_info/UDS_stack/TP/src/TP.o \
./Sources/APP_bootloader_exchange_info/UDS_stack/TP/src/TP_Cfg.o 

C_DEPS += \
./Sources/APP_bootloader_exchange_info/UDS_stack/TP/src/TP.d \
./Sources/APP_bootloader_exchange_info/UDS_stack/TP/src/TP_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/APP_bootloader_exchange_info/UDS_stack/TP/src/%.o: ../Sources/APP_bootloader_exchange_info/UDS_stack/TP/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@Sources/APP_bootloader_exchange_info/UDS_stack/TP/src/TP.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


