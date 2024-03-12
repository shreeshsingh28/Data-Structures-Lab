#include <iostream>
#include <string.h>
using namespace std;

class node
{
    int info;
    node *lcl;
    node *rcl;

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

    class que
    {
        node *arr[100];
        int re= -1;
        int fr=-1;

        public :

        void enque(node *t)
        {
            if (re==99)
            {
                cout<<"que overflow";
                return;
            }
            arr[++re]=t;
        } 

        node *deque()
        {
            return arr[++fr];
        }

        int isempty()
        {
            if(re==fr)
                return 1;
            else
                return 0;
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

    void levelorder(node *root)
    {
        node *curr = root;
        que ob;

        ob.enque(curr);
        while (!ob.isempty())
        {
            curr =ob.deque();
            cout<<curr->info<<" ";

            if(curr->lcl!=NULL)
                ob.enque(curr->lcl);
            if(curr->rcl!=NULL)
                ob.enque(curr->rcl);
        }
        
    }

    void inorderstk(node *root)
    {
        stk ob;
        node *curr = root;
        while (1)
        {
            for (; root != NULL; root = root->lcl)
            {
                ob.push(root);
            }

            root = ob.pop();

            if (root==NULL)
                break;

            cout << root->info << " ";
            root = root->rcl;
        }
    }
    void preorderstk(node *root)
    {
        stk ob;
        while (1)
        {
            for (; root != NULL; root = root->lcl)
            {
                cout << root->info << " ";
                ob.push(root);
            }
            root = ob.pop();
            if (root == NULL)
                break;

            root = root->rcl;
        }
    }

    void postorderstk(node *root)
    {
        stk ob;
        int cnt=0;
        do
        {
            while (root != NULL)
            {
                if (root->rcl != NULL)
                    ob.push(root->rcl);
                ob.push(root);
                root = root->lcl;
            }
            root = ob.pop();
            if (root->rcl != NULL && root->rcl == ob.peek())
            {
                ob.pop();
                ob.push(root);
                root = root->rcl;
            }
            else
            {
                
                if (root->rcl == NULL && root->lcl == NULL)
            {
                cnt++;
            }
                root = NULL;
            }

        } while (!ob.isEmpty());
        cout<<cnt;
    }

    void findparent(node *root, int ele, int par)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->info == ele)
        {
            cout << "parent is- " << par;
        }
        else
        {
            findparent(root->lcl, ele, root->info);
            findparent(root->rcl, ele, root->info);
        }
    }

    void leafnodes(node *root)
    {
        stk ob;
        int cnt=0;
        while (1)
        {
            for (; root != NULL; root = root->lcl)
            {
                ob.push(root);
            }

            root = ob.pop();

            if (!root)
                break;

            if (root->rcl == NULL && root->lcl == NULL)
            {
                cnt++;
            }

            root = root->rcl;
        }
        cout << cnt;
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

        cout << "\n";
        ob.levelorder(root);
    }