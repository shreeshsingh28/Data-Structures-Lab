#include <iostream>
using namespace std;

class stk
{
    int arr[100];
    int top = -1;

public:
    void push(int ele)
    {
        if (top >= 100 - 1)
        {
            cout << "\nStack Overflow.";
            return;
        }
        else
            arr[++top] = ele;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "stack underflow\n";
            return 'e';
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

    int cal(int a, char ch, int b)
    {
        switch (ch)
        {
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '*':
            return a * b;
            break;
        case '/':
            return a / b;
            break;
        default:
            return 0;
            break;
        }
    }

    int PostEval(char postfix[])
    {
        int op1, op2, re;
        for (int i = 0; postfix[i] != '\0'; i++)
        {
            if (is_operator(postfix[i]) == 1)
            {
                op2 = pop();
                op1 = pop();

                re = cal(op1, postfix[i], op2);
                push(re);
            }
            else
            {
                push(postfix[i] - '0');
            }
        }
        return pop();
    }
};

int main()
{
    stk ob;
    char exp[100];
    cout << "enter postfix expression- ";
    gets(exp);

    int result = ob.PostEval(exp);
    cout << "evaluated result is- "<<result;

}