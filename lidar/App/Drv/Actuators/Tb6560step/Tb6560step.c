/*
 * Tb6560step.c
 *
 *  Created on: Jan 26, 2025
 *      Author: grigorian
 */
#include "Tb6560step.h"

static uint8_t motor_dir;

static void Motor_StepPulse()
{
    HAL_GPIO_WritePin(MOTOR_GPIO_PORT, MOTOR_STEP_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(MOTOR_GPIO_PORT, MOTOR_STEP_PIN, GPIO_PIN_RESET);
    HAL_Delay(MOTOR_STEP_DELAY);
}

status_t Motor_init()
{
	motor_dir = 0;
	HAL_GPIO_WritePin(MOTOR_GPIO_PORT, MOTOR_DIR_PIN, GPIO_PIN_RESET);

	return STATUS_SUCCESS;
}

status_t Motor_switch_direction()
{
	  if(motor_dir)
	  {
		  HAL_GPIO_WritePin(MOTOR_GPIO_PORT, MOTOR_DIR_PIN, GPIO_PIN_RESET);
		  motor_dir = 0;
	  }
	  else
	  {
		  HAL_GPIO_WritePin(MOTOR_GPIO_PORT, MOTOR_DIR_PIN, GPIO_PIN_SET);
		  motor_dir = 1;
	  }

	  return STATUS_SUCCESS;
}

status_t Motor_step_big(int16_t *angle)
{
	Motor_StepPulse();
	Motor_StepPulse();
	Motor_StepPulse();

	  if(motor_dir)
	  {
		  *angle += MOTOR_BIG_STEP;
	  }
	  else
	  {
		  *angle -= MOTOR_BIG_STEP;
	  }

	  *angle = *angle % 3600;

	  return STATUS_SUCCESS;
}
