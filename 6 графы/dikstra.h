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