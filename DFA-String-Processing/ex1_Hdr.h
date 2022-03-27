#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int get_sym_ind(char*, char);	//return index of a character from the input symbols array
int is_accepting(int, char*);	//check if cur_state is accepting state or not
int string_processing(char*, int**, char*, int, int, char*);