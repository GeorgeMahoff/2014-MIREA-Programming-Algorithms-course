int IS_search(int M[], int s,int k) // индексно-последовательный поиск
{
	if (k < M[0]) //рассчет памяти под массив
		return -1;
 	int st = sqrt(s); 
	int t = s/st + 1;
	if ((s-1)%st !=0)
		++t;
	int** sub = new int*[2]; //выделение памяти
	sub[0] = new int[t];
	sub[1] = new int[t];
	int l=0,r=0;
	for (int i=0; i<s; i+=st) //cоздание массива
	{
		sub[0][r] = M[i];
		sub[1][r] = i;
		r++;
		if ((s-i) < k)
		{
			sub[0][r] = M[s-1];
			sub[1][r] = s-1;
		}
	}
	for (r=0;r<t;r++) // поиск с помощью подмассива
	{
		if (sub[0][r] == k)
			return sub[1][r];
		if (sub[0][r] > k)
		{
			for(int i=l; i < sub[1][r]; i++)
				if (M[i] == k )
					return i;
			return -1;
		}
		l = sub[1][r];
	}
	return -1;
}