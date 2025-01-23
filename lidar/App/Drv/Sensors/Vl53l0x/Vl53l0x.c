/*
 * Vl53l0x.c
 *
 *  Created on: Jan 10, 2025
 *      Author: grigorian
 *
 * Order of initialization and values to fill with
 * were referenced from stm provided API.
 * Main initialization siquence can be found in vl53l0x_core.h.
 * Defines are mainly in vl53l0x_device.h.
 */
#include "Vl53l0x.h"

static uint8_t stop_variable = 0;

/**
 * We can read the model id to confirm that the device is booted.
 */
static status_t check_dev()
{
	status_t status = STATUS_ERROR;
    uint8_t device_id = 0;

    status = I2c_read_addr8_data8(REG_IDENTIFICATION_MODEL_ID, &device_id);
    if(device_id == EXPECTED_DEVICE_ID)
    {
        status = STATUS_SUCCESS;
    }
    return status;
}

/**
 * One time device initialization
 */
static status_t data_init()
{
	status_t status = STATUS_ERROR;
	bool settings_applied = false;

    /* Set 2v8 mode */
    uint8_t vhv_config_scl_sda = 0;

    status = I2c_read_addr8_data8(REG_VHV_CONFIG_PAD_SCL_SDA_EXTSUP_HV, &vhv_config_scl_sda);
    if(status == STATUS_SUCCESS)
    {
    	vhv_config_scl_sda |= 0x01;
		status = I2c_write_addr8_data8(REG_VHV_CONFIG_PAD_SCL_SDA_EXTSUP_HV, vhv_config_scl_sda);
    }

    if(status == STATUS_SUCCESS)
    {
		/* Set I2c standard mode */
    	settings_applied = I2c_write_addr8_data8(0x88, 0x00);

    	settings_applied |= I2c_write_addr8_data8(0x80, 0x01);
    	settings_applied |= I2c_write_addr8_data8(0xFF, 0x01);
    	settings_applied |= I2c_write_addr8_data8(0x00, 0x00);
    	settings_applied |= I2c_read_addr8_data8(0x91, &stop_variable);
    	settings_applied |= I2c_write_addr8_data8(0x00, 0x01);
    	settings_applied |= I2c_write_addr8_data8(0xFF, 0x00);
    	settings_applied |= I2c_write_addr8_data8(0x80, 0x00);
    }

    if(settings_applied == true)
    {
    	status = STATUS_ERROR;
    }
    return status;
}

/*!
 * @brief Fill setting registers.
 *
 * Filling registers with settings for long range measurement.
 */
