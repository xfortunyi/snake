#pragma once

#include "types.h"
#include <stdbool.h>

typedef struct Food {
  point_t pos;
  bool active;
} food_t;

void food_init(food_t *food);
