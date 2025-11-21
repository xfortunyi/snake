#pragma once
#include <stdbool.h>

bool ui_init(void);
void ui_get_screen_size(int *width, int *height);
void ui_draw_border(int width, int height);
