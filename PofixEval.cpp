#include <iostream>
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
    
    void pofixeval(char pofix[])
    {
        int op1,op2;
        for (int i = 0; pofix[i] != '\0'; i++)
        {
            if (pofix[i]=='+'||pofix[i]=='-'||pofix[i]=='*'||pofix[i]=='/')
            {
                op2=pop();
                op1=pop();
                push(cal(op1,pofix[i],op2));
            }
            else
            {
                push(pofix[i]-'0');
            }
        }
        int result = pop();
        cout<<"eval result is- "<<result;
    }
};

int main()
{
    char pofix[100];
    cout << "enter exp- ";
    cin >> pofix;
    stk ob;
    ob.pofixeval(pofix);
}