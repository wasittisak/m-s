#pragma once

#ifdef CONFIG_STM32F103
#include "f10x/stm32f10x.h"
#include "f10x/stm32f10x_usart.h"
#endif

#include "uart.h"
#include "gpio.h"
#include "time.h"
#include "spi.h"
#include "twi.h"
#include "pwm.h"
#include "adc.h"

#define eeprom_update_block(a, b, c) {}
#define eeprom_read_block(a, b, c) {}
