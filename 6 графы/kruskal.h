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