
//------------------------------------
//	Include Libraries 
//------------------------------------
#include "game.h"

//------------------------------------
//	01. FUNCTION create_new_game
//------------------------------------
game* create_new_game(int connect, int rows, int columns, char* p1, char* p2){
	//1. We create the variable for hosting the game
	game* g = (game*)malloc(1 * sizeof(game));
	
	//2. We use the names passed as arguments 
	(*g).p1 = (char*)malloc((strlen(p1) + 1) * sizeof(char));	
	strcpy((*g).p1, p1);

	(*g).p2 = (char*)malloc((strlen(p1) + 1) * sizeof(char));
	strcpy((*g).p2, p2);

	//3. We set the mode to the one passed by parameter
	int mode = 0;
	if (strcmp(p1, "Computer") == 0)
		mode = mode + 2;
	if (strcmp(p2, "Computer") == 0)
		mode = mode + 1;
	(*g).mode = mode;

	//4. We set the status to be 1; i.e., player1 moves first
	(*g).status = 1;

	//5. We initialise the connect, rows and columns
	(*g).connect = connect;
	(*g).rows = rows;
	(*g).columns = columns;
	
	//6. We initialise the board to contain all positions empty
	(*g).board = (char**)malloc((*g).rows * sizeof(char*));
	(*g).board[0] = (char*)malloc(((*g).rows * (*g).columns) * sizeof(char));
	for (int i = 0; i < (*g).rows; i++)
		(*g).board[i] = (*g).board[0] + ((*g).columns * i);

	for (int i = 0; i < (*g).rows; i++)
		for (int j = 0; j < (*g).columns; j++)
			(*g).board[i][j] = ' ';

	//7. We return the game
	return g;
}

//------------------------------------
//	02. FUNCTION display_board 
//------------------------------------
void display_board(game* g) {
	int i, j;

	printf("--------------Connect 4 Game---------------\n");
	for (i = 0; i < (*g).rows; i++) {
		for (int i = 1; i <= (*g).columns; i++) {
			printf("+---");	
		}
		printf("+");
		printf("\n");
		for (j = 0; j < (*g).columns; j++) {
			printf("| %c ", (*g).board[i][j]);
		}
		printf("|\n");
	}

	printf("+");
	for (j = 0; j < (*g).columns; j++)
		printf("---+");
	printf("\n");
	for (int i = 1; i <= (*g).columns; i++) {
		printf("  %d ",i);
	}
}

//------------------------------------
//	03. FUNCTION display_game_status 
//------------------------------------
void display_game_status(game* g) {
	printf("\n");

	if ((*g).status == 1) {

		printf("\nPlayer %s moves next", (*g).p1);
		//(*g).status = (*g).status + 1;
	}
	else {

		printf("\nPlayer %s moves next", (*g).p2);
		//(*g).status = (*g).status - 1;
	}
}

//--------------------------------------------------
// 04. FUNCTION my_getchar
//--------------------------------------------------
char my_get_char() {
	//1. We create the variable for hosting the char
	char my_char = ' ';

	//2. We create an extra variable to consume any other characters entered until a return is pressed
	bool line_consumed = False;
	char dummy_char = ' ';

	//3. We consume the first char entered, i.e., the one we are interested at
	my_char = getchar();

	//4. While still there are remaining characters
	while (line_consumed == False) {
		//4.1. We consume the next character
		dummy_char = getchar();

		//4.2. If the new character is the end of line one, we can ensure we have consumed the entire line.
		if (dummy_char == '\n')
			line_consumed = True;
	}

	//5. We return the first character entered by the user, i.e., the one we are interested at
	return my_char;
}

//------------------------------------
//	05. FUNCTION ask_for_column 
//------------------------------------
int ask_for_column(game* g) {
	char res = ' ';
	printf("\nEnter a Column from 1 to 7: ");
	res = my_get_char();
	return res;
}

