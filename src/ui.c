#include "ui.h"
#include <ncurses.h>

#define MIN_WIDTH 20
#define MIN_HEIGHT 10

bool ui_init(void) {
  initscr();

  if (LINES < MIN_HEIGHT || COLS < MIN_WIDTH) {
    endwin();
    return false;
  }

  cbreak();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);

  if (has_colors()) {
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
  }

  return true;
};

void ui_get_screen_size(int *width, int *height) {
  *width = COLS;
  *height = LINES;
};

void ui_draw_border(int width, int height) {
  for (int i = 0; i < width; i++) {
    mvaddch(0, i, '#');
    mvaddch(height - 1, i, '#');
  }

  for (int i = 0; i < height; i++) {
    mvaddch(i, 0, '#');
    mvaddch(i, width - 1, '#');
  }
};
