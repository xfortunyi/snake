# 🐍 Snake Game

A terminal-based implementation of the classic **Snake** game written in C using **ncurses**.

---

## 🧩 What is Snake?

Snake is a classic arcade game where you control a growing snake that moves around the screen eating food.

Each time the snake eats, it grows longer — but be careful:

- ❌ Don’t crash into the walls  
- ❌ Don’t crash into yourself  
- ⭐ Try to survive as long as possible!

Your score increases as the snake grows.

---

## ✨ Features

- Smooth gameplay in the terminal  
- Colorful ncurses interface  
- Randomly generated food  
- Score display  
- Collision detection (walls & self-crossing)  
- Clean project structure  
- Easily configurable game speed  

---

## 🛠 Requirements

- GCC or any C compiler  
- ncurses library  
- Terminal with at least **20×10** characters  

### Install ncurses

```bash
# Ubuntu / Debian
sudo apt-get install libncurses5-dev libncursesw5-dev

# macOS
brew install ncurses

# Arch Linux
sudo pacman -S ncurses
```
---

## 🏗️ Building and Running

```bash
# Build
make

# Or compile manually
gcc -Wall -Wextra -std=c99 src/*.c -o snake -lncurses


# Run
./snake

# or
make run


# Clean
make clean
```

---

## 🕹️ Controls

- Arrow keys - move the snake
- Q / q - quit the game

---

## 👾 How to Play

1. Start the game - the snake begins centered on the screen
2. Use the arrow keys to move
3. Eat the food (*) to grow and increase your score
4. Survive as long as possible!

