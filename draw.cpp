#include <ncurses.h>
#include <unistd.h>
#include "drawNode.h"
#include "draw.h"

static void drawTree(DNode* root)
{
	if(root)
	{
		drawNode(root->index, root->data);
		drawTree(root->left);
		drawTree(root->right);
	}
}

void draw(Node* root)
{
	initscr();
	int i;

	DNode* droot = 0;
	Convert(droot, root);	

	if(droot)
	{
		drawTree(droot);
	}

	refresh();

	getch();
	endwin();

	return;
}

Node* Create(Node* root, int data)
{
	if(root == NULL)
	{
		root = new Node();
		root->data = data;
		root->left = 0;
		root->right = 0;
		return root;
	}

	if(data <= root->data)
	{
		root->left = Create(root->left, data);
	}
	else
	{
		root->right = Create(root->right, data);
	}

	return root;
}

void Walk(Node* root)
{
	if(root)
	{
		printf("%-4d", root->data);
		Walk(root->left);
		Walk(root->right);
	}
}

void Walk(DNode* root)
{
	if(root)
	{
		printf("%d(%d)  ", root->data, root->index);
		Walk(root->left);
		Walk(root->right);
	}
}

Node* Copy(Node* root)
{
	Node* r = 0;
	if(root)
	{
		r = new Node();
		r->data = root->data;
		r->left = Copy(root->left);
		r->right = Copy(root->right); 
	}
} 


static void convert(DNode*& dnode, int index, Node* node)
{
	if(node)
	{
		dnode = new DNode();
		dnode->index = index;
		dnode->data = node->data;
//		printf("data:%d\n", node->data);
		convert(dnode->left, 2*index, node->left);
		convert(dnode->right, 2*index+1, node->right);
	}
}

void Convert(DNode* &dnode, Node* node)
{
	convert(dnode, 1, node);	
}


