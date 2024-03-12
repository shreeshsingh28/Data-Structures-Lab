#include <iostream>
using namespace std;

class pali
{
    char arr[100];
    int top;

public:
    pali()
    {
        top = -1;
    }
    void push(char ele)
    {
        if (top==100-1)
        {
            cout<<"stack is full";
            return;
        }
        arr[++top]=ele;
    }
    char pop()
    {
        if (top==-1)
        {
            cout<<"stack is empty";
            return 'e';
        }
        return arr[top--];
        
    }
};

int main()
{
    char str[100];
    gets(str);
    pali ob;
    char temp;

    for (int i = 0; str[i] != '\0'; i++)
    {
        ob.push(str[i]);
    }
    for (int i = 0; str[i] != '\0'; i++)
    {
        temp = ob.pop();
        if (temp != str[i])
        {
            cout<<"not pali";
            return 101;
        }
    }
    cout<<"pali";
    
    
}