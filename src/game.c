#include "game.h"
#include "ui.h"
#include <stdbool.h>

void game_init(game_t *game) {
  ui_get_screen_size(&game->width, &game->height);

  game->score = 0;
  game->running = true;
};

bool game_is_over(const game_t *game) { return !game->running; }
