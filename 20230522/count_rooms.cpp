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
int n, m;

void dfs(int i , int j){
    if(i<0||i>=n||j<0||j>=m) return;
    if(grid[i][j] == '#') return;
    if(visited[i][j]) return;
    visited[i][j] = 1;

    dfs(i, j+1);
    dfs(i, j-1);
    dfs(i+1, j);
    dfs(i-1, j);
}

int main()
{
    // setIO("moocast");
    cin>>n>>m;
    grid = vector<string> (n);
    visited = vector<vi> (n, vi(m));

    forn(i , 0, n-1){
        cin>>grid[i];
    }
    ll ans = 0;
    forn(i , 0, n-1){
        forn(j, 0, m-1){
            if(!visited[i][j] && grid[i][j] == '.'){
                dfs(i, j);
                ans++;
            }
        }
    }

    cout<<ans<<endl;
}