#include<bits/stdc++.h>
using namespace std;
int maxprofit(int arr[],int n)
{
	int profit[n]={0};
	int minPrice=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]<minPrice)
			minPrice=arr[i];
		profit[i]=max(profit[i-1],arr[i]-minPrice);
	}
	int maxPrice=arr[n-1];
	for(int i=n-2;i>=0;i--)
	{
		if(arr[i]>maxPrice)
			maxPrice=arr[i];
		profit[i]=max(profit[i+1],profit[i]+(maxPrice-arr[i]));
	}
	return profit[0];
}
int maxprofit2(int arr[],int n)
{
	int profit1[n]={0};
	int minPrice=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]<minPrice)
			minPrice=arr[i];
		profit1[i]=max(profit1[i-1],arr[i]-minPrice);
	}
	int maxPrice=arr[n-1];
	int profit2[n]={0};
	for(int i=n-2;i>=0;i--)
	{
		if(arr[i+1]>maxPrice)
			maxPrice=arr[i+1];
		profit2[i]=max(profit2[i+1],(maxPrice-arr[i+1]));
	}
	int result=0;
	for(int i=0;i<n;i++)
	{
		result=max(profit2[i]+profit1[i],result);
	}
	return result;
}

int main()
{
	 int  price[] = {10, 22, 23, 75, 79, 80};
    int n = sizeof(price)/sizeof(price[0]); 
    cout << "Maximum Profit = " << maxprofit2(price, n); 
	return 0;
}