################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
C:/NXP/S32DS.3.3/S32DS/software/S32SDK_S32K1XX_RTM_4.0.0/platform/devices/S32K148/startup/gcc/startup_S32K148.S 

OBJS += \
./Project_Settings/Startup_Code/startup_S32K148.o 


# Each subdirectory must supply rules for building sources it contributes
Project_Settings/Startup_Code/startup_S32K148.o: C:/NXP/S32DS.3.3/S32DS/software/S32SDK_S32K1XX_RTM_4.0.0/platform/devices/S32K148/startup/gcc/startup_S32K148.S
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS Assembler'
	arm-none-eabi-gcc "@Project_Settings/Startup_Code/startup_S32K148.args" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


