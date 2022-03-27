#include"ex1_Hdr.h"
#include<string.h>

int get_sym_ind(char* symbols, char ch)	//return index of a character from the input symbols array
{
	int i, l=strlen(symbols);
	for(i=0;i<l;i++)
		if(symbols[i]==ch)
			return i;
}

int is_accepting(int cur_state, char* accepting)	//check if cur_state is accepting state or not
{
	int l, flag=-1, i;
	l=strlen(accepting);
	for(i=0;i<l;i++)
		if(cur_state == (int)accepting[i] - 48)
			flag =1;	//accepted
	return flag;	// 1:accept; -1:rejected
}

int string_processing(char inp_string[],int** table,char* accepting,int n_states,int n_symbols,char* symbols)
{
	int cur_state=0, l, cur_sym_len, i, j, index;
	l=strlen(inp_string);
	printf("\n");
	for(cur_sym_len=0;cur_sym_len<l;cur_sym_len++)
	{
		index = get_sym_ind(symbols, inp_string[cur_sym_len]);
		cur_state = table[cur_state][index];
	}
	return is_accepting(cur_state, accepting);
}