################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/APP_bootloader_exchange_info/Simulink/PowerCtrolProject1_S32K144.c \
../Sources/APP_bootloader_exchange_info/Simulink/PowerCtrolProject1_S32K144_data.c \
../Sources/APP_bootloader_exchange_info/Simulink/rtGetInf.c \
../Sources/APP_bootloader_exchange_info/Simulink/rtGetNaN.c \
../Sources/APP_bootloader_exchange_info/Simulink/rt_nonfinite.c 

OBJS += \
./Sources/APP_bootloader_exchange_info/Simulink/PowerCtrolProject1_S32K144.o \
./Sources/APP_bootloader_exchange_info/Simulink/PowerCtrolProject1_S32K144_data.o \
./Sources/APP_bootloader_exchange_info/Simulink/rtGetInf.o \
./Sources/APP_bootloader_exchange_info/Simulink/rtGetNaN.o \
./Sources/APP_bootloader_exchange_info/Simulink/rt_nonfinite.o 

C_DEPS += \
./Sources/APP_bootloader_exchange_info/Simulink/PowerCtrolProject1_S32K144.d \
./Sources/APP_bootloader_exchange_info/Simulink/PowerCtrolProject1_S32K144_data.d \
./Sources/APP_bootloader_exchange_info/Simulink/rtGetInf.d \
./Sources/APP_bootloader_exchange_info/Simulink/rtGetNaN.d \
./Sources/APP_bootloader_exchange_info/Simulink/rt_nonfinite.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/APP_bootloader_exchange_info/Simulink/%.o: ../Sources/APP_bootloader_exchange_info/Simulink/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@Sources/APP_bootloader_exchange_info/Simulink/PowerCtrolProject1_S32K144.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


