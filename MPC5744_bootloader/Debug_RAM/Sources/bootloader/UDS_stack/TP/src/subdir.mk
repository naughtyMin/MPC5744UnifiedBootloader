################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/bootloader/UDS_stack/TP/src/TP.c \
../Sources/bootloader/UDS_stack/TP/src/TP_Cfg.c 

OBJS += \
./Sources/bootloader/UDS_stack/TP/src/TP.o \
./Sources/bootloader/UDS_stack/TP/src/TP_Cfg.o 

C_DEPS += \
./Sources/bootloader/UDS_stack/TP/src/TP.d \
./Sources/bootloader/UDS_stack/TP/src/TP_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/bootloader/UDS_stack/TP/src/%.o: ../Sources/bootloader/UDS_stack/TP/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@Sources/bootloader/UDS_stack/TP/src/TP.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


