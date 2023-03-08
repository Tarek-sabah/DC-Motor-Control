################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CONFIG/Dio_Lcfg.c \
../CONFIG/KEYPAD_Lcfg.c \
../CONFIG/L298N_Lcfg.c \
../CONFIG/LCD_Lcfg.c \
../CONFIG/Port_Lcfg.c \
../CONFIG/TIMER0_Lcfg.c 

OBJS += \
./CONFIG/Dio_Lcfg.o \
./CONFIG/KEYPAD_Lcfg.o \
./CONFIG/L298N_Lcfg.o \
./CONFIG/LCD_Lcfg.o \
./CONFIG/Port_Lcfg.o \
./CONFIG/TIMER0_Lcfg.o 

C_DEPS += \
./CONFIG/Dio_Lcfg.d \
./CONFIG/KEYPAD_Lcfg.d \
./CONFIG/L298N_Lcfg.d \
./CONFIG/LCD_Lcfg.d \
./CONFIG/Port_Lcfg.d \
./CONFIG/TIMER0_Lcfg.d 


# Each subdirectory must supply rules for building sources it contributes
CONFIG/%.o: ../CONFIG/%.c CONFIG/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Motor Control\Code" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Motor Control\Code\HAL\L298N" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Motor Control\Code\MCAL\GID" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Motor Control\Code\MCAL\TIMER0" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Motor Control\Code\APP\MENU" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Motor Control\Code\HAL\KEYPAD" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Motor Control\Code\HAL\LCD" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Motor Control\Code\APP" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Motor Control\Code\CONFIG" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Motor Control\Code\HAL" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Motor Control\Code\LIB" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Motor Control\Code\MCAL" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Motor Control\Code\MCAL\DIO" -I"D:\Tarek\Work\Learning\NTI\4 Months Program\AVR\AVR Projects\Motor Control\Code\MCAL\PORT" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


