#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

const ll mod = 1e9 + 7;

void cses()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
ll dp[101][1025];
int solve(vector<vector<ll>> &mat, ll mask, ll tshirt, ll n)
{

    // if each person gets shirts
    if (mask == (1 << n) - 1)
        return 1;
    if (tshirt >= 101)
        return 0;

    if (dp[tshirt][mask] != -1)
        return dp[tshirt][mask];

    int ans = 0;
    for (ll pers = 1; pers <= n; pers++)
    { // O(n) for looping through particular state
        if (mat[tshirt][pers] == 1 && !(mask & (1 << (pers - 1))))
        {

            ans = (ans + solve(mat, mask | (1 << (pers - 1)), tshirt + 1, n)) % mod;
        }
    }
    // not assigning that tshirt to any person  Not used that particular tshirt

    ans = (ans + solve(mat, mask, tshirt + 1, n)) % mod;

    return dp[tshirt][mask] = ans % mod;
}

int main()
{
    cses();
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        string str;
        cin >> n;
        vector<vector<ll>> mat(101, vector<ll>(11, 0)); // choice[i]=>  option of tshirts for ith person
        cin.ignore();
        for (ll i = 0; i < n; i++)
        {
            getline(cin, str);
            stringstream s(str);
            int temp;
            while (s >> temp)
            {
                mat[temp][i + 1] = 1; // tshirt temp->  is loved by person i
            }
        }
        memset(dp, -1, sizeof(dp)); // dp[i][mask]== No of ways to assign ti--t100 tshirts to the people represented by mask

        ll mask = 0;
        cout << solve(mat, mask, 1, n) << endl; // time : - O(100*2^N*N)
    }
}
