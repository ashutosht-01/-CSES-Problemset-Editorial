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
  ll a,b;
  cin>>a>>b;
  ll dp[a+1][b+1]; //dp[a][b]=min no cuts req to make rect a*b into square

  for(int i=1;i<=a;i++){
    for(int j=1;j<=b;j++){
      if(i==j)  //if already square then 0 cuts
        dp[i][j]=0;                       //for a rect. of size a*b there are (a-1)+(b-1) cuts possible & we have to choose min from these cuts
      else{
        ll ans=1e9;
        for(int hei=1;hei<i;hei++){   //height cuts (length)
         ans=min(ans,1+dp[i-hei][j]+dp[hei][j]);
        }
        for(int width=1;width<j;width++){   //width cuts        
          ans=min(ans,1+dp[i][j-width]+dp[i][width]);                   
        }
        dp[i][j]=ans;
      }
    }
  }
   cout<<dp[a][b]<<endl;          //time complexity= > O(A*B(A+B))  cubic soln.
}