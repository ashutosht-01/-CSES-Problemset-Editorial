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
#define   trace(x)        cout<<#x<<": "<<x<<endl; 
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
void f_o_x()
{
    fastio;
    #ifndef ONLINE_JUDGE
    freopen("ip.txt","r",stdin);
    freopen("op.txt","w",stdout);
    #endif
} 
int main()
{
	f_o_x();
	ll n,m;
	cin>>n>>m;
	ll a[n];
	readarr(a,n);
	// dp[a[i]][i] = number of ways to fill the array up to index i if value at index is i
	vector<vector<ll>> dp(m+1,vector<ll>(n,0));
	f(i,0,n)
	{
		//bc
		if(i==0)  //first element
		{
			if(a[i]!=0) dp[a[i]][i]=1;
			f(j,1,m+1)
			dp[i][j]=1;
		}
		continue;
		if(a[i]!=0)
		{
          dp[a[i]][i]=dp[a[i]-1][i-1]%mod+dp[a[i]][i-1];
          if(a[i]+1<=m)
          	dp[a[i]][i]=dp[a[i]][i]+dp[a[i]+1][i]%mod;
		}
		else
		{
			f(j,1,m+1)
			{
				dp[j][i]=dp[j-1][i-1];
				dp[j][i]=dp[j][i]%mod+dp[j][i-1]%mod;
				if(j+1<=m)
					dp[j][i]=dp[j][i]%mod+dp[j+1][i-1]%mod;
			}
		}
	}
	  for(int i=0;i<=m;i++)
	  {
	  	for(int j=0;j<n;j++)
	  		cout<<dp[i][j]<<" ";
	  	cout<<"\n";
	  }
	  if(a[n-1]!=0)
	  	cout<<dp[a[n-1]][n-1]<<"\n";
	  //0 ke liye total no of ways count kar liye
	
      else
      {
      	ll res=0;
      	f(j,1,m+1)
      	{
            res=res%mod+dp[j][n-1]%mod;
      	}
      	cout<<res<<"\n";

      }
}