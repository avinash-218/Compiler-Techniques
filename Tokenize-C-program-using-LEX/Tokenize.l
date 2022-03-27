%{
	#include<stdlib.h>
	FILE* fin;
	FILE* fout;
%}

%%
"int"|"float"|"if"|"else"|"for"|"while"|"include"|"return" {fprintf(fout, "%s is Keyword\n", yytext);}

([a-zA-Z]+).h 			{fprintf(fout, "%s is header file\n", yytext);}

"#" {fprintf(fout, "%s is stringize operator\n", yytext);}

"printf"|"main"				{fprintf(fout, "%s is In-built Function\n", yytext);}

\".*\"			{fprintf(fout, "%s is string constant\n", yytext);}

[a-zA-Z][0-9a-zA-Z]* {fprintf(fout, "%s is Identifier\n", yytext);}

"+"|"-"|"*"|"/"|"="|"=="|"++"|"--"	{fprintf(fout, "%s is an operator\n", yytext);}

[(){}|, ]							{fprintf(fout, "%s is an delimeter\n", yytext);}

\n 									{;}

.	{;}
%%

int main()
{
	fin = fopen("input.c", "r");
	fout = fopen("output.txt", "w");
	yyin = fin;
	yyout=fout;
	yylex();
}

int yywrap()
{
	return 1;
}