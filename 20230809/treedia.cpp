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



vector<vi> v;
int furthest = -1;
int dist[2000006];


void dfs(int u, int p){
    for(auto a : v[u]){
        if (a == p) continue;
        dist[a] = dist[u] + 1;
        if(dist[a] > dist[furthest]) furthest = a;
        dfs(a, u);
    }
}

int main()
{
    string name = "";
    // setIO(name);
    //not solved

    int n;
    cin>>n;
    // if(n==1){
    //     cout<<0<<endl;
    //     return 0;
    // }
    v= vector<vi> (n);
    forn(i, 0,n-2){
        int a,b;
        cin>>a>>b;
        v[--a].pb(--b);
        v[b].pb(a);
    }
    dfs(0, -1);
dist[furthest] = 0;
    dfs(furthest, -1);

    cout<<dist[furthest]<<endl;


}