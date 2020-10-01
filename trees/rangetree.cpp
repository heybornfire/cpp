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
node * buildTree(int *arr,int minV,int maxV,int n)
{
	static int i=0;
	if(i>=n)
		return NULL;
	if(arr[i]>minV and arr[i]<maxV)
	{
		node *root=new node(arr[i]);
		i++;
		root->left=buildTree(arr,minV,root->data,n);
		root->right=buildTree(arr,root->data,maxV,n);
		return root;
	}
	
	return NULL;
}
void preorder(node *root)
{
	if(!root)
		return;
	cout<<" "<<root->data;
	preorder(root->left);
	preorder(root->right);
}
void nodeRange(node *root,int k1,int k2 )
{
	if(!root)
		return;
	if(root->data>=k1 and root->data<=k2)
	{
		nodeRange(root->left,k1,k2);
		cout<<" "<<root->data;
		nodeRange(root->right,k1,k2);
	}
	else if(root->data>k1)
	{
		nodeRange(root->left,k1,k2);
	}
	else
	{
		nodeRange(root->right,k1,k2);
	}

}
node* constructTreeUtil( int pre[], int* preIndex, int key,  
                                int min, int max, int size )  
{  
    // Base case  
    if( *preIndex >= size )  
        return NULL;  
  
    node* root = NULL;  
  
    // If current element of pre[] is in range, then  
    // only it is part of current subtree  
    if( key > min && key < max )  
    {  
        // Allocate memory for root of this  
        // subtree and increment *preIndex  
        root = new node ( key );  
        *preIndex = *preIndex + 1;  
          
        if (*preIndex < size)  
        {  
            // Construct the subtree under root  
            // All nodes which are in range  
            // {min .. key} will go in left  
            // subtree, and first such node  
            // will be root of left subtree.  
            root->left = constructTreeUtil( pre, preIndex, pre[*preIndex],  
                                        min, key, size );  
  
            // All nodes which are in range  
            // {key..max} will go in right  
            // subtree, and first such node 
            // will be root of right subtree.  
            root->right = constructTreeUtil( pre, preIndex, pre[*preIndex],  
                                        key, max, size );  
        }  
    }  
  
    return root;  
}  
  
// The main function to construct BST 
// from given preorder traversal.  
// This function mainly uses constructTreeUtil()  
node *constructTree (int pre[], int size)  
{  
    int preIndex = 0;  
    return constructTreeUtil ( pre, &preIndex, pre[0], INT_MIN,  
                            INT_MAX, size );  
}  
int32_t main()
{
	c_p_c();
	w(t)
	{
		int n,k1,k2;
		cin>>n;
		mk(arr,n,int);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cin>>k1>>k2;
		//node *root=buildTree(arr,INT_MIN,INT_MAX,n);
		node *root=constructTree(arr,n);
		cout<<"# Preorder :";
		preorder(root);
		cout<<endl;
		cout<<"# Nodes within range are :";
		nodeRange(root,k1,k2);
		cout<<endl;


	}
	return 0;
}