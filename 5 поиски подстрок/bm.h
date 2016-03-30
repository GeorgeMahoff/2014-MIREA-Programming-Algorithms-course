// Алгоритм Бойера-Мура
int find_suf(char s, map<char,int> m,int max)
{
	for (auto i: m)
		if( i.first == s)
			return i.second;
	return max;
}
int bmsearch (string ins, string ses)
{
	map<char,int> m;
	for (int i = ses.length()-1; i>=0; i--)
	{
		int k = ses.length()-1-i;
		if (k > 1)
			m.insert(pair<char,int>(ses[i],k));
		else
			m.insert(pair<char,int>(ses[i],1));
	}

	int pos = ses.length()-1;
	while( pos < ins.length())
	{
		int cur = 0;
		while (cur < ses.length())
		{
			if (ins[pos-cur] != ses[ses.length()-1-cur])
			{
				pos += find_suf(ins[pos-cur],m,ses.length());
				break;
			}
			cur++;
			if (cur == ses.length())
				return pos-ses.length()+1;
		}
	}
	return -1;
}