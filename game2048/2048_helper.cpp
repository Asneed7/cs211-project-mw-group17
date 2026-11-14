#include "2048_helper.h"
#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

void move_left(int board[][5], int numrows, int &score)
{
	//CODE HERE
	for (int r = 0; r < numrows; r++)
{
	int position =0;
	for (int c = 0; c < 5; c++)
	{
		if (board[r][c] != 0)
		{
			board[r][position] = board[r][c];
			position++;
		}
}
for (int c = position; c < 5; c++)
{
	board[r][c] = 0;
}
for (int c = 0; c < 4; c++)
{

	if (board[r][c] != 0 && board[r][c] == board[r][c + 1])
{
board[r][c] *= 2;
score += board[r][c];
board[r][c + 1] = 0;
c++;
      }
}
position = 0;

for (int c = 0; c < 5; c++)
{
	if (board[r][c] != 0)
	{
		board[r][position] = board[r][c];
		position++;
	}
}

for (int c = position; c < 5; c++)
{
board[r][c] = 0;
}
}
}

void move_right(int board[][5], int numrows, int &score)
{
	//CODE HERE
	for (int r = 0; r < numrows; r++)
{
    int position = 4;

    for (int c = 4; c >= 0; c--)
    {
        if (board[r][c] != 0)
        {
            board[r][position] = board[r][c];
            position--;
        }
    }

    for (int c = position; c >= 0; c--)
    {
        board[r][c] = 0;
    }
	for (int c = 4; c >0; c--)
	{
		if (board[r][c] != 0 && board[r][c] == board[r][c - 1])
		{
			board[r][c] *= 2;
            score += board[r][c];
			board[r][c - 1] = 0;
			c--;
	}
}

position = 4;

for (int c = 4; c >= 0; c--)
{
    if (board[r][c] != 0)
    {
        board[r][position] = board[r][c];
        position--;
    }
}

for (int c = position; c >= 0; c--)
{
    board[r][c] = 0;
}

}

} 


void move_up(int board[][5], int numrows, int &score)
{
   
	for (int c = 0; c < 5; c++)
    {
        int position = 0;


        for (int r = 0; r < numrows; r++)
        {
            if (board[r][c] != 0)
            {
                board[position][c] = board[r][c];
                position++;
            }
        }

    
        for (int r = position; r < numrows; r++)
        {
            board[r][c] = 0;
        }

        
        for (int r = 0; r < numrows - 1; r++)
        {
            if (board[r][c] != 0 &&
                board[r][c] == board[r + 1][c])
            {
                board[r][c] *= 2;
                score += board[r][c];
                board[r + 1][c] = 0;
                r++;
            }
        }

        
        position = 0;

        for (int r = 0; r < numrows; r++)
        {
            if (board[r][c] != 0)
            {
                board[position][c] = board[r][c];
                position++;
            }
        }


        for (int r = position; r < numrows; r++)
        {
            board[r][c] = 0;
        }
    }
}


void move_down(int board[][5], int numrows, int &score)
{
	//CODE HERE

    
    for (int c = 0; c < 5; c++)
    {
        int position = numrows - 1;

        
        for (int r = numrows - 1; r >= 0; r--)
        {
            if (board[r][c] != 0)
            {
                board[position][c] = board[r][c];
                position--;
            }
        }

        
        for (int r = position; r >= 0; r--)
        {
            board[r][c] = 0;
        }

        
        for (int r = numrows - 1; r > 0; r--)
        {
            if (board[r][c] != 0 &&
                board[r][c] == board[r - 1][c])
            {
                board[r][c] *= 2;
                score += board[r][c];
                board[r - 1][c] = 0;
                r--;
            }
        }

        
        position = numrows - 1;

        for (int r = numrows - 1; r >= 0; r--)
        {
            if (board[r][c] != 0)
            {
                board[position][c] = board[r][c];
                position--;
            }
        }

        
        for (int r = position; r >= 0; r--)
        {
            board[r][c] = 0;
        }
    }
}


void print_board(int board[][5], int numrows)
{
	cout << endl << "\t-----------------------------------------" << endl;

	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if(board[r][c] > 0)
				cout << "\t|" << right << setw(6) << setfill(' ') << board[r][c];
			else
				cout << "\t|" << right << setw(6) << setfill(' ') << " ";

			//cout << board[r][c] << "\t|\t";
		}
		cout << "\t|" << endl;
		cout << "\t-----------------------------------------" << endl;
	}

	cout << "\t" << endl << endl;
}


void insert_random(int board[][5], int numrows)
{
	int r, c;
	//count empty
	int empty_count = 0;
	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if (board[r][c] == 0)
				empty_count++;
		}
	}

	if (empty_count > 0)
	{
		while (true)
		{
			//generate random location r, c
			r = rand() % numrows;
			c = rand() % numrows;
			//check if empty
			if (board[r][c] == 0)
			{
			// Insert a 2 into a random empty cell
				board[r][c] = 2;
				break;
			}
		}

	}
}

bool is_game_over(int board[][5], int numrows)
{
    for (int r = 0; r < numrows; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (board[r][c] == 0)
                return false;

            if (c < 4 && board[r][c] == board[r][c + 1])
                return false;

            if (r < numrows - 1 && board[r][c] == board[r + 1][c])
                return false;
        }
    }

    return true;
}