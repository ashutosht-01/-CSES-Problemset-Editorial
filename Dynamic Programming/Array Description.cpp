#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long
void cses()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
int main()
{
  cses();
  ll n,m;
  cin>>n>>m;
  ll arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  vector<vector<int>> dp(n+1,vector<int> (m+2,0)); //size==m+2 => to avoid edge case when arr[i]==m
  for(int i=1;i<=n;i++){                //dp[i][x]=No of arrays upto index i  where arr[i]==x.
    for(int x=1;x<=m;x++){
       if(i==1){    //base case
        if(arr[i-1]==0 || arr[i-1]==x)
          dp[i][x]=1;
       else
        dp[i][x]=0;
      }
      else{
        if(arr[i-1]==0 || arr[i-1]==x)
          dp[i][x]=((dp[i-1][x-1]+dp[i-1][x])%mod+dp[i-1][x+1])%mod;
        else
          dp[i][x]=0;
      }
    }
  }
     int ans=0;
     for(int x=1;x<=m;x++)
      ans=(ans+dp[n][x])%mod;
    cout<<ans<<endl;
}
z