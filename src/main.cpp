#include "stm32f1xx.h"

/***
 * Enables and configures the clocks and PLL to a 72MHz SYSCLK.
 * Must only be called after reset!
 *
 * APB1: 36MHz, ADC: 9MHz
 */
void clock_init_hse_pll_72MHz() {
    RCC->CR |= RCC_CR_HSEON; // Turn on HSE
    RCC->CFGR |= RCC_CFGR_HPRE_DIV2 | RCC_CFGR_ADCPRE_DIV8 | RCC_CFGR_PLLMULL9 | RCC_CFGR_PLLSRC; // Dividers and PLL
    FLASH->ACR |= FLASH_ACR_LATENCY_1; // Set 2 wait states for FLASH access
    while (!(RCC->CR & RCC_CR_HSERDY)); // Wait for HSE to stabilize
    RCC->CR |= RCC_CR_PLLON; // Turn on PLL
    RCC->CFGR |= RCC_CFGR_SW_PLL; // Switch SYSCLK source to PLL
    while (!(RCC->CR & RCC_CR_PLLRDY)); // Wait for PLL to stabilize
}

int main() {
    clock_init_hse_pll_72MHz();

    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    MODIFY_REG(GPIOC->CRH, GPIO_CRH_CNF13 + GPIO_CRH_MODE13, GPIO_CRH_MODE13_0);

    int i;
    while (true) {
        GPIOC->ODR ^= GPIO_ODR_ODR13;
        for (i = 0; i < 500000; i++) {
            __ASM("nop");
        }
    }
}
