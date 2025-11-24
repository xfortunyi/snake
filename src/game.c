#include "game.h"
#include "snake.h"
#include "ui.h"
#include <stdbool.h>

void game_init(game_t *game) {
  ui_get_screen_size(&game->width, &game->height);

  snake_init(&game->snake, game->width / 2, game->height / 2);
  food_init(&game->food);

  game->score = 0;
  game->running = true;
};

void game_handle_input(game_t *game, int input) {

  switch (input) {

  case 'q':
  case 'Q':
    game->running = false;
    break;
  }
};

bool game_is_over(const game_t *game) { return !game->running; }
