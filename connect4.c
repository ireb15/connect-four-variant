/* ENGGEN131 Project - C Project - 2018 */
/* Connect Four */

#include "connect4.h"

/* Isaac Rebello	|	310052676	| 	ireb692
This is the file that you will be submitting for marking
Complete the definitions of the functions in this file
DO NOT REMOVE ANY FUNCTION DEFINITIONS - they all must be present when you submit this file
*/

/*************************************************/
/*************** Helper functions ****************/
/*************************************************/

void Sort(double *values, int length)
{
	// This function takes one value in an array and another value to the right of it and swaps them.
    int i, j;
	double temp;
    for (i = 0; i < length; i++) {
        for (j = 0; j < length - 1; j++) {
            if (values[j] > values[j + 1]) {
                temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
}

/***********************************************/

int TopLeftToBottomRight(int board[MAX_SIZE][MAX_SIZE], int size, int row, int col)
{
    int i = row, j = col, n = 0;
	int seqArray[MAX_SIZE] = {0};
	int playerWins;
	// Find the starting position of the diagonal sequence which the last placed token is a part of.
	while (i >= 0 || j >= 0) {
		i--;
		j--;
	}
	// Copy the diagonal sequence which the last placed token is a part of into seqArray.
	while (i < size || j < size) {
		seqArray[n] = board[i][j];
		i++;
		j++;
		n++;
	}
	// Call the FourInARow function using seqArray.
	playerWins = FourInARow(seqArray, n);
	if (playerWins != -1) {
		return 1;
	} else {
		return 0;
	}
}

/***********************************************/

int BottomLeftToTopRight(int board[MAX_SIZE][MAX_SIZE], int size, int row, int col)
{
    int i = row, j = col, n = 0;
	int seqArray[MAX_SIZE] = {0};
	int playerWins;
	// Find the starting position of the diagonal sequence which the last placed token is a part of.
	while (i < size || j >= 0) {
		i++;
		j--;
	}
	// Copy the diagonal sequence which the last placed token is a part of into seqArray.
	while (i >= 0 || j < size) {
		seqArray[n] = board[i][j];
		i--;
		j++;
		n++;
	}
	// Call the FourInARow function using seqArray.
	playerWins = FourInARow(seqArray, n);
	if (playerWins != -1) {
		return 1;
	} else {
		return 0;
	}
}


/*************************************************/
/**************** Main functions *****************/
/*************************************************/

int SecondPlacePrize(int prize1, int prize2, int prize3)
{
	// Check if prize 1 is the middle value.
	if ((prize1 > prize2 && prize1 < prize3) || (prize1 > prize3 && prize1 < prize2)) {
		return prize1;
	} else if ((prize1 == prize2 && prize1 < prize3) || (prize1 == prize3 && prize1 < prize2)) {
		return prize1;
	} else if ((prize1 == prize2 && prize1 > prize3) || (prize1 == prize3 && prize1 > prize2)) {
		return prize1;
	}
	
	//Check if prize 2 is the middle value.
	if ((prize2 > prize1 && prize2 < prize3) || (prize2 > prize3 && prize2 < prize1)) {
		return prize2;
	} else if ((prize2 == prize3 && prize2 < prize1) || (prize2 == prize3 && prize2 > prize1)) {
		return prize2;
	}

	// Check if prize 3 is the middle value.
	if ((prize3 > prize1 && prize3 < prize2) || (prize3 > prize2 && prize3 < prize1)) {
		return prize3;
	}

	return 0;
}

/***********************************************/

int FourInARow(int values[], int length)
{
	int i;

	for (i = 0; i < length; i++) {
		// Check if the current value and the next three values are within the range of 0 and length (inclusive of 0).
		if (i >= length || (i + 1) >= length || (i + 2) >= length || (i + 3) >= length) {
			return -1;
		} // Check if the current value in the array is the first of a "four in a row".
		else if ((values[i] == values[i + 1] && values[i] == values[i + 2] && values[i] == values[i + 3])) {
			return i;
		}
	}

	return -1;
}

/***********************************************/

int BinaryToDecimal(int binary)
{
	// This function is based on the code from the following link:
	// https://www.sanfoundry.com/c-program-binary-number-into-decimal/
	int decimal = 0, base = 1, remainder;
	
	// Each digit of the binary number is multiplied with it's power of 2, and all of the multiplied digits are then added together. The final sum is the
	// decimal representation of the binary number that was given as input.
	for (base = 1; binary > 0; base = base * 2) {
        remainder = binary % 10;
        decimal = decimal + (remainder * base);
        binary = binary / 10;
    }

	return decimal;
}

/***********************************************/

double MedianAbility(double abilities[], int length)
{
	// Sort the abilities array into increasing order using the Sort function (defined at the top of this source file).
	Sort(abilities, length);

    double median = 0.0;
	// Check if there is an even or odd amount of values in abilities[].
	if (length % 2 == 0) {
		// If there is an even amount of values in abilities[], then the median value is the average of the two middle values in abilities[].
		median = (abilities[(length / 2) - 1] + abilities[length / 2]) / 2;
	} else { // There is an odd amount of values in abilities[] and the median value is the middle value in abilities[].
		median = abilities[length / 2];
	}

	return median;
}

/***********************************************/

void RemoveSpaces(char *name)
{
	// Use the Swap function to swap one character with another character to the left of it if both are spaces.
	int i, n;
	int nameLength = strlen(name);
	for (i = 0; i < nameLength; i++) {
		while (name[i] == ' ' && name[i] == name[i + 1]) {
			n = i + 1;
			while (name[n] != '\0') {
        		name[n] = name[n + 1];
        		n++;
    		}
		}
	}
}

/***********************************************/

void InitialiseBoard(int board[MAX_SIZE][MAX_SIZE], int size)
{
	// Initially set all positions of the board to -1.
	int i, j;
	for (i = 0; i < MAX_SIZE; i++) {
		for (j = 0; j < MAX_SIZE; j++) {
			board[i][j] = -1;
		}
	}

	// Loop through the board array.
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			// Check if the board is an even sized board.
			if (size % 2 == 0) {
				if (i == ((size / 2) - 1) && j == ((size / 2) - 1)) {
					board[i][j] = 3;
					board[i][j + 1] = 3;
					board[i + 1][j] = 3;
					board[i + 1][j + 1] = 3;
				} else {
					if (board[i][j] != 3) {
						board[i][j] = 0;
					}
				}
			} else if (size % 2 != 0) { // The board is an odd sized board.
				if (i == (size / 2) && j == (size / 2)) {
					board[i][j] = 3;
				} else {
					board[i][j] = 0;
				}
			}
		}
	}
}

/***********************************************/

void AddMoveToBoard(int board[MAX_SIZE][MAX_SIZE], int size, char side, int move, int player, int *lastRow, int *lastCol)
{
	int i, j;
	// If side is N.
	if (side == 'N') {
		i = 0;
		// Check if the desired move is already occupied by a token.
		if (board[0][move] != 0) {
			*lastRow = -1;
			*lastCol = -1;
		} // Set the final position of the token against a fixed piece of the board, another token or the end of the board.
		else {
			while (board[i + 1][move] == 0 || i != size - 1) {
				i++;
			}
			board[i][move] = player;
			*lastRow = i;
			*lastCol = move;
		}
	} else if (side == 'E') { // If side is E.
		j = size - 1;
		// Check if the desired move is already occupied by a token.
		if (board[size - 1][move] != 0) {
			*lastRow = -1;
			*lastCol = -1;
		} // Set the final position of the token against a fixed piece of the board, another token or the end of the board.
		else {
			while (board[move][j - 1] == 0 || j != 0) {
				j--;
			}
			board[move][j] = player;
			*lastRow = move;
			*lastCol = j;
		}
	} else if (side == 'S') { // If side is S.
		i = size - 1;
		// Check if the desired move is already occupied by a token.
		if (board[size - 1][move] != 0) {
			*lastRow = -1;
			*lastCol = -1;
		} // Set the final position of the token against a fixed piece of the board, another token or the end of the board.
		else {
			while (board[i - 1][move] == 0 || i != 0) {
				i--;
			}
			board[i][move] = player;
			*lastRow = i;
			*lastCol = move;
		}
	} else if (side == 'W') { // If side is W.
		j = 0;
		// Check if the desired move is already occupied by a token.
		if (board[0][move] != 0) {
			*lastRow = -1;
			*lastCol = -1;
		} // Set the final position of the token against a fixed piece of the board, another token or the end of the board.
		else {
			while (board[move][j + 1] == 0 || j != size - 1) {
				j++;
			}
			board[move][j] = player;
			*lastRow = move;
			*lastCol = j;
		}
	}
}

/***********************************************/

int CheckGameOver(int board[MAX_SIZE][MAX_SIZE], int size, int player, int row, int col)
{
	// Check if the board contains no available positions in which a new token can be placed.
	int i, j;
	int available = 0;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (board[i][j] == 0) {
				available++;
			}
		}
	}
	if (available == 0) {
		return player;
	}

	int seqArray[MAX_SIZE] = {0};
	int playerWins;
	// Check if there is a four in a row in the column sequence of the last placed token.
	for (i = 0; i < size; i++) {
		seqArray[i] = board[i][col];
	}
	playerWins = FourInARow(seqArray, size);
	if (playerWins != -1) {
		return player;
	}

	// Check if there is a four in a row in the row sequence of the last placed token.
	for (j = 0; j < size; j++) {
		seqArray[j] = board[row][j];
	}
	playerWins = FourInARow(seqArray, size); 
	if (playerWins != -1) {
		return player;
	}

	int result;
	// Check if there is a four in a row in a diagonal sequence (top left to bottom right) which the last placed token is a part of.
	result = TopLeftToBottomRight(board, size, row, col);
	if (result == 1) {
		return player;
	}
	// Check if there is a four in a row in a diagonal sequence (bottom left to top right) which the last placed token is a part of.
	result = BottomLeftToTopRight(board, size, row, col);
	if (result == 1) {
		return player;
	}

	return 0;
}

