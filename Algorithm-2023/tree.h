#pragma once

typedef struct _node {
	int val;
	struct _node* left;
	struct _node* right;
}Node;

extern Node* make_tree();
extern void print_tree(Node* root);