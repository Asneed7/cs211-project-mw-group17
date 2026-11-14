# 2048 Game

This is a C++ version of the 2048 game for our CS211 group project. The game uses a 5x5 board and the goal is to combine tiles until you reach 2048.

## How to Compile

From the main project folder, enter:

powershell
g++ -std=c++17 -Wall -Wextra -pedantic .\game2048\main.cpp .\game2048\2048_helper.cpp -o .\game2048\2048.exe

## How to Run

powershell
.\game2048\2048.exe

## Controls

- u - Move up
- d - Move down
- l - Move left
- r - Move right
- s - Save game
- o - Open saved game
- n - Start a new game
- h - Help
- e - Exit

## How to Play

The game starts with two randomly placed 2s. When two tiles with the same number meet, they merge together and the new tile value is added to the score. Each tile can only merge once per move.

Every time a move changes the board, a new 2 is added to a random empty spot and the move count increases by one. If the board does not change, nothing is added.

Once you reach 2048, you can keep playing. The game is over when there are no empty spots and no possible merges.

## Saving and Loading

Press s to save the game to savegame.txt in the working directory. Saving again replaces the previous saved game.

Press o to load the saved board, score, and move count. If the save file is missing or invalid, the current game stays unchanged.

## Testing

The tests and results for the game are recorded in tests.md in the main project folder.