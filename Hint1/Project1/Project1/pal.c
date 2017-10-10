#define _CRT_SECURE_NO_WARNINGS
#include "pal.h"

//--------------------------------------------------
// is_pal
//--------------------------------------------------
boolean is_pal(int a[6]) {
	boolean res = True;

	int l = 0;
	int r = 5;

	while ((l < r) && (res == True)) {
		if (a[l] != a[r])
		{
			printf("%d %d %d %d %d %d is not a palindrome number.\n", a[0], a[1], a[2], a[3], a[4], a[5]);
			res = False;
			
		}
		else {
			printf("%d %d %d %d %d %d is a palindrome number.\n", a[0], a[1], a[2], a[3], a[4], a[5]);
			l = l + 1;
		    r = r - 1;

		}
		
	}

	return res;
}
	/*
		if (a[0] == a[5] && a[1] == a[4] && a[2] == a[3]) {

			printf("%d %d %d %d %d %d is a palindrome number.\n", a[0], a[1], a[2], a[3], a[4], a[5]);
			res = True;
		}
		else {
			printf("%d %d %d %d %d %d is not a palindrome number.\n", a[0], a[1], a[2], a[3], a[4], a[5]);

		}
	return res;
}
*/

//--------------------------------------------------
// ask_for_command
//--------------------------------------------------
char ask_for_command() {
	char res = ' ';
	do
	{
		printf("\nNEW MOVEMENT: Enter a valid command by keyword: \nValid commands: a       d       w       x  \n");
		printf("");
		res = my_get_char();//get character
		if ((res != 'a') && (res != 'x') && (res != 'd') && (res != 'w')) {
		printf("---------Invalid Command Entered!---------\n");
	}
	} while ((res != 'a') && (res != 'x') && (res != 'd') && (res != 'w'));
	
	
     return res;
	
	
}

//--------------------------------------------------
// process_movement
//--------------------------------------------------
void process_movement(int a[6], int** p_p, int* p_nm, char c){
	// check for each character input
	if (c == 'a') {
		if (*p_p != (a + 0))
		{
			int n = *p_p;
			*p_p = *p_p - 1;
			*p_nm = *p_nm + 1;
		}
		else {
			printf("-----No index found!-----\n");
		}
	
	}
	else if (c == 'd') {
		if (*p_p != (a + 5))
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

}

//--------------------------------------------------
// print_status
//--------------------------------------------------
void print_status(int a[6], int* p, int nm) {
	printf("---Game Status---\n");

	printf("Numbers = ");
	int i;
	for (int i = 0; i<6; ++i) {
		printf("%d ", a[i]);//print all int in teh array
	}
	printf("\n");
	for (int j = 0; j < 6; j++)
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
	

	printf("\nNum mov = %d ", nm);
	printf("\n----------------");

}

//--------------------------------------------------
// user_game_palindrome
//--------------------------------------------------
void user_game_palindrome(int pal_num) {

	int a[6];
	char str[7];

	int* p = &a;
	int** p_p = &p;
	int nm = 0;
	int p_nm = &nm;


	sprintf(str, "%d", pal_num);//convert int to string
	
	for (int i = 0; i < 6; i++)
	{
		a[i] = str[i] - '0';
	}
	
	
	
	
	int i;
	for (i = 0; i < 6; i++) {
		printf("*(p + %d) : %d\n", i, *(p + i));
	}
	
	
	while (is_pal(a) == False) {
		print_status(a, p, nm);
	
		char c = ask_for_command();

		printf("character from input is %c\n", c);
		
		process_movement(a, p_p, p_nm, c);
	}
	printf("----------------\nProblem Solved!!\n-----------------");
	my_get_char();
}
