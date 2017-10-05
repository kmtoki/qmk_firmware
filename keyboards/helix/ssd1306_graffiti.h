#ifndef SSD1306_GRAFFITI_H
#define SSD1306_GRAFFITI_H

#include <stdbool.h>
#include <stdio.h>

bool ssd1306_init(void);
void ssd1306_clear(void);
bool ssd1306_on(void);
bool ssd1306_off(void);
void ssd1306_graffiti(void);

#endif
