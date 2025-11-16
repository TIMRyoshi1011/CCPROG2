#include <stdio.h>
#include "tictactoe-RAMOS.c" //Modify this line and change LASTNAME with your actual last name.

//	DO NOT MODIFY THIS FUNCTION!
int main() {
	
	char board[3][3] = {};
	int moves = 0;
	
	printf("Player 1 move:\n");
	setMove(board, 3, 1, 0, 0, &moves);
	displayBoard(board, 3);
	displayOver(board, moves);
	printf("\n");
	printf("Select slot already taken!\n");
	printf("Player 2 move:\n");
	setMove(board, 3, 2, 0, 0, &moves);
	displayBoard(board, 3);
	displayOver(board, moves);
	printf("\n");
	printf("Player 2 move:\n");
	setMove(board, 3, 2, 2, 2, &moves);
	displayBoard(board, 3);
	displayOver(board, moves);
	printf("\n");
	printf("Player 1 move:\n");
	setMove(board, 3, 1, 0, 2, &moves);
	displayBoard(board, 3);
	displayOver(board, moves);
	printf("\n");
	printf("Player 2 move:\n");
	setMove(board, 3, 2, 0, 1, &moves);
	displayBoard(board, 3);
	displayOver(board, moves);
	printf("\n");
	printf("Player 1 move:\n");
	setMove(board, 3, 1, 2, 0, &moves);
	displayBoard(board, 3);
	displayOver(board, moves);
	printf("\n");
	printf("Player 2 move:\n");
	setMove(board, 3, 2, 1, 0, &moves);
	displayBoard(board, 3);
	displayOver(board, moves);
	printf("\n");
	printf("Player 1 move:\n");
	setMove(board, 3, 1, 1, 1, &moves);
	displayBoard(board, 3);
	displayOver(board, moves);
	printf("\n");
			
	return 0;
}
