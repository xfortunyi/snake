#pragma once

#include "types.h"

typedef struct Snake {
  point_t body[MAX_SNAKE_LENGTH];
  int length;
  direction_t dir;
} snake_t;

void snake_init(snake_t *snake, int start_x, int start_y);
void snake_move(snake_t *snake);
void snake_grow(snake_t *snake);
void snake_change_direction(snake_t *snake, direction_t new_dir);
point_t snake_get_head(const snake_t *snake);
