#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;
int main()
{
    vector<int> a;
    vector<int> b;
    string s;
    cin >> s;
    int sl = s.length();
    for (int i = 0; i < sl; i++)
    {
        a.push_back(s[sl - 1 - i] - '0');
    }
    cin >> s;
    sl = s.length();
    for (int i = 0; i < sl; i++)
    {
        b.push_back(s[sl - 1 - i] - '0');
    }
    int al = a.size();
    int bl = b.size();
    if (al < bl)
    {
        for (int i = 0; i < bl - al; i++)
        {
            a.push_back(0);
        }
    }
    else
    {
        for (int i = 0; i < al - bl; i++)
        {
            b.push_back(0);
        }
    }
    a.push_back(0);
    b.push_back(0);
    vector<int> ans(al);
    al = a.size();
    bl = b.size();
    for (int i = 0; i < al; i++)
    {
        ans[i] = a[i] + b[i];
    }
    for (int i = 0; i < al; i++)
    {
        if (ans[i] >= 10)
        {
            ans[i + 1] += 1;
            ans[i] -= 10;
        }
    }
    bool start = false;
    int ansl = ans.size();
    for (int i = ansl - 1; i >= 0; i--)
    {
        if (ans[i] != 0)
        {
            start = true;
        }
        if (start)
        {
            cout << ans[i];
        }
    }
    if (!start)
    {
        cout << 0;
    }
    cout << endl;
    system("pause");
    return 0;
}
