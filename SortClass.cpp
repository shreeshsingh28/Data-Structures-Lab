#include<iostream>
#include<string.h>
using namespace std;

class Student
{
    int roll;
    char name[100];
    char grade;

    public:

    void getdata()
    {
        cin>>roll;
        cin>>grade;
        fflush(stdin);
        gets(name);
    }

    void putdata()
    {
        cout<<roll<<"   "<<name<<"  "<<grade<<"\n";
    }

    void sort(Student a[],int n)
    {
        for (int i = 0; i < n-1; i++)
        {
            for (int j = 0; j < n-i-1; j++)
            {
                Student temp;
                if (a[i].roll>a[i+1].roll)
                {
                    temp=a[i];
                    a[i]=a[i+1];
                    a[i+1]=temp;
                }
                
            }
            
        }
        

    }
};

int main()
{
    
}