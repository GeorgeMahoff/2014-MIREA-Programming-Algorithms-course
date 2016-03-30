#pragma once
using namespace std;

class mTree 
{
	struct tNode 
	{
		int value; //������� ����������
		char name; //��� �����
		tNode* par; 
		tNode* child;
		tNode* right; //������������, ��������, ��������(�� �����) ����. �����.
		tNode(char a = NULL) //����������� ����
		{
			name=a;
			value=0;
			par=child=right=NULL;
		}
	};
private:
	tNode* root; 
public:
	mTree() //����������� ������
	{
		root = new tNode();
	}

	void add_node(string m, tNode* prev = NULL) //���������� ������
	{
		if (prev == NULL) prev = root; //�������
		tNode* n = new tNode(m[0]); //������� ������ ������ ��������
		n->par = prev;
		if (prev->child == NULL) //1�� ������: � �������� ��. ��� ��������� 
		{
			prev->child = n;
			prev = n;
		}
		else
		{
			prev = prev->child; 
			if (prev->name > n->name) //���� � �������� ��-�� ���� ���, ������� ����� ������� ��� (���.��������) 
			{
				n->right = prev;
				n->par->child = n;
				prev = n;
			}
			else while(1) //������� ���������
			{
				if (prev->name == n->name) //��� ���������� ����� ��-�
				{
					delete n;
					break;
				}
				if (prev->name < n->name && prev->right==NULL) //���������� � ����� ������
				{
					prev->right=n;
					prev = n;
					break;
				}
				if (prev->right->name > n->name) //���������� ����� �������
				{
					n->right=prev->right;
					prev->right=n;
					prev = n;
					break;
				}
				prev=prev->right;
			}
		}
		if (m.length()==1) prev->value++; //��������������, ���� ������ ���������
		else 
		{
			m.erase(0,1); //��������, ��������������� ��-�� �� ������
			add_node(m,prev); // ����� ��������
		}
	}
	int find_node(string m)// �� ����������� ������� ������ �� ������ � �������� ��������
	{
		tNode* tmp = root;
		for (int i=0; i < m.length(); i++)
		{
			if (tmp->child != NULL) tmp = tmp->child; //1 ��� ����������� ���� ��������, ����� ������ �� �����
			else return 0;
			while(tmp->right != 0)//��������� �� ����� � ���� ������ ����
			{
				if(tmp->name == m[i]) break;
				tmp = tmp->right;
			}
			if (tmp->name != m[i]) return 0;
		}
		return tmp->value;
	}
	void find_node_r(string m, tNode* prev = NULL) //�����������
	{
		if (prev == NULL) prev = root; //�������
		if (prev->child !=0) prev = prev->child; //���������� �� ������
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
			cout<< prev->value <<endl;// cout ��-�� ��������
			return;
		}
	}
	void del_node(string m, tNode* prev = NULL) // �������� ����� (�� ��������� ����� ��������� ���������� �������)
	{
		if (prev == NULL) prev = root; //�������
		if (m.length()!=1) // ����� �������� �� ������� ���.������� ������
		{
			if (prev->child !=0) prev = prev->child; //���������� �� ������
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
			tNode* tmp;//��������� �������
			if (prev->child !=0) tmp = prev->child;
			else 
			{
				cout << "0: Invalid string"<<endl;
				return;
			} 
			while(tmp->right != 0) //����� �������� �� ������
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
			if (tmp->value == 1 && tmp->child == NULL) //�������� �� ��,��� �� ������� �������� ���������� �������, � ������� ��������������� ��� �������� �������
			{
				if (prev->child == tmp) //�������, ����� ������� ��-� - ������������ ��� ����������
				{
					prev->child = tmp->right;
					delete tmp;
				}
				if (prev->right == tmp) //�������� ��-�� �� �����
				{
					prev->right = tmp->right;
					delete tmp;
				}
			}
			else if (tmp->value !=0) tmp->value--; // �������� ��������, ���� ��� >1
		}
	}
};