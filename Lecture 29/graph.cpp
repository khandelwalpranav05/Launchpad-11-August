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
	Graph(){}

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

	void dfsTopologicalSortHelper(T node,unordered_map<T,bool> &visited,list<T> &ordering){
		
		visited[node] = true;

		for(T neighbor:adjList[node]){
			if(!visited[neighbor]){
				dfsTopologicalSortHelper(neighbor,visited,ordering);
			}
		}

		ordering.push_front(node);
	}

	void dfsTopologicalSort(T src){

		unordered_map<T,bool> visited;
		list<T> ordering;

		dfsTopologicalSortHelper(src,visited,ordering);

		for(T val:ordering){
			cout<<val<<"-> ";
		}
		cout<<endl;
	}

	void journeyToMoonHelper(T node,unordered_map<T,bool> &visited,int &countrySize){

		countrySize++;
		visited[node] = true;

		for(T neighbor:adjList[node]){
			if(!visited[neighbor]){
				journeyToMoonHelper(neighbor,visited,countrySize);
			}
		} 
	}

	int journeyToMoon(){

		int n = adjList.size();
		unordered_map<T,bool> visited;

		int total = n*(n-1)/2;

		for(auto node:adjList){
			if(!visited[node.first]){
				int countrySize = 0;
				journeyToMoonHelper(node.first,visited,countrySize);
				total -= countrySize*(countrySize - 1)/2;
			}
		}

		return total;
	}

	int snakesAndLadder(int src){
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

		return dist[36];
	}

	void bfsTopologicalSort(){
		queue<T> q;
		unordered_map<T,int> indegree;

		for(auto vertex:adjList){
			for(T v:vertex.second){
				indegree[v]++;
			}
		}

		for(auto vertex:adjList){
			if(indegree[vertex.first]==0){
				q.push(vertex.first);
			}
		}

		while(!q.empty()){

			T node = q.front();
			q.pop();

			cout<<node<<" ";

			for(T neighbor:adjList[node]){
				indegree[neighbor]--;

				if(indegree[neighbor]==0){
					q.push(neighbor);
				}
			}
		}

		cout<<endl;
	}

	bool isCyclic(T src){

		queue<T> q;
		unordered_map<T,bool> visited;
		unordered_map<T,T> parent;

		parent[src] = src;
		visited[src] = true;
		q.push(src);

		while(!q.empty()){

			T node = q.front();
			q.pop();

			for(T neighbor:adjList[node]){

				if(visited[neighbor] and parent[node]!=neighbor){
					return true;

				}else if(!visited[neighbor]){
					q.push(neighbor);
					visited[neighbor] = true;
					parent[neighbor] = node;
				}

			}
		}

		return false;
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

	// Graph<int> g;

	// g.addEdge(1,2);
	// g.addEdge(1,4);
	// g.addEdge(2,3);
	// g.addEdge(3,4);
	// g.addEdge(3,5);
	// g.addEdge(5,6);
	// g.addEdge(5,4);
	// g.addEdge(1,5);

	// g.addEdge(8,9);
	// g.addEdge(9,10);
	// g.addEdge(10,8);

	// g.display();

	// g.bfs(1);
	// g.shortestPathBFS(1);

	// g.dfs(1);

	// Graph<int> g;

	// g.addEdge(1,2,false);
	// g.addEdge(1,3,false);
	// g.addEdge(2,4,false);
	// g.addEdge(3,4,false);

	// g.dfsTopologicalSort(1);

	Graph<int> g;

	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(4,5);
	// g.addEdge(1,2);

	cout<<g.journeyToMoon()<<endl;

	// Graph<int> g;

	// int board[50] = {0};

	// board[2] = 13;
	// board[5] = 2;
	// board[9] = 18;
	// board[18] = 11;
	// board[17] = -13;
	// board[20] = -14;
	// board[24] = -8;
	// board[25] = -10;
	// board[32] = -2;
	// board[34] = -22;

	// for(int i=0;i<=36;i++){
	// 	for(int dice = 1;dice<=6;dice++){
	// 		int u = i;
	// 		int v = u + dice + board[u+dice];
	// 		g.addEdge(u,v,false);
	// 	}
	// }

	// cout<<g.snakesAndLadder(0)<<endl;

	// Graph<int> g;

	// g.addEdge(1,4,false);
	// g.addEdge(1,3,false);
	// g.addEdge(2,4,false);
	// g.addEdge(2,3,false);
	// g.addEdge(2,5,false);
	// g.addEdge(3,5,false);
	// g.addEdge(4,5,false);

	// g.bfsTopologicalSort();

	// Graph<int> g;

	// // g.addEdge(1,2);
	// // g.addEdge(1,4);
	// // g.addEdge(2,3);
	// // g.addEdge(3,4);
	// // g.addEdge(3,5);
	// // g.addEdge(5,6);
	// // g.addEdge(5,4);
	// // g.addEdge(1,5);

	// // g.addEdge(1,2);
	// // g.addEdge(1,3);
	// // g.addEdge(3,4);
	// // g.addEdge(4,5);

	// // cout<<g.isCyclic(1)<<endl;

	return 0;
}