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
void buildTree(node *&root)
{
	int data;
	string strleft,strright;
		cin>>data;
		root=new node(data);
		cin>>strleft;
		if(strleft=="true")
			buildTree(root->left);
		cin>>strright;
		if(strright=="true")
			buildTree(root->right);

	
}
void inorder(node *root)
{
	if(!root)
		return;
	cout<<root->data<<" ";
	inorder(root->left);
	inorder(root->right);
}
bool isIdentical(node *root1,node *root2)
{
	if(!root1 and !root2)
		return true;
	else if(!root1 || !root2)
		return false;
	else
		return isIdentical(root1->left,root2->left) and isIdentical(root1->right,root2->right);

}
int32_t main()
{
	c_p_c();
	node *root1=NULL;
	node *root2=NULL;
	buildTree(root1);
	buildTree(root2);
 inorder(root1);
	// cout<<endl;
	// inorder(root2);
	if(isIdentical(root1,root2))
		cout<<"true";
	else
		cout<<"false";


	return 0;
}