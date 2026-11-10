/*
 * HAL_DELAY.c
 *
 *  Created on: Jan 27, 2026
 *      Author: _Margal_
 */

#include "HAL_DELAY.h"


//delay function
void _DELAY(volatile uint32_t _ticks){
	for(uint32_t i = 0; i < _ticks; i++){
		asm volatile("nop");
	}
}
