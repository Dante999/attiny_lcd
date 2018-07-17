#ifndef _SSD1306_H
#define _SSD1306_H

#include <avr/io.h>

void ssd1306_init();
void ssd1306_fill(uint8_t symbol);
void ssd1306_draw_tile(uint8_t page, uint8_t column, uint8_t *tile);
void ssd1306_command(uint8_t cmd);
void ssd1306_data(uint8_t data);
void ssd1306_data_block(uint8_t *data, uint8_t size);

#endif