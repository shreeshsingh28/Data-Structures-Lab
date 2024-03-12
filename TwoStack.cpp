#include <iostream>
using namespace std;

class stk
{
    int top1,top2;
    int arr[5];

public:
    stk()
    {
        top1 = -1;
        top2=5;
    }

    void push(int n,int ele)
    {
        if (n==1)
        {
            if (top2==top1+1)
            {
                cout<<"stack overflow";
                return;
            }
            arr[++top1]=ele;
            
        }
        if (n==2)
        {
            if (top2==top1+1)
            {
                cout<<"stack overflow";
                return;
            }
            arr[--top2]=ele;
        }
        
        
    }
    void pop(int n)
    {
        if (n==1)
        {
            if (top1==-1)
            {
                cout<<"stack underflow";
                return;
            }
            cout<<"deleted out of 1st- "<<arr[top1--];
            
        }
        if (n==2)
        {
            if (top2==5)
            {
                cout<<"stack underflow";
                return;
            }
            cout<<"deleted out of 2nd- "<<arr[top2++];
        }
        
    }
    void display(int n)
    {
        if (n==1)
        {
            if (top1==-1)
            {
                cout<<"stack underflow";
                return;
            }
            cout<<"stk1 is\n";
        for(int i=top1;i>=0;i--)
        {
            cout<<arr[i]<<"\n";
        }
            
            
        }
        if (n==2)
        {
            if (top2==5)
            {
                cout<<"stack underflow";
                return;
            }
        cout<<"stk2 is\n";
        for(int i=top2;i<5;i++)
        {
            cout<<arr[i]<<"\n";
        }
        }
        
        
    }
};
int main()
{
    stk ob;
    ob.push(1,1);
    ob.push(1,2);
    ob.push(1,3);
    ob.push(2,4);
    ob.push(2,5);
    ob.pop(2);
    ob.push(2,6);


    ob.display(1);
    ob.display(2);
}