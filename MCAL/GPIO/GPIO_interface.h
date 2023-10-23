/*
 * GPIO_interface.h
 *
 *  Created on: Sep 4, 2023
 *      Author: alibo
 */

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

typedef enum
{
	GPIO_PORTA,
	GPIO_PORTB,
	GPIO_PORTC
}GPIO_PORT_t;
typedef enum
{
	GPIO_PIN0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
	GPIO_PIN4,
	GPIO_PIN5,
	GPIO_PIN6,
	GPIO_PIN7,
	GPIO_PIN8,
	GPIO_PIN9,
	GPIO_PIN10,
	GPIO_PIN11,
	GPIO_PIN12,
	GPIO_PIN13,
	GPIO_PIN14,
	GPIO_PIN15,
}GPIO_PIN_t;
typedef enum
{
	GPIO_INPUT,
	GPIO_OUTPUT,
	GPIO_ALTERNATE_FUNCTION,
	GPIO_ANALOG
}MODE_t;

typedef enum
{
	GPIO_OUTPUT_PUSH_PULL,
	GPIO_OUTPUT_OPEN_DRAIN
}OUTPUT_TYPE_t;

typedef enum
{
	GPIO_PIN_LOW,
	GPIO_PIN_HIGH
}GPIO_PIN_VALUE_t;

typedef enum
{
	GPIO_LOW_SPEED,
	GPIO_MEDIUM_SPEED,
	GPIO_HIGH_SPEED,
	GPIO_VERY_HIGH_SPEED
}OUTPUT_SPEED_t;
typedef enum
{
	GPIO_NO_PULLUP_NO_PULL_DOWN,
	GPIO_PULL_UP,
	GPIO_PULL_DOWN,
}PULL_TYPE_t;

typedef enum
{
	GPIO_ALTER_SYSTEM,
	GPIO_ALTER_TIM1_TIM2,
	GPIO_ALTER_TIM3_TIM5,
	GPIO_ALTER_TIM9_TIM11,
	GPIO_ALTER_I2C1_3,
	GPIO_ALTER_SPI1_4,
	GPIO_ALTER_SPI3,
	GPIO_ALTER_UART1_2,
	GPIO_ALTER_UART6,
	GPIO_ALTER_I2C2_3,
	GPIO_ALTER_OTG_FS,
	GPIO_ALTER_SDIO=12,
	GPIO_ALTER_EVENTOUT=15,
}ALTERNATE_FUN_t;

typedef struct
{
	GPIO_PORT_t       Port ;
	GPIO_PIN_t        Pin ;
	MODE_t            Mode;
	OUTPUT_TYPE_t     Output_Type;
	OUTPUT_SPEED_t    Output_Speed;
	PULL_TYPE_t       Pull_Type;
	GPIO_PIN_VALUE_t  Pin_Value;
	ALTERNATE_FUN_t   AlternateMode;
}GPIO_PinConfig_t;

void GPIO_voidInit  (GPIO_PinConfig_t * Ptr_To_PinConfig);

void GPIO_voidSetPinMode( u8 Copyu8Port ,u8 Copyu8PinID , u8 Copyu8Mode);
void GPIO_voidSetPortMode8Pins( u8 Copyu8Port , u8 Copyu8Mode);

void GPIO_voidSetPinOutputType( u8 Copyu8Port ,u8 Copyu8PinID , u8 OutputType);

void GPIO_voidSetPinOutputSpeed (u8 Copyu8Port , u8 Copyu8PinID , u8 OutputSpeed );

void GPIO_voidSetInputPull (u8 Copyu8Port , u8 Copyu8PinID , u8 Pull);

u8 GPIO_u8GetPinValue  (u8 Copyu8Port , u8 Copyu8PinID );

void GPIO_voidSetPinValueAtomic (u8 Copyu8Port  , u8 Copyu8PinID , u8 Value);
void GPIO_voidSetPortValue8Pins (u8 Copyu8Port  , u8 Value);

void GPIO_voidSetPinAlternative ( u8 Copyu8Port , u8 Copyu8PinID , u8 Alternative);


#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
