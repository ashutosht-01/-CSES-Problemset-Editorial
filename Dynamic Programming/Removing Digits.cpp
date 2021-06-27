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
void i_o()
{
    fastio;
    #ifndef ONLINE_JUDGE
    freopen("ip.txt","r",stdin);
    freopen("op.txt","w",stdout);
    #endif
} 
//Bottom up
// ll dp[1000002];
// ll solve(ll n)
// {
//     if(n<=9) return dp[n]=1;
//     if(dp[n]!=-1) return dp[n];
//     ll mn=INT_MAX;
//     ll temp=n;
//     while(temp)
//     {
//         ll r=temp%10;
//         temp/=10;
//         if(r!=0)
//         mn=min(mn,solve(n-r));
//     }
//     return dp[n]=mn+1;
// }
///TOP DOWN
ll solve(ll n)
{

    int dp[n+1];
    // dp[i]=>min no of operation req to convert i to 0
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        ll temp=i;
        ll tmp=INT_MAX;
        while(temp)
        {
            ll r=temp%10;
            temp/=10;
            if(r!=0)
                tmp=min(tmp,(ll)dp[i-r]);
        }
        dp[i]=1+tmp;
    }
    // for(int i=0;i<=n;i++)
    //     cout<<dp[i]<<" ";
    // cout<<"\n";
    return dp[n];
}
int main()
{
 i_o();
    ll n;
    cin>>n;
    // memset(dp,-1,sizeof(dp));
    cout<<solve(n)<<"\n";
}
