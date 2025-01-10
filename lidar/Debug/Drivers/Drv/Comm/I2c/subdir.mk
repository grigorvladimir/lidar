################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Drv/Comm/I2c/I2c.c 

OBJS += \
./Drivers/Drv/Comm/I2c/I2c.o 

C_DEPS += \
./Drivers/Drv/Comm/I2c/I2c.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Drv/Comm/I2c/%.o Drivers/Drv/Comm/I2c/%.su: ../Drivers/Drv/Comm/I2c/%.c Drivers/Drv/Comm/I2c/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Drv-2f-Comm-2f-I2c

clean-Drivers-2f-Drv-2f-Comm-2f-I2c:
	-$(RM) ./Drivers/Drv/Comm/I2c/I2c.d ./Drivers/Drv/Comm/I2c/I2c.o ./Drivers/Drv/Comm/I2c/I2c.su

.PHONY: clean-Drivers-2f-Drv-2f-Comm-2f-I2c

