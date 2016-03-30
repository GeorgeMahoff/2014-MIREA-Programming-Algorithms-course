// ЗАДАНИЕ 2Б красно-черное дерево

// Комментариев особо не писал, тк все идет по стандартным случаям, а часть кода взята из обычного ДДП(BST).

#define RED		0
#define BLACK	1

class rbTree
{
	struct node 
	{
		int key;
		node *left;
		node* right;
		node* p;
		bool col;
		node(int a)
		{
			key=a;
			left=right=0;
		}
	};
private:
	node* NIL;
	node* root;
public:
	rbTree() // конструктор
	{
		NIL = new node(NULL);
		root = NIL;
		NIL->left = NIL->right = root;
		NIL->col = BLACK;
		NIL->key = NULL;
		NIL->p = NULL;
	}
	node* get_root() //возврат корня
	{
		return root;
	}
	bool empty_check() // проверка на пустоту
	{
		if (root == NIL) 
			return 1;
		else
			return 0;
	}
	void inorder(node* n, int h = 0) // обход дерева и общая визуализация
	{
		if (n != NIL) 
		{
			inorder(n->left,h+1);
			for (int i=0;i<h;++i) 
				cout<<"    ";
			cout << n->key;
			if (n->col == RED)
				cout <<"r" <<endl;
			else
				cout <<"b" <<endl;
			inorder(n->right,h+1);
		}
	}
	node* search(node* n,int k) // поиск эл-та
	{
		if (n == NIL || n->key == k)
			return n;
		if (k < n->key)
			return search(n->left, k);
		else
			return search(n->right, k);
	}
	node* find_min(node* n) // поиск минимума
	{
		while (n->left != NIL)
			n = n->left;
		return n;
	}
	node* find_max(node* n) // поиск максимума
	{
		while (n->right != NIL)
			n = n->right;
		return n;
	}
	void l_rot(node* n) // левый поворот
	{
		node* y = n->right;
		n->right = y->left;
		if (y->left != NIL) 
			y->left->p = n;
		y->p = n->p;
		if (n->p == NIL) 
			root = y;
		else if (n->p->left == n) 
			n->p->left = y;
		else 
			n->p->right = y;
		y->left = n;
		n->p = y;
	}
	void r_rot(node* n) // правый поворот
	{
		node* y = n->left;
		n->left = y->right;
		if (y->right != NIL) 
			y->right->p = n;
		y->p = n->p;
		if (n->p == NIL) 
			root = y;
		else if (n->p->left == y) 
			y->p->left = y;
		else 
			y->p->right = y;
		y->right = n;
		n->p = y;
	}
	void add_el_fix(node* n) // балансировка после добавления
	{
		while (n->p->col == RED) 
		{
			if (n->p == n->p->p->left) 
			{
				node* y = n->p->p->right;
				if (y->col == RED) 
				{
					n->p->col = BLACK;
					y->col = BLACK;
					n->p->p->col = RED;
					n = n->p->p;
				}
				else 
				{
					if (n == n->p->right) 
					{
						n = n->p;
						l_rot(n);
					}
					n->p->col = BLACK;
					n->p->p->col = RED;
					r_rot(n->p->p);
				}
			}
			else 
			{
				node* y = n->p->p->left;
				if (y->col == RED) 
				{
					n->p->col = BLACK;
					y->col = BLACK;
					n->p->p->col = RED;
					n = n->p->p;
				}
				else 
				{
					if (n == n->p->left) 
					{
						n = n->p;
						r_rot(n);
					}
					n->p->col = BLACK;
					n->p->p->col = RED;
					l_rot(n->p->p);
				}
			}
		}
		root->col = BLACK;
	}
	void add_el(int n) // добавление
	{
		node* N = new node(n);
		node* y = NIL;
		node* h = root;
		while (h != NIL) 
		{
			y = h;
			if (N->key < h->key)
				h = h->left;
			else
				h = h->right;
		}
		N->p = y;
		if (y == NIL)
			root = N;
		else if (N->key < y->key)
			y->left = N;
		else
			y->right = N;
		N->left = NIL;
		N->right = NIL;
		N->col = RED;
		add_el_fix(N);
	}
	void el_change(node* u, node* v) // меняет местами узлы
	{
		if (u->p == NIL)
			root = v;
		else if (u == u->p->left)
			u->p->left = v;
		else
			u->p->right = v;
		v->p = u->p;
	}
	void del_el_fix(node* h) // балансировка после удаления
	{
		while (h != root && h->col == BLACK) 
		{
			if (h == h->p->left) 
			{
				node* w = h->p->right;
				if (w->col == RED) 
				{
					w->col = BLACK;
					h->p->col = RED;
					l_rot(h->p);
					w = h->p->right;
				}
				if (w->left->col == BLACK && w->right->col == BLACK) 
				{
					w->col = RED;
					h = h->p;
				}
				else 
				{
			 		if (w->right->col == BLACK) 
					{
						w->left->col = BLACK;
						w->col = RED;
						r_rot(w);
						w = h->p->right;
					}
					w->col = h->p->col;
					h->p->col = BLACK;
					w->right->col = BLACK;
					l_rot(h->p);
					h = root;
				}
			}
			else 
			{
				node* w = h->p->left;
				if (w->col == RED) 
				{
					w->col = BLACK;
					h->p->col = RED;
					r_rot(h->p);
					w = h->p->left;
				}
				if (w->left->col == BLACK && w->right->col == BLACK) 
				{
					w->col = RED;
					h = h->p;
				}
				else 
				{
					if (w->left->col == BLACK) 
					{
						w->right->col = BLACK;
						w->col = RED;
						l_rot(w);
						w = h->p->left;
					}
					w->col = h->p->col;
					h->p->col = BLACK;
					w->left->col = BLACK;
					r_rot(h->p);
					h = root;
				}
			}
		}
		h->col = BLACK;
	}
	void del_el(int n) // удаление эл-та
	{
		node* N = search(root, n);
		if (N == NIL) 
		{
			cout<<"ERROR: Wrong element"<< endl;
			return;
		}
		node* y = N;
		int yCol = y->col;
		node* h;
		if (N->left == NIL) 
		{
			h = N->right;
			el_change(N,N->right);
		}
		else if (N->right == NIL) 
		{
			h = N->left;
			el_change(N,N->left);
		}
		else 
		{
			y = find_min(N->right);
			yCol = y->col;
			h = y->right;
			if (y->p == N)
				h->p = y;
			else 
			{
				el_change(y,y->right);
				y->right = N->right;
				y->right->p = y;
			}
			el_change(N,y);
			y->left = N->left;
			y->left->p = y;
			y->col = N->col;
		}
		if (yCol == BLACK)
			del_el_fix(h);
	}
};