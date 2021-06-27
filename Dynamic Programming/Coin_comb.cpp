CSES
c_a_c —  
CSES Problem Set
Coin Combinations II
TASK SUBMIT RESULTS STATISTICS HACKING
Submission details
Task: Coin Combinations II
Sender: c_a_c
Submission time:  2021-05-26 05:48:03
Language: C++17
Status: READY
Result: RUNTIME ERROR
Test results
test  verdict time  
#1  ACCEPTED  0.01 s  details
#2  ACCEPTED  0.02 s  details
#3  ACCEPTED  0.01 s  details
#4  RUNTIME ERROR 0.29 s  details
#5  RUNTIME ERROR 0.29 s  details
#6  ACCEPTED  0.01 s  details
#7  ACCEPTED  0.01 s  details
#8  RUNTIME ERROR 0.29 s  details
#9  RUNTIME ERROR 0.28 s  details
#10 ACCEPTED  0.01 s  details
#11 RUNTIME ERROR 0.29 s  details
#12 RUNTIME ERROR 0.29 s  details
#13 ACCEPTED  0.03 s  details
Code
/*▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██▌░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░▄▄███▀░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░▄█░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░▄████████▀░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒░░░░░░░░░░░░░░░░░░░░░░░░▄█████████░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒░░░░░░░░░░░░░░░░░░░░░░░░░░▄███████▌░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒░░░░░░░░░░░░░░░░░░░░░░░░▄█████████░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒░░░░░░░░░░░░░░░░░░░░░▄███████████▌░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒░░░░░░░░░░░░░░░▄▄▄▄██████████████▌░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒░░░░░░░░░░░▄▄███████████████████▌░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒░░░░░░░░░▄██████████████████████▌░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒░░░░░░░░████████████████████████░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒█░░░░░▐██████████▌░▀▀███████████░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▐██░░░▄██████████▌░░░░░░░░░▀██▐█▌░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒██████░█████████ ░░░░░░░░░░▐█▐█▌░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒▀▀▀▀░░░██████▀░░░░░░░░░░░░▐█▐█▌░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒▒▒▒░░░░▐█████▌░░░░░░░░░░░░▐█▐█▌░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒*/
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
#define   trace(x)      cout<<#x<<": "<<x<<endl; 
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
// dp[i][x]= No of ways to calculate the sum x using c0 ----- ci-1
ll n,m;
cin>>n>>m;
vector<ll> a(n+1,0);
f(i,1,n+1)
cin>>a[i];
ll dp[n+1][m+1];
memset(dp,0,sizeof(dp));
for(int i=1;i<=n;i++)
{
  for(int j=0;j<=m;j++)
  {
    if(j==0)
      dp[i][0]=1;
    else if(a[i]<=j)
    dp[i][j]=(dp[i-1][j]+dp[i][j-a[i]])%mod;
      else
        dp[i][j]=dp[i-1][j]%mod;
  }
}
cout<<dp[n][m]%mod<<"\n";
}
  
Share code to others
Test details
Test 1
Verdict: ACCEPTED

input
1 1
1

correct output
1

user output
1

Test 2
Verdict: ACCEPTED

input
1 1000000
1

correct output
1

user output
1

Test 3
Verdict: ACCEPTED

input
3 2000
1 1500 1000

correct output
4

user output
4

Test 4
Verdict: RUNTIME ERROR

input
100 1000000
27 69 68 13 1 63 28 44 45 67 5...

correct output
869167734

user output
(empty)

Test 5
Verdict: RUNTIME ERROR

input
100 1000000
649304 85832 159093 841262 930...

correct output
7029

user output
(empty)

Test 6
Verdict: ACCEPTED

input
1 1
1000000

correct output
0

user output
0

Test 7
Verdict: ACCEPTED

input
100 1000
389 101 552 795 876 269 887 10...

correct output
24369327

user output
24369327

Test 8
Verdict: RUNTIME ERROR

input
100 1000000
999 541 97 522 78 380 993 971 ...

correct output
187405784

user output
(empty)

Test 9
Verdict: RUNTIME ERROR

input
100 1000000
89384 30887 92778 36916 47794 ...

correct output
205112015

user output
(empty)

Test 10
Verdict: ACCEPTED

input
2 123123
1 2

correct output
61562

user output
61562

Test 11
Verdict: RUNTIME ERROR

input
100 1000000
1 2 3 4 5 6 7 8 9 10 11 12 13 ...

correct output
869167734

user output
(empty)

Test 12
Verdict: RUNTIME ERROR

input
100 1000000
1 2 3 4 5 6 7 8 9 10 11 12 13 ...

correct output
869167734

user output
(empty)

Test 13
Verdict: ACCEPTED

input
2 1000000
1 1000000

correct output
2

user output
2

Dynamic Programming
Dice Combinations
Minimizing Coins
Coin Combinations I
Coin Combinations II
Removing Digits
Grid Paths
Book Shop
Array Description
...
Your submissions
2021-05-26 05:53:22
2021-05-26 05:48:03
2021-05-26 05:17:23
2021-05-25 19:43:28
2021-05-25 19:32:07
2021-05-25 19:27:36
2021-05-25 19:17:57
2021-05-25 19:14:39
2021-05-25 19:11:25
2021-05-25 18:59:14
