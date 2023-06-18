#define _CRT_SECURE_NO_WARNINGS /* scanf does not generate errors */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Declaring global variables */
int count = 0; // Variable for height calculation
int height = 0; // Max height
int flag = 0; // If the condition is not met, then set the value to 1.

// List for tree
struct Node {
	int key; // Useful data
	Node* left, * right; // Pointers to sons
};
typedef Node* PNode; // Pointer to top

void AddToTree(PNode& Tree, int data) {
	/* Declaring a function to add an element to a tree

	PNode& Tree - Pointer to top
	int data - Element to add */

	if (Tree == NULL) {
		Tree = new Node; // Create a new node
		Tree->key = data;
		Tree->left = NULL;
		Tree->right = NULL;
		return;
	}
	if (data < Tree->key) AddToTree(Tree->left, data);
	else if (data > Tree->key) AddToTree(Tree->right, data);
}
void PrintLKR(PNode& Tree) {
	/* Declaring a function to traverse the tree and calculate the maximum height

	PNode& Tree - Pointer to top */

	if (Tree == NULL) return;
	count++;
	if (count > height) height = count;
	PrintLKR(Tree->left);
	PrintLKR(Tree->right);
	count--;
}

void Balance(PNode& Tree) {
	/* Function declaration for balance calculation

	PNode& Tree - Pointer to top */

	int difference = 0; // Difference between branch heights

	if (Tree == NULL) return;

	height = 0;
	count = 0;

	PrintLKR(Tree->left);

	difference = height;
	height = 0;
	count = 0;

	PrintLKR(Tree->right);

	difference = abs(difference - height);

	if (difference > 1) flag = 1;
}

void IsBalance(PNode& Tree) {
	
	/* Declaring a function to traverse the treeand calculate balance.

	PNode& Tree - Pointer to top */

	if (Tree == NULL) return;
	if (flag == 1) return;
	Balance(Tree);
	IsBalance(Tree->left);
	IsBalance(Tree->right);
}

int main()
{
	/* Declaring variables */
	PNode Tree = NULL; // Pointer to top
	int input[100003]; // Array with tree elements
	int n = 0; // Number of elements in the tree
	int i = 0; // Loop variable

	/* Input */
	while (1) {
		if (n == 100002) {
			printf("Invalid Input");
			return 0;
		}
		scanf("%d", &input[n]);
		if (input[n] == 0) break;
		n++;
	}

	for (i = 0; i < n; i++)
		AddToTree(Tree, input[i]);

	IsBalance(Tree);

	if (flag == 0) printf("YES");
	else printf("NO");
	return 0;
}