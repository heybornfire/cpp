#include<bits/stdc++.h>
using namespace std;
#define C 10
void zigzag(int row,int col,int mat[][C])
{
	for(int i=0;i<row;i+=2)
	{
		for(int j=0;j<col;j++)
			cout<<mat[i][j]<<" ";
		if(i+1<row)
		{
			for(int j=col-1;j>=0;j--)
				cout<<mat[i+1][j];
		}
	}
}
void spiral(int row,int col,int mat[][C])
{
	int startRow=0,startCol=0;
	int endRow=row-1,endCol=col-1;
	while(startRow<=endRow && startCol<=endCol)
	{
		for(int i=startCol;i<=endCol;i++)
			cout<<mat[startRow][i];
		startRow++;
		for(int i=startRow;i<=endRow;i++)
			cout<<mat[i][endCol];
		endCol--;
		if(startRow<=endRow)
		{
		for(int i=endCol;i>=startCol;i--)
			cout<<mat[endRow][i];
		endRow--;
		}
		if(startCol<=endCol)
		{
		for(int i=endRow;i>=startRow;i--)
			cout<<mat[i][startCol];

		startCol++;
		}

	}
}
int median(int row,int col,int mat[][C])
{
	int maxNumber=INT_MIN,minNumber=INT_MAX;
	for(int i=0;i<row;i++)
	{
		maxNumber=max(maxNumber,mat[i][col-1]);
	}
	for(int i=0;i<row;i++)
	{
		minNumber=min(minNumber,mat[i][col-1]);
	}
	int desired=(row*col+1)/2;
	int place;
	int posi;
	while(minNumber<maxNumber)
	{
		int mid=(minNumber+maxNumber)/2;
		place=0;
		for(int i=0;i<row;i++)
		{
			place+=upper_bound(mat[i],mat[i]+col,mid)-mat[i];
		}
		if(place<desired)
			minNumber=mid+1;
		else if (place>desired)
			maxNumber=mid-1;
		else
		{
			maxNumber=mid;
		}

	}
	return minNumber;
}

int main(int argc, char const *argv[])
{
	int mat[][10]={{1,2,3},
				  {4,5,6},
				  {7,8,9},};
	cout<<median(3,3,mat);
	return 0;
	}
