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
int noofdice(list<int> adjList[],int n)
{
	//cout<<"hello";
	queue<int>q;
	int dist[n+1];
	for(int i=0;i<n+1;i++)
		dist[i]=INT_MAX;
	q.push(0);
	dist[0]=0;
	while(!q.empty())
	{
		//cout<<"hellow";
		int node=q.front();
		q.pop();
		for(int neighbour:adjList[node])
		{
			if(dist[neighbour]==INT_MAX)
			{
				dist[neighbour]=dist[node]+1;
				q.push(neighbour);
			}
		}
	}
	return dist[n];

}
int32_t main()
{
	c_p_c();
	w(t)
	{
		int n,l,s,x,y,v;
		cin>>n>>l>>s;
		int board[n+1]={0};
		for(int i=0;i<l;i++)
		{
			cin>>x>>y;
			board[x]=y;
		}
		for(int i=0;i<s;i++)
		{
			cin>>x>>y;
			board[x]=y;
		}
		//cout<<"hellO";
		list<int> adjList[n+1];
		for(int u=0;u<n;u++)
		{
		for(int dice=1;dice<=6;dice++)
		{
			if(u+dice<=n)
			{
				if(board[u+dice]!=0)
				{
					v=board[u+dice];
				}
				else
				{
					v=u+dice;
				}
				adjList[u].push_back(v);
			}
		}
		}
		//cout<<"helo";
		// for(int i=0;i<=n;i++)
		// {
		// 	cout<<"neighbour of"<<i<<" ";
		// 	for(auto neighbour:adjList[i])
		// 		cout<<neighbour<<"=>";
		// 	cout<<endl;
		// }
		cout<<noofdice(adjList,n)<<endl;
	}
	return 0;
}