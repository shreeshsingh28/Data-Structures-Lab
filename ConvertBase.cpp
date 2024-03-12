#include <iostream>
using namespace std;

class stk
{
    int arr[100];
    int top;

public:
    stk()
    {
        top = -1;
    }
    void push(int ele)
    {
        if (top == 100 - 1)
        {
            cout << "stack is full";
            return;
        }
        arr[++top] = ele;
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "stack is empty";
            return 101;
        }
        return arr[top--];
    }
    void display()
    {
        for (int i = top; i > -1; i--)
        {
            int a = pop();
            if (a < 10)
                cout << a;
            else
            {
                switch (a)
                {
                case 10: cout<<'A';
                    break;
                case 11: cout<<'B';
                    break;
                case 12: cout<<'C';
                    break;
                case 13: cout<<'D';
                    break;
                case 14: cout<<'E';
                    break;
                case 15: cout<<'F';
                    break;
                }
            }
        }
    }
};

int main()
{
    stk ob;
    int num;
    cin>>num;
    int rem;
    int b;
    cin>>b;

    while (num!=0)
    {
        rem=num%b;
        ob.push(rem);
        num=num/b;
    }
    ob.display();
    
}