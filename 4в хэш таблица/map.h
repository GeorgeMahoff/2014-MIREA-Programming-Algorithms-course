#include "stdafx.h"

class hashTable
{
public:
	vector<list<int>> map;

	hashTable(int M) //M - делитель
	{
		map.resize(M);
	}
	void add_el(int val) // добавить эл-т в таблицу
	{
		int k = val % map.size();
		cout <<"adding "<<k<<endl;
		if (map[k].empty())
			map[k].push_back(val);
		else
		{
			for(auto i: map[k])
				if (i == val)
					return;
			map[k].push_back(val);
		}
	}
	void delete_el(int val) // удаление эл-та из таблицы
	{
		int k = val % map.size();
		cout <<"deleting "<<k<<endl;
		map[k].remove(val);
	}
};