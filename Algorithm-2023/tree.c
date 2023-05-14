#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "tree.h"
#include "queue.h"

Node* create_node(int val)
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

void print_tree_all(Node* root)
{
	printf("\n전위순회 방법: ");
	print_tree_preorder(root);
	printf("\n중위순회 방법: ");
	print_tree_inorder(root);
	printf("\n후위순회 방법: ");
	print_tree_postorder(root);
}

void print_tree_preorder(Node* root)
{
	if (root != NULL)
	{
		printf("[%d] ", root->val);
		print_tree_preorder(root->left);
		print_tree_preorder(root->right);
	}
}

void print_tree_inorder(Node* root)
{
	if (root != NULL)
	{
		print_tree_inorder(root->left);
		printf("[%d] ", root->val);
		print_tree_inorder(root->right);
	}
}

void print_tree_postorder(Node* root)
{
	if (root != NULL)
	{
		print_tree_postorder(root->left);
		print_tree_postorder(root->right);
		printf("[%d] ", root->val);
	}
}

Node* findNode(Node* root,int value)
{
	Node* left, * right;
	if (root == NULL)
	{
		return NULL;
	}
	else
	{
		left = findNode(root->left, value);
		right = findNode(root->right, value);
		if (left != NULL)
		{
			if (left->val == value)
				return left;
		}
		if (right != NULL)
		{
			if (right->val == value)
				return right;
		}
		if (root->val == value)
			return root;
		else
			return NULL;
	}
}

Node* insertLeftNode(Node* where, Node* new_node)
{
	if (where == NULL)
		return NULL;
	else
	{
		connect_child(new_node, where->left, NULL);
		connect_child(where, new_node, where->right);
		return where;
	}
}

Node* insertRightNode(Node* where, Node* new_node)
{
	if (where == NULL)
		return NULL;
	else
	{
		connect_child(new_node, where->right, NULL);
		connect_child(where, where->left, new_node);
		return where;
	}
}


//트리의 레벨을 구하는 함수
static int calc_height(Node* n)
{
	int hLeft, hRight;
	if (n == NULL) return 0;
	hLeft = calc_height(n->left);
	hRight = calc_height(n->right);
	return (hLeft > hRight) ? (hLeft + 1) : (hRight + 1);
}

// 이진트리 형식으로 출력하는 함수
void print_tree(Node* root)
{
	if (root == NULL)
		return;
	printf("\n\n");
	Node* n;
	Queue q;
	int height = calc_height(root);
	int max = pow(2.0, height);
	int cnt = 1;
	init_queue(&q);
	enqueue(root, &q);
	int temp = 0;
	for (int i = 1; i < max; i++)
	{
		if (i == cnt)
		{
			cnt *= 2;
			temp = max / cnt - 1;
			if (i == 1)
			{
				printf("\n");
				for (int j = 0; j < temp-1; j++)
					printf("\t");
				printf("   이진 트리 출력");
			}
			printf("\n");
			for (int j = 0; j < temp; j++)
				printf("\t");
		}

		n = dequeue(&q);
		if (n != NULL)
		{
			printf("[%d]", n->val);
			enqueue(n->left, &q);
			enqueue(n->right, &q);
		}
		else
		{
			printf("NULL");
			enqueue(NULL, &q);
			enqueue(NULL, &q);
		}
		for (int j = 0; j < max / cnt*2; j++)
			printf("\t");
	}
}