	int find_node(string m)// НЕ РЕКУРСИВНАЯ функция поиска по адресу и возврата значения
	{
		tNode* tmp = root;
		for (int i=0; i < m.length(); i++)
		{
			if (tmp->child != NULL) tmp = tmp->child; //1 раз обязательно цикл проходит, чтобы отойти от корня
			else return 0;
			while(tmp->right != 0)//двигаемся по линии и ищем нужный лист
			{
				if(tmp->name == m[i]) break;
				tmp = tmp->right;
			}
			if (tmp->name != m[i]) return 0;
		}
		return tmp->value;
	}
	void find_node_r(string m, tNode* prev = NULL) //РЕКУРСИВНАЯ
	{
		if (prev == NULL) prev = root; //костыль
		if (prev->child !=0) prev = prev->child; //спускаемся на строку
		else 
		{
			cout << "0: Invalid string"<<endl;
			return;
		}
		while(prev->right != 0)
		{
			if(prev->name == m[0]) break;
			prev = prev->right;
		}
		if (prev->name != m[0])
		{
			cout << "0: Invalid string"<<endl;
			return;
		}

		if (m.length()!=1)
		{
			m.erase(0,1);
			find_node_r(m,prev);
		}
		else
		{
			cout<< prev->value <<endl;// cout из-за рекурсии
			return;
		}
	}