/*
 * Tb6560step.h
 *
 *  Created on: Jan 26, 2025
 *      Author: grigorian
 */
#ifndef DRV_ACTUATORS_TB6560STEP_H_
#define DRV_ACTUATORS_TB6560STEP_H_

#include "stm32f4xx_hal.h"
#include "Common.h"

#define MOTOR_BIG_STEP 		(54U)
#define MOTOR_GPIO_PORT		GPIOB
#define MOTOR_DIR_PIN		GPIO_PIN_8
#define MOTOR_STEP_PIN		GPIO_PIN_9
#define MOTOR_STEP_DELAY	(1U)

status_t Motor_init();
status_t Motor_switch_direction();

/*!
 * @brief Make one step 5.4 degrees
 *
 * Standard step for used motor is 1.8, but its to little for range sensor.
 * One big step is three basic full steps of motor.
 */
status_t Motor_step_big(int16_t *angle);


#endif /* DRV_ACTUATORS_TB6560STEP_H_ */
