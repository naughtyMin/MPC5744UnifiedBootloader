################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/bootloader/Debug/src/bootloader_debug.c \
../Sources/bootloader/Debug/src/debug_IO.c \
../Sources/bootloader/Debug/src/debug_timer.c 

OBJS += \
./Sources/bootloader/Debug/src/bootloader_debug.o \
./Sources/bootloader/Debug/src/debug_IO.o \
./Sources/bootloader/Debug/src/debug_timer.o 

C_DEPS += \
./Sources/bootloader/Debug/src/bootloader_debug.d \
./Sources/bootloader/Debug/src/debug_IO.d \
./Sources/bootloader/Debug/src/debug_timer.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/bootloader/Debug/src/%.o: ../Sources/bootloader/Debug/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@Sources/bootloader/Debug/src/bootloader_debug.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


