	void add_node(string m, tNode* prev = NULL) //добавление строки
	{
		if (prev == NULL) prev = root; //костыль
		tNode* n = new tNode(m[0]); //создаем шаблон нового элемента
		n->par = prev;
		if (prev->child == NULL) //1ый случай: у опорного эл. нет дочернего 
		{
			prev->child = n;
			prev = n;
		}
		else
		{
			prev = prev->child; 
			if (prev->name > n->name) //Если у опорного эл-та есть сын, который имеет меньшее имя (отн.алфавита) 
			{
				n->right = prev;
				n->par->child = n;
				prev = n;
			}
			else while(1) //немного костыльно
			{
				if (prev->name == n->name) //уже существует такой эл-т
				{
					delete n;
					break;
				}
				if (prev->name < n->name && prev->right==NULL) //добавление в конец строки
				{
					prev->right=n;
					prev = n;
					break;
				}
				if (prev->right->name > n->name) //добавление между листами
				{
					n->right=prev->right;
					prev->right=n;
					prev = n;
					break;
				}
				prev=prev->right;
			}
		}
		if (m.length()==1) prev->value++; //инкрементируем, если символ последний
		else 
		{
			m.erase(0,1); //удаление, использованного эл-та из строки
			add_node(m,prev); // вызов рекурсии
		}
	}