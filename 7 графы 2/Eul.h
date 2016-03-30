#include "stdafx.h"
// граф реализован как класс (сам полез в это болото, раньше нравилось больше, но хоть в STL поработал)
class Graph
{
	int X;
	list<int> *adj;
public:
	Graph(int X)  
	{
		this->X = X;  
		adj = new list<int>[X];  
	}

	void addEdge(int u, int x) 
	{  
		adj[u].push_back(x); 
		adj[x].push_back(u); 
	}

	void delEdge(int u, int x)
	{
		list<int>::iterator iv = find(adj[u].begin(), adj[u].end(), x);
		*iv = -1;

		list<int>::iterator iu = find(adj[x].begin(), adj[x].end(), u);
		*iu = -1;
	}

	void printEulerTour()
	{
		int u = 0;
		for (int i = 0; i < X; i++)
			if (adj[i].size() & 1)
			{
				u = i; 
				break;  
			}
		print_way(u);
		cout << endl;
	}

	void print_way(int u)
	{
		list<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int x = *i;
			if (x != -1 && isValidNextEdge(u, x))
			{
				cout << u << "->" << x << "  ";
				delEdge(u, x);
				print_way(x);
			}
		}
	}

	bool isValidNextEdge(int u, int x)
	{
		int count = 0;
		list<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
			if (*i != -1)
				count++;
		if (count == 1)
			return true;

		bool* visited = new bool(X);
		memset(visited, 0, X);
		int c1 = DFS(u, visited);

		delEdge(u, x);
		memset(visited, 0, X);
		int c2 = DFS(u, visited);

		addEdge(u, x);

		return (c1 > c2)? 0: 1;
	}

	int DFS(int x, bool visited[])
	{
		visited[x] = 1;
		int count = 1;
 
		list<int>::iterator i;
		for (i = adj[x].begin(); i != adj[x].end(); ++i)
			if (*i != -1 && !visited[*i])
				count += DFS(*i, visited);
 
		return count;
	}
};