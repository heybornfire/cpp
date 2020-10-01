#include <bits/stdc++.h>
//#define int long long

using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int hor[n],ver[m];
		for(int i=0;i<n-1;i++)
		{
			cin>>hor[i];
		}
		for(int i=0;i<m-1;i++)
			cin>>ver[i];
		sort(hor,hor+n-1,greater<int>());
		sort(ver,ver+m-1,greater<int>());
		int verPieces=1,horPieces=1;
		long long cost=0;
		while(verPieces<m && horPieces<n)
		{
			if(hor[horPieces-1]>=ver[verPieces-1])
			{
				//cout<<hor[horPieces-1]<<endl;
				cost+=hor[horPieces-1]*verPieces;
				horPieces++;
			}
			else
			{
				//cout<<ver[verPieces-1]<<endl;

				cost+=ver[verPieces-1]*horPieces;
				verPieces++;
			}
		}
		while(verPieces<m)
		{
				//cout<<ver[verPieces-1]<<endl;

			cost+=ver[verPieces-1]*horPieces;
				verPieces++;
		}
		while(horPieces<n)
		{
				//cout<<hor[horPieces-1]<<endl;

			cost+=hor[horPieces-1]*verPieces;
				horPieces++;
		}
		cout<<cost<<endl;

	}
}
