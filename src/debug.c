#include "debug.h"

/*******************************************************************************
 * define which pin should be used for debugging
*******************************************************************************/
#define DEBUG_DDR       DDRB
#define DEBUG_PORT      PORTB
#define DEBUG_BIT       PB1




/*******************************************************************************
 * @brief   initialize the debug I/O pin
 *
 * simply sets the debug-pin as an output with an initial LOW-level
 *
 * @param   none
 *
 * @return  none
 *
*******************************************************************************/
void debug_init() {
    DEBUG_DDR  |=  (1<<DEBUG_BIT);
    DEBUG_PORT &= ~(1<<DEBUG_BIT);
}


/*******************************************************************************
 * @brief   controls the debug pin
 *
 * @param   mode    LOW     sets the pin to a low-level
 *                  HIGH    sets the pin to a high-level
 *                  TOGGLE  toggles the pin
 *
 * @return  none
 *
*******************************************************************************/
void debug_set_pin(uint8_t mode) {

    switch(mode) {

        case DEBUG_LOW:
            DEBUG_PORT &= ~(1<<DEBUG_BIT);
            break;

        case DEBUG_HIGH:
            DEBUG_PORT |= (1<<DEBUG_BIT);
            break;

        case DEBUG_TOGGLE:
            DEBUG_PORT ^= (1<<DEBUG_BIT);
            break;

    }

}
