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



void solve(){
    int n;cin>>n;
    string s;cin>>s;
    if(n%2){
        cout<<-1<<endl;
        return;
    }
    int count=0, ans=0;char anchor;
    vi arr;
    forn(i, 0 ,n-1){
        // cout<<count<<endl;
        if(i==0){
            anchor = s[i];
            count++;
            ans++;
            arr.pb(ans);
        }else if(count == 0){
            anchor = s[i];
            ans++;
            count++;
            arr.pb(ans);
        }else{
            if(s[i] == anchor){
                arr.pb(ans);
                count++;
            }else{
                count--;
                arr.pb(ans);
            }
        }
    }
    if(count > 0){
        cout<<-1;
    }else{
        forn(i, 0, arr.size()-1){
            if(i == arr.size()-1) cout<<arr[i];
            else cout<<arr[i]<<" ";
        }
    }

    cout<<endl;
}

int main()
{
    // setIO("mootube");
    //not solved
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
}