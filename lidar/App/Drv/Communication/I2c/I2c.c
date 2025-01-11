/*
 * I2c.c
 *
 *  Created on: Jan 10, 2025
 *      Author: grigorian
 */
#include "I2c.h"

static I2C_HandleTypeDef *halI2cEntity;

status_t I2c_init(I2C_HandleTypeDef *hi2c)
{
	status_t status = STATUS_SUCCESS;
	halI2cEntity = hi2c;
	return status;
}

status_t I2c_write_addr8_data8(uint8_t addr, uint8_t *data)
{
	uint16_t devAddr = (DEFAULT_SLAVE_ADDR << 1) | 0x00; //adjust address according to hal requirements
	status_t status = HAL_I2C_Mem_Write(halI2cEntity, devAddr, addr, 1, data, 1, 10);

	return status;
}


status_t I2c_read_addr8_data8(uint8_t addr, uint8_t *data)
{
	uint16_t devAddr = (DEFAULT_SLAVE_ADDR << 1) | 0x01;//adjust address according to hal requirements
	status_t status = HAL_I2C_Mem_Read(halI2cEntity, devAddr, addr, 1, data, 1, 10);
	return status;
}
