
#include<iostream>
#include<string.h>
using namespace std;

class stk
{

char arr[100];
int top = -1;

public:

void push(char ele)
{
	if(top >= 100-1)
		cout<<"\nStack Overflow.";
	else
		arr[++top] = ele;
}


char pop()
    {
        if(top==-1)
        {
            cout<<"stack underflow\n";
            return 'e';
        }
        return arr[top--];
    }



int is_operator(char symbol)
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

void InfixToPrefix(char infix_exp[], char prefix_exp[])
{ 
	int i, j;
	char item;
	char x;

    strrev(infix_exp);

	push(')');                               
	strcat(infix_exp,"(");                  

	i=0;
	j=0;
	item=infix_exp[i];        

	while(item != '\0')        
	{
		if(item == ')')
		{
			push(item);
		}
		else if(item>='a' && item<='z')
		{
			prefix_exp[j] = item;             
			j++;
		}
		else if(is_operator(item) == 1)      
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				prefix_exp[j] = x;                  
				j++;
				x = pop();                      
			}
			push(x);

			push(item);                 
		}
		else if(item == '(')         
		{
			x = pop();                 
			while(x != ')')               
			{
				prefix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{ 
			cout<<"\nInvalid Expression.\n";        
			return;
		}
		
        i++;
		item = infix_exp[i]; 
    }
	if(top>0)
	{
		cout<<"\nInvalid Expression.\n";      
		return;
	}
	prefix_exp[j] = '\0';

    strrev(prefix_exp);

}
};


int main()
{
	char infix[100], prefix[100];
	cout<<"\nEnter Infix expression : ";
	gets(infix);
    stk ob;

	ob.InfixToPrefix(infix,prefix);                   
	cout<<"Prefix Expression: ";
	puts(prefix);                 

	return 0;
}
