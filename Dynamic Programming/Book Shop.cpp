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
//Brute Force - o(2^n) trying all subsets & valid subsets having cost < x & then try to find max no of pages
int main()
{

f_o_x();
ll n,x;
cin>>n>>x;
ll price[n+1];
ll pg[n+1];
f(i,0,n)
cin>>price[i];
f(i,0,n)
cin>>pg[i];
ll dp[n+1][x+1];
memset(dp,0,sizeof(dp));
f(i,1,n+1)
{
	f(j,0,x+1)
	{
		// if(j==0)
		// 	dp[i][j]=0;
		 if(j>=price[i-1])
		dp[i][j]=max((pg[i-1]+dp[i-1][j-price[i-1]]),dp[i-1][j]);
	    else  if(j<price[i-1])
	    	dp[i][j]=dp[i-1][j];
 
	}
}
// f(i,0,n+1)
// {
// 	f(j,0,x+1)
// 	cout<<dp[i][j]<<" ";
// 	cout<<"\n";
// }
cout<<dp[n][x]<<"\n";
}