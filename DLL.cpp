#include <iostream>
using namespace std;

class node
{
    int info;
    node *next;
    node *pre;

public:
    node *in_end(node *head, int ele)
    {
        node *temp = new node;
        temp->info = ele;
        temp->next = NULL;
        temp->pre = NULL;

        if (head == NULL)
        {
            head = temp;
            return head;
        }

        node *t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = temp;
        temp->pre = t;
        return head;
    }

    

    node *reverse(node *head)
    {
        if (head == NULL)
        {
            cout << "list empty";
            return head;
        }
        node *pre = NULL;
        node *next = NULL;
        node *curr = head;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = pre;
            curr->pre = next;
            pre = curr;
            curr = next;
        }
        return pre;
    }

    void display(node *head)
    {
        if (head == NULL)
        {
            cout << "list empty";
            return;
        }

        node *t = head;
        while (t != NULL)
        {
            cout << t->info << " ";
            t = t->next;
        }
    }
};

int main()
{
    node *head = NULL;
    node ob;
    head = ob.in_end(head, 10);
    head = ob.in_end(head, 20);
    head = ob.in_end(head, 30);
    head = ob.in_end(head, 40);
    ob.display(head);
    cout<<"\n";
    head = ob.reverse(head);
    ob.display(head);
}
