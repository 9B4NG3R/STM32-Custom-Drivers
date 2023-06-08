#include <stm32f10x.h>
//Uses UART from STM32 to pair it with PM2.5 particle sensor that detects air quality data and stores it in Result. Readable from DEBUG mode in Keil MicroVision 
char data[10];
int Data1;
int Data2;
int result;
int i;
int main(void){
	
	
RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	
	USART1->BRR=0x1D4C;
	
	GPIOA->CRH|=(1<<4);
	GPIOA->CRH|=(1<<5);
	GPIOA->CRH&=~(1<<6);
	GPIOA->CRH|=(1<<7);


USART1->CR1 |= USART_CR1_RE;
USART1->CR1 |= USART_CR1_TE;
USART1->CR1 |= USART_CR1_UE;
	
while(1){

	
if(USART1->SR & USART_SR_RXNE){
	
		data[i]=USART1->DR;
while(!(USART1->SR&USART_SR_TC)){};
	i++;
}

	if(i>=10)
	{i=0;
	
	}
	
	
if (data[0]==0xAA)
{
	
Data1=data[2];
Data2=data[3];
result=((Data2*256	)+Data1)/10;
}

	
	





}

}
