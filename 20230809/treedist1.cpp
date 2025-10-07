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


vector<vi> adj;
int furthest = 0;
int fur1[200006];
int fur2[200006];
int opt1=0,opt2=0;
int dfs1(int u, int p){
    for(auto a: adj[u]){
        if(a == p) continue;
        fur1[a] = fur1[u] + 1;
        if(fur1[a] > fur1[opt1]) opt1 = a;
        dfs1(a, u);
    }
    return opt1;
}

int dfs2(int u, int p){
    for(auto a: adj[u]){
        if(a == p) continue;
        fur2[a] = fur2[u] + 1;
        if(fur2[a] > fur2[opt2]) opt2 = a;
        dfs2(a, u);
    }
    return opt2;
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
    adj = vector<vi> (n);
    forn(i, 0,n-2){
        int a,b;
        cin>>a>>b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }

    int max1 = dfs1(0, -1);
    forn(i, 0, n-1) fur1[i] =0;
    int max2 = dfs1(max1, -1);
    dfs2(max2, -1);
    
    forn(i, 0, n-1) cout<<max(fur1[i], fur2[i])<<" ";
    
}