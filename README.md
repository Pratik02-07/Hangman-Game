# Hangman Game

A classic Hangman game implemented in C++. Test your vocabulary and guessing skills with this interactive console-based game.

![Hangman Game Screenshot](hangman_screenshot.png)

## Features

- Interactive console-based gameplay
- Random word selection
- Visual hangman drawing
- Score tracking
- User-friendly interface

## Requirements

- C++ compiler (GCC, Clang, or MSVC)
- Windows operating system (for .exe file)

## How to Play

1. Run the `Hangman.exe` file
2. Guess letters one at a time
3. Try to guess the word before the hangman is fully drawn
4. You have 6 incorrect guesses before the game ends

## Building from Source

1. Clone the repository:
```bash
git clone https://github.com/Pratik02-07/Hangman-Game.git
```

2. Compile the source code:
```bash
g++ Hangman.cpp -o Hangman
```

## Game Rules

- Each incorrect guess adds a part to the hangman drawing
- You can only guess one letter at a time
- The game ends when either:
  - You guess all letters correctly
  - The hangman is fully drawn (6 incorrect guesses)

## Contributing

Feel free to submit issues and enhancement requests!

## License

This project is open source and available under the MIT License. 