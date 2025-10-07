    #include <iostream>
    #include <vector>
    #include <string>
    #include <map>
    #include <algorithm>
    #include <set>
    #include <utility>
    #include <queue>
    #include <unordered_map>
    #include <math.h>

    using namespace std;

    #define int long long
    #define forn(i, x, n) for (int i = x; i <= n; ++i)
    #define for1(i, n, x) for (int i = n; i >= x; --i)
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

    void solve()
    {
        int n;
        cin >> n;
        int arr[n];
        vi odd, even;
        int max_ = -1;
        int sum = 0;
        int number_of_odd = 0;
        forn(i, 0, n - 1)
        {
            cin >> arr[i];
            sum += arr[i];
            if (arr[i] % 2)
            {
                number_of_odd++;
            }
            if (max_ < arr[i])
            {
                max_ = arr[i];
            }
        }
        if (number_of_odd == 0 || number_of_odd == n)
        {
            cout << max_ << endl;
            return;
        }
        cout << sum - (number_of_odd - 1) << endl;
        // sort(arr, arr + n);

        // forn(i, 0, n - 1)
        // {
        //     if (arr[i] % 2)
        //     {
        //         odd.push_back(arr[i]);
        //     }
        //     else
        //     {
        //         even.push_back(arr[i]);
        //     }
        //     if (arr[i] > max_)
        //     {
        //         max_ = arr[i];
        //     }
        // }
        // if (odd.size() == 0 || even.size() == 0)
        // {
        //     cout << max_ << endl;
        //     return;
        // }
        // if (even.size() > 1)
        // {
        //     forn(i, 1, even.size() - 1)
        //     {
        //         odd[odd.size() - 1] += even[i];
        //     }
        // }
        // odd[0] = odd[0] + even[0] - 1;
        // forn(i, 1, odd.size() - 1)
        // {
        //     if (i == odd.size() - 1)
        //     {
        //         odd[i] = odd[i - 1] + odd[i];
        //     }
        //     else
        //     {
        //         odd[i] = odd[i - 1] + odd[i] - 1;
        //     }
        // }
        // cout << odd[odd.size() - 1] << endl;
    }

    signed main()
    {
        cin.tie(0);
        string name = "";
        // setIO(name);

        int t;
        cin >> t;
        int a = 1;
        while (t--)
        {
            solve();
        }
        return 0;
    }