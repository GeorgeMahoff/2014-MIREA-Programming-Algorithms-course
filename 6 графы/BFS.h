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