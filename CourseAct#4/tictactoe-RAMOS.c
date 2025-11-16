//Function prototypes
int isGameOver(char board[][3], int moves);
void displayBoard(char board[][3], int size);
void displayOver(char board[][3], int moves);
int isTaken(char board[][3], int x, int y);
void setMove(char board[][3], int size, int player, int x, int y, int *moves);

/*	DO NOT MODIFY THIS FUNCTION!
	
	This function checks all winning patterns and
	checks if 9 moves have already been done since
	tic tac toe only has 9 moves.
	
	@param: char board[][3] - The tic-tac-toe board
	@param: int moves - number of moves already played
*/
int isGameOver(char board[][3], int moves) {
	int over = 0;
	
	if(moves == 9)
		over = 1;	
	else if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
		over = 1;
	else if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
		over = 1;
	else if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
		over = 1;
	else if(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
		over = 1;
	else if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
		over = 1;
	else if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
		over = 1;
	else if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
		over = 1;
	else if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
		over = 1;
	else if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
		over = 1;
	else if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
		over = 1;
	else if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
		over = 1;
	else if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
		over = 1;
	else if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
		over = 1;
	else if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
		over = 1;
	else if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
		over = 1;
	else if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
		over = 1;
	
	return over;
}

/*	DO NOT MODIFY THIS FUNCTION!
	
	This function displays the tic-tac-toe board which
	allows you to track the progress of the game.
	
	@param: char board[][3] - tic-tac-toe board
	@param: int size - size of the first dimension of the array
*/
void displayBoard(char board[][3], int size) {
	int i, j;
	
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			if(board[i][j] == '\0')
				printf("[ ]");
			else
				printf("[%c]", board[i][j]);
		}
		printf("\n");
	}
}

/*  TASK#1: Implement displayOver()

	@param: char board[][3] - tic-tac-toe board
	@param: int moves - number of moves already played
	
	This function will call the isGameOver() function to check if the
	there is a winner. If isGameOver() returns 1(true), then display
	a "Game Over!\n" message otherwise display "Keep playing!\n".
*/
void displayOver(char board[][3], int moves) {
	if (isGameOver(board, moves)) 
		printf("Game Over!\n");
	
	else 
		printf("Keep playing!\n");
}

/*	TASK#2: Implement isTaken()
	
	@param: char board[][3] - tic-tac-toe board
	@param: int x - index of the row
	@param: int y - index of the column
	
	This function will check if a selected slot on the board
	is taken. Basically, if the slot has a null byte, it's empty.
	If the slot is taken, the function returns 1 otherwise the
	function returns 0. You may declare variables if you need them.
*/
int isTaken(char board[][3], int x, int y) {
	if (board[x][y] != '\0')
		return 1;
	
	else
		return 0;
}

/*	TASK#3: Implement setMove()

	@param: char board[][3] - tic-tac-toe board
	@param: int size - size of the first dimension of the array
	@param: int player - player making the move (either 1 or 2)
	@param: int x - index of the row
	@param: int y - index of the column
	@param: int *moves - pointer to the moves variable
	
	This function will first check if the selected slot is taken by
	calling the isTaken() function to check. If isTaken() returns 1, display
	the message "Space is taken!\nPlease select another slot!\n". If
	isTaken() return 0, the function will then check which player is playing.
	If player is 1, place a 'O' in the selected slot on the board and add 1
	to the moves counter. Otherwise place a 'X' in the selected slot on the 
	board and add 1 to the moves counter.
*/
void setMove(char board[][3], int size, int player, int x, int y, int *moves) {
	if (isTaken(board, x, y))
		printf("Space is taken!\nPlease select another slot!\n");
	
	else {
		if(player == 1) 
			board[x][y] = 'O';

		else
			board[x][y] = 'X';

		*moves += 1;
	}
}

