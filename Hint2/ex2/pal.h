
//--------------------------------------------------
// INCLUDE SECTION
//--------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "visible.h"

//--------------------------------------------------
// is_pal
//--------------------------------------------------
boolean is_pal(int* a, int size_num);

//--------------------------------------------------
// ask_for_command
//--------------------------------------------------
char ask_for_command(char* c, int size);

//--------------------------------------------------
// process_movement
//--------------------------------------------------
void process_movement(int* a, int size_num, int** p, int* num_mov, char c);

//--------------------------------------------------
// print_status
//--------------------------------------------------
void print_status(int* a, int size_num, int* p, int num_mov);

//--------------------------------------------------
// user_game_palindrome
//--------------------------------------------------
void user_game_palindrome(int pal_num, int num_size, char commands[], int command_size);

