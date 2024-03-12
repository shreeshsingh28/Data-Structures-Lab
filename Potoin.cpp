#include <iostream>
#include <string.h>
using namespace std;

class stk
{
    char arr[100][100];
    int top = -1;

public:
    void push(char ele[])
    {
        if (top == 99)
        {
            cout << "stk overflow ";
        }

        strcpy(arr[++top], ele);
    }

    char *pop()
    {
        if (top == -1)
        {
            cout << "stk underflow ";
        }

        return arr[top--];
    }

    int isop(char c)
    {
        if (c == '+' || c == '-' || c == '*' || c == '/')
            return 1;
        else
            return 0;
    }

    char *potoin(char pofix[])
    {
        char sym[2];
        char op1[100];
        char op2[100];
        char res[100];

        for (int i = 0; pofix[i] != '\0'; i++)
        {
            sym[0] = pofix[i];
            sym[1] = '\0';

            if (isop(pofix[i]))
            {
                strcpy(op2, pop());
                strcpy(op1, pop());

                strcpy(res, "(");
                strcat(res, op1);
                strcat(res, sym);
                strcat(res, op2);
                strcat(res, ")");

                push(res);
            }
            else
            {
                push(sym);
            }
        }

        return pop();
    }
};

int main()
{
    char pofix[100];
    cout << "enter exp- ";
    cin >> pofix;

    stk ob;
    cout << "infix exp- " << ob.potoin(pofix);
}