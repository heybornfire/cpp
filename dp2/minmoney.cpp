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
int minmoney(int rate[],int n,int wt)
{
	int dp[wt+1]={0};
	for(int i=1;i<=wt;i++)
		dp[i]=INT_MAX;
	//dp[0][0]=INT_MAX;
	for(int i=1;i<=wt;i++)
	{
		for(int j=1;j<=n;j++)
		{
			// if(rate[j-1]==-1 or j>i)
			// 	continue;
			if(rate[j-1]!=-1 and j<=i)
				dp[i]=min(dp[i],rate[j-1]+dp[i-j]);
		}
	}
	return dp[wt]==INT_MAX?-1:dp[wt];
}
int minmoney2(int rate[],int n,int wt)
{
	int dp[wt+1][n+1]={0};
	for(int i=1;i<=wt;i++)
		dp[i][0]=INT_MAX;
	//dp[0][0]=INT_MAX;
	for(int i=1;i<=wt;i++)
	{
		for(int j=1;j<=n;j++)
		{
			// if(rate[j-1]==-1 or j>i)
			// 	continue;
			if(rate[j-1]!=-1 and j<=i)
				dp[i][j]=min(dp[i][j-1],rate[j-1]+dp[i-j][j]);
			else
				dp[i][j]=dp[i][j-1];
		}
	}
	return dp[wt][n]==INT_MAX?-1:dp[wt][n];
}
int buyOrangesBottomUp(int *price,int w){
    int dp[w+1];
    dp[0] = 0;
    for(int i=1; i<=w; i++) {
        dp[i] = price[i];
    }

    for(int i=2;i<=w;i++){
        for(int j=0;j<i;j++) {
	        if(price[i-j] == -1  || dp[j] == -1){
			    continue;
			}
            if(dp[i] == -1)
                dp[i] = dp[j] + price[i-j];
            else
                dp[i] = min(dp[i], dp[j] + price[i-j]);
        }
    }

  //  for(int i=1;i<=w;i++)   cout << dp[i] << " "; 
    return dp[w];
}

int32_t main()
{
	c_p_c();
	int n,wt;
	cin>>n>>wt;
	int *rate=new int[n];
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin>>rate[i];
	}
	//cout<<minmoney(rate,n,wt)<<endl;
	cout<<buyOrangesBottomUp(rate,wt);
	return 0;
}