/*
 * stm32f0xx.h
 *
 *  Created on: 15-Jul-2026
 *      Author: 172080
 */
#include <stdint.h>
#ifndef INC_STM32F0XX_H_
#define INC_STM32F0XX_H_
#define __vo volatile
//Base address of Flash ,ROM,RAM

#define FLASH_BASEADDR		0x08000000U
#define SRAM_BASEADDR		0x20000000U
#define ROM_BASEADDR		0x1FFFD800U


//AHB ,APB bus base address

#define PERIPH_BASE			0x40000000U
#define APB1PERIPH_BASE		PERIPH_BASE
#define APB2PERIPH_BASE		0x40010000U
#define AHB1PERIPH_BASE		0x40020000U
#define AHB2PERIPH_BASE		0x48000000U

//Base address of the peripherals which are hanging on the AHB2 Bus
#define RCC_BASEADDR		(AHB2PERIPH_BASE + 0x1000)

//Base address of the peripherals which are hanging on the AHB2 Bus
#define GPIOIA_BASEADDR		 AHB2PERIPH_BASE
#define GPIOIB_BASEADDR		(AHB2PERIPH_BASE + 0X0400)
#define GPIOIC_BASEADDR		(AHB2PERIPH_BASE + 0X0800)
#define GPIOID_BASEADDR		(AHB2PERIPH_BASE + 0X0C00)
#define GPIOIF_BASEADDR		(AHB2PERIPH_BASE + 0X1400)

//Base address of the peripherals which are hanging on the APB1 Bus
#define I2C1_BASEADDR		(APB1PERIPH_BASE + 0X5400)
#define I2C2_BASEADDR		(APB1PERIPH_BASE + 0X5800)

#define USART2_BASEADDR		(APB1PERIPH_BASE + 0X4400)
#define USART3_BASEADDR		(APB1PERIPH_BASE + 0X4800)
#define USART4_BASEADDR		(APB1PERIPH_BASE + 0X4C00)
#define USART5_BASEADDR		(APB1PERIPH_BASE + 0X5000)

#define SPI2_BASEADDR		(APB1PERIPH_BASE + 0X3000)

#define SYSCFG_BASEADDR		APB1PERIPH_BASE

//Base address of the peripherals which are hanging on the APB2 Bus
#define EXTI_BASEADDR		(APB2PERIPH_BASE + 0X0400)

#define USART1_BASEADDR		(APB2PERIPH_BASE + 0X3800)
#define USART6_BASEADDR		(APB2PERIPH_BASE + 0X1400)

#define SPI1_BASEADDR		(APB2PERIPH_BASE + 0X3800)

//******************************Peripheral register definition structures************************
typedef struct {
	__vo uint8_t MODER;
	__vo uint8_t OTYPER;
	__vo uint8_t OSPEEDR;
	__vo uint8_t PUPDR;
	__vo uint8_t IDR;
	__vo uint8_t ODR;
	__vo uint8_t BSRR;
	__vo uint8_t LCKR;
	__vo uint32_t AFR[2];
	__vo uint8_t AFRH;
	__vo uint8_t BRR;
}GPIO_RegDef_t;

typedef struct {
	__vo uint8_t CR;
	__vo uint8_t CFGR;
	__vo uint8_t CIR;
	__vo uint8_t APB2RSTR;
	__vo uint8_t APB1RSTR;
	__vo uint8_t AHBENR;
	__vo uint8_t APB2ENR;
	__vo uint8_t APB1ENR;
	__vo uint8_t BDCR;
	__vo uint8_t CSR;
	__vo uint8_t AHBRSTR;
	__vo uint8_t CFGR2;
	__vo uint8_t CFGR3;
	__vo uint8_t CR2;
}RCC_RegDef_t;

//******************************Peripheral register definition structures typecasting************************
#define GPIOA				((GPIO_RegDef_t*)GPIOIA_BASEADDR)
#define GPIOB				((GPIO_RegDef_t*)GPIOIB_BASEADDR)
#define GPIOC				((GPIO_RegDef_t*)GPIOIC_BASEADDR)
#define GPIOD				((GPIO_RegDef_t*)GPIOID_BASEADDR)
#define GPIOF				((GPIO_RegDef_t*)GPIOIF_BASEADDR)

#define RCC 				((RCC_RegDef_t*)RCC_BASEADDR)
#define EXTI				((EXTI_RegDef_t*)EXTI_BASEADDR)

//******************************Clock Enable macros for GPIOx peri********************************************
#define GPIOA_PCLK_EN()		(RCC->AHBENR |=(1<<17))
#define GPIOB_PCLK_EN()		(RCC->AHBENR |=(1<<18))
#define GPIOC_PCLK_EN()		(RCC->AHBENR |=(1<<19))
#define GPIOD_PCLK_EN()		(RCC->AHBENR |=(1<<20))
#define GPIOF_PCLK_EN()		(RCC->AHBENR |=(1<<22))

