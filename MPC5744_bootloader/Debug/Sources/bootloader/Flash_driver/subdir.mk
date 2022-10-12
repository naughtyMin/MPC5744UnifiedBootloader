################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/bootloader/Flash_driver/flash_c55_driver.c \
../Sources/bootloader/Flash_driver/flash_driver.c 

OBJS += \
./Sources/bootloader/Flash_driver/flash_c55_driver.o \
./Sources/bootloader/Flash_driver/flash_driver.o 

C_DEPS += \
./Sources/bootloader/Flash_driver/flash_c55_driver.d \
./Sources/bootloader/Flash_driver/flash_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/bootloader/Flash_driver/%.o: ../Sources/bootloader/Flash_driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@Sources/bootloader/Flash_driver/flash_c55_driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


