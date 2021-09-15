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
   set<ll> ans;
   for(int i=0;i<n;i++){              
    ll  x;
    cin>>x;
    if(ans.size()==0){
     ans.insert(x);
     continue;
    }
    vector<int> v;
    for(auto ele:ans){                     // 4 2 6 | 5 comes
      v.push_back(ele+x);                  //  4 2 6 9 7 11 | 5 also added to ans set.  for given ele add that ele to ans elements
    }
    for(auto ele:v)
    ans.insert(ele);
    ans.insert(x);
   }
   cout<<ans.size()<<endl;
   for(auto ele:ans)
    cout<<ele<<" ";
    cout<<endl;
}