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

    void transpose(spm a[], spm b[])
    {
        int k = 1;
        for (int i = 0; i < a[0].c; i++)
        {
            for (int j = 1; j <= a[0].v; j++)
            {
                if (i == a[j].c)
                {
                    b[k].r = a[j].c;
                    b[k].c = a[j].r;
                    b[k].v = a[j].v;
                    k++;
                }
            }
        }
        b[0].r = a[0].c;
        b[0].c = a[0].r;
        b[0].v = a[0].v;
    }
};

int main()
{
    spm a[100], b[100];
    spm ob;
    ob.read(a);
    ob.display(a);
    ob.transpose(a, b);
    cout << "\n";
    ob.display(b);
}