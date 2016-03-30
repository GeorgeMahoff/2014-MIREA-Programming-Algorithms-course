// Задание 2а : Поиск и обьединение непересекающихся подмножеств

// Не могу сказать, что все алгоритмы я придумал сам, источником послужила статья http://habrahabr.ru/post/104772/
// Задача состоит в том, чтобы, получая на вход программы последовательность пар (a,b), выполнять операцию НАЙТИ. Далее в случае, если a и b принадлежат различным подмножествам, объединять их в одно.

// Основной вопрос: Что за имя C? Если его делать char, то как хранить и обьединять деревья, не будет ли это слишком затратно для памяти? И главное, как сохранить необходимую сложность?
class DisjointSet
{
private:
	int* parent;
	int* rank;
public:
	DisjointSet(int n)
	{
		parent = (int*)malloc(n*sizeof(int)); //храню все в виде массива
		rank = (int*)malloc(n*sizeof(int)); //
	}

	void make_set(int v) // создание мн-ва
	{
		parent[v]=v;
		rank[v]=0;
		//cout<< parent[v]<<endl;
	}
	int find_set (int v) // поиск на основе статьи
	{
		if (v == parent[v])
			return v;
		return parent[v] = find_set (parent[v]);
	}
	
	void find_unite (int a,int b) // поиск на основе условия
	{
		if (find_set(a) != find_set(b))
			union_sets(a,b);
			//union_sets_name(a,b);
	}
	void union_sets(int a, int b) // обьединение
	{
		a = find_set (a);
		//cout <<"a="<< a <<endl;
		b = find_set (b);
		//cout <<"b="<< b <<endl;
		if (rank[a] < rank[b])
			parent[a]=b;
		else
		{
			parent[b] = a;
			if (rank[a] == rank[b])
				++rank[a];
		}
	}
};