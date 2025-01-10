/*
 * Common.h
 *
 *  Created on: Jan 10, 2025
 *      Author: grigorian
 */

#ifndef DRV_COMMON_COMMON_H_
#define DRV_COMMON_COMMON_H_

#include "stm32f4xx_hal.h"

/*! @brief Status return codes.
 * Error codes will be a unified enumeration that will contain all error codes.
 * There will be separate regions, each of 256 positions will be allocated per functionality.
 */
typedef enum
{
	/* Generic error codes */
	STATUS_SUCCESS                         = 0x000U,    /*!< Generic operation success status */
	STATUS_ERROR                           = 0x001U,    /*!< Generic operation failure status */
	STATUS_BUSY                            = 0x002U,    /*!< Generic operation busy status */
	STATUS_TIMEOUT                         = 0x003U,    /*!< Generic operation timeout status */
	STATUS_UNSUPPORTED                     = 0x004U,    /*!< Generic operation unsupported status */
}status_t;



#endif /* DRV_COMMON_COMMON_H_ */
