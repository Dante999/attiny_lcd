#include <avr/io.h>
#include <util/delay.h>
#include "debug.h"
#include "ssd1306.h"

#ifndef F_CPU
#define F_CPU   16500000UL
#endif



int main(void) {

    uint8_t invader_1[8]    = { 0x00, 0x3E, 0x74, 0x3E, 0x3E, 0x74, 0x3E, 0x00 };

    debug_init();
    ssd1306_init();
#if 0
    ssd1306_draw_tile(0, 0, invader_1);
    ssd1306_draw_tile(0, 8, invader_1);
    ssd1306_draw_tile(0, 16, invader_1);
    ssd1306_draw_tile(0, 24, invader_1);
#endif


    ssd1306_draw_tile_xy(0,  0, invader_1);
    ssd1306_draw_tile_xy(10, 1, invader_1);
    ssd1306_draw_tile_xy(20, 2, invader_1);
    ssd1306_draw_tile_xy(30, 3, invader_1);
    ssd1306_draw_tile_xy(40, 4, invader_1);
    ssd1306_draw_tile_xy(50, 5, invader_1);
    ssd1306_draw_tile_xy(60, 6, invader_1);
    ssd1306_draw_tile_xy(70, 7, invader_1);
    ssd1306_draw_tile_xy(80, 8, invader_1);

    while(1) {

        _delay_ms(500);
        debug_set_pin(DEBUG_HIGH);

        _delay_ms(500);
        debug_set_pin(DEBUG_LOW);


    }











}

