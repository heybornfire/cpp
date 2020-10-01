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
int ways(list<int> adjList[],int n)
{
	bool visited[n]={false};
	queue<int>q;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(!visited[i]){
			q.push(i);
		visited[i]=true;
		int cities=1;
		
		
	
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
			
		for(auto neighbour:adjList[node])
		{
			if(!visited[neighbour])
			{
				q.push(neighbour);
				visited[neighbour]=true;
				cities++;
			}

		}

	}cout<<"cities"<<cities<<"other"<<n-cities<<endl;
	sum+=((n-cities)*cities);
}}
	return sum/2;
}
int32_t main()
{
	c_p_c();
		int n,m,a,b,u,v;
		cin>>n>>m;
		list<int> adjList[n+1];
		for(int i=0;i<m;i++)
		{
			cin>>u>>v;
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
			cout<<ways(adjList,n)<<endl;
	return 0;
}