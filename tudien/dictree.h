#ifndef dictree_h
#define dictree_h
#include <string.h>
struct Node
{
	Node *child;
	Node *next;
	char ch;
};

class DicTree
{
private:
	Node *root;
	Node* AddChar(char s, Node *root)
	{
		Node *p = root->child;
		if( p == 0)
		{
			Node *n = new Node;
			n->next = 0;
			n->child = 0;
			n->ch = s;
			root ->child = n;
			return n;
		}
		else
		{
			while (p->ch != s && p->next != 0) // di den thang e khac ky tu s;
				p = p->next;
			if(p -> ch == s)
				return p;
			else
			{
				Node *n = new Node;
				n->ch = s;
				n->child = 0;
				n->next = 0;
				p->next = n;
				return n;
			}
		}
	};
	Node *SearchChar(char s, Node *root) const // duyet ky tu dau cua tu
	{
		Node *p = root->child;
		while (p != 0)
		{
			if(p -> ch == s)
				return p;
			p = p->next; 
		}
		return 0;
	};
public:
	DicTree()
	{
		root = new Node;
		root -> child = 0;
		root -> next = 0;
	};
	void Add( const char *s)
	{
		int len = strlen(s);
		Node *p = root;

		for(int i = 0; i< len; i++)
			p = AddChar(s[i],p);

		Node *pe = new Node;
		pe->ch ='#';
		pe->child = 0;
		pe->next = 0;

		Node *q = p->child;
		if(q == 0)
		{
			p->child = pe;
		}
		else
		{
			while (q->ch != '#' && q->next != 0)
				q = q->next;
			if (q->next == 0)
				q -> next = pe;
		}
	};
	bool Search(const char *w) const
	{
		int len = strlen(w);
		Node *p = root;
		for(int i = 0; i<len;i++)
		{
			p = SearchChar(w[i],p);
			if (p == 0)
				return false;
		}
		Node *q = p->child; // duyet ky tu tiep theo sau ky tu dau
		while(q != 0)
		{
			if(q->ch == '#')
				return true;
			q = q->next;
		}
		return false;
	};
};

#endif
