################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/APP_bootloader_exchange_info/Debug/src/bootloader_debug.c \
../Sources/APP_bootloader_exchange_info/Debug/src/debug_IO.c \
../Sources/APP_bootloader_exchange_info/Debug/src/debug_timer.c 

OBJS += \
./Sources/APP_bootloader_exchange_info/Debug/src/bootloader_debug.o \
./Sources/APP_bootloader_exchange_info/Debug/src/debug_IO.o \
./Sources/APP_bootloader_exchange_info/Debug/src/debug_timer.o 

C_DEPS += \
./Sources/APP_bootloader_exchange_info/Debug/src/bootloader_debug.d \
./Sources/APP_bootloader_exchange_info/Debug/src/debug_IO.d \
./Sources/APP_bootloader_exchange_info/Debug/src/debug_timer.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/APP_bootloader_exchange_info/Debug/src/%.o: ../Sources/APP_bootloader_exchange_info/Debug/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@Sources/APP_bootloader_exchange_info/Debug/src/bootloader_debug.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


