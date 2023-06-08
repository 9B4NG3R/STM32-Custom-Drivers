#include "stm32f10x.h"                  // Device header

static void delay();
static void resetdisp();
static void brojevidisp(int k);

int brojevi[] = {0xC0, 0x90, 0x80, 0xF8, 0x82, 0x92, 0x99, 0xB0, 0xAC, 0xF9 };
int main(void) {
	
RCC->APB2ENR |=RCC_APB2ENR_IOPAEN; //aktivacija clocka i porta A
	
		GPIOA->CRL |=GPIO_CRL_MODE; //port se proglasava outputom
		GPIOA->CRL &=~GPIO_CRL_CNF;
	
	
	
	while(1) {
	
		int k;
		
		for (int i = 0; i<10; i++){
			
			brojevidisp(i);
			delay();
			resetdisp();
			
		}
		for(int j=0;j<10;j++)
		{
			brojevidisp(j);
			delay();
			resetdisp();
		} 
		/*switch(k) {
			
			case 1:
				
			brojevidisp(0);
			delay();
			resetdisp();
			
			break;
			
			case 2:
				
			brojevidisp(1);
			delay();
			resetdisp();
			
			break;
			
			case 3:
				
			brojevidisp(2);
			delay();
			resetdisp();
			
			break;
			
			case 4:
				
			brojevidisp(3);
			delay();
			resetdisp();
			
			break;
			
			case 5:
				
			brojevidisp(4);
			delay();
			resetdisp();
			
			break;
			
			case 6:
				
			brojevidisp(5);
			delay();
			resetdisp();
			
			break;
			
			case 7:
				
			brojevidisp(6);
			delay();
			resetdisp();
			
			break;
			
			case 8:
				
			brojevidisp(7);
			delay();
			resetdisp();
			
			break;
			
			case 9:
				
			brojevidisp(8);
			delay();
			resetdisp();
			
			break;
			
			case 10:
				
			brojevidisp(9);
			delay();
			resetdisp();
			
			break;
	
}*/
	}
}

void delay()
{
	for ( int i=0; i<1000000; i++); 
}

void resetdisp()
{
	for ( int i=0; i<8; i++)
		{
		
		GPIOA -> ODR |= (1<<i);
										
		}
}

void brojevidisp(int j)
{
	
		GPIOA -> ODR = brojevi[j];
		
}


	
	