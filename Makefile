
CC = gcc
CFLAGS = -I include -Wall -g
SRC = src/main.c src/ui.c src/game.c src/snake.c src/food.c
LDFLAGS = -lncurses
OBJ = $(SRC:.c=.o)
TARGET = snake

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)

run:
	./$(TARGET)

