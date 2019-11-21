#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

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

	void bfs(T src){
		queue<T> q;
		unordered_map<T,bool> visited;

		visited[src] = true;
		q.push(src);

		while(!q.empty()){

			T node = q.front();
			q.pop();

			cout<<node<<" ";

			for(T neighbor:adjList[node]){
				if(!visited[neighbor]){
					q.push(neighbor);
					visited[neighbor] = true;
				}
			}

		}

		cout<<endl;	
	}
};

int main(){

	// Graph g;

	// g.addEdge(1,2);
	// g.addEdge(2,3);
	// g.addEdge(1,3);

	// g.display();

	// Graph<string> g;
	// g.addEdge("Coding Blocks","Java");
	// g.addEdge("Coding Blocks","Python");
	// g.addEdge("Coding Blocks","Django");
	// g.addEdge("Pranav","Coding Blocks");

	// g.display();

	Graph<int> g;

	g.addEdge(1,2);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(3,5);
	g.addEdge(5,6);
	g.addEdge(5,4);

	g.display();

	g.bfs(1);

	return 0;
}