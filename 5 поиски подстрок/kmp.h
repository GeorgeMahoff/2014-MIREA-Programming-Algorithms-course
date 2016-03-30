// Алгоритм Кнута-Мориса-Пратта
int KMPSearch(string ins, string ses)
{
    vector<int> lps;
    int len = 0;
	lps.push_back(0);
	while(lps.size() < ses.length())
    {
		if(ses[lps.size()] == ses[len])
		{
			len++;
			lps.push_back(len);
		}
		else
		{
			if( len != 0 )
			{
				len = lps[len-1];
			}
			else
			{
				lps.push_back(0);
			}
		}
	}

	int j = 0;
    int i = 0;
    while(i < ins.length())
    {
		if(ses[j] == ins[i])
		{
			j++;
			i++;
		}
		if (j == ses.length())
		{
			return i-j;
		}
		else if(ses[j] != ins[i])
		{
			if(j!= 0)
				j = lps[j-1];
			else
				i = i+1;
		}
    }
	return -1;
}