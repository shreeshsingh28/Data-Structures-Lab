#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str1[10], str2[10];
    gets(str1);
    gets(str2);

    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
    {
        if (str1[i] == str2[i])
        {
            cout << "equal";
            continue;
        }
        else
            cout << str1[i] - str2[i];
    }
}