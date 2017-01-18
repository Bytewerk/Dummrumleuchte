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

#include <stdint.h>

/* This file defines the interface to the Dummrumleuchte */

/* Pin setup */
#define DRL_PORT PORTB
#define DRL_DDR  DDRB
#define DRL_PIN  (1 << PORTB7)


/*!
 * Initialize the internal variables and the output pins.
 */
void drl_init(void);

/*!
 * Activate the Dummrumleuchte.
 *
 * \param duration_ms    Number of milliseconds the Dummrumleuchte should stay
 *                       active. If this is 0, no limit will be set.
 */
void drl_activate(uint32_t duration_ms);

/*!
 * Deactivate the Dummrumleuchte.
 */
void drl_deactivate(void);

/*!
 * Function for auto-deactivation. Should be called as often as possible.
 */
void drl_periodic(void);
