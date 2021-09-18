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
  vector<int> a(n,0);
  for(int i=0;i<n;i++)
    cin>>a[i];
    vector<int> v;
       v.push_back(a[0]);           //v.size() represents length of LIS
       for(int i=1;i<n;i++)         
       {
           if(v.back()<a[i])  //highest found value we push it because it makes increasing sequence longer
           v.push_back(a[i]);
           else{
               int ind=lower_bound(v.begin(),v.end(),a[i])-v.begin();   //O(nlog(n))
               v[ind]=a[i];
           }
           
       }
       cout<<v.size()<<endl;
}

