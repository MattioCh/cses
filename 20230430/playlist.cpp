#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;

#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define F first
#define S second
#define pb push_back

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

    int n;cin>>n;
    map<int, int> m;
    vi arr(n);
    forn(i, 0,n-1){
        cin>>arr[i];
    }
    
    int j=0,i=0, cur_len=0,max_len=0;

    while(j<n){
        if(m.find(arr[j]) == m.end() || m[arr[j]] == 0){
            m[arr[j]] ++;
            cur_len++;
            max_len = max(max_len, cur_len);
            j++;
        }else{
            cur_len--;
            m[arr[i]]--;
            i++;
        }
    }

    cout<<max_len;
    
}