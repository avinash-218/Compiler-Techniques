%{
#include<stdio.h>
#include<stdlib.h>
%}

%token ID OPEN CLOSE
%left PLUS MINUS
%left MUL DIV
%start E

%%
E : E PLUS E 	{printf("E->E+E\n");}
	|
	E MINUS E 	{printf("E->E-E\n");}
	|
	E MUL E 	{printf("E->E*E\n");}
	|
	E DIV E 	{printf("E->E/E\n");}
	|
	OPEN E CLOSE {printf("E->(E)\n");}
	|
	ID			{printf("E->ID\n");};
%%

int yyerror()
{
	printf("Parse Error\n");
	exit(0);
}