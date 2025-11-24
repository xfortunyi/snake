#pragma once
#include "snake.h"
#include <stdbool.h>

typedef struct Game {
  snake_t snake;
  // FOOD
  int score;
  int width;
  int height;
  bool running;
} game_t;

void game_init(game_t *game);
bool game_is_over(const game_t *game);
