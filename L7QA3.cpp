#include <iostream>
using namespace std;

class node
{
    int info;
    node *next;

public:
    node *in_end(node *head, int ele)
    {
        node *temp = new node;
        temp->info = ele;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            return head;
        }
        else
        {
            node *t = head;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = temp;
            return head;
        }
    }

    node *merge(node *h1, node *h2)
    {
        int cnt1 = 0;
        int cnt2 = 0;
        node *t = h1;
        while (t != NULL)
        {
            cnt1++;
            t = t->next;
        }
        t = h2;
        while (t != NULL)
        {
            cnt2++;
            t = t->next;
        }
        if (cnt1 >= cnt2)
        {
            node *i = h1;
            node *j = h2;
            node *pre = NULL;
            while (i != NULL)
            {
                pre = j;
                j = j->next;
                pre->next = i->next;
                i->next = pre;
                if (j == NULL)
                {
                    break;
                }

                i = i->next;
                i = i->next;
            }
            return h1;
        }
        else
        {
            node *i = h1;
            node *j = h2;
            node *pre=NULL;
            while (i!=NULL)
            {
                pre=j;
                j=j->next;

                pre->next=i->next;
                i->next=pre;

                i=pre->next;
            }
            pre->next = j;
            return h1;
        }
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
    node *head1 = NULL;
    node *head2 = NULL;
    node *head3 = NULL;
    node ob;
    head1 = ob.in_end(head1, 10);
    head1 = ob.in_end(head1, 30);
    head1 = ob.in_end(head1, 20);
    head1 = ob.in_end(head1, 40);
    
    head2 = ob.in_end(head2, 100);
    head2 = ob.in_end(head2, 300);
    head2 = ob.in_end(head2, 200);
    head2 = ob.in_end(head2, 400);
    head2 = ob.in_end(head2, 500);
    ob.display(head1);
    cout << "\n";
    ob.display(head2);
    cout << "\n";
    head3 = ob.merge(head1, head2);
    ob.display(head3);
}
