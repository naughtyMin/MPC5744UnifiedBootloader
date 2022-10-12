################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/Cpu.c \
../Generated_Code/canCom0.c \
../Generated_Code/clockMan1.c \
../Generated_Code/dmaController1.c \
../Generated_Code/eTimer1.c \
../Generated_Code/fccu1.c \
../Generated_Code/pin_mux.c \
../Generated_Code/uart_pal1.c \
../Generated_Code/wdg_pal1.c 

OBJS += \
./Generated_Code/Cpu.o \
./Generated_Code/canCom0.o \
./Generated_Code/clockMan1.o \
./Generated_Code/dmaController1.o \
./Generated_Code/eTimer1.o \
./Generated_Code/fccu1.o \
./Generated_Code/pin_mux.o \
./Generated_Code/uart_pal1.o \
./Generated_Code/wdg_pal1.o 

C_DEPS += \
./Generated_Code/Cpu.d \
./Generated_Code/canCom0.d \
./Generated_Code/clockMan1.d \
./Generated_Code/dmaController1.d \
./Generated_Code/eTimer1.d \
./Generated_Code/fccu1.d \
./Generated_Code/pin_mux.d \
./Generated_Code/uart_pal1.d \
./Generated_Code/wdg_pal1.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@Generated_Code/Cpu.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


