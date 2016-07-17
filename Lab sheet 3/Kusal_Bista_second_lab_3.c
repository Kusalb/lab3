/* 
*
*	Program: To evaluate a postfix expression.
* 	Author Kusal Bista
* 	Date: 07/14/2016
*   Ref: Data Structure using C and C++, 
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define max 100

typedef struct{
	int top;
	char items[max];
}stack;

//Main Function
void push(stack *, char);
int pop(stack *);
int isDigit(char),value;
int operation(char,int,int);

int main()
{
	char a[max];
	int i,opnd1,opnd2,n,w;
	stack s;
	
	printf("Enter the postfix expression:\n");
	scanf("%s",a);
	
	for(i=0;i<strlen(a);i++)
	{
		if(isDigit(a[i])==1)
		{
			push(&s,(int)(a[i]-'0'));
			printf("The pushed character is %c\n",a[i]);
		}
		
		else if(isDigit(a[i])==0)
		{
			opnd2=pop(&s);
			opnd1=pop(&s);
			printf("the popped characters are %d and %d\n",opnd1,opnd2);
			printf("the operator is %c\n",a[i]);
			value=operation(a[i],opnd1,opnd2);
			push(&s,value);
		}
		
	}
	printf("the value of the given postfix operation is %d",pop(&s));
}
//To execute push operation
void push(stack *s, char x)
{
	s->items[++(s->top)]=x;
}
//To execute pop operation
int pop(stack *s)
{
	int x;
	x=s->items[(s->top)--];
	return x;
	
}

int isDigit(char symb)
{
if(symb>='0' && symb<='9')
return 1;
else
return 0;
}
//To execute mathmatical
int operation(char op,int a,int b)
{
	
	switch(op){
		case '+' : return(a+b);
		break;		
		case '-' : return(a-b);
		break;
		case '*' : return(a*b);
		break;
		case '/' : return(a/b);
		break;
		case '$' : return(pow(a,b));	
		break;
		default  : printf("%s","Illegal operation");
		exit(1);
	}
}
