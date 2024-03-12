#include <iostream>
using namespace std;

class node
{
    int info;
    node *next;

public:
    node *in_end(node *head)
    {
        node *temp = new node;
        cout << "enter info- ";
        cin >> temp->info;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            return head;
        }
        else
        {
            node *t;
            for (t = head; t->next != NULL; t = t->next)
            {
            }

            t->next = temp;
            return head;
        }
    }

    void print(node *head)
    {
        if (head == NULL)
        {
            cout << "list empty";
            return;
        }
        for (node *t = head; t != NULL; t = t->next)
        {
            cout << t->info << "\n";
        }
    }

    node *in_beg(node *head)
    {
        node *temp = new node;
        cout << "enter info- ";
        cin >> temp->info;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            return head;
        }
        else
        {
            temp->next = head;
            head = temp;
            return head;
        }
    }

    node *in_pos(node *head)
    {
        node *temp = new node;
        cout << "enter info- ";
        cin >> temp->info;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            return head;
        }

        cout << "enter position";
        int pos;
        cin >> pos;

        node *t = head;
        for (int i = 1; i < pos-1; i++)
        {
            t = t->next;
        }

        temp->next = t->next;
        t->next = temp;
        return head;
    }

    node *in_after(node *head)
    {
        node *temp = new node;
        cout << "enter info- ";
        cin >> temp->info;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            return head;
        }

        cout << "enter ele to insert after- ";
        int ele;
        cin >> ele;

        node *t = head;
        while (t->info != ele && t != NULL)
        {
            t = t->next;
        }

        temp->next = t->next;
        t->next = temp;
        return head;
    }

    node *del_beg(node *head)
    {
        if (head == NULL)
        {
            cout << "nothing to delete";
            return head;
        }

        node *t = head;
        head = head->next;
        cout << "deleted- " << t->info;
        delete t;
        return head;
    }

    node *del_end(node *head)
    {
        if (head == NULL)
        {
            cout << "nothing to delete";
            return head;
        }

        node *cur = head;
        node *pre;

        while (cur != NULL)
        {
            pre = cur;
            cur = cur->next;
        }

        pre->next = NULL;
        cout << "deleted- " << cur->info;
        delete cur;
        return head;
    }

    node *del_given(node *head)
    {
        if (head == NULL)
        {
            cout << "nothing to delete";
            return head;
        }

        cout << "enter ele to search and delete- ";
        int ele;
        cin >> ele;

        node *cur = head;
        node *pre;

        while (cur->info != ele && cur != NULL)
        {
            pre = cur;
            cur = cur->next;
        }

        if (cur == head)
        {
            head = head->next;
            cout << "deleted- " << cur->info;
            delete cur;
            delete pre;
            return head;
        }
        else if (cur == NULL)
        {
            pre->next = NULL;
            cout << "deleted- " << cur->info;
            delete cur;
            return head;
        }
        else
        {
            pre->next = cur->next;
            cout << "deleted- " << cur->info;
            delete cur;
            return head;
        }
    }

    node *swa(node *head,int a,int b)
    {
        node *curra=head;
        node *prea= head;
        node *currb=head;
        node *preb=head;

        while (curra->info!=a)
        {
            prea=curra;
            curra=curra->next;
        }
        while (currb->info!=b)
        {
            preb=currb;
            currb=currb->next;
        }

        if (curra==head)
        {
            preb->next=head;
            node *temp = currb->next;
            currb->next=head->next;
            head->next=temp;

            head = currb;
        }
        else if(currb == head)
        {
            prea->next=head;
            node *temp = curra->next;
            curra->next=head->next;
            head->next=temp;

            head = curra;
        }
        else
        {
            /* code */
        }
        
        

        return head;
    }
};

int main()
{
    node *head = NULL;
    node ob;

    head = ob.in_end(head);
    head = ob.in_end(head);
    head = ob.in_end(head);
    head = ob.in_end(head);
    head = ob.in_end(head);
    head = ob.in_end(head);
    ob.print(head);
    cout<<"\n";

    head = ob.swa(head,10,20);
    ob.print(head);
    //head = ob.in_pos(head);
    //ob.print(head);
    //head = ob.in_after(head);
    //ob.print(head);
    //head = ob.del_beg(head);
    //ob.print(head);
    //head = ob.del_end(head);
    //ob.print(head);
    //head = ob.del_given(head);
}