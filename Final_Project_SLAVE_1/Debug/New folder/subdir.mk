################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../New\ folder/KPD_Prog.c 

OBJS += \
./New\ folder/KPD_Prog.o 

C_DEPS += \
./New\ folder/KPD_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
New\ folder/KPD_Prog.o: ../New\ folder/KPD_Prog.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"New folder/KPD_Prog.d" -MT"New\ folder/KPD_Prog.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


