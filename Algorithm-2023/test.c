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
		printf("\n�ش��ϴ� ���� ���� ��尡 �����ϴ�.\n");
	else
		printf("\n�ش��ϴ� ���� ���� ��尡 �ֽ��ϴ�.\n");
}

void test_insert()
{
	Node* root = make_tree(), * n = NULL, * new_node = NULL;
	printf("���� ��\n");
	print_tree_all(root);

	n = findNode(root,300);
	new_node = create_node(600);
	insertLeftNode(n, new_node);
	printf("\n\n300���� ���� ��� ���� �Ʒ��� 600���� ���� ���ο� ��� ������\n");
	print_tree_all(root);
	
	n = findNode(root, 200);
	new_node = create_node(700);
	insertRightNode(n, new_node);
	printf("\n\n200���� ���� ��� ���� �Ʒ��� 700���� ���� ���ο� ��� ������\n");
	print_tree_all(root);

	print_tree(root);
}