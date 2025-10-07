#include <iostream>
#include <vector>
#include <string>
#include <string.h>
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

int n, m;
vi adj[N][2];
bool visited[N];
bool impossible = false;


void dfs(int node, int dir)
{
    if(visited[node]) return;
    visited[node] = true;
    for(auto to: adj[node][dir]){
        dfs(to, dir);
    }
}

int main()
{
    setIO();
    //this is a fun problem, I need to think in reverse adj.
    //You have two conditions to meet. First one being I need to know whether it will at least meet all of them.
    //However, even if the condition is satisfied, that is tno end of the question
    //I also need to know if reverse backward, if all of the cities would be visteid.
    //the idea is not compilicated, whether the dfs of all coming in and out can help to travel all the city.

    cin >> n >> m;
    forn(i, 0, m - 1)
    {
        int a, b;
        cin >> a >> b;
        adj[--a][0].pb(b);
        adj[b][1].pb(a);
    }

    dfs(0 , 0);

    forn(i, 0, n-1){
        if(!visited[i]){
            cout<<"NO\n";
            cout<<1<<" "<<i+1<<endl;
            return 0;
        }
    }

    memset(visited, false, sizeof(visited));

    dfs(0, 1);

    forn(i ,0,n-1){
        if(!visited[i]){
            cout<<"NO\n";
            cout<<i+1<<" "<<1<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;
    
}