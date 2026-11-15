#ifndef GAME2048_HELPER_H
#define GAME2048_HELPER_H

void move_left(int board[][5], int numrows, int &score);

void move_right(int board[][5], int numrows, int &score);

void move_up(int board[][5], int numrows, int &score);

void move_down(int board[][5], int numrows, int &score);

void print_board(int board[][5], int numrows = 5);

void insert_random(int board[][5], int numrows = 5);

bool is_game_over(int board[][5], int numrows);

#endif