#include "game.h"
#include "food.h"
#include "snake.h"
#include "types.h"
#include "ui.h"
#include <ncurses.h>
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
  case KEY_UP:
    snake_change_direction(&game->snake, DIR_UP);
    break;
  case KEY_DOWN:
    snake_change_direction(&game->snake, DIR_DOWN);
    break;
  case KEY_LEFT:
    snake_change_direction(&game->snake, DIR_LEFT);
    break;
  case KEY_RIGHT:
    snake_change_direction(&game->snake, DIR_RIGHT);
    break;
  case 'q':
  case 'Q':
    game->running = false;
    break;
  }
};

void game_update(game_t *game) {
  snake_move(&game->snake);

  point_t head = snake_get_head(&game->snake);

  // Check if eats
  if (food_is_eaten(&game->food, head)) {
    snake_grow(&game->snake);
    game->score += 10;
    food_deactivate(&game->food);
  }

  if (!game->food.active) {
    food_spawn(&game->food, &game->snake, game->width, game->height);
  }
};

bool game_is_over(const game_t *game) { return !game->running; }
