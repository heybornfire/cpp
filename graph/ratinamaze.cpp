#include<bits/stdc++.h>
using namespace std;
bool ratInMaze(vector<vector<char>> &board,int i,int j)
{
	if(i>=board.size()||j>=board[0].size()||board[i][j]=='X')
		{
				//cout<<i<<" "<<j<<board.size()<<board[0].size()<<endl;

			return false;
		}
	if(i==board.size()-1 && j==board[0].size()-1)
	{
		board[i][j]='1';
		for(int i=0;i<board.size();i++)
		{
			for(int j=0;j<board[i].size();j++)
			{
					if(board[i][j]!='1')
						cout<<0<<" ";
					else
						cout<<1<<" ";
			}
			cout<<endl;
		}
		board[i][j]='0';
		//cout<<"-----------"<<endl;
		return true;
	}
	
	else
	{
		board[i][j]='1';
		if(ratInMaze(board,i,j+1))
			return true;
		if(ratInMaze(board,i+1,j))
			return true;
		
		board[i][j]='O';
		return false;
	}

}
int main()
{
	/* code */
	int n,m;
	cin>>n>>m;
	vector<vector<char>> board(n,vector<char>(m,'O'));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cin>>board[i][j];
	}
	if(!ratInMaze(board,0,0))
		cout<<-1<<endl;
	return 0;
}