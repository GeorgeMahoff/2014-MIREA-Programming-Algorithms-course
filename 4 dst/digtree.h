#include "stdafx.h"

struct Node
{
	string data;
	Node *par;
    Node *left;
    Node *right;           
};

class DST
{
private:
	Node *root;
    Node *NIL;

	void add_Node(Node* par, Node* &cur, string st, int deep = 0)
    {
		if (cur == NIL)
		{
			cur = new_node(st);
			cur->par = par;
			return;
		}
		if (get_bit(st, deep))
			add_Node(cur, cur->left, st, deep+1);
		else
			add_Node(cur, cur->right, st, deep+1);
    }

	Node* find_Node(Node* cur, string st, int deep = 0)
    {
		if (cur == NIL) 
			return 0;
		if (cur->data == st) 
			return cur;

		if (get_bit(st, deep))
			return find_Node(cur->left, st, deep+1);
		else
			return find_Node(cur->right, st, deep+1);
    }

public:
	Node* new_node(string st)
    {
		Node* newNode;
		newNode = new Node;
		newNode->data = st;
		newNode->par = 0;
		newNode->left = NIL;
		newNode->right = NIL;
		return newNode;
	}

	DST()
    {
        NIL = new_node("");
		root = NIL;
    }

	bool get_bit(string &st, int bit)
    {
		bool res = 1;
        int t = (1 << (7 - bit % 8));
        res = (st[bit / 8] & t);
        return res;
    }

	void add_Node(string st)
    {
        add_Node(0, root, st);
    }

	Node* find_Node(string st)
	{
		return find_Node(root,st);
	}

	void print(Node* cur, int deep = 0)
    {
		if (cur == NIL) return;

		print(cur->left, deep + 1);

		for (int i = 0; i < deep; ++i) cout << "     ";
		cout << cur->data << endl;

		print(cur->right, deep + 1);
	}
};