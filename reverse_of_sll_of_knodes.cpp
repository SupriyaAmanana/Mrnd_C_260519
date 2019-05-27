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

struct Node *reverse_when_k_is_2(struct Node *root)
{
	struct Node *temp = root->next,*prev=root,*temp1=root->next->next;
	if (root == NULL)
		return NULL;
	temp->next = prev;
	prev->next = temp1;
	root = temp;
	temp = temp1;
	temp1 = temp1->next;
	while (true)
	{
		prev->next = temp1;
		temp->next = temp1->next;
		temp1->next = temp;
		if (temp->next == NULL)
			break;
		prev = temp;
		temp = prev->next;
		temp1 = temp->next;
	}
	return root;
}

struct Node *reverse_sll(struct Node *root)
{
	struct Node *prev = root, *temp = root->next, *temp1 = root->next->next;
	if (root == NULL)
		return NULL;
	while (temp1 != NULL)
	{
		temp->next = prev;
		prev = temp;
		temp = temp1;
		temp1 = temp1->next;
	}
	temp->next = prev;
	root->next = NULL;
	return temp;
}

struct Node * connect_sll(struct Node *root, int k)
{
	int i = 0, flag = 0;
	struct Node *temp = root,*prev=root;
	if (root == NULL)
		return NULL;
	if (root->next == NULL && k == 1)
		return root;
	while (true)
	{
		struct Node *temp1 = temp,*head=temp1;
		i = 1;
		while (i < k)
		{
			if (temp1)
			temp1 = temp1->next;
			if (temp1 == NULL)
				break;
			i++;
		}
		if (temp1 == NULL)
			break;
		struct Node *next_ll = temp1->next;
		temp1->next = NULL;
		temp=reverse_sll(temp);
		if (flag == 0)
		{
			root = temp;
			flag = 1;
		}
		else
			prev->next = temp;
		head->next = next_ll;
		temp = next_ll;
		prev = head;
	}
	return root;
}

int main()
{
	int n,k;
	scanf("%d", &n);
	printf("enter value of k");
	scanf("%d", &k);
	struct Node *root = NULL;
	for (int i = 0; i < n; i++)
	{
		int data;
		scanf("%d", &data);
		root = insertNodeAtEnd(root, data);
	}
	root=connect_sll(root, k);
	Display(root);
	system("pause");
}