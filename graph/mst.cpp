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
int findMin(int weight[],bool visited[],int v)
{
	int minVertex=-1,minwt=INT_MAX;
	for(int i=0;i<v;i++)
	{
		if(!visited[i] and weight[i]<minwt)
			{minVertex=i;minwt=weight[i];}


	}
	return minVertex;
}
void prim(list<pair<int,int>>adjlist[],int v)
{
	bool visited[v];
	//int parent[v];
	int weight[v];
	for(int i=0;i<v;i++)
	{
		weight[i]=INT_MAX;
		visited[i]=false;
	}
	weight[0]=0;
	//parent[0]=-1;
	for(int i=0;i<v;i++)
	{
		int minVertex=findMin(weight,visited,v);
		//cout<<minVertex<<endl;
		visited[minVertex]=true;
		for(auto neighbour:adjlist[minVertex])
		{
			if(!visited[neighbour.first] and weight[neighbour.first]>neighbour.second)
			{
				weight[neighbour.first]=neighbour.second;
				//parent[neighbour.first]=minVertex;
			}
		}
	}
	int sum=0;
	for(int i=0;i<v;i++)
	{
		//cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
		sum+=weight[i];
	}
	cout<<sum;
}
int32_t main()
{
	c_p_c();
	int vertices,edges,u,v,w;
	cin>>vertices>>edges;
	list<pair<int,int>> adjlist[vertices];
	for(int i=0;i<edges;i++)
	{
		cin>>u>>v>>w;
		adjlist[u].push_back(make_pair(v,w));
		adjlist[v].push_back(make_pair(u,w));

	}
	//cout<<adjlist[3].size()<<endl;
	prim(adjlist,vertices);
	return 0;
}