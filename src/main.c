/*******************************************************************************
 * @file main.c
 *
 * author               : dante999
 *
 * brief                : just a little demonstration of the ssd1306 library
 *
 * description          : this demonstrates how the lcd-library work. 
 *
 * supported devices    : all avr-devices, testet with attiny85
 *
 * usage                : 
 * 
 * 
*******************************************************************************/
#include <avr/io.h>
#include <util/delay.h>
#include "debug.h"
#include "ssd1306.h"

#ifndef F_CPU
#define F_CPU   16500000UL
#endif

// define min and max of the lcd x-coordinates
#define X_MIN   0
#define X_MAX   128
#define X_STEP  16

// define min and max of the lcd y-coordinates
#define Y_MIN   0
#define Y_MAX   64
#define Y_STEP  16




/*******************************************************************************
 * @brief   prints a space-invader at the given coordinates :)
 *
 * @param   x   the x-coordinate
 *
 * @param   y   the y-coordinate
 *
 * @return  none
*******************************************************************************/
void print_invader(uint8_t x, uint8_t y) {

    static uint8_t left_up[8]    = { 0x00, 0x00, 0xE0, 0xF0, 0xF9, 0xDA, 0xFC, 0xF8 };
    static uint8_t right_up[8]   = { 0xF8, 0xFC, 0xDA, 0xF9, 0xF0, 0xE0, 0x00, 0x00 };
    static uint8_t left_down[8]  = { 0x00, 0x00, 0x03, 0x00, 0x01, 0x03, 0x04, 0x00 };
    static uint8_t right_down[8] = { 0x00, 0x04, 0x03, 0x01, 0x00, 0x03, 0x00, 0x00 };

    ssd1306_draw_tile_xy(x      , y     , left_up);
    ssd1306_draw_tile_xy(x+8    , y     , right_up);
    ssd1306_draw_tile_xy(x      , y+8   , left_down);
    ssd1306_draw_tile_xy(x+8    , y+8   , right_down);

}


/*******************************************************************************
 * @brief   the main function
 *
 * @param   none
 *
 * @return  none
*******************************************************************************/
int main(void) {

    debug_init();
    ssd1306_init();

    uint8_t x = 0;
    uint8_t y = 0;

    while(1) {

        debug_set_pin(DEBUG_TOGGLE);    // let the debug pin toggle every loop iteration
        _delay_ms(500);                 // slow down the main-loop

        print_invader(x,y);             // print the invader

        if( x < (X_MAX-X_STEP) ) {      // maximum right-side not reached
            x += X_STEP;                // -> go one step to the right-side
        }
        else {

            if( y < (Y_MAX-Y_STEP) ) {  // maximum down-side not reached
                x = 0;                  // -> start at the left-side again
                y += Y_STEP;            // -> go one step downwards 
            }
            else {                      // maximum right- and down-side reached
                ssd1306_fill(0x00);     // -> clear the whole lcd
                x = 0;                  // -> start on the left-side again
                y = 0;                  // -> start on the top-side again
            }

        }

    } // end of main-loop


} // end of main()

