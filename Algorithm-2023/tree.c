#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

Node* root;

static Node* create_node(int val)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->val = val;
	p->left = NULL;
	p->right = NULL;
	
	return p;
}

static Node* connect_child(Node* parent, Node* left, Node* right)
{
	if (parent == NULL)
		return NULL;
	
	parent->left = left;
	parent->right = right;
	return parent;
}

Node* make_tree()
{
	Node* pRoot = NULL;
	Node* tLeft = NULL;
	Node* tRight = NULL;

	pRoot = create_node(100);
	tLeft = create_node(200);
	tRight = create_node(300);

	connect_child(pRoot, tLeft, tRight);

	connect_child(tRight, create_node(400), create_node(500));

	return pRoot;
}

void print_tree(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		printf("Node: %d, ", root->val);
		print_tree(root->left);
		print_tree(root->right);
	}
}