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
    string s;
    cin>>s;
    int n= s.size();
    if(n==1){
        cout<<(s[0] == '?' ? 1 : s[0])<<endl;
        return;
    }

    if(n==2){
        char c1=s[0], c2 = s[1];
        if(c2 == '1'){
            cout<<s<<endl;
            return;
        }else if(c2 == '?'){
            if(c1 =='?'){
                cout<<00<<endl;
            }else{
                cout<<c1<<1<<endl;
            }
        }
    }else{
        char prev ='p';
        string ans = "";
        forn(i,0,n-1){

            if(i == n-1){
                if(s[i] == '?'){
                    ans += s[i-1] == '1' ? '1' : '0';
                }else{
                    ans += s[i];
                }
            }
            else if(s[i] == '?'){
                // cout<<prev<<"hihi"<<endl;
                if(prev == '1' || s[i+1] == '1'){
                    ans += '1';
                    prev = '1';
                }else{
                    ans += '0';
                    prev = '0';
                }
            }else{
                ans += s[i];
                prev = s[i];
            }


            
        }

        cout<<ans<<endl;
    }
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