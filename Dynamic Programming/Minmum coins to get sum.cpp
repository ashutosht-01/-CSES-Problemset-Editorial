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
void cses()
{
    fastio;
    #ifndef ONLINE_JUDGE
    freopen("ip.txt","r",stdin);
    freopen("op.txt","w",stdout);
    #endif
} 
int main()
{
	cses();
	ll n,m;
	cin>>n>>m;
    ll a[n];
    readarr(a,n)
    // dp[i]=min no of coins required to make sum i
    vector<ll> dp(m+1,1e7);
    dp[0]=0;
    for(int i=1;i<=m;i++)
    {
    	for(int  j=0;j<n;j++)
    	{
    		if(a[j]<=i)
    			dp[i]=min(dp[i],dp[i-a[j]]+1);

    	}
    }
    if(dp[m]==1e7) cout<<-1<<"\n";
    else
    	 cout<<dp[m]<<"\n";
}
