################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/bootloader/boot/src/boot.c \
../Sources/bootloader/boot/src/boot_Cfg.c 

OBJS += \
./Sources/bootloader/boot/src/boot.o \
./Sources/bootloader/boot/src/boot_Cfg.o 

C_DEPS += \
./Sources/bootloader/boot/src/boot.d \
./Sources/bootloader/boot/src/boot_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/bootloader/boot/src/%.o: ../Sources/bootloader/boot/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@Sources/bootloader/boot/src/boot.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


