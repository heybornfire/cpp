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
int memo[100][100];
int lcs(string s1,string s2,int i,int j)
{
	if(i==s1.length()|| j==s2.length())
		return 0;
	if(memo[i][j]!=-1)
		return memo[i][j];
	if(s1[i]==s2[j])
		return (memo[i][j]= 1+lcs(s1,s2,i+1,j+1));
	return (memo[i][j]=max(lcs(s1,s2,i,j+1),lcs(s1,s2,i+1,j)));
}
int32_t main()
{
	c_p_c();
	string s1,s2;
	cin>>s1>>s2;
	memset(memo,-1,sizeof(memo));
	lcs(s1,s2,0,0);
	// for(int i=0;i<s1.size();i++)
	// {
	// 	for(int j=0;j<s2.size();j++)
	// 	{
	// 		if(s1[i]==s2[j])
	// 			cout<<s1[i];

	// 	}
	// 	cout<<endl;
	// }
	int i=0,j=0;
	while(i<s1.size() and j<s2.size())
	{
		if(s1[i]==s2[j])
		{
			cout<<s1[i];
			i++;
			j++;
		}
		else if(memo[i+1][j]>memo[i][j+1])
		{
			i++;
		}
		else
			j++;

	}
	return 0;
}