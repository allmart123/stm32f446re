/*
 * HAL_GPIO.h
 *
 *  Created on: Jan 27, 2026
 *      Author: _Margal_
 */



#include "mem_map.h"

#ifndef HAL_GPIO_H
#define HAL_GPIO_H


/* Pin Modes */
#define GPIO_MODE_INPUT     (0UL)
#define GPIO_MODE_OUTPUT    (1UL)
#define GPIO_MODE_ALT       (2UL)
#define GPIO_MODE_ANALOG    (3UL)

/* Pin States */
#define GPIO_STATE_LOW      (0)
#define GPIO_STATE_HIGH     (1)

/* Function Prototypes */
void GPIO_ClockControl(GPIO_TypeDef *GPIOx, uint8_t state);
void GPIO_Init(GPIO_TypeDef *GPIOx, uint8_t pin, uint32_t mode);
void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t state);
uint8_t GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint8_t pin);
void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint8_t pin);

#endif /* GPIO_H */


