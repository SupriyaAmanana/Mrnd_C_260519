#include<stdio.h>
#include<stdlib.h>
#include "add_two_sll.h"

int main()
{
	int n1, n2;
	printf("enter length of ll 1: ");
	scanf("%d", &n1);
	struct Node *root1 = NULL;
	for (int i = 0; i < n1; i++)
	{
		int data;
		scanf("%d", &data);
		root1 = insertNodeAtEnd(root1, data);
	}
	printf("enter length of ll 2: ");
	scanf("%d", &n2);
	struct Node *root2 = NULL;
	for (int i = 0; i < n2; i++)
	{
		int data;
		scanf("%d", &data);
		root2 = insertNodeAtEnd(root2, data);
	}
	root1 = add_two_sll(root1, root2, n1, n2);
	Display(root1);
	system("pause");
}