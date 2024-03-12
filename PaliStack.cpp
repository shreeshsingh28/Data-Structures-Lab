#include <iostream>
using namespace std;

class stk
{
    int top;
    char arr[100];

public:
    stk()
    {
        top = -1;
    }

    int isempty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }
    int isfull()
    {
        if (top == 100-1)
            return 1;
        else
            return 0;
    }
    void push(char ele)
    {
        if(isfull())
        {
            cout<<"stk overflow";
            return;
        }
        arr[++top]=ele;
    }
    char pop()
    {
        if(isempty())
        {
            cout<<"stk underflow";
            return 'e';
        }
        return arr[top--];
    }
    void display()
    {
        if(isempty())
        {
            cout<<"stk underflow";
            return;
        }
        
        cout<<"stk is\n";
        for(int i=top;i>=0;i--)
        {
            cout<<arr[i]<<"\n";
        }
    }
};

int main()
{
    cout<<"enetr string-";
    char str[100];
    gets(str);

    stk ob;

    for (int i = 0; str[i]!='\0'; i++)
    {
        ob.push(str[i]);
    }

    int flag=1;

    for (int i = 0; str[i] != '\0'; i++)
    {
        char c=ob.pop();

        if (c!=str[i])
        {
            flag=0;
            break;
        }
        
    }
    if (flag)
    {
        cout<<"pali";
    }
    else
    cout<<"not";
    
    
    
}

