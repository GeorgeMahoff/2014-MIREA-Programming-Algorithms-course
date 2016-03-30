struct Node 
{
	char val;
	int left;
	int right;
	int par;
	bool road;
	Node(char v,int l=-1,int r=-1, int p=-1, bool ro=0)
	{
		val = v;
		left = l;
		right = r;
		par = p;
		road = ro;
	}
};
vector<Node> create_tree(char al[],int f[],int s)
{
	multimap<int,char> map; //multimap из-за автоматической сортировки
	vector<Node> tree;
	for(int i=0;i<s;i++)
	{
		tree.push_back(Node(al[i]));
		map.insert(make_pair(f[i],tree.size()-1));
	}
	while (map.size() > 1)
    {
		int f1 = map.begin()->first;
		int c1 = map.begin()->second;
		map.erase(map.begin());
		int f2 = map.begin()->first;
		int c2 = map.begin()->second;
		map.erase(map.begin());
		tree.push_back(Node('\0', c1, c2));
		tree[c1].par = tree.size() - 1;
		tree[c1].road = 0;
		tree[c2].par = tree.size() - 1;
		tree[c2].road = 1;
		map.insert(make_pair(f1 + f2, tree.size() - 1));
    }
	return tree;
}
string coder (vector<Node> tr,string str)
{
	string cst;
	for (auto i:str)
	{
		for(int j=0;j<tr.size();j++)
			if (tr[j].val == i)
			{
				int n = j;
				vector<char> rst;
				while (tr[n].par != -1)
				{
					rst.push_back(tr[n].road+48);
					n = tr[n].par;
				}
				reverse(rst.begin(),rst.end());
				for (auto k:rst)
				{
					cst.push_back(k);
				}
			}
	}
	return cst;
}