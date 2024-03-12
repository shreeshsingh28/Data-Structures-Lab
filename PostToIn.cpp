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
        if (top >= 100 - 1)
            cout << "\nStack Overflow.";
        else
            strcpy(arr[++top], ele);
    }

    char * pop()
    {
        if (top == -1)
        {
            cout << "stack underflow\n";
        }
        return arr[top--];
    }

    int is_operator(char symbol)
    {
        if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    char* convert(char postfix[])
    {
        char sym[2];
        char op1[100];
        char op2[100];
        char res[100];
        for (int i = 0; postfix[i] != '\0'; i++)
        {
            sym[0] = postfix[i];
            sym[1] = '\0';

            if (is_operator(postfix[i]))
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
                push(sym);
        }
        return pop();
    }
};

int main()
{
    char exp[100];
    cout<<"enter posfix exp- ";
    gets(exp);

    stk ob;
    cout<<"infix exp is- ";
    puts(ob.convert(exp));
}
