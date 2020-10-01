#include <bits/stdc++.h>
using namespace std;
pair<int,int> minmax(int arr[],int n)
{
	pair<int,int> minmax{INT_MAX,INT_MIN};
	for(int i=0;i<n;i++)
	{
		if(arr[i]>minmax.second)
		{
			minmax.second=arr[i];
		}
		else if(arr[i]<minmax.first)
		{
			minmax.first=arr[i];
		}
	}
	return minmax;
}
int kthLargest(int arr[],int n,int k)
{
	priority_queue<int,vector<int>,greater<int>>klarge(arr,arr+k);
	for(int i=k;i<n;i++)
	{
		if(arr[i]>klarge.top())
		{
			klarge.pop();
			klarge.push(arr[i]);

		}
	}
	return klarge.top();
}
int numberOfOccurences(int arr[],int n,int key)
{
		int *i=lower_bound(arr,arr+n,key);
		if(i==arr+n|| *i!=key)
		{
			return 0;
		}
		int *j=upper_bound(i,arr+n,key);
		return i-j;
}
int reverse(int arr[],int n)
{
	int start=0;
	int end=n-1;
	int temp;
	while(start<end)
	{
		temp=arr[start];
		arr[start]=arr[end];
		arr[end]=temp;
		start++;
		end--;
	}
}
int reverseRecursion(int arr[],int start,int end)
{
	if(start<end)
	{
		reverseRecursion(arr,start+1,end-1);
		int temp=arr[start];
		arr[start]=arr[end];
		arr[end]=temp;
	}
}
void largest3(int arr[],int n)
{
	int firstLargest=INT_MIN,secondLargest=INT_MIN,thirdLargest=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>=firstLargest)
		{
			thirdLargest=secondLargest;
			secondLargest=firstLargest;
			firstLargest=arr[i];
		}
		else if(arr[i]>=secondLargest)
		{
			thirdLargest=secondLargest;
			secondLargest=arr[i];
		}
		else if(arr[i]>=thirdLargest)
		{
			thirdLargest=arr[i];
		}
	}
	cout<<firstLargest<<" "<<secondLargest<<" "<<thirdLargest;
}
void merge(int arr[],int start,int end)
{
	int mid=(start+end)/2;
	int i=start;
	while(start<=mid && arr[i]<0)
		i++;
	int j=mid+1;
	while(j<=end && arr[j]<0)
		j++;
	//arr[start,i-1] arr[i,mid],arr[mid+1,j-1],arr[j,end]
	reverseRecursion(arr,i,mid);
	reverseRecursion(arr,mid+1,j-1);
	reverseRecursion(arr,i,j-1);
}
int * unionn(int a[],int n,int b[],int m)
{
	int *unon=new int(n+m);
	if(n>m)
	{
		sort(b,b+m);
		memcpy(unon,b,sizeof(int)*m);
		int j=m;
		for(int i=0;i<n;i++)
		{
			if(!binary_search(b,b+m,a[i]))
				unon[j++]=a[i];
		}

	}
	else
	{

		sort(a,a+n);
		memcpy(unon,a,sizeof(int)*n);
		int j=n;
		for(int i=0;i<m;i++)
		{
			if(!binary_search(a,a+n,b[i]))
				unon[j++]=b[i];
		}
	}
	return unon;
}
int * intersection(int a[],int n,int b[],int m)
{
	int *inters=new int(m+n);
	if(n<m)
	{
		sort(a,a+n);
		int j=0;
		for(int i=0;i<m;i++)
		{
			if(binary_search(a,a+n,b[i]))
			{
				inters[j++]=b[i];
			}
		}
	}
	else
	{
		sort(b,b+m);
		int j=0;
		for(int i=0;i<n;i++)
		{
			if(binary_search(b,b+m,a[i]))
			{
				inters[j++]=a[i];
			}
		}
	}
	return inters;
}
void cyclicrotate(int arr[],int n)
{
	int temp=arr[n-1];
	int i=n-1;
	while(i>0)
	{
		arr[i]=arr[i-1];
		i--;
	}
	arr[i]=temp;
}
int dupilicate1ton(int arr[],int n)
{
	int sum=1;
	for(int i=0;i<n;i++)
	{
		sum+=i+2;
		sum-=arr[i];

	}
	return sum;
}
void findDuplicates(int arr[],int n)
{
	
	for(int i=0;i<n;i++)
	{
		arr[arr[i]%n]+=n;
		
	}
	for(int i=0;i<n;i++)
	{
		int numberOfOccurences=arr[i]/n;
		if(numberOfOccurences>1)
			cout<<i<<" "<<arr[i]<<endl;
	}
}
int pairwithsum(int arr[],int n,int sum)
{
	unordered_map<int,int> freq;
	for(int i=0;i<n;i++)
	{
		freq[arr[i]]++;
	}
	int twicecount=0;
	for(int i=0;i<n;i++)
	{
		twicecount+=freq[sum-arr[i]];
		if(sum-arr[i]==arr[i])
			twicecount--;
	}
	return twicecount/2;
}
void rearrangenegpos(int arr[],int start,int end)
{
	if(start<=end)
	{
	int mid=(start+end)/2;
	rearrangenegpos(arr,start,mid);
	rearrangenegpos(arr,mid+1,end);
	merge(arr,start,end);
	}
}
void printArray(int A[], int size) 
{ 
    for (int i = 0; i < size; i++) 
        cout << A[i] << " "; 
    cout << endl; 
} 
void common3arrays(int ar1[],int ar2[],int ar3[],int m,int n,int o)
{
	int i=0,j=0,k=0;
	while(i<m && j<n && k<o)
	{
		 if (ar1[i] == ar2[j] && ar2[j] == ar3[k]) 
         {   cout << ar1[i] << " ";   i++; j++; k++; } 
  
         // x < y 
         else if (ar1[i] < ar2[j] && ar1[i] < ar3[k]) 
             i++; 
  
         // y < z 
         else if (ar2[j] < ar3[k] && ar2[j] < ar1[i]) 
             j++; 
  
         // We reach here when x > y and z < y, i.e., z is smallest 
         else
         	k++;
	}
}
void firstRepeating(int arr[],int n)
{
	unordered_map<int,int>freq;
	int minIndex=-1;
	for(int i=n-1;i>=0;i--)
	{	
		freq[arr[i]]++;
		if(freq[arr[i]]>1)
			minIndex=i;
	
	}
	if(minIndex>=0)
	 cout<<arr[minIndex]<<endl;
	else
		cout<<"nothing repeating\n";

}
void firstNonRepeating(int arr[],int n)
{
	unordered_map<int,int>freq;
	int minIndex=-1;
	for(int i=0;i<n;i++)
	{
		freq[arr[i]]++;

	}
	for(int i=0;i<n;i++)
	{
		if(freq[arr[i]]==1)
		{
			cout<<"min non repeating is "<<arr[i]<<endl;
			return;
		}
	}
	cout<<"no non repeating"<<endl;
}
int kadannes(int arr[],int n)
{
	int maxSum=INT_MIN;
	int currSum=0;
	for(int i=0;i<n;i++)
	{
		currSum+=arr[i];
		if(currSum<=0)
		{
			currSum=0;
		}
		if(currSum>maxSum)
			maxSum=currSum;
	}
	return maxSum;
}
int multiply(int res[],int resSize,int x)
{
	int carry=0;
	int product=1;
	for(int i=0;i<resSize;i++)
	{
		product=res[i]*x+carry;
		res[i]=product%10;
		carry=product/10;
	}
	while(carry)
	{
		res[resSize]=carry%10;
		carry/=10;
		resSize++;
	}
	return resSize;
}
void factorial(int n)
{
	int res[500];
	res[0]=1;
	int resSize=1;
	for(int i=1;i<=n;i++)
	{
		resSize=multiply(res,resSize,i);
	}
	cout<<"the huge factorial is";
	for(int i=resSize-1;i>=0;i--)
	{
		cout<<res[i];
	}

}
int lconsecutivesubsequence(int arr[],int n)
{
	sort(arr,arr+n);
	int count=1;int max=1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]=arr[i-1]+1)
		{
			count++;
		}
		else
		{
			count=1;
		}
		result=max(result,count);
	}
	return result;
}
int binarySearchrotated
int main()
{
	int ar1[] = {1, 5, 10, 20, 40, 5}; 
    int ar2[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
    int ar3[] = {3, 4, 15, 20, 30, 70, 80, 120}; 
    int n1 = sizeof(ar1)/sizeof(ar1[0]); 
    int n2 = sizeof(ar2)/sizeof(ar2[0]); 
    int n3 = sizeof(ar3)/sizeof(ar3[0]); 
    //firstRepeating(ar1,n1);
    //firstNonRepeating(ar2,n2);
   //cout<<kadannes(ar2,n2);
    factorial(100);
  
 //    cout << "Common Elements are "; 
 //    common3arrays(ar1, ar2, ar3, n1, n2, n3); 
	// // int n;
	// cin>>n;
	// int *arr=new int[n];
	// for(int i=0;i<n;i++)
	// {
	// 	cin>>arr[i];
	// }
	
	//findDuplicates(arr,n);
	//cout<<dupilicate1ton(arr,n);
	//cout<<pairwithsum(arr,n,6);
	//cyclicrotate(arr,n);
	// int a[]={1,2,3};
	// int *inter =unionn(arr,n,a,3);
	//merge(arr,0,n-1);
	//reverseRecursion(arr,0,n-1);
	
	//rearrangenegpos(arr,0,n-1);
	//printArray(inter,5);
	//largest3(arr,n);

	//cout<<kthLargest(arr,n,3);
	return 0;



	
}