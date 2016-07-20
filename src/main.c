/************************************************************************\
 * ODROID C2 Bare Metal                                                  *
 * Copyright (C) 2016  Federico "MrModd" Cosentino                       *
 *                                                                       *
 * This program is free software: you can redistribute it and/or modify  *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 \***********************************************************************/

#include "odroidc2_gpio.h"

volatile unsigned int *gpio = (unsigned int *) GPIOAO_BASE;

void main(void)
{
	/* Reset mux */
	volatile unsigned int *ao_reg = (unsigned int *) AO_REG;
	volatile unsigned int *ao_reg2 = (unsigned int *) AO_REG2;
	
	*ao_reg &= ~(1u<<31 | 1u<<4 | 1u<<3);
	*ao_reg2 &= ~(1u<<1);
	
	/* Set as an output */
	gpio[GPIOAO_OFF1] &= ~(1u<<LED_BIT);
	/*gpio[GPIOAO_OFF3] &= ~(1u<<LED_BIT);*/
	
	/* Set high */
	gpio[GPIOAO_OFF1] |= 1u<<(LED_BIT+16);
	/* Set low */
	/*gpio[GPIOAO_OFF1] &= ~(1u<<(LED_BIT+16));*/
	
	for(;;)
		;
}
