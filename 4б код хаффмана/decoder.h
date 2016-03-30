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
string decoder(vector<Node> tr,string str)
{
	string dst;
	int n = tr.size()-1;
	for (auto i:str)
	{		
		if (i == '1')
			n = tr[n].right;
		else
			n = tr[n].left;
		if (tr[n].left == -1)
		{
			dst.push_back(tr[n].val);
			n = tr.size()-1;
		}
	}
	return dst;
}