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

int n, m, ans;
vector<vi> adj;
bool vis[5000];

void dfs(int node, int k){
    if(vis[node]) return;
    for(auto y: adj[node])
}


int main()
{
    // setIO("mootube");
    //not solved
    cin >> n >> m;
    adj = vector<vi> (n, vi(n));
    forn(i, 0, n-1){
        int a,b,c;
        cin>>a>>b>>c;
        adj[--a][--b]=c;
        adj[b][a]= c;
    }

    forn(i, 0, m-1){
        int k ,v;
        cin>>k>>v;
        vis[v] = true;
        ans = 0;
        dfs(v, k);
    }
}