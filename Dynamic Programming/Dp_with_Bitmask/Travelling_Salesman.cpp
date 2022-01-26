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

//dp[curr_city][setofcities]= stores shortest trip cost from curr_City to the starting city via setofcities which are unset or NOT visited

int tsp(vector<vector<int>> &dist, int n, int setofcities, int curr_city, vector<vector<int>> &dp)
{

    //base case
    if (setofcities == ((1 << n) - 1))
        return dist[curr_city][0];

    if (dp[curr_city][setofcities] != -1)
        return dp[curr_city][setofcities];

    int ans = INT_MAX;
    for (int choice = 0; choice < n; choice++)
    {
        if ((setofcities & (1 << choice)) == 0)
        { //bitwise less precedence then equaliy (relational) operator
            ans = min(ans, dist[curr_city][choice] + tsp(dist, n, setofcities | (1 << choice), choice, dp));
        }
    }

    return dp[curr_city][setofcities] = ans;
}

int main()
{
    cses();

    /* code */
    vector<vector<int>> dist = {{0, 24, 42, 25},
                                {20, 0, 30, 34},
                                {42, 30, 0, 10},
                                {25, 34, 10, 0}};

    vector<vector<int>> dp(4, vector<int>((1 << 4), -1));
    cout << tsp(dist, 4, 1, 0, dp) << endl;
}