
//--------------------------------------------------
// INCLUDE SECTION
//--------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include "pal.h"

//--------------------------------------------------
// is_pal
//--------------------------------------------------
boolean is_pal(int* a, int size_num) {
	boolean res = True;

	int l = 0;
	int r = size_num-1;

	while ((l < r) && (res == True)) {
		if (a[l] != a[r])
		{
			for (int i = 0; i < size_num; i++)
			{
               printf("%d ", a[i]);
			}
			printf("is not a palindrome number.\n");
			res = False;

		}
		else {
			for (int i = 0; i < size_num; i++)
			{
				printf("%d ", a[i]);
			}
			printf("is a palindrome number.\n");
			l = l + 1;
			r = r - 1;
			

		}

	}

	return res;
}

//--------------------------------------------------
// ask_for_command
//--------------------------------------------------
char ask_for_command(char c[], int size) {
	char res = ' ';


		printf("\nNEW MOVEMENT : Enter a valid command by keyword : \nValid commands : ");
		for (int i = 0; i < size; i++)
		{
			printf("%c ", c[i]);
		}

		printf("\n");
		res = my_get_char();//get character
		

	return res;
}

//--------------------------------------------------
// process_movement
//--------------------------------------------------
void process_movement(int* a, int size_num, int** p_p, int* p_nm, char c) {
	// check for each character input


	if (c == 'a') {
		if (**p_p != (a[0]))
		{
			*p_p = *p_p - 1;
			*p_nm = *p_nm + 1;
		}
		else {
			printf("-----No index found!-----\n");
		}

	}
	else if (c == 'd') {
	
		if (*p_p != (a + (size_num-1)))
		{
			*p_p = *p_p + 1;			
			*p_nm = *p_nm + 1;	    
		}
		else {
			printf("-----No index found!-----\n");
		}
	}
	else if (c == 'w') {
		if (**p_p != 9)
		{
			**p_p = (**p_p) + 1;
			*p_nm = *p_nm + 1;
		}
		else {
			printf("-----Limit Reached!-----\n");
		}
	}
	else if (c == 'x') {
		if (**p_p != 0)
		{
			**p_p = **p_p - 1;
			*p_nm = *p_nm + 1;
		}
		else {
			printf("-----Limit Reached!-----\n");
		}
	}
	else if (c == 'h') {
		if (*p_p != &(a[0]))
		{
			*p_p = &a[0];
			*p_nm = *p_nm + 1;
		}
		else {
			printf("-----First Element reached!-----\n");
		}
	}
	else if (c == 'k') {
		if (*p_p != &a[size_num-1])
		{
			*p_p = &a[size_num - 1];
			*p_nm = *p_nm + 1;
		}
		else {
			printf("-----Last Element reached!-----\n");
		}
	}
	else if (c == 'u') {
		if (**p_p != 9)
		{
			int max = 9;
			int current = **p_p;
			int addValue = max - current;
			**p_p = **p_p + addValue;
			*p_nm = *p_nm + 1;
		}
		else {
			printf("-----Limit Reached!-----\n");
		}
	}
	else if (c == 'm') {
		if (**p_p != 0)
		{
			int min = 0;
			int current = **p_p;
			int minusValue = current - min;
			**p_p = **p_p - minusValue;
			*p_nm = *p_nm + 1;
		}
		else {
			printf("-----Limit Reached!-----\n");
		}
	}else {
		printf("-------Invalid Command!!--------\n");
	}
}

//--------------------------------------------------
// print_status
//--------------------------------------------------
void print_status(int* a, int size_num, int* p, int num_mov) {
	printf("---Game Status---\n");

	printf("Numbers = ");
	int i;
	for (int i = 0; i < size_num; ++i) {
		printf("%d ", a[i]); //print all element in the array
	}

	printf("\n");
	for (int j = 0; j < size_num; j++)
	{
		if (p == (a + j))
		{
			int k = 0;
			printf("         ");
			while (k < (0 + j))
			{
				printf("  ");
				k++;

			}printf(" ^ ");
		}

	}


	printf("\nNum mov = %d ", num_mov);
	printf("\n----------------");

}

//--------------------------------------------------
// user_game_palindrome
//--------------------------------------------------
void user_game_palindrome(int pal_num, int num_size, char commands[], int command_size) {
	int* a = (int*)malloc(num_size * sizeof(int));
	int** size = &num_size;
	char str[sizeof(a)];

	int* p = a;
	int** p_p = &p;
	int num_mov = 0;
	int p_nm = &num_mov;


	sprintf(str, "%d", pal_num);//convert int to string

	for (int i = 0; i < num_size; i++)
	{
		a[i] = str[i] - '0';
	}

	

	while (is_pal(a, num_size) == False) {
		print_status(a, num_size, p, num_mov);

		char c = ask_for_command(commands, command_size);

		printf("character from input is %c\n", c);

		process_movement(a, num_size, p_p, p_nm, c);
	}
	printf("----------------\nProblem Solved!!\n-----------------");
	my_get_char();
}
