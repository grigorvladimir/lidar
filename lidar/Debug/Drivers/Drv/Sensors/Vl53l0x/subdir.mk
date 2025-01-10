################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Drv/Sensors/Vl53l0x/Vl53l0x.c 

OBJS += \
./Drivers/Drv/Sensors/Vl53l0x/Vl53l0x.o 

C_DEPS += \
./Drivers/Drv/Sensors/Vl53l0x/Vl53l0x.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Drv/Sensors/Vl53l0x/%.o Drivers/Drv/Sensors/Vl53l0x/%.su: ../Drivers/Drv/Sensors/Vl53l0x/%.c Drivers/Drv/Sensors/Vl53l0x/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Drv-2f-Sensors-2f-Vl53l0x

clean-Drivers-2f-Drv-2f-Sensors-2f-Vl53l0x:
	-$(RM) ./Drivers/Drv/Sensors/Vl53l0x/Vl53l0x.d ./Drivers/Drv/Sensors/Vl53l0x/Vl53l0x.o ./Drivers/Drv/Sensors/Vl53l0x/Vl53l0x.su

.PHONY: clean-Drivers-2f-Drv-2f-Sensors-2f-Vl53l0x

