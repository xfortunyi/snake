#include "ui.h"
#include "food.h"
#include "snake.h"
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

void ui_draw_score(int score) { mvprintw(0, 2, " Score: %d ", score); };

void ui_draw_snake(const snake_t *snake) {
  attron(COLOR_PAIR(1));
  mvaddch(snake->body[0].y, snake->body[0].x, '0');
  attroff(COLOR_PAIR(1));

  attron(COLOR_PAIR(2));
  for (int i = 1; i < snake->length; i++) {
    mvaddch(snake->body[i].y, snake->body[i].x, 'o');
  }
  attroff(COLOR_PAIR(2));
};

void ui_draw_food(const food_t *food) {
  if (food->active) {
    attron(COLOR_PAIR(3));
    mvaddch(food->pos.y, food->pos.x, '*');
    attroff(COLOR_PAIR(3));
  }
};

void ui_draw_game_over(int score) {
  int height, width;
  ui_get_screen_size(&width, &height);

  mvprintw(height / 2 - 1, width / 2 - 10, "GAME OVER");
  mvprintw(height / 2, width / 2 - 10, "Score: %d", score);
  mvprintw(height / 2 + 1, width / 2 - 15, "Press any key to exit");

  nodelay(stdscr, FALSE);
};
