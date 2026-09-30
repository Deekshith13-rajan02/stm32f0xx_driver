/*
 * stm32f0xx_gpio_driver.h
 *
 *  Created on: 23-Jul-2026
 *      Author: 172080
 */

#ifndef INC_STM32F0XX_GPIO_DRIVER_H_
#define INC_STM32F0XX_GPIO_DRIVER_H_

#include "stm32f0xx.h"
#include <stdint.h>

//This is the configuration structure for a GPIO pin
typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;			/*!< possible values from @GPIO_PIN_MODES >*/
	uint8_t GPIO_PinSpeed;			/*!< possible values from @GPIO_PIN_SPEED >*/
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;


//This is the handle structure for a GPIO pin
typedef struct
{

	GPIO_RegDef_t *pGPIOx;  //This hold the base address of the GPIO Port to which the pin belongs
	GPIO_PinConfig_t GPIO_PinConfig; //This holds GPIO pin Configuration settings

}GPIO_Handle_t;

/*
 * @GPIO_PIN_MODES
 * GPIO pin possible modes
 */
#define GPIO_MODE_IN 		0
#define GPIO_MODE_OUT 		1
#define GPIO_MODE_ALTFN 	2
#define GPIO_MODE_ANALOG 	3
#define GPIO_MODE_IT_FT     4
#define GPIO_MODE_IT_RT     5
#define GPIO_MODE_IT_RFT    6

/*
 * GPIO pin possible output types
 */
#define GPIO_OP_TYPE_PP  		0
#define GPIO_OP_TYPE_OD  	 	1

/*
 * @GPIO_PIN_SPEED
 * GPIO pin possible output speeds
 */
#define GPIO_SPEED_LOW			0
#define GPIO_SPEED_MEDIUM		1
#define GPIO_SPEED_FAST			2
#define GPOI_SPEED_HIGH			3

/*
 * GPIO pin pull up AND pull down configuration macros
 */
#define GPIO_NO_PUPD   		0
#define GPIO_PIN_PU			1
#define GPIO_PIN_PD			2

//Peripheral clock setup
void GPIO_PeriClckControl(GPIO_RegDef_t *pGPIOx ,uint8_t EnorDi);

// Init and De-Init
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);


//Data read write
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx ,uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber ,uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber);



//IRQ Configuration and ISR handling
void GPIO_IRQConfig(uint8_t IRQNumber ,uint8_t IRQPriority ,uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);



#endif /* INC_STM32F0XX_GPIO_DRIVER_H_ */
