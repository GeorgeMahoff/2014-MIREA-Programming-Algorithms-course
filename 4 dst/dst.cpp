// dst.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
	string alp[10] = {"abg","bqe","cdasd","trerw","4fdf","isda","kbcvb","hfgdfg","*ewre","+jhg"};
	int freq[10] =	{ 6 , 3 , 2 , 10, 1 , 7 , 3 , 2 , 5 , 1 };
	multimap<int,string> map;
	for(int i=0;i<10;i++)
	{
		map.insert(make_pair(freq[i],alp[i]));
	}
	DST tree;
	for(auto i :map)
	{
		cout<<i.first<<"  "<<i.second<<endl;
		tree.add_Node(i.second);
	}


	system("pause");
	return 0;
}

