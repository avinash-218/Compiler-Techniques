%{
	#include<stdio.h>
	#include"y.tab.h"
%}
%%
[a-zA-z] {return ID;}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
"("	{return OPEN;}
")"	{return CLOSE;}
%%

int yywrap()
{
	return 1;
}