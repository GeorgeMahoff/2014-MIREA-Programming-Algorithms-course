int IP_search(int M[], int X, int hi, int li = 0) // интерпол€ционный поиск
{
	if ( X == M[hi])
		return hi;
	else
	{
		if (X <= M[hi] && X >= M[li])
		{
			int j = ((X-M[li])*(hi-li+1))/(M[hi]-M[li]);
			if (M[j]==X)
				return j;
			else 
				if (M[j] < X)
					IP_search(M,X,hi,++j);
				else
					IP_search(M,X,--j,li);
		}
		else
			return -1;
	}
}