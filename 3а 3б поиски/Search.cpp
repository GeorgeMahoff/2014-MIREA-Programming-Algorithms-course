// Searchs.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"

int IS_search(int M[], int s,int k) // индексно-последовательный поиск
{
	if (k < M[0]) //рассчет пам€ти под массив
		return -1;
 	int st = sqrt(s); 
	int t = s/st + 1;
	if ((s-1)%st !=0)
		++t;
	int** sub = new int*[2]; //выделение пам€ти
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
		l = r;
	}
	return -1;
}

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

int main()
{
	int mass[10];
	mass[0] = 0;
	cout <<"0 ";
	for (int i=1;i<10;i++)
	{
		mass[i] = mass[i-1]+rand()%7 + 1;
		cout<< mass[i]<<' ';
	}
	cout<<endl;
	for (int i=0;i<45;i++)
		cout<< IP_search(mass,i,10-1)<<endl;
	cout<<"!!!!";
	for (int i=0;i<45;i++)
		cout << IS_search(mass,10,i)<<endl;
	
	system("pause");
	return 0;
}

