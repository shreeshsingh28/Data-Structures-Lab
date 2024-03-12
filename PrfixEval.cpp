#include <iostream>
#include<string.h>
using namespace std;

class stk
{
    char arr[100];
    int top = -1;

public:
    int isempty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }

    int isfull()
    {
        if (top == 99)
            return 1;
        else
            return 0;
    }

    void push(char ele)
    {
        if (isfull())
        {
            cout << "stk overflow";
            return;
        }

        arr[++top] = ele;
    }

    char pop()
    {
        if (isempty())
        {
            cout << "stk underflow";
            return 'e';
        }

        return arr[top--];
    }

    int pre(char c)
    {
        switch (c)
        {
        case '/':
            return 2;
            break;
        case '*':
            return 2;
            break;
        case '+':
            return 1;
            break;
        case '-':
            return 1;
            break;
        default:
            return 0;
            break;
        }
    }

    int cal(int a,char c,int b)
    {
        switch (c)
        {
        case '+': return (a+b);
            break;
        case '-': return (a-b);
            break;
        case '*': return (a*b);
            break;
        case '/': return (a/b);
            break;
        default: return 0;
            break;
        }
    }
    
    void prfixeval(char prfix[])
    {
        int op1,op2;
        strrev(prfix);
        for (int i = 0; prfix[i] != '\0'; i++)
        {
            if (prfix[i]=='+'||prfix[i]=='-'||prfix[i]=='*'||prfix[i]=='/')
            {
                op1=pop();
                op2=pop();
                push(cal(op1,prfix[i],op2));
            }
            else
            {
                push(prfix[i]-'0');
            }
        }
        int result = pop();
        cout<<"eval result is- "<<result;
    }
};

int main()
{
    char prfix[100];
    cout << "enter exp- ";
    cin >> prfix;
    stk ob;
    ob.prfixeval(prfix);
}