//------------------------------------
//	06. FUNCTION user_movement 
//------------------------------------
int user_movement(game* g) {
	char res = ask_for_column(g);
	int x = res - '0';
	for (int i = (*g).rows-1; i + 1 > 0; i--) {
		if (x <= (*g).columns && x > 0 && (*g).board[0][x - 1] == ' ') {

			if ((*g).board[i][x - 1] == ' ') {
				if ((*g).status == 1)
				{
					(*g).board[i][x - 1] = 'o';

					break;

				}
				else {
					(*g).board[i][x - 1] = 'x';
					
					break;
				}
			}
		}
		else {
			printf("\nInvalid Input, Try again!!");
			if ((*g).status == 2) {
				(*g).status = (*g).status - 1;
			}
			else {
				(*g).status = (*g).status + 1;
			}
		}

	}
}

//------------------------------------
//	07. FUNCTION computer_movement 
//------------------------------------
int computer_movement(game* g) {
	getchar();
	int col = rand() % (*g).columns;
	for (int i = (*g).rows-1; i + 1 > 0; i--) {

		if ((*g).board[i][col] == ' ') {
			if ((*g).status == 1)
			{
				(*g).board[i][col] = 'o';
				break;

			}
			else {
				(*g).board[i][col] = 'x';
				break;
			}
		}
	}
}

//------------------------------------
//	08. FUNCTION new_movement 
//------------------------------------
void new_movement(game* g, char* p1, char* p2) {
	while (winning_player(g, p1, p2) == 0) {
		if ((*g).mode == 0) {
			if ((*g).status == 1) {
				display_game_status(g);
				(*g).status = (*g).status + 1;
				user_movement(g);
				//system("cls");
				display_board(g);
				winning_player(g, p1, p2);
			}
			else if ((*g).status == 2) {
				display_game_status(g);
				(*g).status = (*g).status - 1;
				user_movement(g);
				//system("cls");
				display_board(g);
				winning_player(g, p1, p2);
			}
		}
		else if ((*g).mode == 1) {
			if ((*g).status == 1) {
				display_game_status(g);
				(*g).status = (*g).status + 1;
				user_movement(g);
				system("cls");
				display_board(g);
				winning_player(g, p1, p2);
			}
			else {
				display_game_status(g);
				(*g).status = (*g).status - 1;
				computer_movement(g);
				system("cls");
				display_board(g);
				winning_player(g, p1, p2);
			}
		}
		else if ((*g).mode == 2) {

			if ((*g).status == 1) {
				display_game_status(g);
				(*g).status = (*g).status + 1;
				computer_movement(g);
				system("cls");
				display_board(g);
				winning_player(g, p1, p2);
			}
			else {
				display_game_status(g);
				(*g).status = (*g).status - 1;
				user_movement(g);
				system("cls");
				display_board(g);
				winning_player(g, p1, p2);
			}
		}
		else if ((*g).mode == 3) {
			if ((*g).status == 1) {
				display_game_status(g);
				(*g).status = (*g).status + 1;
				computer_movement(g);
				system("cls");
				display_board(g);
				winning_player(g, p1, p2);
			}
			else {
				display_game_status(g);
				(*g).status = (*g).status - 1;
				computer_movement(g);
				system("cls");
				display_board(g);
				winning_player(g, p1, p2);
			}
		}
	}
}

//------------------------------------
//	09. FUNCTION winning_row 
//------------------------------------
bool winning_row(game* g) {
	int count = 0;
	for (int j = 0; j < (*g).rows; j++) {
		for (int i = 0; i < (*g).columns; i++)
		{
			if ((*g).board[j][i] == 'x') {
				count++;
			}
			else {
				count = 0;
			}
			if (count >= (*g).connect)
				return 1;
		}
		for (int i = 0; i < (*g).columns; i++)
		{
			if ((*g).board[j][i] == 'o') {
				count++;
			}
			else {
				count = 0;
			}
			if (count >= (*g).connect)
				return 2;
				
		}
	}
}

