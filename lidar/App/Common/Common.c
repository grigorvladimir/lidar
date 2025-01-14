/*
 * Common.c
 *
 *  Created on: Jan 10, 2025
 *      Author: grigorian
 */
#include "Common.h"

void Mirror_array(uint8_t *arr, uint32_t size)
{
    for(uint32_t i = 0, j = size - 1; i < j; i++, j--)
    {
        int32_t temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