/***********************************************/

void GetDisplayBoardString(int board[MAX_SIZE][MAX_SIZE], int size, char *boardString)
{
	// This definition is WRONG.  To avoid compiler warnings, all of the input variables have been
	// referred to below.  Fix this function by *deleting this comment* and the code below, and
	// writing a correct definition.  If you do not attempt this task, leave this definition unchanged.
	// board[0][0] = size-size;
	// boardString[0] = '\0';

	int c, n, i, j, row;
	// Add the North row of printable characters to the boardString buffer.
	boardString[0] = '-';
	boardString[1] = '-';
	for (c = 2; c < size + 2; c++) {
		boardString[c] = 'N';
	}
	boardString[size + 2] = '-';
	boardString[size + 3] = '-';
	boardString[size + 4] = '\n';

	// Add the row of indices that corresponds to the North row to the boardString buffer.
	boardString[size + 5] = '-';
	boardString[size + 6] = '-';
	n = 48;
    for (c = size + 7; c < (size * 2) + 7; c++) {
        boardString[c] = (char)n;
		n++;
	}
    boardString[(size * 2) + 7] = '-';
    boardString[(size * 2) + 8] = '-';
    boardString[(size * 2) + 9] = '\n';

    // Add the West and East sides of the board, as well as the board itself, to the boardString buffer.
    row = 0;
	n = 48;
    for (i = 0; i < size; i++) {
        boardString[(size * 2) + 10 + row] = 'W';
        boardString[(size * 2) + 11 + row] = (char)n;
        for (j = 0; j < size; j++) {
            if (board[i][j] == 0) {
                boardString[(size * 2) + 12 + row + j] = '.';
            } else if (board[i][j] == 1) {
                boardString[(size * 2) + 12 + row + j] = 'X';
            } else if (board[i][j] == 2) {
                boardString[(size * 2) + 12 + row + j] = 'O';
            } else if (board[i][j] == 3) {
                boardString[(size * 2) + 12 + row + j] = '#';
            }
        }
        boardString[(size * 3) + 11 + row] = (char)n;
        boardString[(size * 3) + 12 + row] = 'E';
        boardString[(size * 3) + 13 + row] = '\n';
        row = row + (size + 4);
		n++;
    }

    // Add the row of indices that corresponds to the South row to the boardString buffer.
    boardString[(size * 3) + 14 + row] = '-';
    boardString[(size * 3) + 15 + row] = '-';
	n = 48;
    for (c = (size * 3) + 16 + row; c < (size * 4) + 16 + row; c++) {
        boardString[c] = (char)n;
		n++;
    }
    boardString[(size * 4) + 16 + row] = '-';
    boardString[(size * 4) + 17 + row] = '-';

    // Add the South row of printable characters to the boardString buffer.
    boardString[(size * 4) + 18 + row] = '-';
    boardString[(size * 4) + 19 + row] = '-';
    for (c = (size * 4) + 20 + row; c < (size * 5) + 20 + row; c++) {
		boardString[c] = 'S';
	}
    boardString[(size * 5) + 20 + row] = '-';
    boardString[(size * 5) + 21 + row] = '-';
    boardString[(size * 5) + 22 + row] = '\n';
    boardString[(size * 5) + 23 + row] = '\0';
}

/***********************************************/

void GetMoveBot1(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
{
	int randRow, randCol;
	randRow = (rand() % size);
	randCol = (rand() % size);
	if (board[randRow][randCol] > 0) {
		*side = 'N';
		*move = 0 + player;
		return;
	} else {
		int randSide;
		// Select a random side.
		randSide = (rand() % 4);
		if (randSide == 1) {
			*side = 'N';
		} else if (randSide == 2) {
			*side = 'E';
		} else if (randSide == 3) {
			*side = 'S';
		} else {
			*side = 'W';
		}
		//Select a random move.
		*move = (rand() % size);
	}

	return;
}

/***********************************************/

void GetMoveBot2(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
{
	int randRow, randCol;
	randRow = (rand() % size);
	randCol = (rand() % size);
	if (board[randRow][randCol] > 0) {
		*side = 'N';
		*move = 0 + player;
		return;
	} else {
		int randSide;
		// Select a random side.
		randSide = (rand() % 4);
		if (randSide == 1) {
			*side = 'N';
		} else if (randSide == 2) {
			*side = 'E';
		} else if (randSide == 3) {
			*side = 'S';
		} else {
			*side = 'W';
		}
		//Select a random move.
		*move = (rand() % size);
	}

	return;
}
