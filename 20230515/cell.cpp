#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <utility>
#include <queue>
#include<unordered_map>

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


int main()
{
    // setIO("div7");
    // dfs? dynamic programming, what am I missing?
    // ans: nothing special, sort it, if the cur sum+1 is smaller than next number

    int n, k; cin>>n>>k;
    vi cities(n);
    set<int> towers;
    forn(i, 0, n-1){
        cin>>cities[i];
    }

    forn(i, 0 , k-1){
        int a;cin>>a;
        towers.insert(a);
    }

    ll r = 0;
    forn(i, 0 , n-1){
        ll dist = 2e9;
        auto rightmost = towers.lower_bound(cities[i]);
        if(rightmost != towers.end()){
            dist = *rightmost - cities[i];
        }

        if(rightmost != towers.begin()){
            rightmost--;
            dist = min(dist, cities[i] - *rightmost);
        }

        r = max(r, dist);
    }

    cout<<r<<endl;

}