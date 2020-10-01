#include<bits/stdc++.h>
using namespace std;
int maxrow1s(int R,int C,bool mat[][10])
{
	int startIndex=-1;
	int maxRow=-1;
	for(int i=0;i<C;i++)
	{
		if(mat[0][i]==1)
		{
			startIndex=i;
			maxRow=0;
			break;
		}
	}
	if(startIndex==-1)
		startIndex=C;
	for(int i=1;i<R;i++)
	{
		while(startIndex>0 && mat[i][startIndex-1]==1)
		{
			startIndex--;
			maxRow=i;
		}
	}
	return maxRow;
}
int main()
{
	bool mat[][10] = { {0, 0, 0, 0},  
                    {0, 0, 0, 0},  
                    {0, 0, 0, 0},  
                    {0, 0, 0, 0}};  
  
    cout << "Index of row with maximum 1s is " << maxrow1s(4,4,mat);  
  
    return 0;  
}  
  
// This is code is contributed by rathbhupendra 


