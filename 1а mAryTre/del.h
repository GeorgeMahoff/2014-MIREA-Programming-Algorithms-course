	void del_node(string m, tNode* prev = NULL) // удаление листа (на основании моего понимания постановки задания)
	{
		if (prev == NULL) prev = root; //костыль
		if (m.length()!=1) // поиск элемента на подобии рек.функции поиска
		{
			if (prev->child !=0) prev = prev->child; //спускаемся на строку
			else 
			{
				cout << "0: Invalid string"<<endl;
				return;
			}
			while(prev->right != 0)
			{
				if (prev->name == m[0]) break;
				prev = prev->right;
			}
			if (prev->name != m[0])
			{
			cout << "0: Invalid string"<<endl;
			return;
			}
			m.erase(0,1);
			del_node(m,prev);
		}
		else
		{
			tNode* tmp;//удаляемый элемент
			if (prev->child !=0) tmp = prev->child;
			else 
			{
				cout << "0: Invalid string"<<endl;
				return;
			} 
			while(tmp->right != 0) //поиск элемента на строке
			{
				if (tmp->name == m[0]) break;
				prev = tmp;
				tmp = tmp->right;
			}
			if (tmp->name != m[0])
			{
				cout << "0: Invalid string"<<endl;
				return;
			}
			if (tmp->value == 1 && tmp->child == NULL) //проверка на то,что мы УДАЛЯЕМ одиножды занесенный элемент, а удаляем вспомогаетльные или понижаем счетчик
			{
				if (prev->child == tmp) //условие, когда опорный эл-т - родительский для удаляемого
				{
					prev->child = tmp->right;
					delete tmp;
				}
				if (prev->right == tmp) //удаление эл-та из линии
				{
					prev->right = tmp->right;
					delete tmp;
				}
			}
			else if (tmp->value !=0) tmp->value--; // понижаем значение, если оно >1
		}
	}