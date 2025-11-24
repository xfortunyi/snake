#pragma once
#include "food.h"
#include "snake.h"
#include <stdbool.h>

typedef struct Game {
  snake_t snake;
  food_t food;
  int score;
  int width;
  int height;
  bool running;
} game_t;

void game_init(game_t *game);
void game_handle_input(game_t *game, int input);
void game_update(game_t *game);
bool game_is_over(const game_t *game);
