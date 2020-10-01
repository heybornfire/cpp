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
node *buildTree()
{
	int d;
	cin>>d;
	string left,right;
	node *root=new node(d);
	cin>>left;
	if(left=="true")
		root->left=buildTree();
	cin>>right;
	if(right=="true")
		root->right=buildTree();
	return root;
}
pair<int,bool> isBalanced(node *root)
{
	pair<int,bool> p;
	if(!root)
	{
		p.first=0;
		p.second=true;
		return p;
	}
	pair<int,bool>pleft=isBalanced(root->left);
	pair<int,bool>pright=isBalanced(root->right);
	if(abs(pleft.first-pright.first)<=1 and pleft.second and pright.second)
	{
		p.second=true;

	}
	else
	{
		p.second=false;
	}
	p.first=max(pleft.first,pright.first)+1;
	return p;


}
void preorder(node *root)
{
	if(!root)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
int32_t main()
{
	c_p_c();
	node *root=buildTree();
	//preorder(root);
	if(isBalanced(root).second)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}