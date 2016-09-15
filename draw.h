#ifndef __DRAW__H__
#define __DRAW__H__

#include <ncurses.h>
#include <unistd.h>
#include "drawNode.h"

typedef struct Node Node;
typedef struct DNode DNode;

struct Node
{
	int data;
	Node* left;
	Node* right;
}; 

struct DNode
{
	int data;
	int index;
	DNode* left;
	DNode* right;
};

void draw(Node* node);
Node* Create(Node* root, int data);
void Convert(DNode*& droot, Node* root);
void Walk(Node* node);

#endif
