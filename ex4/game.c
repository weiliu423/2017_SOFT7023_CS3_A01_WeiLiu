
//------------------------------------
//	Include Libraries 
//------------------------------------
#include "game.h"

//------------------------------------
//	01. FUNCTION create_new_game
//------------------------------------
game* create_new_game(char* p1, char* p2){
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

	//5. We initialise the board to contain all positions empty
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLUMNS; j++)
			(*g).board[i][j] = ' ';

	//6. We return the game
	return g;
}

//------------------------------------
//	02. FUNCTION display_board 
//------------------------------------
void display_board(game* g){
	int i, j;

				printf("--------------Connect 4 Game---------------\n");
				for (i = 0; i < ROWS; i++) {
					printf("\t+---+---+---+---+---+---+---+");
					printf("\n\t");

					for (j = 0; j < COLUMNS; j++) {
						printf("| %c ", (*g).board[i][j]);
					}
					    printf("|\n");
				}
				
				printf("\t+");
				for (j = 0; j < ROWS + 1; j++)
					printf("---+");
				printf("\n");
				printf(" \t  1   2   3   4   5   6   7 \n ");



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
		for (int i = ROWS; i + 1 > 0; i--) {
			if(x <= COLUMNS && x > 0 && (*g).board[0][x - 1] == ' '){
				if ((*g).board[i][x - 1] == ' ') {
				if ((*g).status == 1)
				{
					(*g).board[i][x - 1] = 'o';

					break;

				}
				else {
					(*g).board[i][x - 1] = 'x';
					printf("\n\nnow is x");
					break;
				}
			}
		}else {
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
	int col = rand() % 7;
	for (int i = ROWS; i + 1 > 0; i--) {
		
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
				system("cls");
				display_board(g);
				winning_player(g, p1, p2);
			}
			else if((*g).status == 2){
				display_game_status(g);
				(*g).status = (*g).status - 1;
				user_movement(g);
				system("cls");
				display_board(g);
				winning_player(g,  p1, p2);
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
	for (int j = 0; j < ROWS; j++) {
		for (int i = 0; i < COLUMNS; i++)
		{
			if ((*g).board[j][i] == 'x') {
				count++;
			}
			else {
				count = 0;
			}
			if (count >= 4)
			return 1;
		}
		for (int i = 0; i < COLUMNS; i++)
		{
			if ((*g).board[j][i] == 'o') {
				count++;
			}
			else {
				count = 0;
			}
			if (count >= 4)
			return 2;
		}
	}
}

//------------------------------------
//	10. FUNCTION winning_column 
//------------------------------------
bool winning_column(game* g) {
	int count = 0;
	for (int j = 0; j < COLUMNS; j++) {
		for (int i = 0; i < ROWS; i++)
		{
			if ((*g).board[i][j] == 'x') {
				count++;
			}
			else {
				count = 0;
			}
			if (count >= 4)
				return 1;
		}
		for (int i = 0; i < ROWS; i++)
		{
			if ((*g).board[i][j] == 'o') {
				count++;
			}
			else {
				count = 0;
			}
			if (count >= 4)
				return 2;
		}
	}
}

//------------------------------------
//	11. FUNCTION winning_diagonal 
//------------------------------------
bool winning_diagonal(game* g) {
	int count = 0;
	for (int i = 3; i < COLUMNS; i++) {
		for (int j = 0; j< ROWS - 3; j++) {
			if ((*g).board[i][j] == 'x' && (*g).board[i - 1][j + 1] == 'x' && (*g).board[i - 2][j + 2] == 'x' && (*g).board[i - 3][j + 3] == 'x') {
				return 1;
			}
			else if ((*g).board[i][j] == 'o' && (*g).board[i - 1][j + 1] == 'o' && (*g).board[i - 2][j + 2] == 'o' && (*g).board[i - 3][j + 3] == 'o')
			{
				return 2;
			}
		}
	}
	// descendingDiagonalCheck
	for (int i = 3; i< COLUMNS; i++) {
		for (int j = 3; j< ROWS; j++) {
			if ((*g).board[i][j] == 'x' && (*g).board[i - 1][j - 1] == 'x' && (*g).board[i - 2][j - 2] == 'x' && (*g).board[i - 3][j - 3] == 'x') {
				return 1;
			}
			else if ((*g).board[i][j] == 'o' && (*g).board[i - 1][j - 1] == 'o' && (*g).board[i - 2][j - 2] == 'o' && (*g).board[i - 3][j - 3] == 'o') {
				return 2;
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
	else if(winning_row(g) == 2 || winning_column(g) == 2 || winning_diagonal(g) == 2) {
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
void play_game(char* p1, char* p2) {
	game* g = create_new_game(p1, p2);

	display_board(g);
	new_movement(g, p1, p2);
	
}
