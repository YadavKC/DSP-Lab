#include <stdio.h>
//#include <ctype.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 50

char stack[SIZE];
int top=-1;


int check_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}
void push(char item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}
char pop()
{
	char item ;

	if(top <0)
	{
		printf("UNDER FLOW: invalid infix expression");
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}
int precedence(char symbol)
{
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void PostfixConversion(char infix_exp[], char postfix_exp[])
{
	int i, j;
	char item;
	char x;

	push('(');
	strcat(infix_exp,")");

	i=0;
	j=0;
	item=infix_exp[i];

	while(item != '\0')
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item;
			j++;
		}
		else if(check_operator(item) == 1)
		{
			x=pop();
			while(check_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
			push(x);

			push(item);
		}
		else if(item == ')')
		{
			x = pop();
			while(x != '(')
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{
			printf("\nInfix Expression is not Valid .\n");
			exit(1);
		}
		i++;


		item = infix_exp[i];
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");
		exit(1);
	}
	if(top>0)
	{
		printf("\nInfix Expression is Invalid .\n");
		exit(1);
	}

    printf("\nInfix Expression is Valid .\n\n");


	postfix_exp[j] = '\0';

}


int main()
{
	char infix[SIZE], postfix[SIZE];
	printf("\nEnter Infix expression : ");
	//gets(infix);
	scanf("%s",infix);

	PostfixConversion(infix,postfix);
	printf("Postfix Expression: %s",postfix);

    InfixtoPrefix(infix);

	return 0;
}


void reverse(char *exp){

    int size = strlen(exp);
    int j = size, i=0;
    char temp[SIZE];

    temp[j--]='\0';
    while(exp[i]!='\0')
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp,temp);
}
void brackets(char* exp){
    int i = 0;
    while(exp[i]!='\0')
    {
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
        i++;
    }
}
void InfixtoPrefix(char *exp){

    int size = strlen(exp);
    char *postfx;

    reverse(exp);
    brackets(exp);
    PostfixConversion(exp, postfx);
    reverse(postfx);
    printf("%s",postfx);
}





