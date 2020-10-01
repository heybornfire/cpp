#include<iostream>
#include<stack>
using namespace std;
void printSpan(int price[],int n)
{
	stack<int>s;
	int stock[n];
	for(int i=0;i<n;i++)
	{
		int currPrice=price[i];
		while(!s.empty()&& price[s.top()]<currPrice)
		{
			s.pop();
		}
		int span=s.empty()?-1:s.top();
		stock[i]=i-span;
		s.push(i);


	}
	for(int i=0;i<n;i++)
		cout<<stock[i]<<" ";
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int *arr=new int[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		printSpan(arr,n);
	}
	

}