#pragma once
#include "food.h"
#include "snake.h"
#include <stdbool.h>

bool ui_init(void);
void ui_get_screen_size(int *width, int *height);
void ui_draw_border(int width, int height);
void ui_draw_score(int score);
void ui_draw_snake(const snake_t *snake);
void ui_draw_food(const food_t *food);
void ui_draw_game_over(int score);
