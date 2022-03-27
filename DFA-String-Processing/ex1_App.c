#include"ex1_Hdr.h"
#include<stdlib.h>

void main()
{
	int n_states, n_symbols, n_accept, i, j, out;
	char* symbols;
	char* accepting;
	int** table;
	char inp_string[10];

	printf("\nEnter the number of states : ");
	scanf("%d",&n_states);

	printf("\nEnter the number of accepting states : ");
	scanf("%d",&n_accept);
	accepting = (char*)malloc(sizeof(char)*n_accept);
	printf("\nEnter the accepting states : ");
	scanf("%s",accepting);

	printf("\nEnter the number of input symbols : ");
	scanf("%d",&n_symbols);
	symbols = (char*)malloc(n_symbols);
	printf("\nEnter the input symbol(s) : ");
	scanf("%s",symbols);

	table = (int**)malloc(sizeof(int*)*n_states);
	for(i=0;i<n_states;i++)
		table[i] = (int*)malloc(sizeof(int)*n_symbols);
	printf("\nEnter the transition table details : Transition[State][Symbol]\n");
	for(i=0;i<n_states;i++)
	{
		for(j=0;j<n_symbols;j++)
		{
			printf("Transition[%d]['%c'] : ", i, symbols[j]);
			scanf("%d",&table[i][j]);
		}
	}

	printf("\nEnter the string to process :");
	scanf("%s",inp_string);
	out = string_processing(inp_string, table, accepting, n_states, n_symbols, symbols);
	if(out==1)
	{
		printf("\nString is accepted.\n\n");

		//set of all states Q
		printf("Set of All States (Q) : { ");
		for(i=0;i<n_states;i++)
			printf("%d ", i);
		printf("}\n\n");

		//set of input symbols (sigma)
		printf("Set of All Input Symbols (Sigma) : { ");
		for(i=0;i<n_symbols;i++)
			printf("%c ", symbols[i]);
		printf("}\n\n");

		//starting state
		printf("Start State (q) : 0\n\n");

		//set of final states (F)
		printf("Set of All Final States (F) : { ");
		for(i=0;i<n_accept;i++)
			printf("%c ", accepting[i]);
		printf("}\n\n");

		//transition function
		printf("Transition Table : Transition[State][Symbol]\n");
		printf("--------------------------------------------\n");
		for(i=0;i<n_states;i++)
			for(j=0;j<n_symbols;j++)
				printf("Transition[%d]['%c'] : %d\n", i, symbols[j], table[i][j]);
	}
	else
		printf("\nString is not accepted\n");
}