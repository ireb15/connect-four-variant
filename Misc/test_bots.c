#define _CRT_SECURE_NO_WARNINGS

#include "connect4.h"

int main( void )
{
	
	
	//Horizontal
	
	//int competition_board[MAX_SIZE][MAX_SIZE] = {{1, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 3, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};
	//int competition_board[MAX_SIZE][MAX_SIZE] = {{1, 1, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 3, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};
	//int competition_board[MAX_SIZE][MAX_SIZE] = {{1, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 3, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};
	//int competition_board[MAX_SIZE][MAX_SIZE] = {{0, 1, 1, 1, 2, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 3, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};
	
	//Vertical
	
	//int competition_board[MAX_SIZE][MAX_SIZE] = {{1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 3, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};
	//int competition_board[MAX_SIZE][MAX_SIZE] = {{1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 3, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};
	//int competition_board[MAX_SIZE][MAX_SIZE] = {{1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 3, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};
	//int competition_board[MAX_SIZE][MAX_SIZE] = {{0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 3, 0, 0, 0}, {2, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};
	
	//Left-Diagonal
	
	//int competition_board[MAX_SIZE][MAX_SIZE] = {{0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 3, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};
	//int competition_board[MAX_SIZE][MAX_SIZE] = {{0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 3, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};
	//int competition_board[MAX_SIZE][MAX_SIZE] = {{0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 2, 1, 0, 0, 0}, {0, 0, 0, 3, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};
	//int competition_board[MAX_SIZE][MAX_SIZE] = {{0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 3, 1, 0, 0}, {0, 0, 0, 0, 0, 2, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};
	
	//Right-diagonal
	
	//int competition_board[MAX_SIZE][MAX_SIZE] = {{0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 3, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};
	//int competition_board[MAX_SIZE][MAX_SIZE] = {{0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 2, 0, 0}, {0, 0, 1, 3, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};
	//int competition_board[MAX_SIZE][MAX_SIZE] = {{0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 2, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {0, 0, 1, 3, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};
	//int competition_board[MAX_SIZE][MAX_SIZE] = {{0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 0, 0, 0}, {0, 0, 1, 3, 0, 0, 0}, {0, 2, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};

	int size = 7;
	int player = 1;
	int lastRow, lastCol;
	char side_chosen;
	int position_chosen;
	char stringy[250];

	GetDisplayBoardString(competition_board,size,stringy);
	printf("\n%s\n",stringy);
	printf("-------------------------------\n\n");
	
	GetMoveBot1(competition_board, size, player, &side_chosen, &position_chosen);
	AddMoveToBoard(competition_board, size, side_chosen, position_chosen, player, &lastRow, &lastCol);
	printf("GetMoveBot1 called: (%c) (%d)\n\n", side_chosen, position_chosen);
	
	GetDisplayBoardString(competition_board,size,stringy);
	printf("%s\n\n",stringy);
	
	return 0;
}