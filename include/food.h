#pragma once

#include "snake.h"
#include "types.h"
#include <stdbool.h>

typedef struct Food {
  point_t pos;
  bool active;
} food_t;

void food_init(food_t *food);
void food_spawn(food_t *food, const snake_t *snake, int max_x, int max_y);
bool food_is_eaten(const food_t *food, point_t head);
void food_deactivate(food_t *food);
