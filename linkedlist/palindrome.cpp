#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define i2nt             long long
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
	node *next;
	node(int d)
	{
		data=d;
		next=NULL;
	}
};
class linkedList
{
public:
	node *head;
	node *tail;
	linkedList(node *h,node *t)
	{
		head=h;
		tail=t;
	}
};
node *buildLinkdedList(int n)
{
	int data;
	cin>>data;
	node *head=new node(data);
	node *temp=head;
	n--;
	while(n--)
	{
		cin>>data;
		temp->next=new node(data);
		temp=temp->next;
	}
	return head;
}
void print(node *head)
{
	node *temp=head;
	while(temp)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
bool palindrome(node *head)
{
	stack<int>s;
	node *temp=head;
	while(temp)
	{
		s.push(temp->data);
		temp=temp->next;
	}
	temp=head;
	while(temp)
	{
		if(s.top()!=temp->data)
			return false;
		s.pop();
		temp=temp->next;
	}
	return true;
}
int32_t main()
{
	c_p_c();
	int n,k;
	cin>>n;
	node *head=buildLinkdedList(n);
	int *a;
	cout<<sizeof(node)<<sizeof(head)<<sizeof(*head)<<sizeof(int);
	if(palindrome(head))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}