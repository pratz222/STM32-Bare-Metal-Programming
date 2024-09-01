// Board: STM32F407VG

#include "stdint.h"

void delay(volatile unsigned int time);

int main(void){

  uint32_t *pClkCtrl = (uint32_t*) 0x40023830;        // Pointer to memory address = (base addr + offset addr)
  uint32_t *pPortMode = (uint32_t*) 0x40020C00;       // Pointer to memory address = (base addr + offset addr)
  uint32_t *pPortDout = (uint32_t*) 0x40020C14;      // Pointer to memory address = (base addr + offset addr)

  *pClkCtrl |= 0x08;                               // set RCC (Enable clk for the peripheral)

  *pPortMode &= 0xFCFFFFFF;                        // clear all the bits (making sure)
  *pPortMode |= 0x01000000;                        // set the Mode Reguster as OUTPUT MODE

  *pPortDout |= 0x1000;                            // Set PORT-D PIN HIGH

  while(1){
    *pPortDout |= 0x0000;          // LED ON
    delay(500000);
    *pPortDout |= 0x1000;          // LED OFF 
    delay(500000);
  }
}

// Delay function
void delay(volatile unsigned int time)
{
    while (time--) {}  // Simple delay loop
}
