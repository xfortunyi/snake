🐍 Snake Game

A terminal-based implementation of the classic Snake game written in C using ncurses.

What is Snake?

Snake is a classic arcade game where you control a growing snake that moves around the screen eating food.
Each time the snake eats, it grows longer — but be careful:

Don’t crash into the walls

Don’t crash into yourself

And try to survive as long as possible!

Your score increases as the snake grows.

✨ Features

Smooth gameplay in the terminal

Colorful ncurses interface

Randomly generated food

Score display

Collision detection (walls & self-crossing)

Clean project structure

Easily configurable game speed

🛠 Requirements

GCC or any C compiler

ncurses library

A terminal that supports at least 20×10 characters

Install ncurses
# Ubuntu/Debian
sudo apt-get install libncurses5-dev libncursesw5-dev

# macOS
brew install ncurses

# Arch Linux
sudo pacman -S ncurses

▶️ Building & Running
Build
make

Run
./snake


Or directly using gcc:

gcc -Wall -Wextra -std=c99 src/*.c -o snake -lncurses

Clean
make clean

🎮 Controls

Arrow keys — move the snake

Q — quit the game

🕹 How to Play

Start the game — the snake appears in the center of the screen.

Use the arrow keys to move.

Eat the food (*) to grow and increase your score.

Avoid hitting the walls or your own body.

Survive as long as you can!

📁 Project Structure
snake/
├── src/
│   ├── main.c        # Program entry point
│   ├── game.c/h      # Game loop and high-level logic
│   ├── snake.c/h     # Snake movement and behavior
│   ├── food.c/h      # Food spawning and logic
│   ├── ui.c/h        # ncurses-based rendering
│   └── types.h       # Common type definitions
├── Makefile
└── README.md


Modules:

game — main loop, input handling, collision detection

snake — body structure, movement, growth

food — random spawning, collision checks

ui — rendering the game with ncurses

🏆 Tips

Try to plan ahead — the snake gets longer fast!

Corners are risky if you turn too late

The game speed can be adjusted in the source for more challenge
