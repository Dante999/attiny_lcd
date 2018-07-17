#include <avr/io.h>
#include <util/delay.h>
#include "debug.h"
#include "ssd1306.h"

#ifndef F_CPU
#define F_CPU   16500000UL
#endif



int main(void) {

    uint8_t invader_1[8]    = { 0x00, 0x3E, 0x74, 0x3E, 0x3E, 0x74, 0x3E, 0x00 };
    uint8_t empty_block[8]  = { 0x00 };

    debug_init();
    ssd1306_init();
#if 0
    ssd1306_draw_tile(0, 0, invader_1);
    ssd1306_draw_tile(0, 8, invader_1);
    ssd1306_draw_tile(0, 16, invader_1);
    ssd1306_draw_tile(0, 24, invader_1);
#endif

    uint8_t x = 0;
    uint8_t y = 0;
    

    while(1) {

        debug_set_pin(DEBUG_TOGGLE);
        _delay_ms(500);

        ssd1306_draw_tile_xy(x, y, empty_block);

        if( x < 128-8 ) {
            x += 8;
        }
        else if( y < 64-8 ) {
            x =0;
            y += 8;
        }
        else {
            x = 0;
            y = 0;
        }

        ssd1306_draw_tile_xy(x, y, invader_1);

    }











}

