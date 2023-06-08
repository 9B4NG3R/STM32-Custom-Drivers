#include "stm32f10x.h"                  // Device header
#include "STM32toArduinoHeader.h"                 // Device header

//This cpp together with it's Header file is used to program STM32 just like an Arduino(Instead of typing GPIOA and all that just type pinMode(1,OUTPUT) and you're done
	void GPIO_ClockCtrl(GPIO_TypeDef *pGPIOx, uint8_t EnOrDi)
{
	if(EnOrDi==ENABLE)
	{
		if (pGPIOx == GPIOA)
		{
			RCC->APB2ENR |= (1<<2);
		}
else if (pGPIOx == GPIOB)
		{
			RCC->APB2ENR |= (1<<3);
		}
		else if(pGPIOx == GPIOC)
		{
			RCC->APB2ENR |= (1<<4);
		}
	}

else if(EnOrDi==DISABLE) {
	if (pGPIOx == GPIOA)
		{
			RCC->APB2ENR &=~ (1<<2);
		}
		else if (pGPIOx == GPIOB)
		{
			RCC->APB2ENR &=~(1<<3);
		}
		else if (pGPIOx == GPIOC)
		{
			RCC->APB2ENR &=~ (1<<4);
		}
}
}

void PinMode( uint16_t pinNumber, uint16_t pinMode)
{
	if (pinNumber<=15 && pinMode==OUTPUT)
	{
		RCC->APB2ENR |= (1<<2);
		if(pinNumber<8)
		{
		GPIOA->CRL |=(1<<pinNumber*4);
			GPIOA->CRL |=(1<<(pinNumber*4)+1);
			GPIOA->CRL &=~(1<<(pinNumber*4)+2);
			GPIOA->CRL&=~(1<<(pinNumber*4)+3);
			
		}
		else if (pinNumber>7 && pinMode==OUTPUT)
		{
		GPIOA->CRH |=(1<<(pinNumber%8)*4);
			GPIOA->CRH |=(1<<((pinNumber%8)*4)+1);
			GPIOA->CRH &=~(1<<((pinNumber%8)*4)+2);
			GPIOA->CRH &=~(1<<((pinNumber%8)*4)+3);
		}
			
			
	}
	if (pinNumber>15 && pinNumber<32 &&  pinMode==OUTPUT)
	{
	RCC->APB2ENR |= (1<<3);
		if(pinNumber<24)
		{
		GPIOB->CRL |=(1<<(pinNumber%16)*4);
			GPIOB->CRL |=(1<<((pinNumber%16)*4)+1);
			GPIOB->CRL &=~(1<<((pinNumber%16)*4)+2);
			GPIOB->CRL&=~(1<<((pinNumber%16)*4)+3);
			
		}
		else if (pinNumber>23 &&  pinMode==OUTPUT)
		{
		GPIOB->CRH |=(1<<(pinNumber%24)*4);
			GPIOB->CRH |=(1<<((pinNumber%24)*4)+1);
			GPIOB->CRH &=~(1<<((pinNumber%24)*4)+2);
			GPIOB->CRH&=~(1<<((pinNumber%24)*4)+3);
		}
		
	}
	if (pinNumber>=32 &&  pinMode==OUTPUT)
	{
	RCC->APB2ENR |= (1<<4);
		GPIOC->CRH |=(1<<(pinNumber%32)*4);
		GPIOC->CRH |=(1<<((pinNumber%32)*4)+1);
		GPIOC->CRH &=~(1<<((pinNumber%32)*4)+2);
		GPIOC->CRH &=~(1<<((pinNumber%32)*4)+3);
		
	}
	
	
		}

		void DigitalWrite(uint16_t pinNumber, bool Value)
		{
			if (pinNumber<=15 && Value==true)
	{
		GPIOA->ODR |= (1<<pinNumber);
			
		}
	else if (pinNumber<=15 && Value==false)
	{
		GPIOA->ODR &=~ (1<<pinNumber);
	}
		
			
			
	
	if (pinNumber>15 && pinNumber<32 && Value==true)
	{
		GPIOB->ODR |= (1<<(pinNumber%8));
			
		}
	else if (pinNumber>15 && pinNumber<32 && Value==false)
	{
		GPIOB->ODR &=~ (1<<(pinNumber%8));
			
		}
		
	
	if (pinNumber>=32 &&  Value==true)
	{
		GPIOC->ODR |= (1<<(pinNumber%32));
		
	}
else if (pinNumber>=32 &&  Value==false)
	{
		GPIOC->ODR &=~ (1<<(pinNumber%32));
		
	}
	
		}
		

		
		
		
		
	

