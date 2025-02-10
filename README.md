# Tic Tac Toe - Console Game

##Prefix
Fully writen and construct fully by **LIEW WEN HAO**.


## Introduction
This project is a console-based Tic Tac Toe game written in C++. It supports two gameplay modes:
1. **Versus Mode** - Two players take turns playing on the same console.
2. **Computer Mode** - A player competes against a computer opponent.

The game interface is enhanced with ANSI escape codes for colored output and formatted text to improve user experience. Players can enter coordinates to place their marks ('X' or 'O') on a 3x3 grid, and the game determines the winner based on the standard Tic Tac Toe rules.

## Methodology

### 1. Type of Coding Skill Used
- **Object-Oriented Programming (OOP)**: The game is encapsulated within the `TicTacToe` class, demonstrating principles of encapsulation and modular design.
- **Regular Expressions (Regex)**: Used to validate user input and ensure only valid numbers (1-9) are accepted.
- **Multithreading & Time Handling**: Utilizes `<thread>` and `<chrono>` to add delays and improve UX (e.g., pausing before displaying win messages).
- **ANSI Escape Codes**: Applied for text formatting, cursor movement, and screen clearing for a dynamic UI.
- **Random Number Generation**: Implemented using `<cstdlib>` and `<ctime>` for computer move logic.

### 2. Libraries Used
#### Standard Libraries:
- **`<iostream>`** - Handles console input and output.
- **`<chrono>`** - Used for time delays.
- **`<thread>`** - Implements sleep delays to improve UX.
- **`<regex>`** - Validates user input.
- **`<cstdlib>` & `<ctime>`** - Used for random number generation (computer move logic).

#### ANSI Escape Code Usage:
- **Color Definitions**: Implements colors like `RED`, `GREEN`, `BLUE`, and text styles such as `BOLD` and `UNDERLINE`.
- **Cursor Control**: `MOVE_CURSOR`, `CLEAR_SCREEN`, `SAVE_CURSOR`, `RESTORE_CURSOR`, `HIDE_CURSOR`, and `SHOW_CURSOR`.

### 3. Game Mechanics
- **User Input Validation**: Ensures players enter valid numbers within the correct range.
- **Win Detection**: Checks for horizontal, vertical, and diagonal win conditions.
- **Draw Handling**: Detects when all board spaces are filled without a winner.
- **Computer AI**: Generates a random move until it finds an empty space.

## Functions and Their Purpose
| Function | Description |
|----------|-------------|
| `versusMode()` | Handles two-player mode gameplay. |
| `computerMode()` | Manages player vs. computer mode. |
| `printInterface()` | Displays the Tic Tac Toe board. |
| `enterTheOption(int position)` | Places user input on the board. |
| `ComputerEnterTheOption(int position)` | Places computer-generated moves. |
| `Emptyness(int r, int c)` | Checks if a position is empty. |
| `EmptyCheck()` | Detects if the board is full. |
| `WinCheck()` | Checks if a player has won. |
| `ComputerMove()` | Generates a random move for the computer. |

## Future Improvements
- **Better AI**: Implement a Minimax algorithm for smarter decision-making.
- **Graphical Interface**: Upgrade to a GUI-based version using a library like SDL or SFML.
- **Multiplayer Online Mode**: Allow players to compete over the internet.
- **Difficulty Levels**: Add easy, medium, and hard difficulty settings for AI.
- **Save and Load Feature**: Enable saving the game state for later continuation.
- **Custom Board Size**: Allow users to play on larger grids like 4x4 or 5x5.
- **Replay Feature**: Enable users to review the game history after a match.

## Conclusion
This Tic Tac Toe game demonstrates fundamental C++ programming concepts, including OOP, regex handling, and ANSI escape codes for an enhanced CLI experience. While functional, it can be expanded with more advanced AI and multiplayer capabilities in the future.

