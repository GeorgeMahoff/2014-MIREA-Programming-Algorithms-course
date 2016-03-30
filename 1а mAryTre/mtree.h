#pragma once
using namespace std;

class mTree 
{
	struct tNode 
	{
		int value; //счетчик добавлений
		char name; //им€ листа
		tNode* par; 
		tNode* child;
		tNode* right; //родительский, дочерний, соседний(по линии) элем. соотв.
		tNode(char a = NULL) //конструктор лист
		{
			name=a;
			value=0;
			par=child=right=NULL;
		}
	};
private:
	tNode* root; 
public:
	mTree() //конструктор дерева
	{
		root = new tNode();
	}

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
			if (prev->name > n->name) //≈сли у опорного эл-та есть сын, который имеет меньшее им€ (отн.алфавита) 
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
	int find_node(string m)// Ќ≈ –≈ ”–—»¬Ќјя функци€ поиска по адресу и возврата значени€
	{
		tNode* tmp = root;
		for (int i=0; i < m.length(); i++)
		{
			if (tmp->child != NULL) tmp = tmp->child; //1 раз об€зательно цикл проходит, чтобы отойти от корн€
			else return 0;
			while(tmp->right != 0)//двигаемс€ по линии и ищем нужный лист
			{
				if(tmp->name == m[i]) break;
				tmp = tmp->right;
			}
			if (tmp->name != m[i]) return 0;
		}
		return tmp->value;
	}
	void find_node_r(string m, tNode* prev = NULL) //–≈ ”–—»¬Ќјя
	{
		if (prev == NULL) prev = root; //костыль
		if (prev->child !=0) prev = prev->child; //спускаемс€ на строку
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
	void del_node(string m, tNode* prev = NULL) // удаление листа (на основании моего понимани€ постановки задани€)
	{
		if (prev == NULL) prev = root; //костыль
		if (m.length()!=1) // поиск элемента на подобии рек.функции поиска
		{
			if (prev->child !=0) prev = prev->child; //спускаемс€ на строку
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
			tNode* tmp;//удал€емый элемент
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
			if (tmp->value == 1 && tmp->child == NULL) //проверка на то,что мы ”ƒјЋя≈ћ одиножды занесенный элемент, а удал€ем вспомогаетльные или понижаем счетчик
			{
				if (prev->child == tmp) //условие, когда опорный эл-т - родительский дл€ удал€емого
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
};