static status_t load_settings()
{
	status_t status = STATUS_ERROR;
    bool settings_applied = I2c_write_addr8_data8(0xFF, 0x01);
    settings_applied |= I2c_write_addr8_data8(0x00, 0x00);
    settings_applied |= I2c_write_addr8_data8(0xFF, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x09, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x10, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x11, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x24, 0x01);
    settings_applied |= I2c_write_addr8_data8(0x25, 0xFF);
    settings_applied |= I2c_write_addr8_data8(0x75, 0x00);
    settings_applied |= I2c_write_addr8_data8(0xFF, 0x01);
    settings_applied |= I2c_write_addr8_data8(0x4E, 0x2C);
    settings_applied |= I2c_write_addr8_data8(0x48, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x30, 0x20);
    settings_applied |= I2c_write_addr8_data8(0xFF, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x30, 0x07);
    settings_applied |= I2c_write_addr8_data8(0x54, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x31, 0x04);
    settings_applied |= I2c_write_addr8_data8(0x32, 0x03);
    settings_applied |= I2c_write_addr8_data8(0x40, 0x83);
    settings_applied |= I2c_write_addr8_data8(0x46, 0x25);
    settings_applied |= I2c_write_addr8_data8(0x60, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x27, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x50, 0x06);
    settings_applied |= I2c_write_addr8_data8(0x51, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x52, 0x96);
    settings_applied |= I2c_write_addr8_data8(0x56, 0x08);
    settings_applied |= I2c_write_addr8_data8(0x57, 0x50);
    settings_applied |= I2c_write_addr8_data8(0x61, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x62, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x64, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x65, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x66, 0xA0);
    settings_applied |= I2c_write_addr8_data8(0xFF, 0x01);
    settings_applied |= I2c_write_addr8_data8(0x22, 0x32);
    settings_applied |= I2c_write_addr8_data8(0x47, 0x14);
    settings_applied |= I2c_write_addr8_data8(0x49, 0xFF);
    settings_applied |= I2c_write_addr8_data8(0x4A, 0x00);
    settings_applied |= I2c_write_addr8_data8(0xFF, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x7A, 0x0A);
    settings_applied |= I2c_write_addr8_data8(0x7B, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x78, 0x21);
    settings_applied |= I2c_write_addr8_data8(0xFF, 0x01);
    settings_applied |= I2c_write_addr8_data8(0x23, 0x34);
    settings_applied |= I2c_write_addr8_data8(0x42, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x44, 0xFF);
    settings_applied |= I2c_write_addr8_data8(0x45, 0x26);
    settings_applied |= I2c_write_addr8_data8(0x46, 0x05);
    settings_applied |= I2c_write_addr8_data8(0x40, 0x40);
    settings_applied |= I2c_write_addr8_data8(0x0E, 0x06);
    settings_applied |= I2c_write_addr8_data8(0x20, 0x1A);
    settings_applied |= I2c_write_addr8_data8(0x43, 0x40);
    settings_applied |= I2c_write_addr8_data8(0xFF, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x34, 0x03);
    settings_applied |= I2c_write_addr8_data8(0x35, 0x44);
    settings_applied |= I2c_write_addr8_data8(0xFF, 0x01);
    settings_applied |= I2c_write_addr8_data8(0x31, 0x04);
    settings_applied |= I2c_write_addr8_data8(0x4B, 0x09);
    settings_applied |= I2c_write_addr8_data8(0x4C, 0x05);
    settings_applied |= I2c_write_addr8_data8(0x4D, 0x04);
    settings_applied |= I2c_write_addr8_data8(0xFF, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x44, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x45, 0x20);
    settings_applied |= I2c_write_addr8_data8(0x47, 0x08);
    settings_applied |= I2c_write_addr8_data8(0x48, 0x48);
    settings_applied |= I2c_write_addr8_data8(0x67, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x70, 0x04);
    settings_applied |= I2c_write_addr8_data8(0x71, 0x01);
    settings_applied |= I2c_write_addr8_data8(0x72, 0xFE);
    settings_applied |= I2c_write_addr8_data8(0x76, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x77, 0x00);
    settings_applied |= I2c_write_addr8_data8(0xFF, 0x01);
    settings_applied |= I2c_write_addr8_data8(0x0D, 0x01);
    settings_applied |= I2c_write_addr8_data8(0xFF, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x80, 0x01);
    settings_applied |= I2c_write_addr8_data8(0x01, 0xF8);
    settings_applied |= I2c_write_addr8_data8(0xFF, 0x01);
    settings_applied |= I2c_write_addr8_data8(0x8E, 0x01);
    settings_applied |= I2c_write_addr8_data8(0x00, 0x01);
    settings_applied |= I2c_write_addr8_data8(0xFF, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x80, 0x00);

    if(settings_applied == false)
    {
    	status = STATUS_SUCCESS;
    }

    return status;
}

static status_t configure_interrupt()
{
	status_t status = I2c_write_addr8_data8(REG_SYSTEM_INTERRUPT_CONFIG_GPIO, 0x04);
	/* Interrupt on new sample ready */
	if(status == STATUS_SUCCESS)
	{
		/* Configure active low since the pin is pulled-up on most breakout boards */
		uint8_t gpio_hv_mux_active_high = 0;
		status = I2c_read_addr8_data8(REG_GPIO_HV_MUX_ACTIVE_HIGH, &gpio_hv_mux_active_high);
		if(status == STATUS_SUCCESS)
		{
			gpio_hv_mux_active_high &= ~0x10;
			status = I2c_write_addr8_data8(REG_GPIO_HV_MUX_ACTIVE_HIGH, gpio_hv_mux_active_high);
			if(status ==  STATUS_SUCCESS)
			{
				status = I2c_write_addr8_data8(REG_SYSTEM_INTERRUPT_CLEAR, 0x01);
			}
		}
	}

	return status;
}

/**
 * Enable steps in range measuring sequence
 */
static status_t set_sequence_steps_enabled(uint8_t sequence_step)
{
    return I2c_write_addr8_data8(REG_SYSTEM_SEQUENCE_CONFIG, sequence_step);
}

/**
 * Basic device initialization
 */
static status_t static_init()
{
	status_t status = load_settings();
    if(status == STATUS_SUCCESS)
    {
    	status = configure_interrupt();
    	if(status == STATUS_SUCCESS)
    	{
    		status = set_sequence_steps_enabled(RANGE_SEQUENCE_STEP_DSS +
    												RANGE_SEQUENCE_STEP_PRE_RANGE +
    												RANGE_SEQUENCE_STEP_FINAL_RANGE);
		}
    }

    return status;
}

