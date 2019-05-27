#include<stdio.h>
#include<stdlib.h>

void Display(struct Node* root);
struct Node* getNode(int data);
struct Node *insertNodeAtEnd(struct Node *root, int data);
int length(struct Node *root);
int add_two_sll_carry(struct Node *temp, struct Node *temp1);
struct Node *add_two_sll(struct Node *root1, struct Node *root2, int l1, int l2);