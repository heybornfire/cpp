#include<iostream>
#include<queue>
#include<vector>
#include <string>
using namespace std;
bool isSafe(int i ,int j,int n)
{
    if(i>=0 && i<n && j>=0 && j<n)
        return true;
        return false;
}
void bfs(vector<vector<char>> &grid,int i ,int j,int n)
{
    grid[i][j]='0';
    queue<pair<int,int>> indices;
    indices.push(make_pair(i,j));
    int dx[]={0,0,1,-1,};
    int dy[]={1,-1,0,0,};
    while(!indices.empty())
    {
        int x=indices.front().first;
        int y=indices.front().second;
        indices.pop();
        for(int i=0;i<4;i++)
        {
            if(isSafe(x+dx[i],y+dy[i],n)&& grid[x+dx[i]][y+dy[i]]!='0')
            {
                indices.push(make_pair(x+dx[i],y+dy[i]));
                grid[x+dx[i]][y+dy[i]]='0';
            }
        }

    }
    
}
int main()
{
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<vector<char>> grid(n,vector<char>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cin>>grid[i][j];
            //cout<<endl;
        }
        int count =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    bfs(grid,i,j,n);
                    count++;
                }
            }
        }
        if(count%2==0)
        cout<<"EVEN"<<endl;
        else
            cout<<"ODD"<<endl;
    }
    return 0;
}