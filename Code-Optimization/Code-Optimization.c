#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct Quadruple 	//structure for each quadruple
{
	char res[10];	//Result
	char op1[10];	//operand 1
	char op2[10];	//operand 2
	char opr[1];		//operator
};


void print_Quadruples(struct Quadruple q[], int n) 	// print TAC as quadruples
{
	int i;
	printf("\nIndex\t\tOperator\t\tOperand1\t\tOperand2\t\tResult\n");
	printf("----------------------------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		if(strcmp(q[i].op2, "Nan")==0)  	//Nan for operand2 (for assignment statement)
			printf("%d\t\t=\t\t\t%s\t\t\tNan\t\t\t%s\n", i+1, q[i].op1, q[i].res);
		else
			printf("%d\t\t%c\t\t\t%s\t\t\t%s\t\t\t%s\n", i+1, q[i].opr[0], q[i].op1, q[i].op2, q[i].res);
	}
}

int isNumber(char* str)	//to check if a string is a number of not
{
	int i;
	for(i=0;i<strlen(str);i++)
	{
		if(!(isdigit(str[i])))
			return 0;	//false
	}
	return 1;	//true
}

void constantFolding(struct Quadruple q[], int n)	//constant folding of input TAC
{
	int i, op1, op2, res;
	for(i=0;i<n;i++)
	{
		if(isNumber(q[i].op1) && isNumber(q[i].op2))	//if both operands are numbers perform folding else do nothing
		{
			sscanf(q[i].op1, "%d", &op1); //op1 = (int)q[i].op1
			sscanf(q[i].op2, "%d", &op2);
			switch(q[i].opr[0])
			{
				case '+':
				{
					res = op1 + op2;
					break;
				}
				case '-':
				{
					res = op1 - op2;
					break;
				}
				case '*':
				{
					res = op1 * op2;
					break;
				}
				case '/':
				{
					res = op1 / op2;
					break;
				}
			}
			sprintf(q[i].op1, "%d", res); //copy result value to operand1
			strcpy(q[i].op2, "Nan"); //after constant folding, operand 2 is Nan
		}
	}
}

void input_Quadruples(struct Quadruple q[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nQuadruple %d :\n", i+1);
		printf("--------------\n");
		
		printf("Result : ");
		scanf("%s", q[i].res);
		
		printf("Operand 1 : ");
		scanf("%s", q[i].op1);
		
		printf("Operator : ");
		scanf("%s", q[i].opr);
		
		printf("Operand 2 : ");
		scanf("%s", q[i].op2);
	}
}


void main()
{
	int n, i;
	struct Quadruple q[20];
	
	printf("Enter number of Quadruples : ");
	scanf("%d", &n);
	
	input_Quadruples(q, n);
	
	printf("\nQuadruples :\n");
	printf("--------------\n");
	print_Quadruples(q, n);
	
	printf("\n\nAfter Constant Folding\n");
	printf("---------------------------\n");
	constantFolding(q, n);
	print_Quadruples(q, n);
}