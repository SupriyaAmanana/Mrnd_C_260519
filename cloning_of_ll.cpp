#include<stdio.h>
#include<stdlib.h>
#include<iterator>
#include<map>

struct Node
{
	int data;
	struct Node *next;
	struct Node *rptr;
};

typedef struct Node Node;

void Display(struct Node* root)
{
	struct Node *temp = root;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		if (temp->rptr)
			printf("  %d random", temp->rptr->data);
		temp = temp->next;
		printf("\n");
	}
}

struct Node* getNode(int data)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;
	node->rptr = NULL;
	return node;
}

struct Node *insertNodeAtEnd(struct Node *root, int data)
{
	struct Node *newNode = getNode(data), *temp;
	if (root == NULL)
		root = newNode;
	else
	{
		temp = root;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
	}
	return root;
}

struct Node *clone_by_mapping(struct Node *root)
{
	using namespace std;
	map<struct Node*, struct Node*> hash;
	struct Node *temp = root, *root1 = NULL, *temp1 = root1;
	while (temp != NULL)
	{
		struct Node *newTemp = getNode(temp->data);
		hash[temp] = newTemp;
		if (root1 == NULL)
			root1 = newTemp;
		else
		{
			temp1 = root1;
			while (temp1->next != NULL)
				temp1 = temp1->next;
			temp1->next = newTemp;
		}
		temp = temp->next;
	}
	temp = root; temp1 = root1;
	while (temp != NULL)
	{
		temp1->rptr = hash[temp->rptr];
		temp = temp->next;
		temp1 = temp1->next;
	}
	return root1;
}

struct Node *clone_by_inserting(struct Node *root)
{
	struct Node * temp = root, *prev = root, *temp1 = root,*root1=NULL;
	while (temp != NULL)
	{
		prev = temp->next;
		struct Node * temp1 = getNode(temp->data);
		temp->next = temp1;
		temp1->next = prev;
		temp = temp1->next;
	}
	
	
	temp = root;
	while (temp != NULL)
	{
		prev = temp;
		temp = temp->next;
		if (prev->rptr)
		temp->rptr = prev->rptr->next;
		temp = temp->next;
	}

	temp = root->next; prev = root; temp1 = temp->next; root1 = prev;
	while (temp1 != NULL)
	{
		prev->next = temp1;
		temp->next = temp1->next;
		prev = temp1;
		temp = prev->next;
		temp1 = temp->next;
	}
	prev->next = NULL;
	return root1;
}

int main()
{
	struct Node *root = NULL;
	struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* node4 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* node5 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* node6 = (struct Node*)malloc(sizeof(struct Node));
	
	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;
	node5->data = 5;
	node6->data = 6;
	
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = NULL;

	node1->rptr = node3;
	node2->rptr = node5;
	node3->rptr = NULL;
	node4->rptr = node5;
	node5->rptr = NULL;
	node6->rptr = node4;

	root = node1;

	struct Node *head = NULL, *temp = root;
	while (temp != NULL)
	{
		head=insertNodeAtEnd(head, temp->data);
		temp = temp->next;
	}

	head=clone_by_mapping(root);
	Display(head);
	head = clone_by_inserting(root);
	Display(head);
	system("pause");
}