#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <climits>

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

	void shortestPathBFS(T src){
		queue<T> q;
		unordered_map<T,int> dist;

		for(auto node:adjList){
			dist[node.first] = INT_MAX;
		}

		dist[src] = 0;
		q.push(src);

		while(!q.empty()){

			T node = q.front();
			q.pop();

			for(T neighbor:adjList[node]){
				if(dist[neighbor]==INT_MAX){
					dist[neighbor] = dist[node] + 1;
					q.push(neighbor);
				}
			}
		}

		for(auto vertex:adjList){
			cout<<"Distance of "<<vertex.first<<" from source is "<<dist[vertex.first]<<endl;
		}
	}

	void dfsHelper(T src,unordered_map<T,bool> &visited){

		cout<<src<<" ";
		visited[src] = true;

		for(T neighbor:adjList[src]){
			if(!visited[neighbor]){
				dfsHelper(neighbor,visited);
			}
		}
	}

	void dfs(T src){
		unordered_map<T,bool> visited;

		int component = 1;

		dfsHelper(src,visited);

		cout<<endl;

		for(auto node:adjList){
			if(!visited[node.first]){
				dfsHelper(node.first,visited);
				component++;
				cout<<endl;
			}
		}

		cout<<"Number of Components "<<component<<endl;
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
	g.addEdge(1,5);

	g.addEdge(8,9);
	g.addEdge(9,10);
	g.addEdge(10,8);

	g.display();

	// g.bfs(1);
	// g.shortestPathBFS(1);

	g.dfs(1);

	return 0;
}