//#define STM32F4
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include "example_folder_include.h"

/* Set STM32 to 84 MHz. */
static void clock_setup(void)
{
	//rcc_clock_setup_pll(&rcc_hse_25mhz_3v3[RCC_CLOCK_3V3_84MHZ]);

	rcc_periph_clock_enable(RCC_GPIOC);
}

static void gpio_setup(void)
{
	/* Enable led as output */
	gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13);
	gpio_clear(GPIOC, GPIO13);
}

int main(void) {
    clock_setup();
	gpio_setup();

	if(add_two(2) == 4) {
    	gpio_clear(GPIOC, GPIO13);
	} else {
    	gpio_set(GPIOC, GPIO13);
	}
    while(1);
}