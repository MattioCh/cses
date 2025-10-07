#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <utility>
#include <queue>
#include <unordered_map>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<ll> vi;

const int N = 2e6 + 1;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

ll MOD = 7;

void setIO(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (!name.empty())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

vector<string> grid;
vector<vi> visited;
int n;

// {area, peri}
vector<int> dfs(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= n)
        return {0, 1};
    if (grid[i][j] == '.')
        return {0, 1};
    if (visited[i][j])
        return {0, 0};
    visited[i][j] = 1;
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    vector<int> output = {1, 0}, temp;

    forn(k, 0, 3)
    {
        temp = dfs(i + dx[k], j + dy[k]);
        output[0] = output[0] + temp[0];
        output[1] = output[1] + temp[1];
    }

    return output;
}

int main()
{
    setIO("perimeter");
    cin >> n;
    grid = vector<string>(n);
    visited = vector<vi>(n, vi(n));

    forn(i, 0, n - 1)
    {
        cin >> grid[i];
    }

    vector<int> area_peri = {0, N}, last = {0, N};
    forn(i, 0, n - 1)
    {
        forn(j, 0, n - 1)
        {
            if (!visited[i][j] && grid[i][j] == '#')
            {
                vector<int> temp = dfs(i, j);
                if (area_peri[0] <= temp[0])
                {
                    if (area_peri[0] == temp[0])
                    {
                        area_peri[0] = temp[0];
                        area_peri[1] = min(area_peri[1], temp[1]);
                    }
                    else
                    {
                        area_peri[0] = temp[0];
                        area_peri[1] = temp[1];
                    }
                }
            }
        }
    }

    cout << area_peri[0] << " " << area_peri[1] << endl;
}