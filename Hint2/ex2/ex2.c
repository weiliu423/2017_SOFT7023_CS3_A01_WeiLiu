
//--------------------------------------------------
// INCLUDE SECTION
//--------------------------------------------------
#include "pal.h"

//------------------------------------
//	main
//------------------------------------
int main() {
	//1. We generate the seed for the random number
	srand(time(NULL));
	
	//2. We select the number and commands we want to play with
	int pal_num = 123322;
	int num_size = 6;
	char commands[] = { 'a','d','w','x', 'h', 'k', 'u', 'm' };
	int commands_size = 8;

	//3. We perform the interactive session
	user_game_palindrome(pal_num, num_size, commands, commands_size);

	//4. We finish the program
	return 0;
}

