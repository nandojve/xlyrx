// Copyright (c) 2017 Patrik Bachan
//
// GNU GENERAL PUBLIC LICENSE
//    Version 3, 29 June 2007
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef _HARDWARE_LIB
	#define _HARDWARE_LIB

	#include "stm32f103xb.h"
	#include "misc.h"
	#include <inttypes.h>

	void gpio_init(void);

	#define HARDWARE_LED_1		0
	#define HARDWARE_LED_2		1
	#define HARDWARE_LED_COUNT	2

	inline void led_on(uint8_t led)
	{
		switch(led)
		{
			case HARDWARE_LED_1:
				GPIOC->BSRR=GPIO_BSRR_BR13;
				return;

			case HARDWARE_LED_2:
				GPIOC->BSRR=GPIO_BSRR_BR14;
				return;
		}
	}

	inline void led_off(uint8_t led)
	{
		switch(led)
		{
			case HARDWARE_LED_1:
				GPIOC->BSRR=GPIO_BSRR_BS13;
				return;

			case HARDWARE_LED_2:
				GPIOC->BSRR=GPIO_BSRR_BS14;
				return;
		}
	}

#endif