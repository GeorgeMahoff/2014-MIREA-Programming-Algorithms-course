	void del_el_fix(node* h) 
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
	void del_el(int n) 
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