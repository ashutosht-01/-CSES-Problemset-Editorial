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
  ll sum=n*(n+1)/2;
  if(sum%2==1)
    cout<<0<<endl;
  else{
    sum/=2;
  vector<ll> v(n,0);
  for(int i=1;i<=n;i++)
  v[i-1]=i;
  ll dp[n+1][sum+1];
  for(int i=0;i<=n;i++){
    for(int j=0;j<=sum;j++){   //dp[i][j]=No. of ways to find j using first i numbers.
      if(j==0)                //Base Case - dp[0][x] = 0 (No natural nos then sum x)
        dp[i][j]=1;
      else if(i==0)          //dp[x][0]=1 (ways to sum=0 using 1st x natural nos)
        dp[i][j]=0;
      else{
        if(j-v[i-1]>=0)
        dp[i][j]=((dp[i-1][j-v[i-1]])%mod+dp[i-1][j])%mod;
        else
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  cout<<((dp[n][sum])* 500000004)%mod<<endl;  //multiply by modulo_inverse(2) =500000004 devision in case of mod then use modulo inverse
}
}
