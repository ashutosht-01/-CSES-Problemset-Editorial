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
#define   trace(x) 		  cout<<#x<<": "<<x<<endl; 
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

		ll n;
		cin>>n;
		 char grid[n][n];
		 ll dp[n][n];
		 memset(dp,0,sizeof(dp));
		f(i,0,n)
		{
			f(j,0,n)
			cin>>grid[i][j];
		}
	    if(grid[0][0]=='*')
	    cout<<dp[n-1][n-1]%mod<<"\n";
	    else
	    {
           for(int j=0;j<n;j++){
           	if(grid[0][j]=='*'){
           		dp[0][j]=0;
           		break;
           	}
           	else
           		dp[0][j]=1;
           }
           for(int i=0;i<n;i++)
           {
           	if(grid[i][0]=='*')
           		break;
           	else
           		dp[i][0]=1;
           }
          for(int i=1;i<n;i++)
          {
          	f(j,1,n)
          	{
          		if(grid[i][j]=='*')
          			dp[i][j]=0;
          		else
          			dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
          	}
          }
          cout<<dp[n-1][n-1]%mod<<"\n";
           }

		// f(i,0,n)
		// {
		// 	f(j,0,n)
		// 	cout<<dp[i][j]<<" ";
		// 	cout<<"\n";
		// }

 
	

}
	
