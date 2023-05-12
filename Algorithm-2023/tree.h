#pragma once

typedef struct _node {
	int val;
	struct _node* left;
	struct _node* right;
}Node;

extern Node* make_tree();
extern void print_tree_preorder(Node* root);
extern void print_tree_inorder(Node* root);
extern void print_tree_postorder(Node* root);
extern Node* findNode(Node* root, int value);
extern Node* insertLeftNode(Node* where, Node* new_node);
extern Node* insertRightNode(Node* where, Node* new_node);
extern Node* create_node(int val);
extern void print_tree_all(Node* root);
extern void print_tree(Node* root);
extern void test();
extern void test_insert();