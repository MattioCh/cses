#include <iostream>
#include <vector>
using namespace std;

vector<int> p, ans;
bool in_cycle = false;

void dfs(int n)
{
    if (ans[n] != -2)
    {
        if (ans[n] == -1)
        {
            in_cycle = true;
            ans[n] = n;
        }
        return;
    }

    ans[n] = -1;

    dfs(p[n]);

    if (ans[n] != -1)
    {
        in_cycle = false;
    }
    else
    {
        ans[n] = in_cycle ? n : ans[p[n]];
    }
}

int main()
{
    int n;
    cin >> n;
    p = vector<int>(n);
    ans = vector<int>(n, -2);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++)
    {
        dfs(i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 1;
}