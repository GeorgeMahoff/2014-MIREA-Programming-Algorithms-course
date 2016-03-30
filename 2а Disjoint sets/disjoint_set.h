// ������� 2� : ����� � ����������� ���������������� �����������

// �� ���� �������, ��� ��� ��������� � �������� ���, ���������� ��������� ������ http://habrahabr.ru/post/104772/
// ������ ������� � ���, �����, ������� �� ���� ��������� ������������������ ��� (a,b), ��������� �������� �����. ����� � ������, ���� a � b ����������� ��������� �������������, ���������� �� � ����.

// �������� ������: ��� �� ��� C? ���� ��� ������ char, �� ��� ������� � ���������� �������, �� ����� �� ��� ������� �������� ��� ������? � �������, ��� ��������� ����������� ���������?
class DisjointSet
{
private:
	int* parent;
	int* rank;
public:
	DisjointSet(int n)
	{
		parent = (int*)malloc(n*sizeof(int)); //����� ��� � ���� �������
		rank = (int*)malloc(n*sizeof(int)); //
	}

	void make_set(int v) // �������� ��-��
	{
		parent[v]=v;
		rank[v]=0;
		//cout<< parent[v]<<endl;
	}
	int find_set (int v) // ����� �� ������ ������
	{
		if (v == parent[v])
			return v;
		return parent[v] = find_set (parent[v]);
	}
	
	void find_unite (int a,int b) // ����� �� ������ �������
	{
		if (find_set(a) != find_set(b))
			union_sets(a,b);
			//union_sets_name(a,b);
	}
	void union_sets(int a, int b) // �����������
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