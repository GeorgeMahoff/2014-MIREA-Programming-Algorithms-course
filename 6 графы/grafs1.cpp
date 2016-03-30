// grafs1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;

#define INF 10000000000

void BFS (int** g, int n,int st) //обход в ширину
{
	vector<bool> used (n,0);
	vector<int> par (n);
	queue<int> q;
	used[st] = 1;
	q.push(st);
	par[st] = -1;
	//cout<<st<<' ';
	while (!q.empty()) 
	{
		int v = q.front();
		q.pop();
		for (int i=0; i<n; ++i) 
		{
			int k = g[v][i];
			if (!used[i] && k!=0) 
			{
				used[i] = true;
				q.push (i);
				par[i] = v;
				//cout<<i<<' ';
			}
		}
	}
	// путь до вершины можно найти с помощью вектора par[]
	//cout<<endl;
}
void DFSm (int** g,int n,int st,vector<bool>used, vector<int> par)
{
	//cout<<st<<' ';
	for (int i=0;i<n;i++)
		if (!used[i] && g[st][i] != 0)
		{
			par[i]=st;
			DFSm (g,n,i,used,par);
		}
}
void DFS (int** g, int n,int st) //обход в глубину (изврат ради массива родителей)
{
	vector<bool> used (n,0);
	vector<int> par (n);
	used[st] = 1;
	par[st] = -1;
	//cout<<st<<' ';
	for (int i=0;i<n;i++)
		if (!used[i] && g[st][i] != 0)
		{
			par[i]=st;
			used[i] = 1;
			DFSm (g,n,i,used,par);
		}
	//cout<<endl;
}

void dikstra (int** g,int n,int st) //алгоритм Дейкстры
{
	vector<int> d (n, INF);
	vector< list<int> > p (n);
	for (int i=0;i<n;i++)
		p[i].push_back(st);
	d[st] = 0;
	set < pair<int,int> > q;
	q.insert (make_pair (d[st], st));
	while (!q.empty()) 
	{
		int v = q.begin()->second;
		q.erase (q.begin());
		for (int j=0; j<n; ++j) 
		{
			int	len = g[v][j];
			if (d[v] + len < d[j] && len != 0) 
			{
				q.erase (make_pair (d[j], j));
				d[j] = d[v] + len;
				p[j].push_back(v);
				q.insert (make_pair (d[j], j));
			}
		}
	}
	for (auto i: d)
		cout << i <<' ';
	cout<<endl;
	for (int i=0;i<n;i++)
	{
		while(!p[i].empty())
		{
			cout << p[i].front()<<' ';
			p[i].pop_front();
		}
	cout<<endl;
	}
}

void prima (int** g,int n) // алгоритм Прима
{
	vector<bool> used (n);
	vector<int> min_e (n, INF), sel_e (n, -1);
	min_e[0] = 0;
	for (int i=0; i<n; ++i) 
	{
		int v = -1;
		for (int j=0; j<n; ++j)
			if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
				v = j;
		used[v] = true;
		if (sel_e[v] != -1)
			cout << v << " " << sel_e[v] << endl;
		for (int to=0; to<n; ++to)
			if (g[v][to] < min_e[to]) 
			{
				min_e[to] = g[v][to];
				sel_e[to] = v;
			}
	}
}

void kruskal (int** gr,int n) // алгоритм Крускала
{
	
	vector < pair < int, pair<int,int> > > g; // вес - вершина 1 - вершина 2
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			if (gr[i][j] != INF)
				g.push_back(make_pair(gr[i][j],make_pair(i,j)));
	int cost = 0;
	vector < pair<int,int> > res;

	sort (g.begin(), g.end());
	vector<int> trid (n);
	for (int i=0; i<n; ++i)
		trid[i] = i;
	for (int i=0; i<g.size(); ++i)
	{
		int a = g[i].second.first,  b = g[i].second.second,  l = g[i].first;
		if (trid[a] != trid[b])
		{
			cost += l;
			res.push_back (make_pair (a, b));
			int old = trid[b],  ne = trid[a];
			for (int j=0; j<n; ++j)
				if (trid[j] == old)
					trid[j] = ne;
		}
	}
	for(auto i: res)
		cout<< i.first <<' '<<i.second<<endl;
}

int main()
{
	const int n = 5;
	int gr1[n][n] =
	{
		{ 0, 0, 1, 1, 0 },
		{ 1, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 0 },
		{ 1, 0, 0, 0, 1 },
		{ 0, 0, 1, 0, 0 }
	};
	int gr2[n][n];
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			int k = rand()%100 + 1;
			if (k !=0)
			{
				gr2[i][j] = k;
				gr2[j][i] = k;
			}
			else 
			{
				gr2[i][j] = INF;
				gr2[j][i] = INF;
			}
		}
		gr2[i][i] = INF;
	}

	/*int gr2[n][n] =
	{
		{ INF, 23, 10, 3, 17 },
		{ 1, INF, 5, 15, 7 },
		{ 2, 5, INF, 3, 18 },
		{ 3, 6, 3, INF, 6 },
		{ 4, 7, 4, 6, INF }
	};*/
	int* gr[]={gr1[0],gr1[1],gr1[2],gr1[3],gr1[4]};
	int* grn[]={gr2[0],gr2[1],gr2[2],gr2[3],gr2[4]};
	//dikstra(gr,n,0);
	//cout <<gr1[0][2]<<endl;
	//prima(grn,n);
	//kruskal(grn,n);
	//BFS(gr,n,0);
	DFS(gr,n,0);
	system("pause");
	return 0;
}

