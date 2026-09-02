#include <stdint.h>

#define PERIPH_BASE     (0x40000000UL)
#define RCC_BASE        (0x40023800UL)
#define GPIOA_BASE      (0x40020000UL)

#define RCC_AHB1ENR     (*(volatile uint32_t *)(RCC_BASE + 0x30))
#define GPIOA_MODER     (*(volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_ODR       (*(volatile uint32_t *)(GPIOA_BASE + 0x14))

#define GPIOAEN         (1U << 0) // -> 000000001
#define PIN5            (1U << 5) // ---> 100000

int main(void)
{
    RCC_AHB1ENR |= GPIOAEN;          // enable GPIOA clock

    GPIOA_MODER |= (1U << 10);      // set bit 10 -> 1
    GPIOA_MODER &= ~(1U << 11);     // set bit 11 -> 0  (mode = 01, output)



    while (1)
    {
        GPIOA_ODR ^= PIN5;          // toggle PA5   1 1 = 0 - 1 0 = 1
        for (volatile int i = 0; i < 1000000; i++); // crude delay
    }
}
