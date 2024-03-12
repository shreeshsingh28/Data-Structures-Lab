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

    void intopr(char infix[], char prfix[])
    {
        strrev(infix);
        char c1, c2;
        int p = 0;
        for (int i = 0; infix[i] != '\0'; i++)
        {
            c1 = infix[i];

            switch (c1)
            {
            case ')':
                push(c1);
                break;

            case '(':
                c2 = pop();
                while (c2 != ')')
                {
                    prfix[p++] = c2;
                    c2 = pop();
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                if (!(isempty()))
                {
                    c2 = pop();

                    if (pre(c1) > pre(c2))
                    {
                        push(c2);
                    }

                    while (pre(c2) >= pre(c1))
                    {
                        prfix[p++] = c2;

                        if (!(isempty()))
                        {
                            c2 = pop();
                        }
                        else
                            break;
                    }
                }
                push(c1);
                break;
            default:
                prfix[p++] = c1;
                break;
            }
        }

        while (!(isempty()))
        {
            prfix[p++] = pop();
        }

        prfix[p] = '\0';

        strrev(prfix);

        cout << "prefix exp- " << prfix;
    }
};

int main()
{
    char infix[100], prfix[100];
    cout << "enter exp- ";
    cin >> infix;
    stk ob;
    ob.intopr(infix, prfix);
}