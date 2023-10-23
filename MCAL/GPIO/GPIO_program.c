/*
 * GPIO_program.c
 *
 *  Created on: Sep 4, 2023
 *      Author: alibo
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"



#define GPIO_PORTA_LOW	*((volatile u8*)(GPIOA_BASE_ADDRESS+0x14))
#define GPIO_PORTB_LOW	*((volatile u8*)(GPIOB_BASE_ADDRESS+0x14))
#define GPIO_PORTC_LOW	*((volatile u8*)(GPIOC_BASE_ADDRESS+0x14))

void GPIO_voidSetPinMode( u8 Copyu8Port ,u8 Copyu8PinID , u8 Copyu8Mode)
{
	if( (Copyu8Port <= GPIO_PORTC )  && (Copyu8PinID <= GPIO_PIN15) )
	{
		switch (Copyu8Port)
		{
		case GPIO_PORTA:
			GPIOA->GPIO_MODER &= ~( 0b11       << ( Copyu8PinID *2 ) );
			GPIOA->GPIO_MODER |=  ( Copyu8Mode << ( Copyu8PinID *2 ) );
			break;

		case GPIO_PORTB:
			GPIOB->GPIO_MODER &= ~( 0b11       << ( Copyu8PinID *2 ) );
			GPIOB->GPIO_MODER |=  ( Copyu8Mode << ( Copyu8PinID *2 ) );
			break;


		case GPIO_PORTC:
			GPIOC->GPIO_MODER &= ~( 0b11       << ( Copyu8PinID *2 ) );
			GPIOC->GPIO_MODER |=  ( Copyu8Mode << ( Copyu8PinID *2 ) );
			break;
		}
	}
	else
	{
		// error
	}
}
void GPIO_voidSetPortMode8Pins( u8 Copyu8Port , u8 Copyu8Mode)
{
	if( Copyu8Port <= GPIO_PORTC )
	{
		if( Copyu8Mode == GPIO_OUTPUT )
		{
			switch (Copyu8Port)
			{
			case GPIO_PORTA:

				SET_BIT(GPIOA->GPIO_MODER,0);//0
				SET_BIT(GPIOA->GPIO_MODER,2);//1
				SET_BIT(GPIOA->GPIO_MODER,4);//2
				SET_BIT(GPIOA->GPIO_MODER,6);//3
				SET_BIT(GPIOA->GPIO_MODER,8);//4
				SET_BIT(GPIOA->GPIO_MODER,10);//5
				SET_BIT(GPIOA->GPIO_MODER,12);//6
				SET_BIT(GPIOA->GPIO_MODER,14);//7

				break;

			case GPIO_PORTB:
				SET_BIT(GPIOB->GPIO_MODER,0);//0
				SET_BIT(GPIOB->GPIO_MODER,2);//1
				SET_BIT(GPIOB->GPIO_MODER,4);//2
				SET_BIT(GPIOB->GPIO_MODER,6);//3
				SET_BIT(GPIOB->GPIO_MODER,8);//4
				SET_BIT(GPIOB->GPIO_MODER,10);//5
				SET_BIT(GPIOB->GPIO_MODER,12);//6
				SET_BIT(GPIOB->GPIO_MODER,14);//7
				break;


			case GPIO_PORTC:
				SET_BIT(GPIOC->GPIO_MODER,0);//0
				SET_BIT(GPIOC->GPIO_MODER,2);//1
				SET_BIT(GPIOC->GPIO_MODER,4);//2
				SET_BIT(GPIOC->GPIO_MODER,6);//3
				SET_BIT(GPIOC->GPIO_MODER,8);//4
				SET_BIT(GPIOC->GPIO_MODER,10);//5
				SET_BIT(GPIOC->GPIO_MODER,12);//6
				SET_BIT(GPIOC->GPIO_MODER,14);//7
				break;
			}
		}
		else if( Copyu8Mode == GPIO_INPUT )
		{
			switch (Copyu8Port)
			{
			case GPIO_PORTA:
				GPIOA->GPIO_MODER = 0b00000000  ;
				break;

			case GPIO_PORTB:
				GPIOB->GPIO_MODER = 0b00000000  ;
				break;


			case GPIO_PORTC:
				GPIOC->GPIO_MODER = 0b00000000 ;
				break;
			}
		}
	}
	else
	{
		//error
	}
}

void GPIO_voidSetPinOutputType( u8 Copyu8Port ,u8 Copyu8PinID , u8 OutputType)
{
	if( (Copyu8Port <= GPIO_PORTC )  && (Copyu8PinID <= GPIO_PIN15) )
	{
		switch (Copyu8Port)
		{
		case GPIO_PORTA:
			GPIOA->GPIO_OTYPER &= ~( 0b1        << Copyu8PinID );
			GPIOA->GPIO_OTYPER |=  ( OutputType << Copyu8PinID );
			break;

		case GPIO_PORTB:
			GPIOB->GPIO_OTYPER &= ~( 0b1        << Copyu8PinID );
			GPIOB->GPIO_OTYPER |=  ( OutputType << Copyu8PinID );
			break;

		case GPIO_PORTC:
			GPIOC->GPIO_OTYPER &= ~( 0b1        << Copyu8PinID );
			GPIOC->GPIO_OTYPER |=  ( OutputType << Copyu8PinID );
			break;
		}
	}
	else
	{
		// error
	}
}

void GPIO_voidSetPinOutputSpeed (u8 Copyu8Port , u8 Copyu8PinID , u8 OutputSpeed )
{
	if( (Copyu8Port <= GPIO_PORTC )  && (Copyu8PinID <= GPIO_PIN15) )
	{
		switch (Copyu8Port)
		{
		case GPIO_PORTA:
			GPIOA->GPIO_OSPEEDR &= ~( 0b11        << ( Copyu8PinID * 2 ) );
			GPIOA->GPIO_OSPEEDR |=  ( OutputSpeed << ( Copyu8PinID * 2 ) );
			break;

		case GPIO_PORTB:
			GPIOA->GPIO_OSPEEDR &= ~( 0b11        << ( Copyu8PinID * 2 ) );
			GPIOA->GPIO_OSPEEDR |=  ( OutputSpeed << ( Copyu8PinID * 2 ) );
			break;

		case GPIO_PORTC:
			GPIOA->GPIO_OSPEEDR &= ~( 0b11        << ( Copyu8PinID * 2 ) );
			GPIOA->GPIO_OSPEEDR |=  ( OutputSpeed << ( Copyu8PinID * 2 ) );
			break;
		}
	}
	else
	{
		//error
	}
}
void GPIO_voidSetInputPull (u8 Copyu8Port , u8 Copyu8PinID , u8 Pull)
{
	if( (Copyu8Port <= GPIO_PORTC )  && (Copyu8PinID <= GPIO_PIN15) )
	{
		switch (Copyu8Port)
		{
		case GPIO_PORTA:
			GPIOA->GPIO_PUPDR &= ~( 0b11  << ( Copyu8PinID *2 ) );
			GPIOA->GPIO_PUPDR |=  ( Pull  << ( Copyu8PinID *2 ) );
			break;

		case GPIO_PORTB:
			GPIOB->GPIO_PUPDR &= ~( 0b11  << ( Copyu8PinID *2 ) );
			GPIOB->GPIO_PUPDR |=  ( Pull  << ( Copyu8PinID *2 ) );
			break;


		case GPIO_PORTC:
			GPIOC->GPIO_PUPDR &= ~( 0b11   << ( Copyu8PinID *2 ) );
			GPIOC->GPIO_PUPDR |=  ( Pull   << ( Copyu8PinID *2 ) );
			break;
		}
	}
	else
	{
		// error
	}
}

u8 GPIO_u8GetPinValue  (u8 Copyu8Port , u8 Copyu8PinID )
{
	u8 Local_Returned_Value = 255;
	if( (Copyu8Port <= GPIO_PORTC )  && (Copyu8PinID <= GPIO_PIN15) )
	{
		switch (Copyu8Port)
		{
		case GPIO_PORTA:

			Local_Returned_Value = GET_BIT ( (GPIOA->GPIO_IDR) , Copyu8PinID );
			break;

		case GPIO_PORTB:
			Local_Returned_Value = GET_BIT ( (GPIOB->GPIO_IDR) , Copyu8PinID );
			break;

		case GPIO_PORTC:
			Local_Returned_Value = GET_BIT ( (GPIOB->GPIO_IDR) , Copyu8PinID );
			break;
		}

	}
	else
	{
		//error
	}
	return Local_Returned_Value;
}

void GPIO_voidSetPinValueAtomic (u8 Copyu8Port  , u8 Copyu8PinID , u8 Value)
{
	if( (Copyu8Port <= GPIO_PORTC )  && (Copyu8PinID <= GPIO_PIN15) )
	{
		if( Value == GPIO_PIN_HIGH)
		{
			switch (Copyu8Port)
			{
			case GPIO_PORTA:

				GPIOA->GPIO_BSRR = (GPIO_PIN_HIGH<<Copyu8PinID);
				break;

			case GPIO_PORTB:
				GPIOB->GPIO_BSRR = (GPIO_PIN_HIGH<<Copyu8PinID);
				break;

			case GPIO_PORTC:
				GPIOC->GPIO_BSRR = (GPIO_PIN_HIGH<<Copyu8PinID);
				break;
			}
		}
		else if( Value == GPIO_PIN_LOW )
		{
			switch (Copyu8Port)
			{
			case GPIO_PORTA:
				GPIOA->GPIO_BSRR = (GPIO_PIN_HIGH<< (Copyu8PinID + 16) );
				break;

			case GPIO_PORTB:
				GPIOB->GPIO_BSRR = (GPIO_PIN_HIGH<< (Copyu8PinID + 16) );
				break;

			case GPIO_PORTC:
				GPIOC->GPIO_BSRR = (GPIO_PIN_HIGH<< (Copyu8PinID + 16) );
				break;
			}
		}
	}
	else
	{
		// error
	}
}

void GPIO_voidSetPortValue8Pins (u8 Copyu8Port  , u8 Value)
{
	if( Copyu8Port <= GPIO_PORTC )
	{
		switch (Copyu8Port)
		{
		case GPIO_PORTA:
			GPIO_PORTA_LOW = Value ;
			break;

		case GPIO_PORTB:
			GPIO_PORTB_LOW = Value ;
			break;

		case GPIO_PORTC:
			GPIO_PORTC_LOW = Value ;
			break;
		}
	}
	else
	{
		// error
	}
}

void GPIO_voidSetPinAlternative ( u8 Copyu8Port , u8 Copyu8PinID , u8 Alternative)
{
	if(Copyu8PinID<8)
	{
		switch (Copyu8Port)
		{
		case GPIO_PORTA:
			GPIOA->GPIO_AFRL &= ~( (0b1111)     << (Copyu8PinID*4 ) )  ;
			GPIOA->GPIO_AFRL |=  (  Alternative << (Copyu8PinID*4 ) )  ;
			break;

		case GPIO_PORTB:
			GPIOB->GPIO_AFRL &= ~( (0b1111)     << (Copyu8PinID*4 ) )  ;
			GPIOB->GPIO_AFRL |=  (  Alternative << (Copyu8PinID*4 ) )  ;
			break;

		case GPIO_PORTC:
			GPIOC->GPIO_AFRL &= ~( (0b1111)     << (Copyu8PinID*4 ) )  ;
			GPIOC->GPIO_AFRL |=  (  Alternative << (Copyu8PinID*4 ) )  ;
			break;
		}
	}
	else if(Copyu8PinID  <16)
	{
		switch (Copyu8Port)
		{
		case GPIO_PORTA:
			GPIOA->GPIO_AFRH &= ~( (0b1111)     << ( (Copyu8PinID-8)*4 ) )  ;
			GPIOA->GPIO_AFRH |=  (  Alternative << ( (Copyu8PinID-8)*4 ) ) ;
			break;

		case GPIO_PORTB:
			GPIOB->GPIO_AFRH &= ~( (0b1111)     << ( (Copyu8PinID-8)*4 ) )  ;
			GPIOB->GPIO_AFRH |=  (  Alternative << ( (Copyu8PinID-8)*4 ) )  ;
			break;

		case GPIO_PORTC:
			GPIOC->GPIO_AFRH &= ~( (0b1111)     << ( (Copyu8PinID-8)*4 ) )  ;
			GPIOC->GPIO_AFRH |=  (  Alternative << ( (Copyu8PinID-8)*4 ) )  ;
			break;
		}
	}

}



void GPIO_voidInit  (GPIO_PinConfig_t * Ptr_To_PinConfig)
{

	GPIO_voidSetPinMode        ( (Ptr_To_PinConfig->Port) , (Ptr_To_PinConfig->Pin) , (Ptr_To_PinConfig->Mode)          );
	GPIO_voidSetPinOutputType  ( (Ptr_To_PinConfig->Port) , (Ptr_To_PinConfig->Pin) , (Ptr_To_PinConfig->Output_Type)   );
	GPIO_voidSetPinOutputSpeed ( (Ptr_To_PinConfig->Port) , (Ptr_To_PinConfig->Pin) , (Ptr_To_PinConfig->Output_Speed)  );
	GPIO_voidSetInputPull      ( (Ptr_To_PinConfig->Port) , (Ptr_To_PinConfig->Pin) , (Ptr_To_PinConfig->Pull_Type)     );
	GPIO_voidSetPinValueAtomic ( (Ptr_To_PinConfig->Port) , (Ptr_To_PinConfig->Pin) , (Ptr_To_PinConfig->Pin_Value)     );
	GPIO_voidSetPinAlternative ( (Ptr_To_PinConfig->Port) , (Ptr_To_PinConfig->Pin) , (Ptr_To_PinConfig->AlternateMode) );
}
