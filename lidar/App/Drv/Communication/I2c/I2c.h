/*
 * I2c.h
 *
 *  Created on: Jan 10, 2025
 *      Author: grigorian
 */

#ifndef DRV_COMMUNICATION_I2C_I2C_H_
#define DRV_COMMUNICATION_I2C_I2C_H_

#include "stdint.h"
#include "Common/Common.h"


#define DEFAULT_SLAVE_ADDR	(0x29U)


status_t i2c_init(I2C_HandleTypeDef *hi2c);

/*I2c wraper functions*/
status_t i2c_write_addr8_data8(uint8_t addr, uint8_t *data);
status_t i2c_read_addr8_data8(uint8_t addr, uint8_t *data);



#endif /* DRV_COMMUNICATION_I2C_I2C_H_ */
