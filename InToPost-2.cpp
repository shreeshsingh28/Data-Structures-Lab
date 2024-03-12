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

    void intopo(char infix[], char pofix[])
    {
        char c1, c2;
        int p = 0;
        for (int i = 0; infix[i] != '\0'; i++)
        {
            c1 = infix[i];

            switch (c1)
            {
            case '(':
                push(c1);
                break;

            case ')':
                c2 = pop();
                while (c2 != '(')
                {
                    pofix[p++] = c2;
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
                        pofix[p++] = c2;

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
                pofix[p++] = c1;
                break;
            }
        }

        while (!(isempty()))
        {
            pofix[p++] = pop();
        }

        pofix[p] = '\0';

        cout << "postfix exp- " << pofix;
    }
};

int main()
{
    char infix[100], pofix[100];
    cout << "enter exp- ";
    cin >> infix;
    stk ob;
    ob.intopo(infix, pofix);
}