################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/bootloader/UDS_stack/UDS/src/uds_app.c \
../Sources/bootloader/UDS_stack/UDS/src/uds_app_cfg.c 

OBJS += \
./Sources/bootloader/UDS_stack/UDS/src/uds_app.o \
./Sources/bootloader/UDS_stack/UDS/src/uds_app_cfg.o 

C_DEPS += \
./Sources/bootloader/UDS_stack/UDS/src/uds_app.d \
./Sources/bootloader/UDS_stack/UDS/src/uds_app_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/bootloader/UDS_stack/UDS/src/%.o: ../Sources/bootloader/UDS_stack/UDS/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@Sources/bootloader/UDS_stack/UDS/src/uds_app.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


