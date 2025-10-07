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

int n;
vector<vector<bool>> connected;
vector<bool> visited;

int dist_sq(pii x, pii y){
    int dx = x.F - y.F;
    int dy = x.S - y.S;
    
    return dx*dx + dy*dy;
}

int main()
{
    setIO("moocast");
    cin>>n;
    vector<pii> cows(n);
    forn(i, 0, n-1){
        int a,b;
        cin>>a>>b;
        cows[i] = {a,b};
    }
    // this is an interesting implementation;
    //not a very robust ways to get things done, but it works.
    //a better ways is to add a set? to check whether a number is in the spanning tree or not.

    vector<int> dist(n, N -1);
    dist[0] = 0;
    int m=0;

    forn(t, 0 , n-1){
        int i = min_element(all(dist)) - dist.begin();
        m = max(m , dist[i]);
        dist[i] = N;
        forn(j, 0, n-1){
            if(dist[j]!= N){
                dist[j] = min(dist[j], dist_sq(cows[i], cows[j]));
            }
        }
    }

    cout<<m<<endl;

    
}