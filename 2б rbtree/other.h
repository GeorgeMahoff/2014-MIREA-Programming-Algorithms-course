	rbTree() 
	{
		NIL = new node(NULL);
		root = NIL;
		NIL->left = NIL->right = root;
		NIL->col = BLACK;
		NIL->key = NULL;
		NIL->p = NULL;
	}
	node* get_root()
	{
		return root;
	}
	bool empty_check()
	{
		if (root == NIL) 
			return 1;
		else
			return 0;
	}
	void inorder(node* n, int h = 0) 
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
	node* search(node* n,int k) 
	{
		if (n == NIL || n->key == k)
			return n;
		if (k < n->key)
			return search(n->left, k);
		else
			return search(n->right, k);
	}
	node* find_min(node* n) 
	{
		while (n->left != NIL)
			n = n->left;
		return n;
	}
	node* find_max(node* n) 
	{
		while (n->right != NIL)
			n = n->right;
		return n;
	}
	void l_rot(node* n) 
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
	void r_rot(node* n) 
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
	void el_change(node* u, node* v) 
	{
		if (u->p == NIL)
			root = v;
		else if (u == u->p->left)
			u->p->left = v;
		else
			u->p->right = v;
		v->p = u->p;
	}