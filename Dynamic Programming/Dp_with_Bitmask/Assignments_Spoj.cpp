#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

const ll mod = 1e9 + 7;
const ll inf = 1e18;
void cses()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
ll dp[20][1ll << 20];
ll solve(ll n, ll i, ll mask, vector<vector<ll>> &mat)
{ // Returns Num of ways to assign topic (i--n) to some students  represented using mask

    if (i == n - 1)
        return 1;
    if (dp[i][mask] != -1)
        return dp[i][mask];

    ll ans = 0;
    for (ll j = 0; (1ll << j) <= mask; j++)
    {
        if ((mask & (1ll << j)) && mat[j][i] == 1)
            ans += solve(n, i + 1, mask ^ (1ll << j), mat);
    }
    return dp[i][mask] = ans;
}
int main()
{
    cout << "some changes in master wrt rebasing" << endl;
    cses();

    ll t;
    cin >> t;
    cout << "changes in experiment ";

    while (t--)
    {
        ll n;
        cin >> n;
        vector<vector<ll>> mat(n, vector<ll>(n, 0));
        cout << "Hi from temp"
             << "\n";
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
                cin >> mat[i][j];
        }
        cout << "Helo rd" << endl;
        cout << "sone chnages to be cheryypick";
        memset(dp, -1, sizeof(dp));
        cout << solve(n, 0, (1ll << n) - 1, mat) << endl;
        cout << "Hi there from master" << endl;
        cout << "fetature changes" << endl;
        cout << "temoc " << endl;
    }
}
