/*
 * mem_map.h
 *
 *  Created on: Jan 27, 2026
 *      Author: _Margal_
 */



#ifndef MEM_MAP_H
#define MEM_MAP_H

#include <stdint.h>

/* ========================================================================== */
/* =========              Memory Base Addresses                      ======== */
/* ========================================================================== */
#define FLASH_BASE            (0x08000000UL) /* Flash memory (up to 512 KB) */
#define SRAM1_BASE            (0x20000000UL) /* SRAM1 (112 KB)             */
#define SRAM2_BASE            (0x2001C000UL) /* SRAM2 (16 KB)              */
#define ROM_BASE              (0x1FFF0000UL) /* System Memory (Bootloader) */

/* ========================================================================== */
/* =========              Bus Boundary Addresses                     ======== */
/* ========================================================================== */
#define PERIPH_BASE           (0x40000000UL) /* Peripheral Base Address    */

#define APB1PERIPH_BASE       (PERIPH_BASE)
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x50000000UL)

/* ========================================================================== */
/* =========             AHB1 Peripheral Base Addresses              ======== */
/* ========================================================================== */
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0CUL)
#define GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000UL)
#define GPIOF_BASE            (AHB1PERIPH_BASE + 0x1400UL)
#define GPIOG_BASE            (AHB1PERIPH_BASE + 0x1800UL)
#define GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00UL)
#define CRC_BASE              (AHB1PERIPH_BASE + 0x3000UL)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800UL)
#define FLASH_R_BASE          (AHB1PERIPH_BASE + 0x3C00UL)
#define DMA1_BASE             (AHB1PERIPH_BASE + 0x6000UL)
#define DMA2_BASE             (AHB1PERIPH_BASE + 0x6400UL)

/* ========================================================================== */
/* =========             APB1 Peripheral Base Addresses              ======== */
/* ========================================================================== */
#define TIM2_BASE             (APB1PERIPH_BASE + 0x0000UL)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x0400UL)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x0800UL)
#define TIM5_BASE             (APB1PERIPH_BASE + 0x0C00UL)
#define TIM6_BASE             (APB1PERIPH_BASE + 0x1000UL)
#define TIM7_BASE             (APB1PERIPH_BASE + 0x1400UL)
#define RTC_BASE              (APB1PERIPH_BASE + 0x2800UL)
#define WWDG_BASE             (APB1PERIPH_BASE + 0x2C00UL)
#define IWDG_BASE             (APB1PERIPH_BASE + 0x3000UL)
#define SPI2_BASE             (APB1PERIPH_BASE + 0x3800UL)
#define SPI3_BASE             (APB1PERIPH_BASE + 0x3C00UL)
#define USART2_BASE           (APB1PERIPH_BASE + 0x4400UL)
#define USART3_BASE           (APB1PERIPH_BASE + 0x4800UL)
#define UART4_BASE            (APB1PERIPH_BASE + 0x4C00UL)
#define UART5_BASE            (APB1PERIPH_BASE + 0x5000UL)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x5400UL)
#define I2C2_BASE             (APB1PERIPH_BASE + 0x5800UL)
#define I2C3_BASE             (APB1PERIPH_BASE + 0x5C00UL)
#define CAN1_BASE             (APB1PERIPH_BASE + 0x6400UL)
#define CAN2_BASE             (APB1PERIPH_BASE + 0x6800UL)
#define PWR_BASE              (APB1PERIPH_BASE + 0x7000UL)
#define DAC_BASE              (APB1PERIPH_BASE + 0x7400UL)

/* ========================================================================== */
/* =========             APB2 Peripheral Base Addresses              ======== */
/* ========================================================================== */
#define TIM1_BASE             (APB2PERIPH_BASE + 0x0000UL)
#define TIM8_BASE             (APB2PERIPH_BASE + 0x0400UL)
#define USART1_BASE           (APB2PERIPH_BASE + 0x1000UL)
#define USART6_BASE           (APB2PERIPH_BASE + 0x1400UL)
#define ADC_BASE              (APB2PERIPH_BASE + 0x2000UL)
#define ADC1_BASE             (ADC_BASE + 0x00UL)
#define ADC2_BASE             (ADC_BASE + 0x10UL)
#define ADC3_BASE             (ADC_BASE + 0x20UL)
#define ADC_COMMON_BASE       (ADC_BASE + 0x300UL)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x3000UL)
#define SPI4_BASE             (APB2PERIPH_BASE + 0x3400UL)
#define SYSCFG_BASE           (APB2PERIPH_BASE + 0x3800UL)
#define EXTI_BASE             (APB2PERIPH_BASE + 0x3C00UL)
#define TIM9_BASE             (APB2PERIPH_BASE + 0x4000UL)
#define TIM10_BASE            (APB2PERIPH_BASE + 0x4400UL)
#define TIM11_BASE            (APB2PERIPH_BASE + 0x4800UL)

/* ========================================================================== */
/* =========            Peripheral Register Structures               ======== */
/* ========================================================================== */
typedef struct {
    volatile uint32_t MODER;    /* GPIO port mode register               */
    volatile uint32_t OTYPER;   /* GPIO port output type register        */
    volatile uint32_t OSPEEDR;  /* GPIO port output speed register       */
    volatile uint32_t PUPDR;    /* GPIO port pull-up/pull-down register  */
    volatile uint32_t IDR;      /* GPIO port input data register         */
    volatile uint32_t ODR;      /* GPIO port output data register        */
    volatile uint32_t BSRR;     /* GPIO port bit set/reset register      */
    volatile uint32_t LCKR;     /* GPIO port configuration lock register */
    volatile uint32_t AFR[2];   /* GPIO alternate function registers     */
} GPIO_TypeDef;

typedef struct {
    volatile uint32_t CR;         /* RCC clock control register              */
    volatile uint32_t PLLCFGR;    /* RCC PLL configuration register         */
    volatile uint32_t CFGR;       /* RCC clock configuration register        */
    volatile uint32_t CIR;        /* RCC clock interrupt register            */
    volatile uint32_t AHB1RSTR;   /* RCC AHB1 peripheral reset register      */
    volatile uint32_t AHB2RSTR;   /* RCC AHB2 peripheral reset register      */
    volatile uint32_t AHB3RSTR;   /* RCC AHB3 peripheral reset register      */
    uint32_t          RESERVED0;  /* Reserved slot                           */
    volatile uint32_t APB1RSTR;   /* RCC APB1 peripheral reset register      */
    volatile uint32_t APB2RSTR;   /* RCC APB2 peripheral reset register      */
    uint32_t          RESERVED1[2];
    volatile uint32_t AHB1ENR;    /* RCC AHB1 peripheral clock enable        */
    volatile uint32_t AHB2ENR;    /* RCC AHB2 peripheral clock enable        */
    volatile uint32_t AHB3ENR;    /* RCC AHB3 peripheral clock enable        */
    uint32_t          RESERVED2;
    volatile uint32_t APB1ENR;    /* RCC APB1 peripheral clock enable        */
    volatile uint32_t APB2ENR;    /* RCC APB2 peripheral clock enable        */
    /* Note: Further registers like DCKCFGR exist on F446 for advanced clocks */
} RCC_TypeDef;

/* ========================================================================== */
/* =========                 Peripheral Casts                        ======== */
/* ========================================================================== */
#define GPIOA                 ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB                 ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC                 ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD                 ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE                 ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF                 ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG                 ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH                 ((GPIO_TypeDef *) GPIOH_BASE)

#define RCC                   ((RCC_TypeDef *) RCC_BASE)

#endif /* MEM_MAP_H */
