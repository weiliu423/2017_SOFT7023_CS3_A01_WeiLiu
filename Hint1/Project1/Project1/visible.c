
#include "visible.h"

//--------------------------------------------------
// gen_num
//--------------------------------------------------
int gen_num(int lb, int ub) {
	int num = (rand() % (ub - lb)) + lb;

	return num;
}

//--------------------------------------------------
// my_getchar
//--------------------------------------------------

char my_get_char() {
	//1. We create the output variable with the value the user has input by keyboard
	char my_char = getchar();

	//2. We discard any extra character the user has input by keyboard
	boolean finish = False;
	char dummy_char = ' ';

	while (finish == False) {
		dummy_char = getchar();
		if (dummy_char == '\n')
			finish = True;
	}

	//3. We return the output variable
	return my_char;
}




