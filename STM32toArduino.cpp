#include "stm32f10x.h"
#include "STM32toArduinoHeader.h"                 // Device header

void PinMode(uint16_t pinNumber, uint16_t pinMode){
	//
	if(pinMode==OUTPUT){
	if(pinNumber<=7){
		RCC->APB2ENR |=(1<<2);
		GPIOA->CRL|=(1<<(pinNumber*4));
		GPIOA->CRL|=(1<<(pinNumber*4)+1);
		GPIOA->CRL&=~(1<<(pinNumber*4)+2);
		GPIOA->CRL&=~(1<<(pinNumber*4)+3);
		
	}
	if(pinNumber<=15&&pinNumber>7){
		RCC->APB2ENR |=(1<<2);
		GPIOA->CRH|=(1<<(pinNumber%8*4));
		GPIOA->CRH|=(1<<(pinNumber%8*4)+1);
		GPIOA->CRH&=~(1<<(pinNumber%8*4)+2);
		GPIOA->CRH&=~(1<<(pinNumber%8*4)+3);
		
	}
	if(pinNumber>15&&pinNumber<=23){
		RCC->APB2ENR |=(1<<3);
		GPIOB->CRL|=(1<<(pinNumber%16*4));
		GPIOB->CRL|=(1<<(pinNumber%16*4)+1);
		GPIOB->CRL&=~(1<<(pinNumber%16*4)+2);
		GPIOB->CRL&=~(1<<(pinNumber%16*4)+3);
		
	}
	if(pinNumber<=31&&pinNumber>23){
		RCC->APB2ENR |=(1<<3);
		GPIOB->CRH|=(1<<(pinNumber%24*4));
		GPIOB->CRH|=(1<<(pinNumber%24*4)+1);
		GPIOB->CRH&=~(1<<(pinNumber%24*4)+2);
		GPIOB->CRH&=~(1<<(pinNumber%24*4)+3);
		
	}
	if(pinNumber<=34&&pinNumber>31){
		RCC->APB2ENR |=(1<<4);
		
		GPIOC->CRH|=(1<<(pinNumber%27*4));
		GPIOC->CRH|=(1<<(pinNumber%27*4)+1);
		GPIOC->CRH&=~(1<<(pinNumber%27*4)+2);
		GPIOC->CRH&=~(1<<(pinNumber%27*4)+3);
		
	}
	} 
	
	
	
	if(pinMode==INPUT){	
	if(pinNumber<=7){
		RCC->APB2ENR |=(1<<2);
		GPIOA->CRL|=(1<<(pinNumber*4)+3);
		GPIOA->CRL&=~(1<<(pinNumber*4)+2);
		GPIOA->CRL&=~(1<<(pinNumber*4)+1);
		GPIOA->CRL&=~(1<<(pinNumber*4));
		
	}
	if(pinNumber<=15&&pinNumber>7){
		RCC->APB2ENR |=(1<<2);
		GPIOA->CRH|=(1<<(pinNumber%8*4)+3);
		GPIOA->CRH&=~(1<<(pinNumber%8*4)+2);
		GPIOA->CRH&=~(1<<(pinNumber%8*4)+1);
		GPIOA->CRH&=~(1<<(pinNumber%8*4));
		
	}
	if(pinNumber>15&&pinNumber<=23){
		RCC->APB2ENR |=(1<<3);
		GPIOB->CRL|=(1<<(pinNumber%16*4)+3);
		GPIOB->CRL&=~(1<<(pinNumber%16*4)+2);
		GPIOB->CRL&=~(1<<(pinNumber%16*4)+1);
		GPIOB->CRL&=~(1<<(pinNumber%16*4));
		
	}
	if(pinNumber<=31&&pinNumber>23){
		RCC->APB2ENR |=(1<<3);
		GPIOB->CRH|=(1<<(pinNumber%24*4)+3);
		GPIOB->CRH&=~(1<<(pinNumber%24*4)+2);
		GPIOB->CRH&=~(1<<(pinNumber%24*4)+1);
		GPIOB->CRH&=~(1<<(pinNumber%24*4));
		
	}
	if(pinNumber<=34&&pinNumber>31){
		RCC->APB2ENR |=(1<<4);
		GPIOC->CRH|=(1<<(pinNumber%27*4)+3);
		GPIOC->CRH&=~(1<<(pinNumber%27*4)+2);
		GPIOC->CRH&=~(1<<(pinNumber%27*4)+1);
		GPIOC->CRH&=~(1<<(pinNumber%27*4));
		
	}
	
	} 
	
}





