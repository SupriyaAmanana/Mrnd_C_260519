#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

typedef struct Node Node;

void Display(struct Node* root)
{
	struct Node *temp = root;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}


struct Node* getNode(int data)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;
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

int detection_of_loop(struct Node *root)
{
	struct Node *fast = root, *slow = root;
	if (root == NULL)
		return 0;
	if (root->next == NULL || root->next->next == NULL)
		return 0;
	while (fast->next->next && slow->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return 1;
	}
	return 0;
}

struct Node *meeting_point_of_loop(struct Node *root)
{
	struct Node *fast = root, *slow = root;
	if (root == NULL)
		return 0;
	if (root->next == NULL || root->next->next == NULL)
		return 0;
	while (fast->next->next && slow->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			break;
	}
	struct Node *temp = root;
	while (temp != slow)
	{
		temp = temp->next;
		slow = slow->next;
	}
	return temp;
}

int main()
{
	int n;
	scanf("%d", &n);
	struct Node *root = NULL;
	for (int i = 0; i < n; i++)
	{
		int data;
		scanf("%d", &data);
		root = insertNodeAtEnd(root, data);
	}
	struct Node *temp=root;
	while (temp->next)
		temp = temp->next;
	//loop
	temp->next = root->next->next->next;
	if (detection_of_loop(root) == 1)
		temp=meeting_point_of_loop(root);
	printf("%d", temp->data);
	system("pause");
}