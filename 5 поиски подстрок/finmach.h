// Поиск с помощью конечного автомата
int get_next(string str, int st, int x)
{
    if (st < str.length() && x == str[st])
		return st+1;

    for (int ns = st; ns > 0; ns--)
    {
		if(str[ns-1] == x)
        {
			int i;
			for(i = 0; i < ns-1; i++)
            {
				if (str[i] != str[st-ns+1+i])
                    break;
            }
            if (i == ns-1)
                return ns;
        }
    }
    return 0;
}
int FSMsearch(string ins, string ses)
{
	vector<vector<int>> TF (ses.length()+1);

    for (int i = 0; i <= ses.length(); ++i)
		for (int j = 0; j < 256; ++j)
			TF[i].push_back(get_next(ses,i,j));

    int k=0;
    for (int i = 0; i < ins.length(); i++)
    {
		k = TF[k][ins[i]];
		if (k == ses.length())
		{
			return i-ses.length()+1;
		}
    }
	return -1;
}