#  C++ Console Games Collection

A collection of **classic and fun console-based games written in C++**.  
This repository is meant to practice **C++ fundamentals, OOP, and game logic**, while recreating simple retro-style games that run directly in the terminal.

Each game is lightweight, written from scratch, and uses **basic C++ (with minimal external libraries)**. Great for beginners who want to learn by building!

##  Repository Structure

`cpp-games-collection/

│── SnakeGame/        # Snake game source code 

│── TicTacToe/        # Tic-Tac-Toe game 

│── Pong/             # (planned) Pong game 

│── README.md         # Project documentation`


##  Games Included

### 1. Snake Game 🐍

- Classic snake game in the console.
- Controls: **W (Up), S (Down), A (Left), D (Right), X (Exit)**.
- Eat food `$` to grow and earn points.
- Game ends when you hit the wall or your own tail.

 Implemented Features:

- Snake head + growing tail
- Random food placement
- Collision detection
- Score tracking
- Game Over screen

---

### 2. Tic Tac Toe with AI 

- Play Tic Tac Toe against an AI opponent using the Minimax algorithm.
- Board: 3x3 grid.
- Player: X | AI: O.
- The AI always tries to make the optimal move.

 Implemented Features:

- 3x3 Tic Tac Toe board
- Human vs AI gameplay
- Minimax algorithm for unbeatable AI
- Input validation (avoids invalid or already occupied moves)
- Winner detection (Player / AI / Draw)
- Game Over screen

---

##  Getting Started

### 1. Clone the Repository

`git clone https://github.com/your-username/cpp-games-collection.git cd cpp-games-collection`

### 2. Compile a Game (Example: Snake)

`cd SnakeGame g++ snake.cpp -o snake`

### 3. Run

`./snake`

---

##  Requirements

- C++ Compiler (GCC, MinGW, MSVC)
- Windows (uses `<conio.h>` & `<windows.h>`)

---

##  Future Games Planned
 
- Pong
- Minesweeper
- Hangman
