#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "tree.h"

int main(int argc,char* argv[])
{
	printf("Hellow World!\n");

	Node* root = make_tree();
	print_tree(root);

	_getch();
}