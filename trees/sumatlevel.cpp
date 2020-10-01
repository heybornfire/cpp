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
	node *left;
	node *right;
	node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};
node * buildTree()
{
	int data,childs;
	cin>>data>>childs;
	node * root=new node(data);
	if(childs==1)
	{
		root->left=buildTree();
	}
	else if(childs==2)
	{
		root->left=buildTree();
		root->right=buildTree();
	}
	return root;

}
void preorder(node *root)
{
	if(!root)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
int sumAtLevelK(node *root,int k)
{
	if(!root)
		return 0;
	if(k==0)
		return root->data;
	return sumAtLevelK(root->left,k-1)+sumAtLevelK(root->right,k-1);

}
int32_t main()
{
	c_p_c();
	node *root=buildTree();
	int k;
	cin>>k;
	//preorder(root);
	cout<<sumAtLevelK(root,k)<<endl;
	return 0;
}