/* 
*
*	Program: To convert an infix expression to postfix.
* 	Author:	Kusal Bista
* 	Date: 07/12/2016
*   Ref: Data Structure using C and C++, 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max 100
//Creating Stack
typedef struct{
	int top;
	char items[max];
}stack;
//main Function
char push(stack *,char);
int pop(stack *);
int symbolValue(char);

int main()
{
	int i,p,k,b=0;
	char infix[max],a[max],y;
	stack s;
	s.top=-1;
	
	printf("enter the infix expression:\n");
	scanf("%s",&infix);
	
	for(i=0;i<=strlen(infix);i++)
	{
		if((infix[i]>='0' && infix[i]<='9') || (infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z'))
		{
			a[b++]=infix[i];
		}
		else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='$')
		{
			p=symbolValue(infix[i]);
			if(s.top==-1)
			{
				push(&s,infix[i]);
			}
			else if(!(s.top==-1))
			{
				y=pop(&s);
				push(&s,y);
				if(p>(k=symbolValue(y)))
				{
					push(&s,infix[i]);
				}
				else if(p<=(k=symbolValue(y)))
				{
					a[b++]=pop(&s);
					push(&s,infix[i]);
				}
			}	
		}
	}
	while(!(s.top==-1))
	{
		a[b++]=pop(&s);
	}
	printf("The postfix expression of given infix expression is: %s",a);
}

int symbolValue(char x)
{
	if(x=='+' || x=='-')
	{
		return 1;
	}
	else if(x=='*' || x=='/' || x=='%')
	{
		return 2;
	}
	else if(x=='$')
	{
		return 3;
	}
}
//Creating push function
char push(stack *s, char x)
{
	s->items[++(s->top)]=x;
}
//Creating pop function
int pop(stack *s)
{
	int x;
	x=s->items[(s->top)--];
	return x;
}

