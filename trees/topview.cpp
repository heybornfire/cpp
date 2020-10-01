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
class node
{
public:
	int data;
	node * left;
	node * right;
	node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};
void topview(node *root,int level,int distance,map<int,pair<int,int>> &mp)
{
	if(!root)
		return;
	if(mp.find(distance)==mp.end())
	{
		mp.insert(make_pair(distance,make_pair(level,root->data)));
	}
	else
	{
		if(mp[distance].first>level)
			mp[distance]={level,root->data};
	}
	topview(root->left,level+1,distance-1,mp);
	topview(root->right,level+1,distance+1,mp);
}
void inorder(node *root)
{
	if(!root)
		return;
	cout<<root->data;
	inorder(root->left);
	inorder(root->right);
}

int32_t main()
{
	c_p_c();
	int data;
	cin>>data;
	node *root=new node(data);
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		node *temp=q.front();
		q.pop();
		cin>>data;
		if(data!=-1)
		{
			temp->left=new node(data);
			q.push(temp->left);
		}
		cin>>data;
		if(data!=-1)
		{
			temp->right=new node(data);
			q.push(temp->right);
		}
	}
	map<int,pair<int,int>> mp;
	topview(root,0,0,mp);
	for(auto i:mp)
	{
		cout<<i.second.second<<" ";
	}
	cout<<endl;
	return 0;
}