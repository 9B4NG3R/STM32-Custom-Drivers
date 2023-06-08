#include "stm32f10x.h"                  // Device header
#include "PrviProjekat.h"                 // Device header


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

void GPIO_PinMode(GPIO_TypeDef *pGPIOx, uint16_t pinNumber, uint16_t pinMode)
{
	if (pinMode==OUTPUT) 
	{
	if (pGPIOx == GPIOA)
		{
			RCC->APB2ENR |= (1<<2);
			
			if (pinNumber==0)
			{
				GPIOA->CRL |=0X0011 ;
		}
			else if (pinNumber==1)
			{
				GPIOA->CRL |= A1;
		}
			else if (pinNumber==2)
			{
				GPIOA->CRL |= A2;
		}
			else if (pinNumber==3)
			{
				GPIOA->CRL |= A3;
		}
			else if (pinNumber==4)
			{
				GPIOA->CRL |= A4;
		}
			else if (pinNumber==5)
			{
				GPIOA->CRL |= A5;
		}
			else if (pinNumber==6)
			{
				GPIOA->CRL |= A6;
		}
			else if (pinNumber==7)
			{
				GPIOA->CRL |= A7;
		}
	}
		else if(pinMode==INPUT)
		{
			if (pinNumber==0)
			{
				GPIOA->CRL |= A0;
		}
			else if (pinNumber==1)
			{
				GPIOA->CRL |= A1;
		}
			else if (pinNumber==2)
			{
				GPIOA->CRL |= A2;
		}
			else if (pinNumber==3)
			{
				GPIOA->CRL |= A3;
		}
			else if (pinNumber==4)
			{
				GPIOA->CRL |= A4;
		}
			else if (pinNumber==5)
			{
				GPIOA->CRL |= A5;
		}
			else if (pinNumber==6)
			{
				GPIOA->CRL |= A6;
		}
			else if (pinNumber==7)
			{
				GPIOA->CRL |= A7;
		}
			
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
}
