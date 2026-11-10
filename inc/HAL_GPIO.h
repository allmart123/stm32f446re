/*
 * HAL_GPIO.h
 *
 *  Created on: Jan 27, 2026
 *      Author: _Margal_
 */



#include "stm32_mem_map.h"

#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include <stdint.h>


/* Base addresses for GPIO Ports on STM32F4 */
/*
#define GPIOA_BASE  (0x40020000UL)
#define GPIOB_BASE  (0x40020400UL)
#define GPIOC_BASE  (0x40020800UL)
#define GPIOD_BASE  (0x40020C00UL)
#define GPIOE_BASE  (0x40021000UL)
#define GPIOH_BASE  (0x40021C00UL)
*/
/* RCC Base and Offset for GPIO Clocks */
//#define RCC_BASE    (0x40023800UL)



/*#define RCC_AHB1ENR (*(volatile uint32_t *)(RCC_BASE + 0x30UL))*/

/* GPIO Register Definition Structure */

//typedef struct {
    //volatile uint32_t MODER;    /* GPIO port mode register */
    //volatile uint32_t OTYPER;   /* GPIO port output type register */
    //volatile uint32_t OSPEEDR;  /* GPIO port output speed register */
    //volatile uint32_t PUPDR;    /* GPIO port pull-up/pull-down register */
    //volatile uint32_t IDR;      /* GPIO port input data register */
    //volatile uint32_t ODR;      /* GPIO port output data register */
    //volatile uint32_t BSRR;     /* GPIO port bit set/reset register */
   // volatile uint32_t LCKR;     /* GPIO port configuration lock register */
  //  volatile uint32_t AFR[2];   /* GPIO alternate function registers */
//} GPIO_TypeDef;

/* Port Pointer Definitions */
/*
#define GPIOA ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOH ((GPIO_TypeDef *) GPIOH_BASE)
*/

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


