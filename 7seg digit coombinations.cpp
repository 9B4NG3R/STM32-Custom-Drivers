#include "stm32f10x.h"                  // Device header
static void nula();
static void jedan();
static void dva();
static void tri();
static void cetiri();
static void pet();
static void sest();
static void sedam();
static void osam();
static void devet();

int main(void) {
	
RCC->APB2ENR |=RCC_APB2ENR_IOPAEN; //aktivacija clocka i porta A
	
		GPIOA->CRL |=GPIO_CRL_MODE; //port se proglašava outputom
		GPIOA->CRL &=~GPIO_CRL_CNF;
	
	while(1) {
	tri();
	
}
	}

void nula()
{
GPIOA->ODR&=~(1<<0);
GPIOA->ODR&=~(1<<1);
GPIOA->ODR&=~(1<<2);
GPIOA->ODR|=(1<<3);
GPIOA->ODR&=~(1<<4);
GPIOA->ODR&=~(1<<5);
GPIOA->ODR&=~(1<<6);
}

void jedan()
{
GPIOA->ODR|=(1<<0);
GPIOA->ODR &=~(1<<1);
GPIOA->ODR &=~(1<<2);
GPIOA->ODR|=(1<<3);
GPIOA->ODR|=(1<<4);
GPIOA->ODR|=(1<<5);
GPIOA->ODR|=(1<<6);
}

void dva()
{	
GPIOA->ODR&=~(1<<0);
GPIOA->ODR&=~(1<<1);
GPIOA->ODR|=(1<<2);
GPIOA->ODR&=~(1<<3);
GPIOA->ODR&=~(1<<4);
GPIOA->ODR&=~(1<<5);
GPIOA->ODR|=(1<<6);
}

void tri()
{
GPIOA->ODR&=~(1<<0);
GPIOA->ODR&=~(1<<1);
GPIOA->ODR&=~(1<<2);
GPIOA->ODR&=~(1<<3);
GPIOA->ODR&=~(1<<4);
GPIOA->ODR|=(1<<5);
GPIOA->ODR|=(1<<6);
}

void cetiri ()
{
GPIOA->ODR|=(1<<0);
GPIOA->ODR|=(1<<1);
GPIOA->ODR&=~(1<<2);
GPIOA->ODR&=~(1<<3);
GPIOA->ODR|=(1<<4);
GPIOA->ODR|=(1<<5);
GPIOA->ODR&=~(1<<6);
}

void pet ()
{
GPIOA->ODR&=~(1<<0);
GPIOA->ODR|=(1<<1);
GPIOA->ODR&=~(1<<2);
GPIOA->ODR&=~(1<<3);
GPIOA->ODR&=~(1<<4);
GPIOA->ODR|=(1<<5);
GPIOA->ODR&=~(1<<6);
}

void sest ()
{
GPIOA->ODR&=~(1<<0);
GPIOA->ODR|=(1<<1);
GPIOA->ODR&=~(1<<2);
GPIOA->ODR&=~(1<<3);
GPIOA->ODR&=~(1<<4);
GPIOA->ODR&=~(1<<5);
GPIOA->ODR&=~(1<<6);
}

void sedam ()
{
GPIOA->ODR&=~(1<<0);
GPIOA->ODR&=~(1<<1);
GPIOA->ODR&=~(1<<2);
GPIOA->ODR|=(1<<3);
GPIOA->ODR|=(1<<4);
GPIOA->ODR|=(1<<5);
GPIOA->ODR|=(1<<6);
}

void osam ()
{
GPIOA->ODR&=~(1<<0);
GPIOA->ODR&=~(1<<1);	
GPIOA->ODR&=~(1<<2);
GPIOA->ODR&=~(1<<3);
GPIOA->ODR&=~(1<<4);
GPIOA->ODR&=~(1<<5);
GPIOA->ODR&=~(1<<6);
}

void devet ()
{
GPIOA->ODR&=~(1<<0);
GPIOA->ODR&=~(1<<1);	
GPIOA->ODR&=~(1<<2);
GPIOA->ODR&=~(1<<3);
GPIOA->ODR&=~(1<<4);
GPIOA->ODR|=(1<<5);
GPIOA->ODR&=~(1<<6);
}


	
	