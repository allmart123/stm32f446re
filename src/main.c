/**
 ******************************************************************************
 * @file           : main.c
 * @author         : _Margal_
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2026 _Margal_.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */


#include "stm32_mem_map.h"
#include "HAL_DELAY.h"
#include "HAL_GPIO.h"

#define _t 1000000UL


/* Define the onboard LED configuration */
/* Adjust these definitions to match your specific STM32F4 board */
#define LED_PORT    GPIOA       /* Port A */
#define LED_PIN     5          /* Pin 5 (Green LED on STM32F446re) */


int main(void) {
    /* 1. Enable the peripheral clock for the LED port */
    GPIO_ClockControl(LED_PORT, GPIO_STATE_HIGH);

    /* 2. Configure the LED pin as a digital output */
    GPIO_Init(LED_PORT, LED_PIN, GPIO_MODE_OUTPUT);

    /* 3. Infinite loop to blink the LED */
    while (1) {
        /* Toggle the state of the LED pin */
        GPIO_TogglePin(LED_PORT, LED_PIN);

        /* Block execution for a brief moment */
        /* Note: Exact delay time depends on the processor's core clock speed */
        _DELAY(_t);
    }

    /* Safety return (execution never reaches here) */
    return 0;
}
