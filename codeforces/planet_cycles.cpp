#include <iostream>
#include <vector>
using namespace std;

vector<int> p, ans, in_cycle;
bool in_cycle = false;

void dfs(int n){
    if(ans[n] != -2){
        if()
    }

    ans[n] = -1;
}


int main()
{
    int n;
    cin >> n;
    p = vector<int>(n);
    ans = vector<int>(n, -2);
    in_cycle = vector<int>(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << dfs(i) << " ";
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 1;
}