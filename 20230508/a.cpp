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


void solve(){
    string s;
    cin>>s;
    int length = s.length();
    char first_char = s[0];
    int not_same = 0;

    unordered_map<char,int> ans;
    forn(i, 0 , length -1){
        if (s[i] == s[0]) not_same++;
        ans[s[i]]++;
    }

    int count = 0;

    for(auto i : ans){
        if(i.second%2!= 0){
            count++;
        }
    }

    int longest = count > 1 ? length -count +1: length;

    if(not_same == length){
        cout<<-1<<endl;
    }else{
        cout<<longest-1<<endl;
    }

    
}

int main()
{
    // setIO("div7");
    // dfs? dynamic programming, what am I missing?
    // ans: nothing special, sort it, if the cur sum+1 is smaller than next number

    int n;
    cin>>n;
    while(n--){
        solve();
    }
}