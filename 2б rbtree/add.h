	void add_el_fix(node* n) 
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
	void add_el(int n) 
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