#include<bits/stdc++.h>
using namespace std;
int memo[1000];
int _lisrec(int arr[],int n,int i)
{
	if(i==0)
		return 1;
	if(memo[i]!=-1)
	{
		return memo[i];
	}
	int lis=1;
	for(int j=i-1;j>=0;j--)
	{
		if(arr[j]<arr[i])
		lis=max(lis,1+lisrec(arr,n,j));
	}
	memo[i]=lis;
	return memo[i];
}
int lisdp(int arr[],int n)
{
	int dp[n];
	//length of incresing sunseq ending with ith position
	for(int i=0;i<n;i++)
		dp[i]=1;
	int best=0;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i])
			{
				dp[i]=max(dp[i],1+dp[j]);
			}
			best=max(best,dp[i]);
		}
	}
	return best;

}
int main(int argc, char const *argv[])
{
	memset(memo,-1,sizeof(memo));
	int arr[]={3,10,1,2,20};
	cout<<lisdp(arr,5);
	cout<<lisrec(arr,5,1);
	return 0;
}