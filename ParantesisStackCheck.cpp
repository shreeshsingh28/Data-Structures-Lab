#include <iostream>
using namespace std;

class stk
{
    char arr[100];
    int top;

public:
    stk()
    {
        top = -1;
    }
    void push(char ele)
    {
        if (top == 100 - 1)
        {
            cout << "stack is full";
            return;
        }
        arr[++top] = ele;
    }
    char pop()
    {
        if (top == -1)
        {
            cout << "stack is empty";
            return 'e';
        }
        return arr[top--];
    }
};

int main()
{
    char str[100];
    gets(str);
    stk ob;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '[' || str[i] == '{' || str[i] == '(')
            ob.push(str[i]);
        else if (str[i] == ']')
        {
            char a = ob.pop();
            if (a != '[')
            {
                cout << "wrong exp";
                return 101;
            }
        }
        else if (str[i] == '}')
        {
            char a = ob.pop();
            if (a != '{')
            {
                cout << "wrong exp";
                return 101;
            }
        }
        else if (str[i] == ')')
        {
            char a = ob.pop();
            if (a != '(')
            {
                cout << "wrong exp";
                return 101;
            }
        }
        else
            continue;
    }
    cout<<"correct exp";
}