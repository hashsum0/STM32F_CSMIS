#include "src/stm32f10x.h"


void SystemInit()
{

}
void InitGPIO(void)
{
   RCC->APB2ENR	|= RCC_APB2ENR_IOPCEN;		 
   GPIOC->CRH	&= ~GPIO_CRH_CNF9;			
   GPIOC->CRH   |= GPIO_CRH_MODE9_0;		
   GPIOC->CRH	&= ~GPIO_CRH_CNF8;
   GPIOC->CRH   |= GPIO_CRH_MODE8_0;
}

int main(void)
{
  InitGPIO();
  
  uint32_t t=0;
while(1)
	{
       GPIOC->BSRR =GPIO_BSRR_BR8;
	   GPIOC->BSRR =GPIO_BSRR_BS9;
       for(t=0;t<500000;t++)
        {
		  __NOP();
        }
	   GPIOC->BSRR =GPIO_BSRR_BR9;
	   GPIOC->BSRR =GPIO_BSRR_BS8;
       for(t=0;t<50000;t++)
        {
		   __NOP();
        }
	}
} 


