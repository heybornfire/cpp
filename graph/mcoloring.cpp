#include<bits/stdc++.h>
using namespace std;
bool isSafe(bool graph[][4],int col[],int vertex,int color)
{
	// for(int i=0;i<4;i++)
	// {
	// 	if(graph[vertex][i] && col[i]==color)
	// 		return false;
	// }
	// return true;
	for(int i=0;i<vertex;i++)
	{
		if(graph[vertex][i] && col[i]==color)
			return false;
	}
	return true;
}

bool graphColoring(bool graph[][4],int m,int col[],int vertex)
{
	if(vertex==4)
	{
		//print solution
		for(int i=0;i<vertex;i++)
			cout<<col[i];

		return true;
	}

	for(int c=1;c<=m;c++)
	{
		if(isSafe(graph,col,vertex,c))
		{
			col[vertex]=c;
			if(graphColoring(graph,m,col,vertex+1))
			{
				return true;
			}
			col[vertex]=0;
		}
		


	}
	return false;
}
int main(int argc, char const *argv[])
{
	bool graph[4][4] = {{0, 1, 1, 1}, 
        {1, 0, 1, 0}, 
        {1, 1, 0, 1}, 
        {1, 0, 1, 0}, 
    }; 
    int m = 3;
    int color[4]={0}; // Number of colors 
    cout<<graphColoring (graph, m,color,0); 
	return 0;
}