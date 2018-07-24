/*******************************************************************************
 * @file debug.c
 *
 * author               : dante999
 *
 * brief                : a little one-pin-debug library
 *
 * description          : pretty simple module, with this one you can choose a 
 *                        pin for debugging purposes. The module supports 
 *                        setting the pin HIGH, LOW or TOGGLE it. 
 *
 * supported devices    : all avr controllers
 *
 * usage                : at first change the defines to the pin you want to use
 *                        for debugging. Then call the 'debug_init()' function 
 *                        and after that you can use the 'debug_set_pin()'
 * 
 ******************************************************************************/

#include "debug.h"

/*******************************************************************************
 * define which pin should be used for debugging
 ******************************************************************************/
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
 ******************************************************************************/
void debug_init() {
    DEBUG_DDR  |=  (1<<DEBUG_BIT);
    DEBUG_PORT &= ~(1<<DEBUG_BIT);
}


/*******************************************************************************
 * @brief   controls the debug pin
 *
 * use the 'defines' from the header file for passing the parameter 'mode'
 * to this function. 
 *
 * @param   mode    DEBUG_LOW     sets the pin to a low-level
 *                  DEBUG_HIGH    sets the pin to a high-level
 *                  DEBUG_TOGGLE  toggles the pin
 *
 * @return  none
 *
 ******************************************************************************/
void debug_set_pin(uint8_t mode) {

    switch(mode) {

        case DEBUG_LOW:
            DEBUG_PORT &= ~(1<<DEBUG_BIT);
            break;

        case DEBUG_HIGH:
            DEBUG_PORT |=  (1<<DEBUG_BIT);
            break;

        case DEBUG_TOGGLE:
            DEBUG_PORT ^= (1<<DEBUG_BIT);
            break;

    }

}
