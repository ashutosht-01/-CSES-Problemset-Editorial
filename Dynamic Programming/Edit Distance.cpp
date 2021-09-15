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
  string s1;
  string s2;
  cin>>s1>>s2;
  ll n=s1.length();
  ll m=s2.length();        
  ll dp[n+1][m+1];         //dp[i][j]= min no. of operation req to convert pref[i] to pref[j].
  for(int i=0;i<=n;i++)   //deletion
    dp[i][0]=i;
  for(int j=0;j<=m;j++)  //insertion or adding
    dp[0][j]=j;
   for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(s1[i-1]==s2[j-1])
        dp[i][j]=dp[i-1][j-1];
      else                         //dp[i-1][j-1]=> after updation dp[i][j-1]=> after insertion  dp[i-1][j]=> after removal 
        dp[i][j]=1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));  //dp[i][j-1]=after insertion s2[j] min no of steps req to convert prefix(i) to prefix(j-1)
    }
   }
   cout<<dp[n][m]<<endl;
}