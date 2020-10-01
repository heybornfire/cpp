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
int multiply(int multiply[],int n,int x)
{
	int carry=0,prod;
	for(int i=0;i<n;i++)
	{
		prod=multiply[i]*x+carry;
		multiply[i]=prod%10;
		carry=prod/10;
	}
	while(carry>0)
	{
		multiply[n++]=carry%10;
		carry/=10;
	}
	return n;
}
int factorial(int arr[],int num)
{
	arr[0]=1;
	int length=1;
	for(int i=1;i<=num;i++)
	{
		length=multiply(arr,length,i);
	}
	return length;
}
void print(int arr[],int n)
{
	for(int i=n-1;i>=0;i--)
	{
		cout<<arr[i];
	}
	cout<<endl;
}
int32_t main()
{
	c_p_c();
	int n;
	cin>>n;
	int arr[1140];
	int length=factorial(arr,n);
	print(arr,length);
	return 0;
}