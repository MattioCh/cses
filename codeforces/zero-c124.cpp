#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <utility>
#include <queue>
#include <unordered_map>
#include <math.h>
#include <stack>

using namespace std;
const int MAXN = 1e6;
int L, R, C;
char adj[32][32][32];
int start_i, start_j, start_k;
int end_i, end_j, end_k;

void input()
{
    for (int i = L; i > 0; i--)
    {
        for (int j = 1; j <= R; j++)
        {
            string s;
            getline(cin, s);
            for (int k = 1; k <= C; k++)
            {
                adj[i][j][k] = s[k - 1];
                if (s[k - 1] = 'S')
                {
                    start_i = i;
                    start_j = j;
                    start_k = k;
                }
                if (s[k - 1] = 'E')
                {
                    _i = i;
                    start_j = j;
                    start_k = k;
                }
            }
        }
    }
    string blank;
    getline(cin, blank);
}

void solve()
{
    input();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (1)
    {
        cin >> L >> R >> C;
        if (!L || !R || !C)
        {
            break;
        }
        else
        {
            solve();
        }
    }
}