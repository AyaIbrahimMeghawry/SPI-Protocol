################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../New\ folder/LCD_Prog.c 

OBJS += \
./New\ folder/LCD_Prog.o 

C_DEPS += \
./New\ folder/LCD_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
New\ folder/LCD_Prog.o: ../New\ folder/LCD_Prog.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"New folder/LCD_Prog.d" -MT"New\ folder/LCD_Prog.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


