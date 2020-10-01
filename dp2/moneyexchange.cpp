#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("/home/krishna/Documents/competitive/input.txt", "r", stdin);
	freopen("/home/krishna/Documents/competitive/output.txt", "w", stdout);
#endif
}
unordered_map<int,int> memo;
int maxGold(int n)
{
	if(n==0)
		return 0;
	if(memo.count(n)!=0)
		return memo[n];
	int change= maxGold(n/2)+maxGold(n/3)+maxGold(n/4);
	if(change>n)
		return memo[n]=change;
	else
		return memo[n]=n;
}
int maxGolddp(int n)
{
	int dp[n+1]={0};
	for(int i=1;i<=n;i++)
	{
		dp[i]=max(i,dp[i/2]+dp[i/3]+dp[i/4]);
	}
	// for (int i = 0; i <= n; ++i)
	// {
	// 	/* code */
	// 	cout<<dp[i]<<" ";
	// }
	//cout<<endl;
	return dp[n];
}

int32_t main()
{
	c_p_c();
	int n;
	cin>>n;
	//memset(memo,-1,sizeof(memo));
	cout<<maxGold(n);
	return 0;
}