#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "2048_helper.h"
using namespace std;

int main()
{
    srand(time(0));
	int size = 5;
	int board[5][5] = {0};

	insert_random(board, size);
insert_random(board, size);
	//while getch == x loop for up down left right

	cout << "Initial Board : [5x5] :" << endl;
	print_board(board);

	cout << "Successful Moves: 0" << endl;
cout << "Score: 0" << endl;
cout << "Highest Tile: 2" << endl;

	char choice = 'u';	//initialized

int move_count = 0; //counts succesful moves 
int score = 0;
bool has_won = false;

	while (choice != 'e')
	{

		cout << "Commands: u/d/l/r (Move), s (Save), o (Load), n (New Game), h (Help), e (Exit)" << endl;
		cout << "Choice: ";
		string command;

if (!(cin >> command))
{
    break;
}

if (command.length() != 1)
{
    cout << "Invalid command. Please try again." << endl;
    continue;
}

choice = command[0];

if (choice == 'e')
{
    break;
}
int old_board[5][5];

for (int r = 0; r < 5; r++)
{
    for (int c = 0; c < 5; c++)
    {
        old_board[r][c] = board[r][c];
    }
}
		if (is_game_over(board, size) &&
    (choice == 'u' || choice == 'd' ||
     choice == 'l' || choice == 'r'))
{
    cout << "No moves remaining." << endl;
}
else if (choice == 'u')
			move_up(board, size, score);
		else if (choice == 'd')
			move_down(board, size, score);
		else if (choice == 'l')
			move_left(board, size, score);
		else if (choice == 'r')
			move_right(board, size, score);

			else if (choice == 'n')
{
    string confirm;

    cout << "Start a new game? (y/n): ";
    if (!(cin >> confirm))
{
    break;
}

    if (confirm == "y")
    {
        for (int r = 0; r < 5; r++)
        {
            for (int c = 0; c < 5; c++)
            {
                board[r][c] = 0;
            }
        }

        score = 0;
        move_count = 0;
has_won = false;

        insert_random(board, size);
        insert_random(board, size);
    }
}
else if (choice == 'h')
{
    cout << "\n===== 2048 HELP =====" << endl;
    cout << "u - Move UP" << endl;
    cout << "d - Move DOWN" << endl;
    cout << "l - Move LEFT" << endl;
    cout << "r - Move RIGHT" << endl;
    cout << "n - New Game" << endl;
    cout << "s - Save Game" << endl;
    cout << "The game saves to savegame.txt in the working directory." << endl;
cout << "Saving again replaces the previous saved game." << endl;
    cout << "o - Open Game" << endl;
    cout << "h - Help" << endl;
    cout << "e - Exit" << endl;
    cout << "Goal: Reach 2048!" << endl;
}
else if (choice == 's')
{
    ofstream saveFile("savegame.txt");

    if (!saveFile)
    {
        cout << "Error: Could not save game." << endl;
    }
    else
    {
        saveFile << "CS211_2048_V1" << endl;
        saveFile << score << " " << move_count << endl;

        for (int r = 0; r < 5; r++)
        {
            for (int c = 0; c < 5; c++)
            {
                saveFile << board[r][c] << " ";
            }
            saveFile << endl;
        }

        saveFile.close();

if (saveFile.fail())
{
    cout << "Error: Could not save game." << endl;
}
else
{
    cout << "Game saved to savegame.txt!" << endl;
}
    }
}
else if (choice == 'o')
{
    ifstream loadFile("savegame.txt");

    if (!loadFile)
    {
        cout << "Error: Could not open savegame.txt." << endl;
    }
    else
    {
        string version;
        loadFile >> version;

        if (version != "CS211_2048_V1")
        {
            cout << "Error: Invalid save file version." << endl;
        }
   else
{
    int saved_score;
    int saved_moves;

    if (!(loadFile >> saved_score >> saved_moves) ||
        saved_score < 0 || saved_moves < 0)
    {
        cout << "Error: Invalid saved score or move count." << endl;
    }
   
    else
{
    int saved_board[5][5] = {0};
    bool valid = true;

    for (int r = 0; r < 5; r++)
{
    for (int c = 0; c < 5; c++)
    {
        int tile;

        if (!(loadFile >> tile))
        {
            valid = false;
            break;
        }

        if (tile < 0 || (tile != 0 && (tile < 2 || (tile & (tile - 1)) != 0)))
        {
            valid = false;
            break;
        }

        saved_board[r][c] = tile;
    }

    if (!valid)
    {
        break;
    }
}

loadFile >> ws;

if (loadFile.peek() != EOF)
{
    valid = false;
}

if (valid)
{
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            board[r][c] = saved_board[r][c];
        }
    }

    score = saved_score;
    move_count = saved_moves;
    has_won = false;

    cout << "Game loaded successfully!" << endl;
}
else
{
    cout << "Error: Invalid save file. Game unchanged." << endl;
}
}
}
    }
}

else if (choice != 'e' && choice != 's' && choice != 'o')
{
    cout << "Invalid command. Please try again." << endl;
}

bool changed = false;

for (int r = 0; r < 5; r++)
{
    for (int c = 0; c < 5; c++)
    {
        if (board[r][c] != old_board[r][c])
        {
            changed = true;
        }
    }
}


		if (changed && (choice == 'u' || choice == 'd' ||
                choice == 'l' || choice == 'r'))
{
   move_count++;
	insert_random(board, size);
}
int highest_tile = 0;

for (int r = 0; r < 5; r++)
{
    for (int c = 0; c < 5; c++)
    {
        if (board[r][c] > highest_tile)
        {
            highest_tile = board[r][c];
        }
    }
}

print_board(board);
cout << "Successful Moves: " << move_count << endl;
cout << "Score: " << score << endl;
cout << "Highest Tile: " << highest_tile << endl;

if (highest_tile >= 2048 && has_won == false)
{
    cout << "Congratulations! You reached 2048!" << endl;
    cout << "You can continue playing!" << endl;

    has_won = true;
}
if (is_game_over(board, size))
{
    cout << "Game Over! No moves remaining." << endl;
    cout << "You can save, load, start a new game, or exit." << endl;
}

	}


	return 0;
}