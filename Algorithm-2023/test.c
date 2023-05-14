#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "tree.h"

void test()
{
	Node* root = make_tree(), * n = NULL;
	
	print_tree_all(root);
	n = findNode(root, 10);
	if (n == NULL)
		printf("\n해당하는 값을 가진 노드가 없습니다.\n");
	else
		printf("\n해당하는 값을 가진 노드가 있습니다.\n");
}

void test_insert()
{
	Node* root = make_tree(), * n = NULL, * new_node = NULL;
	printf("삽입 전\n");
	print_tree_all(root);

	n = findNode(root,300);
	new_node = create_node(600);
	insertLeftNode(n, new_node);
	printf("\n\n300값을 가진 노드 왼쪽 아래에 600값을 가진 새로운 노드 삽입후\n");
	print_tree_all(root);
	
	n = findNode(root, 200);
	new_node = create_node(700);
	insertRightNode(n, new_node);
	printf("\n\n200값을 가진 노드 왼쪽 아래에 700값을 가진 새로운 노드 삽입후\n");
	print_tree_all(root);

	print_tree(root);
}