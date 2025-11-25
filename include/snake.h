#pragma once

#include "types.h"
#include <stdbool.h>

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
bool snake_check_wall_collision(const snake_t *snake, int max_x, int max_y);
bool snake_check_self_collision(const snake_t *snake);
