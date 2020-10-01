#include<iostream>
#include<stack>
using namespace std;
long long areaHist(long long a[],int n)
{
	stack<int>in;
	int i=0;
	long long maxarea=0,area,tp;
	while(i<n)
	{
		if(in.empty()||a[in.top()]<a[i])
		{
			in.push(i++);
			
		}
		else
		{
			tp=in.top();
			in.pop();
			if(!in.empty())
			area=a[tp]*(i-in.top()-1);
			else
				area=a[tp]*(i);
			maxarea=max(maxarea,area);
		}

		
	}
		while(!in.empty())
		{
			tp=in.top();
			in.pop();
			if(!in.empty())
			area=a[tp]*(i-in.top()-1);
			else
				area=a[tp]*(i);
			maxarea=max(maxarea,area);
		}
		return maxarea;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int i=0;
	long long a[n];
	while(n--)
	{
		cin>>a[i++];
	}
	cout<<areaHist(a,i);
	
		return 0;
}