/* 
*
*	Program: To find if a mathematical expression is valid or not.
* 	Author:	Kusal Bista
* 	Date: 07/12/2016
*   Ref: Data Structure using C and C++, 
*/

#include <stdio.h>
#include <string.h>
#define max 100

typedef struct{
	int top;
	char items[max];
}stack;

//Main Function
void push(stack *,char);
char pop(stack*);
char opening(char);
int main()
{
	char a[max],p,d;
	stack s;
	s.top=-1;
	int i, n,valid=1;
	
	printf("Enter the equation:\n");
	scanf("%s",&a);
	n=strlen(a);

	for(i=0;i<n;i++)
	{
		if(a[i]=='(' || a[i]=='{' || a[i]=='[')
		{
			push(&s,a[i]);
		}
		if (a[i]==')' || a[i]=='}' || a[i]==']')
		{	
			if(s.top==-1)
			{
			valid=0;
			}
			
			else
			{
			p=pop(&s);
			d=opening(a[i]);
			
			
			if(p!=d)
			{
			valid=0;
			}
			}
		
		}
		
	}
	
if(!(s.top==-1))
{
	valid=0;
}

if(valid==1)
{
	printf("GIVEN EXPRESSION IS VALID");
}

else
{
	printf("GIVEN EXPRESSION IS INVALID");
}
}
//To execute push operation
void push(stack *s, char x)
{
	s->items[++(s->top)]=x;
}
//To execute pop operation
char pop(stack *s)
{
	return s->items[(s->top)--];
}
//To match the oprning with closing
char opening(char c)
{
	if(c==')')
	{
		return'(';
	}
	else if(c=='}')
	{
		return'{';
	}
	else if(c==']')
	{
		return'[';
	}
}

