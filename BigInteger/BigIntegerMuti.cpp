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
        a.push_back(s[sl - i - 1] - '0');
    }
    s.clear();
    cin >> s;
    sl = s.length();
    for (int i = 0; i < sl; i++)
    {
        b.push_back(s[sl - i - 1] - '0');
    }
    int al = a.size();
    int bl = b.size();
    vector<int> ans(al + bl);
    for (int i = 0; i < al; i++)
    {
        for (int j = 0; j < bl; j++)
        {
            ans[i + j] += a[i] * b[j];
        }
    }
    int ansl = ans.size();
    for (int i = 0; i < ansl; i++)
    {
        if (ans[i] >= 10)
        {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }
    bool start = false;
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