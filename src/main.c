#include "game.h"
#include "types.h"
#include "ui.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
  srand(time(NULL));

  if (!ui_init()) {
    printf("Error: Terminal too small \n");
    printf("Minimum size required: 20x10\n");
    return 1;
  }

  game_t game;
  game_init(&game);

  while (!game_is_over(&game)) {
    clear();

    int width, height;
    ui_get_screen_size(&width, &height);

    ui_draw_border(width, height);
    ui_draw_score(game.score);
    ui_draw_food(&game.food);
    ui_draw_snake(&game.snake);

    refresh();

    int input = getch();
    game_handle_input(&game, input);
    game_update(&game);

    usleep(GAME_SPEED);
  }

  clear();
  ui_draw_game_over(game.score);
  refresh();
  getch();

  endwin();

  return 0;
}
