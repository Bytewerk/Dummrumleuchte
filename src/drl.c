/*
	This file is part of Dummrumleuchte.
	LeuchtSchild is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	LeuchtSchild is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Dummrumleuchte.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <avr/io.h>

#include "timer.h"
#include "drl.h"

/*
 * This implements the interface to the Dummrumleuchte.
 */

static uint32_t drl_off_time;

void drl_init(void)
{
	drl_off_time = 0;

	DRL_PORT &= ~DRL_PIN;
	DRL_DDR  |= DRL_PIN;
}

void drl_activate(uint32_t duration_ms)
{
	if(duration_ms == 0) {
		// keep it on forever
		drl_off_time = 0;
	} else {
		drl_off_time = timer_getMs() + duration_ms;
	}

	DRL_PORT |= DRL_PIN;
}

void drl_deactivate(void)
{
	drl_off_time = 0;

	DRL_PORT &= ~DRL_PIN;
}

void drl_periodic(void)
{
	if(drl_off_time != 0 && drl_off_time < timer_getMs()) {
		drl_deactivate();
	}
}
