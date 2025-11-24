#include "snake.h"
#include "types.h"

void snake_init(snake_t *snake, int start_x, int start_y) {
  snake->length = 3;
  snake->dir = DIR_RIGHT;

  for (int i = 0; i < snake->length; i++) {
    snake->body[i].x = start_x - i;
    snake->body[i].y = start_y;
  }
};
