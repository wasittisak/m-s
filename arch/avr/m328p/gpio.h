#pragma once

typedef enum {
	GPIO_NONE = 0,
	/*GPIO_A0,
	GPIO_A1,
	GPIO_A2,
	GPIO_A3,
	GPIO_A4,
	GPIO_A5,
	GPIO_A6,
	GPIO_A7,*/
	GPIO_B0,
	GPIO_B1,
	GPIO_B2,
	GPIO_B3,
	GPIO_B4,
	GPIO_B5,
	GPIO_B6,
	GPIO_B7,
	GPIO_C0,
	GPIO_C1,
	GPIO_C2,
	GPIO_C3,
	GPIO_C4,
	GPIO_C5,
	GPIO_C6,
	//GPIO_C7,
	GPIO_D0,
	GPIO_D1,
	GPIO_D2,
	GPIO_D3,
	GPIO_D4,
	GPIO_D5,
	GPIO_D6,
	GPIO_D7,
} gpio_pin_t;


typedef enum {
	/*GPIO_A0,
	GPIO_A1,
	GPIO_A2,
	GPIO_A3,
	GPIO_A4,
	GPIO_A5,
	GPIO_A6,
	GPIO_A7,*/
	GPIO_ICP1 = GPIO_B0,
	GPIO_CLK0 = GPIO_B0,
	GPIO_OC1A = GPIO_B1,
	GPIO_OC1B = GPIO_B2,
	GPIO_SS = GPIO_B2,
	GPIO_OC2A = GPIO_B3,
	GPIO_MOSI = GPIO_B3, 
	GPIO_MISO = GPIO_B4,
	GPIO_SCK = GPIO_B5,
	GPIO_TOSC1 = GPIO_B6,
	GPIO_TOSC2 = GPIO_B7,
	GPIO_ADC0 = GPIO_C0,
	GPIO_ADC1 = GPIO_C1,
	GPIO_ADC2 = GPIO_C2,
	GPIO_ADC3 = GPIO_C3,
	GPIO_ADC4 = GPIO_C4,
	GPIO_SDA = GPIO_C4,
	GPIO_ADC5 = GPIO_C5,
	GPIO_SCL = GPIO_C5,
	GPIO_RESET = GPIO_C6,
	//GPIO_C7,
	GPIO_RXD = GPIO_D0,
	GPIO_TXD = GPIO_D1,
	GPIO_INT0 = GPIO_D2,
	GPIO_INT1 = GPIO_D3,
	GPIO_XCK = GPIO_D4,
	GPIO_T0 = GPIO_D4,
	GPIO_OC0B = GPIO_D5,
	GPIO_T1 = GPIO_D5,
	GPIO_OC0A = GPIO_D6,
	GPIO_AIN0 = GPIO_D6,
	GPIO_AIN1 = GPIO_D7,
} aux_pin_t;

extern void 		gpio_write_pin(gpio_pin_t pin, uint8_t value);
extern uint8_t 	gpio_read_pin(gpio_pin_t pin);
extern void 		gpio_set_function(gpio_pin_t pin, uint8_t fun);
extern void 		gpio_set_pullup(gpio_pin_t pin, uint8_t pullup);
