#pragma once

#include <stdbool.h>

typedef struct Game {
  // SNAKE
  // FOOD
  int score;
  int width;
  int height;
  bool running;
} game_t;

void game_init(game_t *game);
bool game_is_over(const game_t *game);
