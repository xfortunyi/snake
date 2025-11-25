#include "food.h"
#include "snake.h"
#include "types.h"
#include <stdlib.h>

void food_init(food_t *food) { food->active = false; };

void food_spawn(food_t *food, const snake_t *snake, int max_x, int max_y) {
  bool valid;

  do {
    valid = true;
    food->pos.x = rand() % (max_x - 2) + 1;
    food->pos.y = rand() % (max_y - 2) + 1;

    // Not where snake is placed
    for (int i = 0; i < snake->length; i++) {
      if (snake->body[i].x == food->pos.x && snake->body[i].y == food->pos.y) {
        valid = false;
        break;
      }
    }
  } while (!valid);

  food->active = true;
};

bool food_is_eaten(const food_t *food, point_t head) {
  return food->active && food->pos.x == head.x && food->pos.y == head.y;
};

void food_deactivate(food_t *food) { food->active = false; };
