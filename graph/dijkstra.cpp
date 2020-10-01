#include<iostream>
#include<unordered_map>
#include<set>
#include<climits>
#include <list>
using namespace std;
template<typename T>
class Graph
{
	unordered_map<T,list<pair<T,int>>>adjList;
public:
	void addEdge(T u,T v,int dist,bool bidir=true)
	{
		adjList[u].push_back(make_pair(v,dist));
		if(bidir)
			adjList[v].push_back(make_pair(u,dist));
	}
	void dijkstra(T src)
	{
		unordered_map<T,int> dist;
		set<pair<int,T>>s;
		for(auto i:adjList)
		{
			dist[i.first]=INT_MAX;
		}
		dist[src]=0;
		s.insert(make_pair(dist[src],src));
		while(!s.empty())
		{
			auto p=*(s.begin());
			T node=p.second;
			int nodedist=p.first;
			s.erase(s.begin());
			for(auto neighbourPair:adjList[node])
			{
				if(dist[neighbourPair.first]>nodedist+neighbourPair.second)
				{
					if(dist[neighbourPair.first]!=INT_MAX)
					{
						auto f=s.find(make_pair(dist[neighbourPair.first],neighbourPair.first));
						s.erase(f);
					}
					dist[neighbourPair.first]=nodedist+neighbourPair.second;
					s.insert(make_pair(dist[neighbourPair.first],neighbourPair.first));	
				}

			}
		}
		for(auto d:dist)
		{
			cout<<d.first<<"dist is :"<<d.second<<endl;
		}
	}
};
int main(int argc, char const *argv[])
{
	Graph<string> g;
	g.addEdge("haridwar","delhi",10);
	g.addEdge("haridwar","kolkata",20);
	g.addEdge("jaipur","delhi",20);
	g.addEdge("lucknow","delhi",15);
	g.addEdge("jaipur","mumabai",30);
	g.addEdge("delhi","mumabai",40);
	g.addEdge("lucknow","mumabai",80);
	g.addEdge("chennai","mumabai",10);
	g.addEdge("chennai","kolkata",50);
	g.addEdge("ranchi","kolkata",12);
	g.addEdge("lucknow","kolkata",40);
	g.addEdge("lucknow","ranchi",30);
	g.addEdge("lucknow","jaipur",30);
	g.dijkstra("ranchi");
	return 0;
}