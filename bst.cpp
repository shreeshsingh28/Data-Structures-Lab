#include <iostream>
using namespace std;

class node
{
    int info;
    node *rcl;
    node *lcl;

public:
    node *insert(node *root)
    {
        node *temp = new node;
        cout << "enter data- ";
        cin >> temp->info;
        temp->lcl = NULL;
        temp->rcl = NULL;
        if (root == NULL)
        {
            return temp;
        }
        node *curr = root;
        node *pre = NULL;

        while (curr != NULL)
        {
            pre = curr;
            if (temp->info == curr->info)
            {
                cout << "duplicate not allowed";
                delete temp;
                return root;
            }

            if (temp->info < curr->info)
                curr = curr->lcl;
            else
                curr = curr->rcl;
        }
        if (temp->info < pre->info)
            pre->lcl = temp;
        else
            pre->rcl = temp;
        return root;
    }

    void inorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->lcl);
        cout << root->info << " ";
        inorder(root->rcl);
    }

    void del(node *root, int ele)
    {
        node *par, *curr, *succ;
        node *q = root;

        while (q != NULL)
        {
            if (q->info == ele)
            {
                curr = q;
                break;
            }
            par = q;
            if (q->info < ele)
                q = q->lcl;
            else
                q = q->rcl;
        }

        if (curr->lcl != NULL && curr->rcl != NULL)
        {
            par = curr;
            succ = curr->rcl;

            while (succ->lcl != NULL)
            {
                par = succ;
                succ = succ->lcl;
            }
            curr->info = succ->info;
            curr = succ;
        }
        if (curr->lcl == NULL && curr->rcl == NULL)
        {
            if (par->lcl == curr)
                par->lcl = NULL;
            else
                par->rcl = NULL;
            delete curr;
            return;
        }
        if (curr->lcl != NULL && curr->rcl == NULL)
        {
            if (par->lcl == curr)
                par->lcl = curr->lcl;
            else
                par->rcl = curr->lcl;
            delete curr;
            return;
        }
        if (curr->lcl == NULL && curr->rcl != NULL)
        {
            if (par->lcl == curr)
                par->lcl = curr->rcl;
            else
                par->rcl = curr->rcl;
            delete curr;
            return;
        }
    }
};

int main()
{
    node *root = NULL;
    node ob;
    for (int i = 0; i < 5; i++)
    {
        root = ob.insert(root);
    }
    ob.inorder(root);
    ob.del(root,20);
    cout<<"\n";
    ob.inorder(root);
}