static status_t perform_single_ref_calibration(calibration_type_t calib_type)
{
	status_t status = STATUS_ERROR;
    uint8_t sysrange_start = 0;
    uint8_t sequence_config = 0;

    switch (calib_type)
    {
    case CALIBRATION_TYPE_VHV:
        sequence_config = 0x01;
        sysrange_start = 0x01 | 0x40;
        break;
    case CALIBRATION_TYPE_PHASE:
        sequence_config = 0x02;
        sysrange_start = 0x01 | 0x00;
        break;
    }

    status = I2c_write_addr8_data8(REG_SYSTEM_SEQUENCE_CONFIG, sequence_config);
    if(status == STATUS_SUCCESS)
    {
    	status = I2c_write_addr8_data8(REG_SYSRANGE_START, sysrange_start);
    	if(status == STATUS_SUCCESS)
    	{
    		/* Wait for interrupt */
			uint8_t interrupt_status = 0;
			while ((status == STATUS_SUCCESS) && ((interrupt_status & 0x07) == 0))
			{
				status = I2c_read_addr8_data8(REG_RESULT_INTERRUPT_STATUS, &interrupt_status);
			}
			if(status == STATUS_SUCCESS)
			{
				status = I2c_write_addr8_data8(REG_SYSTEM_INTERRUPT_CLEAR, 0x01);
				if(status == STATUS_SUCCESS)
				{
					status = I2c_write_addr8_data8(REG_SYSRANGE_START, 0x00);
				}
			}
		}
    }
    return status;
}

/**
 * Temperature calibration needs to be run again if the temperature changes by
 * more than 8 degrees according to the datasheet.
 */
static status_t perform_ref_calibration()
{
	status_t status = perform_single_ref_calibration(CALIBRATION_TYPE_VHV);

    if(status == STATUS_SUCCESS)
    {
        status = perform_single_ref_calibration(CALIBRATION_TYPE_PHASE);
        if(status == STATUS_SUCCESS)
        {
        	/* Restore sequence steps enabled */
			status = set_sequence_steps_enabled(RANGE_SEQUENCE_STEP_DSS +
											RANGE_SEQUENCE_STEP_PRE_RANGE +
											RANGE_SEQUENCE_STEP_FINAL_RANGE);
		}
    }

    return status;
}

status_t Vl53l0x_init()
{
	status_t status = check_dev();
    if(status == STATUS_SUCCESS)
    {
    	status = data_init();
    	if(status == STATUS_SUCCESS)
    	{
    		status = static_init();
    		if(status == STATUS_SUCCESS)
    		{
				status = perform_ref_calibration();
			}
		}
    }

    return status;
}

status_t Read_range(uint16_t *range)
{
	status_t status = STATUS_ERROR;
	uint8_t sysrange_start = 1;
	uint8_t interrupt_status = 0;

    bool settings_applied = I2c_write_addr8_data8(0x80, 0x01);
    settings_applied |= I2c_write_addr8_data8(0xFF, 0x01);
    settings_applied |= I2c_write_addr8_data8(0x00, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x91, stop_variable);
    settings_applied |= I2c_write_addr8_data8(0x00, 0x01);
    settings_applied |= I2c_write_addr8_data8(0xFF, 0x00);
    settings_applied |= I2c_write_addr8_data8(0x80, 0x00);
    if(settings_applied == false)
    {
    	status = I2c_write_addr8_data8(REG_SYSRANGE_START, 0x01);
    	if(status == STATUS_SUCCESS)
    	{
    		while((status == STATUS_SUCCESS) && (sysrange_start & 0x01))
    		{
				status = I2c_read_addr8_data8(REG_SYSRANGE_START, &sysrange_start);
			}
			if(status == STATUS_SUCCESS)
			{
				while ((status == STATUS_SUCCESS) && ((interrupt_status & 0x07) == 0))
				{
					status = I2c_read_addr8_data8(REG_RESULT_INTERRUPT_STATUS, &interrupt_status);
				}
				if(status == STATUS_SUCCESS)
				{
					status = I2c_read_addr8_data16(REG_RESULT_RANGE_STATUS + 10, range);
					if(status == STATUS_SUCCESS)
					{
						status = I2c_write_addr8_data8(REG_SYSTEM_INTERRUPT_CLEAR, 0x01);
					}
				}
			}
		}
    }

    return status;
}
