/*
 * HAL_GPIO.c
 *
 *  Created on: Jan 27, 2026
 *      Author: _Margal_
 */


#include "HAL_GPIO.h"

/**
  * @brief  Enables or disables the clock for the given GPIO port.
  * @param  GPIOx: Base address of the GPIO port (GPIOA, GPIOB, etc.)
  * @param  state: GPIO_STATE_HIGH to enable, GPIO_STATE_LOW to disable.
  */
void GPIO_ClockControl(GPIO_TypeDef *GPIOx, uint8_t state) {
    uint32_t bitPosition = 0;

    /* Determine bit position in RCC_AHB1ENR based on port address */
    if      (GPIOx == GPIOA) bitPosition = 0;
    else if (GPIOx == GPIOB) bitPosition = 1;
    else if (GPIOx == GPIOC) bitPosition = 2;
    else if (GPIOx == GPIOD) bitPosition = 3;
    else if (GPIOx == GPIOE) bitPosition = 4;
    else if (GPIOx == GPIOH) bitPosition = 7;
    else return; /* Unsupported port */

    if (state == GPIO_STATE_HIGH) {
        RCC->AHB1ENR |= (1UL << bitPosition);
    } else {
        RCC->AHB1ENR &= ~(1UL << bitPosition);
    }
}

/**
  * @brief  Initializes the selected GPIO pin mode.
  * @param  GPIOx: Base address of the GPIO port.
  * @param  pin: Pin number (0 to 15).
  * @param  mode: Pin mode selection (Input, Output, Alt, Analog).
  */
void GPIO_Init(GPIO_TypeDef *GPIOx, uint8_t pin, uint32_t mode) {
    if (pin > 15) return;

    /* Clear the 2 bits for the target pin */
    GPIOx->MODER &= ~(3UL << (2 * pin));

    /* Set the new mode bits */
    GPIOx->MODER |= (mode << (2 * pin));
}

/**
  * @brief  Sets or clears the selected GPIO pin.
  * @param  GPIOx: Base address of the GPIO port.
  * @param  pin: Pin number (0 to 15).
  * @param  state: GPIO_STATE_HIGH or GPIO_STATE_LOW.
  */
void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t state) {
    if (pin > 15) return;

    if (state == GPIO_STATE_HIGH) {
        /* Set bit using Bit Set Reset Register (atomic operation) */
        GPIOx->BSRR = (1UL << pin);
    } else {
        /* Reset bit using upper half of Bit Set Reset Register */
        GPIOx->BSRR = (1UL << (pin + 16));
    }
}

/**
  * @brief  Reads the input status of the selected GPIO pin.
  * @param  GPIOx: Base address of the GPIO port.
  * @param  pin: Pin number (0 to 15).
  * @return GPIO_STATE_HIGH or GPIO_STATE_LOW.
  */
uint8_t GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint8_t pin) {
    if (pin > 15) return GPIO_STATE_LOW;

    /* Mask the Input Data Register for the specific pin */
    if ((GPIOx->IDR & (1UL << pin)) != 0UL) {
        return GPIO_STATE_HIGH;
    }
    return GPIO_STATE_LOW;
}

/**
  * @brief  Toggles the state of the selected GPIO pin.
  * @param  GPIOx: Base address of the GPIO port.
  * @param  pin: Pin number (0 to 15).
  */
void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint8_t pin) {
    if (pin > 15) return;

    /* Exclusive OR (XOR) with the Output Data Register */
    GPIOx->ODR ^= (1UL << pin);
}

