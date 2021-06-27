#include<bits/stdc++.h>
using namespace std;
#define   f(a,b,n)        for(ll a=b;a<n;a++)
#define   readarr(arr,n)  f(i,0,n) cin>>arr[i];
#define   ll              long long
#define   pb              push_back
#define   fastio            ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define   all(x)          x.begin(), x.end()
#define   mod             1000000007
#define   w(t)            int t; cin>>t; while(t--) 
#define   fi              first
#define   sd              second                                                                                                                                                                                                                           
#define   sp(x,y)         fixed<<setprecision(y)<<x              
#define   trace(x)      cout<<#x<<": "<<x<<endl; 
#define   trav(a, x)      for(auto& a : x) 
#define   setbits(x)      __builtin_popcountll(x)  
#define   zrobits(x)      __builtin_ctzll(x)  
#define   pqmax           priority_queue<ll>
#define   pqmin           priority_queue<ll,vi,greater<ll>>                         
#define   vi              vector<ll>
#define   mpi              map<ll,ll> 
#define   pi              pair<ll,ll>  
#define   N               1e5   
#define   inf             1e18 
#define   nline           "\n"
void i_o()
{
  fastio;
  #ifndef ONLINE_JUDGE
  freopen("ip.txt","r",stdin);
  freopen("op.txt","w",stdout);
  #endif
} 
 
 
int main()
{
i_o();
// dp[i][x]= No of ways to calculate the sum x using c0 ----- ci-1
ll n,m;
cin>>n>>m;
vector<ll> a(n+1,0);
f(i,1,n+1)
cin>>a[i];
ll dp[n+1][m+1];
memset(dp,0,sizeof(dp));
for(int i=1;i<=n;i++)
{
  for(int j=0;j<=m;j++)
  {
    if(j==0)
      dp[i][0]=1;
    else if(a[i]<=j)
    dp[i][j]=(dp[i-1][j]+dp[i][j-a[i]])%mod;
      else
        dp[i][j]=dp[i-1][j]%mod;
  }
}
cout<<dp[n][m]%mod<<"\n";
}
  

