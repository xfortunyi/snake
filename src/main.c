#include "game.h"
#include "ui.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    refresh();
  }

  return 0;
}
