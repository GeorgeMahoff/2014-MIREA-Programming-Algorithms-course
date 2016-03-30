// stringSearch.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
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
// Алгоритм Рабина-Карпа
int rksearch (string ins, string ses,int pr)
{
	int M = ses.length();
	int N = ins.length();
    int p = 0;
    int t = 0;
    int h = 1;
    for (int i = 0; i < M-1; i++)
		h = (h*256)%pr;
    for (int i = 0; i < M; i++)
    {
		p = (256*p + ses[i])%pr;
		t = (256*t + ins[i])%pr;
    }
    for (int i = 0; i <= N - M; i++)
    {
		if ( p == t )
        {
			int j;
            for (j = 0; j < M; j++)
            {
                if (ins[i+j] != ses[j])
                    break;
            }
            if (j == M)
            {
				return i%256;
            }
        }        
        if ( i < N-M )
        {
			t = (256*(t - ins[i]*h) + ins[i+M])%pr;
            if (t < 0) 
				t = (t + pr); 
        }
    }
	return -1;
}
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

int main()
{
	string st1 = "aaaraadrunner inthe forestroadrunner";
	string st = "roadrunner";
	cout<< bmsearch(st1,st)<<"   "<<st1[bmsearch(st1,st)] <<endl;
	cout<< rksearch(st1,st,101)<<endl;
	cout<< KMPSearch(st1,st)<<endl;
	cout<< FSMsearch(st1,st)<<endl;
	system("pause");
	return 0;
}

