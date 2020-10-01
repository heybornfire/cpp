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

int32_t main()
{
	c_p_c();
	int n,sum,curr;
	cin>>n;
	vi v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	cin>>sum;
	sort(v.begin(),v.end());
	int start=0;
	int end=v.end()-v.begin()-1;
	while(start<end)
	{
		curr=v[start]+v[end];
		if(curr<sum)
		{
			start++;
		}
		else if(curr>sum)
		{
			end--;
		}
		else
		{
			cout<<v[start]<<" and "<<v[end]<<endl;
			start++;
			end--;
		}

	}
	return 0;
}