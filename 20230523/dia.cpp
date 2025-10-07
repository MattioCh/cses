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

vi adj[N];
int dist[2][200000];

int dfs(int u, int p, int d, int i){
    dist[i][u] = d;
    int opt = -1;
    for(auto v : adj[u]){
        if(v!=p){
            int x = dfs(v, u, d+1, i);
            if(opt == -1 || dist[i][x] > dist[i][opt]) opt = x;
        }
    }
    
    return opt == -1?u:opt;
}

int main()
{
    // setIO("mootube");
    //not solved
    int n,u,v;
    cin>>n;
    forn(i, 0,n-2){
        cin>>u>>v;
        adj[--u].pb(--v);
        adj[v].pb(u);
    }

    int mxnode = dfs(0 ,0 ,0 ,0);

    
}