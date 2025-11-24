#pragma once

#include "types.h"

typedef struct Snake {
  point_t body[MAX_SNAKE_LENGTH];
  int length;
  direction_t dir;
} snake_t;

void snake_init(snake_t *snake, int start_x, int start_y);
