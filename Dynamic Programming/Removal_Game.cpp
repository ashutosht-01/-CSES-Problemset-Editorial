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
  ll n;
  cin>>n;
  vector<ll> arr(n,0);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  ll dp[n][n];    //dp[L][R]= max. score that a player can get by playing optimally in range [L,R]
  for(int gap=0;gap<n;gap++){
    for(int i=0,j=gap;j<n;i++,j++){
      if(gap==0)
        dp[i][j]=arr[i];
      else if(gap==1)
        dp[i][j]=max(arr[i],arr[j]);
      else{   //R-L>2
        ll val1=min(dp[i+2][j],dp[i+1][j-1]); //if it chooses i => (i+1,j) ===> these are set for opponent choice
        ll val2=min(dp[i+1][j-1],dp[i][j-2]); //if it chooses j => (i,j-1) ===> these are set for opponent choice
        dp[i][j]=max(arr[i]+val1,arr[j]+val2);
      }
    }
  } 
  cout<<dp[0][n-1]<<endl; 
}