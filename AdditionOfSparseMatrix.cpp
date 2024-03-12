#include <iostream>
using namespace std;

class spm
{
    int r, c, v;

public:
    void read(spm a[])
    {
        cout << "enter dimenssion-";
        int m, n, ele, k = 1;
        cin >> m >> n;
        cout << "enter ele-";

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> ele;

                if (ele == 0)
                    continue;

                a[k].r = i;
                a[k].c = j;
                a[k].v = ele;
                k++;
            }
        }
        a[0].r = m;
        a[0].c = n;
        a[0].v = k - 1;
    }

    void display(spm a[])
    {
        cout << "index "
             << "row "
             << "col "
             << "val\n";

        for (int i = 0; i <= a[0].v; i++)
        {
            cout << "  " << i << "    " << a[i].r << "   " << a[i].c << "   " << a[i].v << "\n";
        }
    }

    void add(spm a[], spm b[], spm c[])
    {
        int k = 1, k1 = 1, k2 = 1;

        for (int i = 0; i < a[0].r; i++)
        {
            for (int j = 0; j < a[0].c; j++)
            {
                if (((a[k1].r == i) && (a[k1].c == j)) && ((b[k2].r == i) && (b[k2].c == j)))
                {
                    c[k].r = i;
                    c[k].c = j;
                    c[k].v = a[k1].v + b[k2].v;
                    k++;
                    k1++;
                    k2++;
                }
                else if (b[k2].r == i && b[k2].c == j)
                {
                    c[k].r = i;
                    c[k].c = j;
                    c[k].v = b[k2].v;
                    k++;
                    k2++;
                }
                else if (a[k1].r == i && a[k1].c == j)
                {
                    c[k].r = i;
                    c[k].c = j;
                    c[k].v = a[k1].v;
                    k++;
                    k1++;
                }
            }
        }
        c[0].r=a[0].r;
        c[0].c=a[0].c;
        c[0].v=k-1;
    }
};

int main()
{
    spm a[100], b[100], c[100];
    spm ob;
    ob.read(a);
    ob.read(b);
    ob.display(a);
    ob.display(b);
    ob.add(a, b, c);
    ob.display(c);
}