//******************************Clock Enable macros for I2C Peri********************************************
#define I2C1_PCLK_EN()		(RCC->APB1ENR |=(1<<21))
#define I2C2_PCLK_EN()		(RCC->APB1ENR |=(1<<22))

//******************************Clock Enable macros for SPI peri********************************************
#define SPI1_PCLK_EN()		(RCC->APB2ENR |=(1<<12))
#define SPI2_PCLK_EN()		(RCC->APB1ENR |=(1<<14))

//******************************Clock Enable macros for USART peri********************************************
#define USART1_PCLK_EN()		(RCC->APB2ENR |=(1<<14))
#define USART2_PCLK_EN()		(RCC->APB1ENR |=(1<<17))
#define USART3_PCLK_EN()		(RCC->APB1ENR |=(1<<18))
#define USART4_PCLK_EN()		(RCC->APB1ENR |=(1<<19))
#define USART5_PCLK_EN()		(RCC->APB1ENR |=(1<<20))
#define USART6_PCLK_EN()		(RCC->APB2ENR |=(1<<6))

//******************************Clock Enable macros for SYSCFG peri********************************************
#define SYSCFG_PCLK_EN()		(RCC->APB2ENR |=(1<<0))

//******************************Clock Disable macros for GPIOx peri********************************************
#define GPIOA_PCLK_DI()		(RCC->AHBENR &=~(1<<17))
#define GPIOB_PCLK_DI()		(RCC->AHBENR &=~(1<<18))
#define GPIOC_PCLK_DI()		(RCC->AHBENR &=~(1<<19))
#define GPIOD_PCLK_DI()		(RCC->AHBENR &=~(1<<20))
#define GPIOF_PCLK_DI()		(RCC->AHBENR &=~(1<<22))

//******************************Clock Enable macros for I2C Peri********************************************
#define I2C1_PCLK_DI()		(RCC->APB1ENR &=~|=(1<<21))
#define I2C2_PCLK_DI()		(RCC->APB1ENR &=~(1<<22))

//******************************Clock Enable macros for SPI peri********************************************
#define SPI1_PCLK_DI()		(RCC->APB2ENR &=~(1<<12))
#define SPI2_PCLK_DI()		(RCC->APB1ENR &=~(1<<14))

//******************************Clock Enable macros for USART peri********************************************
#define USART1_PCLK_DI()		(RCC->APB2ENR &=~(1<<14))
#define USART2_PCLK_DI()		(RCC->APB1ENR &=~(1<<17))
#define USART3_PCLK_DI()		(RCC->APB1ENR &=~(1<<18))
#define USART4_PCLK_DI()		(RCC->APB1ENR &=~(1<<19))
#define USART5_PCLK_DI()		(RCC->APB1ENR &=~(1<<20))
#define USART6_PCLK_DI()		(RCC->APB2ENR &=~(1<<6))

//******************************Clock Disable macros for SYSCFG peri********************************************
#define SYSCFG_PCLK_DI()		(RCC->APB2ENR &=~(1<<0))


#define GPIO_BASEADDR_TO_CODE(x)      ( (x == GPIOA)?0:\
										(x == GPIOB)?1:\
										(x == GPIOC)?2:\
										(x == GPIOD)?3:\
								        (x == GPIOF)?5:0 )


//Some generic macros
#define ENABLE			1
#define DISABLE			0
#define SET				ENABLE
#define RESET			DISABLE
#define GPIO_PIN_SET 	SET
#define GPIO_PIN_RESET 	RESET

/*
 * IRQ(Interrupt Request) Numbers of STM32F030x MCU
 * NOTE: update these macros with valid values according to your MCU
 * TODO: You may complete this list for other peripherals
 */
#define IRQ_NO_EXTI0_1		5
#define IRQ_NO_EXTI2_3		6
#define IRQ_NO_EXTI4_15		7
#define IRQ_NO_SPI1			25
#define IRQ_NO_SPI2			26
#define IRQ_NO_I2C1			23
#define IRQ_NO_I2C2			24
#define IRQ_NO_USART1		27
#define IRQ_NO_USART2		28
#define IRQ_NO_USART3_4_5_6	29

/*
 * peripheral register definition structure for EXTI
 */
typedef struct
{
	__vo uint32_t IMR;    /*!< Give a short description,          	  	    Address offset: 0x00 */
	__vo uint32_t EMR;    /*!< TODO,                						Address offset: 0x04 */
	__vo uint32_t RTSR;   /*!< TODO,  									     Address offset: 0x08 */
	__vo uint32_t FTSR;   /*!< TODO, 										Address offset: 0x0C */
	__vo uint32_t SWIER;  /*!< TODO,  									   Address offset: 0x10 */
	__vo uint32_t PR;     /*!< TODO,                   					   Address offset: 0x14 */

}EXTI_RegDef_t;

#endif /* INC_STM32F0XX_H_ */
