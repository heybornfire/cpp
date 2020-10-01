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
bool isSubset(int arr[],int n,int sum)
{
	bool dp[n+1][sum+1];
	dp[0][0]=true;
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=true;
	}
	for (int i = 1; i <= sum; ++i)
	{
		/* code */
		dp[0][i]=false;
	}
	for(int i=1;i<=sum;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(arr[j-1]<=i)
			dp[j][i]=dp[j-1][i]||dp[j-1][i-arr[j-1]];
			else
			dp[j][i]=dp[j-1][i];
		}
	}
	// for(int i=0;i<=sum;i++)
	// {
	// 	for(int j=0;j<=n;j++)
	// 		cout<<dp[j][i]<<" ";
	// 	cout<<endl;
	// }
	return dp[n][sum];

}
bool isSubsetOpt(int arr[],int n,int wt)
{
	bool dp[2][wt+1];
	for(int i=1;i<=wt;i++)
		dp[0][i]=false;
	for (int i = 0; i <=n; ++i)
	{
		/* code */
		dp[i%2][0]=true;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=wt;j++)
		{
			if(arr[i-1]>j)
				dp[i%2][j]=dp[(i+1)%2][j];
			else
				dp[i%2][j]=dp[(i+1)%2][j] or dp[(i+1)%2][j-arr[i-1]];
		}
	}
	return dp[n%2][wt];
}
int32_t main()
{    c_p_c();
	int n,sum;
	cin>>n>>sum;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	if(isSubsetOpt(arr,n,sum))
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}