bool DigitalRead(uint16_t pinNumber){
	//
		if(pinNumber<=15){ 
	if(pinNumber==0&&GPIOA->IDR&0x1){return HIGH;}
	else if(pinNumber==1&&GPIOA->IDR&0x2){return HIGH;}
	else if(pinNumber==2&&GPIOA->IDR&0x4){return HIGH;}
	else if(pinNumber==3&&GPIOA->IDR&0x8){return HIGH;}
	else if(pinNumber==4&&GPIOA->IDR&0x10){return HIGH;}
	else if(pinNumber==5&&GPIOA->IDR&0x20){return HIGH;}
	else if(pinNumber==6&&GPIOA->IDR&0x40){return HIGH;}
	else if(pinNumber==7&&GPIOA->IDR&0x80){return HIGH;}
	else if(pinNumber==8&&GPIOA->IDR&0x100){return HIGH;}
	else if(pinNumber==9&&GPIOA->IDR&0x200){return HIGH;}
	else if(pinNumber==10&&GPIOA->IDR&0x400){return HIGH;}
	else if(pinNumber==11&&GPIOA->IDR&0x800){return HIGH;}
	else if(pinNumber==12&&GPIOA->IDR&0x1000){return HIGH;}
	else if(pinNumber==13&&GPIOA->IDR&0x2000){return HIGH;}
	else if(pinNumber==14&&GPIOA->IDR&0x4000){return HIGH;}
	else if(pinNumber==15&&GPIOA->IDR&0x8000){return HIGH;}
	else{return LOW;}
	
}

  else if(pinNumber>15&&pinNumber<=31){ 
	if(pinNumber==16&&GPIOB->IDR&0x1){return HIGH;}
	else if(pinNumber==17&&GPIOB->IDR&0x2){return HIGH;}
	else if(pinNumber==18&&GPIOB->IDR&0x4){return HIGH;}
	else if(pinNumber==19&&GPIOB->IDR&0x8){return HIGH;}
	else if(pinNumber==20&&GPIOB->IDR&0x10){return HIGH;}
	else if(pinNumber==21&&GPIOB->IDR&0x20){return HIGH;}
	else if(pinNumber==22&&GPIOB->IDR&0x40){return HIGH;}
	else if(pinNumber==23&&GPIOB->IDR&0x80){return HIGH;}
	else if(pinNumber==24&&GPIOB->IDR&0x100){return HIGH;}
	else if(pinNumber==25&&GPIOB->IDR&0x200){return HIGH;}
	else if(pinNumber==26&&GPIOB->IDR&0x400){return HIGH;}
	else if(pinNumber==27&&GPIOB->IDR&0x800){return HIGH;}
	else if(pinNumber==28&&GPIOB->IDR&0x1000){return HIGH;}
	else if(pinNumber==29&&GPIOB->IDR&0x2000){return HIGH;}
	else if(pinNumber==30&&GPIOB->IDR&0x4000){return HIGH;}
	else if(pinNumber==31&&GPIOB->IDR&0x8000){return HIGH;}
	else{return LOW;}
		
		}
	else if(pinNumber>31&&pinNumber<=34){ 
	if(pinNumber==32&&GPIOC->IDR&0x2000){return HIGH;}
	else if(pinNumber==33&&GPIOC->IDR&0x4000){return HIGH;}
	else if(pinNumber==34&&GPIOC->IDR&0x8000){return HIGH;}
	else{return LOW;}
		
		}
		
	else{ return LOW;}
		
	
}

	uint16_t DigitalReadPort(GPIO_TypeDef *pGPIOx){
	
	if(pGPIOx==GPIOA){
	return GPIOA->IDR;
	}
	else if(pGPIOx==GPIOB){
	return GPIOB->IDR;
	}
	else if(pGPIOx==GPIOC){
	return GPIOC->IDR;
	}
	else {return 0;}
	}

void DigitalWrite(uint16_t PinNumber, bool Value){
	//
	if(PinNumber<=15){
		if(Value==HIGH){
		GPIOA->ODR |=(1<<PinNumber);
		}
		if(Value==LOW){
		GPIOA->ODR &=~(1<<PinNumber);
		}	
	}
	if(PinNumber>15&&PinNumber<=31){
		if(Value==HIGH){
		GPIOB->ODR |=(1<<PinNumber%16);
		}
		if(Value==LOW){
		GPIOB->ODR &=~(1<<PinNumber%16);
		}	
	}
	 if(PinNumber>31&&PinNumber<=34){ 
		if(Value==HIGH){
		GPIOC->ODR |=(1<<PinNumber%19);
		}
		if(Value==LOW){
		GPIOC->ODR &=~(1<<PinNumber%19);
		}	
	}
}



void ToggleOutputPin(uint16_t PinNumber){

if(PinNumber<=15){
		
		GPIOA->ODR ^=(1<<PinNumber);
}
	if(PinNumber>15&&PinNumber<=31){
		
		GPIOB->ODR ^=(1<<PinNumber%16);
	}
	if(PinNumber>31&&PinNumber<=34){ 
		
		GPIOC->ODR ^=(1<<PinNumber%19);
		
	}

}


void DigitalWritePort(GPIO_TypeDef *pGPIOx,uint16_t Value){
if(pGPIOx==GPIOA){
	GPIOA->ODR=Value;
	}
	else if(pGPIOx==GPIOB){
	GPIOB->ODR=Value;
	}
	else if(pGPIOx==GPIOC){
	GPIOC->ODR=Value;
	}


}
