#include <iostream>
#include <string.h>
using namespace std;

class node
{
    int info;
    node *rcl;
    node *lcl;

public:
    class stk
    {
        node *arr[100];
        int top = -1;

    public:
        void push(node *t)
        {
            arr[++top] = t;
        }

        node *pop()
        {
            return arr[top--];
        }

        int isEmpty()
        {
            if (top == -1)
                return 1;
            else
                return 0;
        }
        node *peek()
        {
            return arr[top];
        }
    };

    node *createtree(node *root)
    {
        node *temp = new node;
        cout << "enter data- ";
        cin >> temp->info;
        temp->rcl = NULL;
        temp->lcl = NULL;

        if (root == NULL)
        {
            root = temp;
            return root;
        }

        node *curr = root;
        node *pre = NULL;
        char d[10];
        cout << "enter path- ";
        cin >> d;

        int i;
        for (i = 0; i < strlen(d); i++)
        {
            if (curr == NULL)
                break;
            pre = curr;

            if (d[i] == 'L')
                curr = curr->lcl;
            else
                curr = curr->rcl;
        }
        if (curr != NULL || i != strlen(d))
        {
            cout << "error";
            delete temp;
            return root;
        }
        if (d[i - 1] == 'L')
            pre->lcl = temp;
        else
            pre->rcl = temp;

        return root;
    }

    void leaf(node *root)
    {
        if (root == NULL)
            return;
        stk S;
        int cnt = 0;
        node *curr = root;
        while (curr != NULL || !S.isEmpty())
        {
            while (curr != NULL)
            {
                S.push(curr);
                curr = curr->lcl;
            }
            curr = S.peek();
            S.pop();
            if (curr->lcl==NULL && curr->rcl==NULL)
            {
                cnt++;
            }
            
            curr = curr->rcl;
        }
        cout << cnt;
    }

    void display(node *root, int lev)
    {
        if (root == NULL)
        {
            return;
        }
        display(root->rcl, lev + 1);

        for (int i = 0; i < lev; i++)
        {
            cout << "   ";
        }
        cout << root->info << endl;

        display(root->lcl, lev + 1);
    }

    void leaf(node *root)
    {

    }


};

int main()
{
    node *root = NULL;
    node ob;

    for (int i = 0; i < 5; i++)
    {
        root = ob.createtree(root);
    }

    ob.parent(root,40);
}