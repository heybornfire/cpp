#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define in2t             long long
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
int memo[100][100][100];
int lcs(string one,string two,string three,int i,int j,int k)
{
	if(i==one.size() || j==two.size() || k== three.size())
		return 0;
	if(memo[i][j][k]!=-1)
		return memo[i][j][k];
	if(one[i]==two[j] and two[j]==three[k])
		return memo[i][j][k]= 1+lcs(one,two,three,i+1,j+1,k+1);
	return memo[i][j][k]=max(lcs(one,two,three,i+1,j,k),max(lcs(one,two,three,i,j+1,k),lcs(one,two,three,i,j,k+1)));
}
int32_t main()
{
	c_p_c();
	string one,two,three;
	cin>>one>>two>>three;
	memset(memo,-1,sizeof(memo));

	cout<<lcs(one,two,three,0,0,0)<<endl;
	// for(int i=0;i<one.size();i++)
	// {
	// 	for(int j=0;j<two.size();j++)
	// 	{
	// 		for(int k=0;k<three.size();k++)
	// 			cout<<memo[i][j][k];
	// 		// if(s1[i]==s2[j])
	// 		// 	cout<<s1[i];

	// 	}
	// 	cout<<endl;
	// }
	return 0;
}