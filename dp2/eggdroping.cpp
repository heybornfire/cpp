#include<iostream>
#include <cstdlib>
#include<cstring>
#include<algorithm>
#include <climits>
using namespace std;
int memo[1000][1000];
int eggdropping(int n,int k)
{
	if(n==1)
		return k;
	if(k==1||k==0)
		return k;
	if(memo[n][k]!=-1)
		return memo[n][k];
	int mintrial=INT_MAX;
	for(int i=1;i<=k;i++)
	{
		mintrial=min(mintrial,1+max(eggdropping(n-1,i-1),eggdropping(n,k-i)));
		
	}
	memo[n][k]=mintrial;
	return mintrial;

}
int eggdroppingdp(int n,int k)
{
	int dp[1000][1000];//making dp declaration

	for(int i=1;i<=n;i++)
	{
		dp[i][0]=0;//initialization
		dp[i][1]=1;
	}
	for(int i=2;i<=k;i++)
	{
		dp[1][i]=i;
	}
	for(int eggs=2;eggs<=n;eggs++)
	{
		for(int floor=2;floor<=k;floor++)
		{
			dp[eggs][floor]=INT_MAX;//first set to max
			for(int x=1;x<=floor;x++)
			{
				//find minimum of two cases
				dp[eggs][floor]=min(dp[eggs][floor],1+max(dp[eggs][floor-x],dp[eggs-1][x-1]));
			}
			
		}
	}
	
	return dp[n][k];
}
int main(int argc, char const *argv[])
{
	int n,k,t;
	memset(memo,-1,sizeof(memo));//intializes the memo
	cin>>t;
	while(t--)
	{
		cin>>k>>n;//taking input
		cout<<eggdroppingdp(k,n)<<endl;
	}
	return 0;
}