//------------------------------------
//	10. FUNCTION winning_column 
//------------------------------------
bool winning_column(game* g) {
	int count = 0;
	for (int j = 0; j < (*g).columns; j++) {
		for (int i = 0; i < (*g).rows; i++)
		{
			if ((*g).board[i][j] == 'x') {
				count++;
			}
			else {
				count = 0;
			}
			if (count >= (*g).connect) {
				return 1;
			}
		}
		for (int i = 0; i < (*g).rows; i++)
		{
			if ((*g).board[i][j] == 'o') {
				count++;
			}
			else {
				count = 0;
			}
			if (count >= (*g).connect)
				return 2;
		}
	}
}

//------------------------------------
//	11. FUNCTION winning_diagonal 
//------------------------------------
bool winning_diagonal(game* g) {
	int P1count, P2count;
	//// descendingDiagonalCheck
	for (int i = 0; i <= (*g).columns- (*g).connect; i++) {
		for (int j = 0; j <= (*g).rows -(*g).connect; j++) {
			
				P1count = 0;
				P2count = 0;
			for (int c = 0; c < (*g).connect; c++)
			{	
				
					if ((*g).board[j + c][i + c] == 'x')
					{
						P1count++;
					}
					else if ((*g).board[j + c][i + c] == 'o') {
						P2count++;
					}
					else {
						P1count = 0;
						P2count = 0;
					}
					if (P1count == (*g).connect)
					{
						return 1;
					}
					else if (P2count == (*g).connect)
					{
						return 2;
					}
				
			}
		}
	}
	//// AscendingDiagonalCheck
	if ((*g).connect >= 4) {
		for (int i = 0; i < (*g).columns - (*g).connect; i++) {
			for (int j = (*g).rows; j > (*g).rows - (*g).connect; j--) {
				P1count = 0;
				P2count = 0;

				for (int c = 0; c < (*g).connect; c++)
				{
					if ((*g).board[i + c][j - c] == 'x')
					{
						P1count++;
					}
					else if ((*g).board[i + c][j - c] == 'o') {

						P2count++;
					}
					else {
						P1count = 0;
						P2count = 0;
					}

					if (P1count == (*g).connect)
					{
						return 1;
					}
					else if (P2count == (*g).connect)
					{
						return 2;
					}

				}


			}


		}
	}
	else {
		for (int i = 0; i < (*g).columns - (*g).connect; i++) {
				for (int j = (*g).rows-1; j > (*g).rows - (*g).connect; j--) {
					P1count = 0;
					P2count = 0;

					for (int c = 0; c < (*g).connect; c++)
					{
						if ((*g).board[j - c][i + c] == 'x')
						{
							P1count++;
						}
						else if ((*g).board[j - c][i + c] == 'o') {

							P2count++;
						}
						else {
							P1count = 0;
							P2count = 0;
						}

						if (P1count == (*g).connect)
						{
							return 1;
						}
						else if (P2count == (*g).connect)
						{
							return 2;
						}

					}

				}
			}
	}
}

//------------------------------------
//	12. FUNCTION winning_player 
//------------------------------------
bool winning_player(game* g, char* p1, char* p2) {
	if (winning_row(g) == 1 || winning_column(g) == 1 || winning_diagonal(g) == 1)
	{
		printf("\rPlayer %s has won!", p1);
	}
	else if (winning_row(g) == 2 || winning_column(g) == 2 || winning_diagonal(g) == 2) {
		printf("\rPlayer %s has won!", p2);
	}
	else {
		return 0;
	}
}

//------------------------------------
//	13. FUNCTION update_status 
//------------------------------------
void update_status(game* g) {

}

//------------------------------------
//	14. FUNCTION play_game 
//------------------------------------
void play_game(int connect, int rows, int columns, char* p1, char* p2){
 


	game* g = create_new_game(connect, rows, columns, p1, p2);
	

	display_board(g, rows, columns);
	new_movement(g, p1, p2, rows, columns);
}
