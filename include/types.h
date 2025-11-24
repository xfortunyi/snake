#pragma once

#define MAX_SNAKE_LENGTH 100

typedef struct Point {
  int x;
  int y;
} point_t;

typedef enum Direction { DIR_UP, DIR_DOWN, DIR_LEFT, DIR_RIGHT } direction_t;
