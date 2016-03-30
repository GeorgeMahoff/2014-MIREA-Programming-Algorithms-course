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

    void addEdge(int x, int w)
	{
		adj[x].push_back(w);
	}

	void fill(int x, bool used[], stack<int> &Stack)
	{
		used[x] = 1;
 
		list<int>::iterator i;
		for(i = adj[x].begin(); i != adj[x].end(); ++i)
			if(!used[*i])
				fill(*i, used, Stack);

		Stack.push(x);
	}

    void DFS(int x, bool used[])
	{
		used[x] = 1;
		cout << x << " ";
		list<int>::iterator i;
		for (i = adj[x].begin(); i != adj[x].end(); ++i)
			if (!used[*i])
				DFS(*i, used);
	}

    Graph getTranspose()
	{
		Graph g(X);
		for (int x = 0; x < X; x++)
		{
			list<int>::iterator i;
			for(i = adj[x].begin(); i != adj[x].end(); ++i)
			{
				g.adj[*i].push_back(x);
			}
		}
		return g;
	}

	void findSCC()
	{
		stack<int> Stack;

		bool *used = new bool[X];
		for(int i = 0; i < X; i++)
			used[i] = 0;

		for(int i = 0; i < X; i++)
			if(used[i] == 0)
				fill(i, used, Stack);

		Graph gr = getTranspose();
 
		for(int i = 0; i < X; i++)
			used[i] = 0;
		while (Stack.empty() == 0)
		{
			int x = Stack.top();
			Stack.pop();
 
			if (used[x] == 0)
			{
				gr.DFS(x, used);
				cout << endl;
			}
		}
	}
};