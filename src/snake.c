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

void snake_move(snake_t *snake) {
  for (int i = snake->length - 1; i > 0; i--) {
    snake->body[i] = snake->body[i - 1];
  }

  switch (snake->dir) {
  case DIR_UP:
    snake->body[0].y--;
    break;
  case DIR_DOWN:
    snake->body[0].y++;
    break;
  case DIR_LEFT:
    snake->body[0].x--;
    break;
  case DIR_RIGHT:
    snake->body[0].x++;
    break;
  }
}

void snake_grow(snake_t *snake) {
  if (snake->length < MAX_SNAKE_LENGTH) {
    snake->length++;
  }
}

void snake_change_direction(snake_t *snake, direction_t new_dir) {

  if ((snake->dir == DIR_UP && new_dir == DIR_DOWN) ||
      (snake->dir == DIR_RIGHT && new_dir == DIR_LEFT) ||
      (snake->dir == DIR_LEFT && new_dir == DIR_RIGHT) ||
      (snake->dir == DIR_DOWN && new_dir == DIR_UP)) {
    return;
  }

  snake->dir = new_dir;
};

point_t snake_get_head(const snake_t *snake) { return snake->body[0]; }
