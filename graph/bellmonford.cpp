#include<iostream>
#include <climits>
using namespace std;
class Edge
{
public:
	int src,dest,weight;
};
class Graph
{
	int v,e;
	Edge *edge;
public:
	Graph(int v,int e)
	{
		this->v=v;
		this->e=e;
		edge=new Edge[e];
	}
	void addEdge(int u,int v,int weight,int cnt)
	{
		edge[cnt].src=u;
		edge[cnt].dest=v;
		edge[cnt].weight=weight;
	}
	void bellmanFord(int sourc)
	{
		int distance[v];
		for(int i=0;i<v;i++)
		{
			distance[i]=INT_MAX;
		}
		distance[sourc]=0;
		for(int i=1;i<v;i++)
		{
			for(int j=0;j<e;j++)
			{
				int src=edge[j].src;
				int dest=edge[j].dest;
				int weight=edge[j].weight;
				if(distance[src]!=INT_MAX)
				{
					if(distance[src]+weight<distance[dest])
						distance[dest]=distance[src]+weight;
				}
			}
		}
		for(int j=0;j<e;j++)
			{
				int src=edge[j].src;
				int dest=edge[j].dest;
				int weight=edge[j].weight;
					if(distance[src]+weight<distance[dest])
					{
						cout<<"negative weight cycle";
						//return;
					}
					
			}
			for(int i=0;i<v;i++)
			{
				cout<<"distance of "<<i<<"is"<<distance[i]<<endl;
			}
		
		

	}
};
int main(int argc, char const *argv[])
{
	Graph g(5,8);
	g.addEdge(1,2,3,0);
	g.addEdge(1,3,4,1);
	g.addEdge(1,4,5,2);
	g.addEdge(1,5,6,3);
	g.addEdge(3,2,3,4);
	g.addEdge(4,2,3,5);
	g.addEdge(5,4,3,6);
	g.addEdge(5,3,7,7);
	g.bellmanFord(3);
	return 0;
}