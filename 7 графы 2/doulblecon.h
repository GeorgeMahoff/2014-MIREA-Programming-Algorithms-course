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
		adj[w].push_back(x);// из-за неориентированности
	}

	void brindge_sup(int u, bool used[], int disc[], int low[], int par[])
	{
		static int time = 0;
		used[u] = 1;
		disc[u] = low[u] = ++time;

		list<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int x = *i;
			if (!used[x])
			{
				par[x] = u;
				brindge_sup(x, used, disc, low, par);
				low[u]  = min(low[u], low[x]);
 
				if (low[x] > disc[u])
				  cout << u <<" " << x << endl;
			}
			else if (x != par[u])
				low[u]  = min(low[u], disc[x]);
		}
	}
 
	void bridge()
	{
		bool *used = new bool[X];
		int *disc = new int[X];
		int *low = new int[X];
		int *par = new int[X];
 
		for (int i = 0; i < X; i++)
		{
			par[i] = -1;
			used[i] = 0;
		}
		for (int i = 0; i < X; i++)
			if (used[i] == 0)
				brindge_sup(i, used, disc, low, par);
	}
};