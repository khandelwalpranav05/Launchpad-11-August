#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

template <typename T>
class Graph{
	unordered_map< T,list<T> > adjList;

public:
	Graph(){

	}

	void addEdge(T u,T v,bool bidir = true){
		adjList[u].push_back(v);

		if(bidir){
			adjList[v].push_back(u);
		}
	}

	void display(){
		for(auto vertex:adjList){
			cout<<vertex.first<<" -> ";

			for(T node:vertex.second){
				cout<<node<<" ,";
			}
			cout<<endl;
		}
	}
};

int main(){

	// Graph g;

	// g.addEdge(1,2);
	// g.addEdge(2,3);
	// g.addEdge(1,3);

	// g.display();

	Graph<string> g;
	g.addEdge("Coding Blocks","Java");
	g.addEdge("Coding Blocks","Python");
	g.addEdge("Coding Blocks","Django");
	g.addEdge("Pranav","Coding Blocks");

	g.display();

	return 0;
}