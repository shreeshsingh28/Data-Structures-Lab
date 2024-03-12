#include <iostream>
using namespace std;

class stk
{
    int top;
    int arr[5];

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
        if (top == 5-1)
            return 1;
        else
            return 0;
    }
    void push(int ele)
    {
        if(isfull())
        {
            cout<<"stk overflow";
            return;
        }
        arr[++top]=ele;
    }
    void pop()
    {
        if(isempty())
        {
            cout<<"stk underflow";
            return;
        }
        cout<<"deleted ele- "<<arr[top--]<<"\n";
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
    stk ob;

    cout<<"no of ele to enter-";
    int n;
    cin>>n;
    int ele;

    cout<<"eneter ele-";
    for (int i = 0; i < n; i++)
    {
        cin>>ele;
        ob.push(ele);
    }

    ob.display();

    cout<<"no to delete-";
    int m;
    cin>>m;

    for (int i = 0; i < m; i++)
    {
        ob.pop();
    }
    ob.display();
    
    
}