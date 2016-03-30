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