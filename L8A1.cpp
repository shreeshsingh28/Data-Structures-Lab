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

    node *sort(node *head)
    {
        for (node *i = head; i != NULL; i = i->next)
        {
            for (node *j = i->next; j != NULL; j = j->next)
            {
                if (j->info < i->info)
                {
                    swap(j->info, i->info);
                }
            }
        }
        return head;
    }

    /*node *uni(node *h1, node *h2, node *h3)
    {
        sort(h1);
        sort(h2);
        while (h1 != NULL || h2 != NULL)
        {
            if (h1->info == h2->info)
            {
                h3 = in_end(h3, h1->info);
                h1 = h1->next;
                h2 = h2->next;
                continue;
            }
            else if (h2->info > h1->info)
            {
                h3 = in_end(h3, h1->info);
                h1 = h1->next;
                continue;
            }
            else
            {
                h3 = in_end(h3, h2->info);
                h2 = h2->next;
                continue;
            }

            if (h1 == NULL)
            {
                h3 = in_end(h3, h2->info);
                h2 = h2->next;
            }
            else
            {
                h3 = in_end(h3, h1->info);
                h1 = h1->next;
            }
        }

        return h3;
    }
*/
    node *merge(node *h1, node *h2)
    {
        node *t = h1;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = h2;
        h2->pre = t;
        return h1;
    }

    node *uni(node *h1, node *h2, node *h3)
    {
        h3 = merge(h1, h2);
        node *i = h3;
        while (i->next != NULL)
        {
            node *j = i->next;
            while (j->next != NULL)
            {
                if (i->info == j->info)
                {
                    j->pre->next = j->next;
                    j->next->pre = j->pre;
                    node *del = j;
                    j=j->pre;
                    delete del;
                }
                j = j->next;
            }
            i = i->next;
        }
        return h3;
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
    node *h1 = NULL;
    node *h2 = NULL;
    node *h3 = NULL;
    node ob;
    h1 = ob.in_end(h1, 1);
    h1 = ob.in_end(h1, 2);
    h1 = ob.in_end(h1, 3);
    h1 = ob.in_end(h1, 4);
    h1 = ob.in_end(h1, 5);
    h1 = ob.in_end(h1, 6);
    ob.display(h1);
    cout << "\n";
    h2 = ob.in_end(h2, 1);
    h2 = ob.in_end(h2, 2);
    h2 = ob.in_end(h2, 7);
    h2 = ob.in_end(h2, 8);
    ob.display(h2);
    cout << "\n";
    h3 = ob.uni(h1, h2, h3);
    ob.display(h3);
}
