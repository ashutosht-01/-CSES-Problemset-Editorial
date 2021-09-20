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
struct project{
int start;
int end;
int reward;
};
bool static comapre(project p1,project p2){
  if(p1.end<p2.end)
    return true;
    return  false;
}
int main()
{
  cses();
  ll n;
  cin>>n;           // brute force:- we can find all the subsets of project & then check valid subsets & take that valid subset which is having maximum reward. //time= O(2^N).
  project arr[n];                
  for(int i=0;i<n;i++){
    cin>>arr[i].start>>arr[i].end>>arr[i].reward;
  }
    sort(arr,arr+n,comapre);      
     vector<ll> dp(n+1,0);                 //dp[i]= largest possible reward using (p1,p2--pi) projects
     vector<int> end_points;
     for(auto proj:arr)
     end_points.push_back(proj.end);                 //vector containing end point of project
    for(int i=1;i<=n;i++){
    int j;
    auto it=lower_bound(end_points.begin(),end_points.end(),arr[i-1].start);
      if(it==end_points.begin())
      j=0;
      else{
      j=distance(end_points.begin(),it);
     }
      dp[i]=max(dp[i-1],arr[i-1].reward+dp[j]);
   }
   cout<<dp[n]<<endl;
}


