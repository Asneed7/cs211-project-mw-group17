# CS211 Group Project: 2048 and Luhn Validation

## Group Information

- Session: MW
- Group: 17
- Member A: [Alyssa Sneed] - Asneed7
- Member B: [Dominic Sneed] - DSneed7
- GitHub Repository: https://github.com/Asneed7/cs211-project-mw-group17

## Project Overview

This project consists of two C++ programs: a 2048 game and a Luhn checksum validation program. Both programs were developed and tested using C++17 in Visual Studio Code on Windows.

## Part A: 2048 Game

The 2048 game uses a 5x5 board. Players can move tiles left, right, up, and down. Equal tiles merge according to the game rules. The game keeps track of the score, successful moves, and highest tile.

### How to Compile

From the main project folder, enter the following command in PowerShell:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic .\game2048\main.cpp .\game2048\2048_helper.cpp -o .\game2048\2048.exe
```

### How to Run

```powershell
.\game2048\2048.exe
```

### Game Controls

- u - Move up
- d - Move down
- l - Move left
- r - Move right
- s - Save game
- o - Open saved game
- n - Start a new game
- h - Display help
- e - Exit game

### Saving and Loading

The game saves the board, score, and successful move count to savegame.txt in the current working directory. Saving again overwrites the previous saved game.

Loading restores the saved board, score, and move count. If the save file is missing or invalid, the current game is not changed.

A sample save file is included in the game2048 folder. To use it, copy it into the main project folder and rename it savegame.txt.

## Part B: Luhn Validation

The Luhn program checks whether a 16-digit number passes the Luhn checksum. The program checks that the input contains exactly 16 digits and allows users to enter multiple numbers without restarting.

### How to Compile

From the main project folder, enter:

powershell
g++ -std=c++17 -Wall -Wextra -pedantic .\luhn\main.cpp .\luhn\luhn.cpp -o .\luhn\luhn.exe


### How to Run

powershell
.\luhn\luhn.exe


Enter a 16-digit number to check whether it passes or fails the Luhn checksum. Enter q or Q to exit the program.

## Group Responsibilities

Member A was responsible for developing the 2048 game. Member B was responsible for developing the Luhn validation program. Both members reviewed and tested each other's programs.

Additional information about individual contributions and pull requests is included in contributions.md.

## Testing

Both programs were compiled and manually tested. Test cases and results are included in tests.md.

## Known Limitations

- The 2048 game is played using a text-based interface and a fixed 5x5 board.
- Only one saved game can be stored at a time.
- The Luhn program only accepts exactly 16 digits without spaces or letters.
- Passing the Luhn checksum does not guarantee that a card number is real or active.

## Project Status

Both programs have been completed, tested, reviewed, approved, and merged into the main branch.