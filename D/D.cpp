#define _CRT_SECURE_NO_WARNINGS /* scanf does not generate errors */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Stack declaration */
const int MAXSIZE = 100000;
struct Stack {
	int *data;
	int size;
};

void Push(Stack& S, int x)
{
	/* Declaring a function to add an element to the stack

	Stack S - The stack to add the element to
	int x - The element to be added to the stack */

	if (S.size == MAXSIZE) {
		printf("Stack full");
		return;
	}
	S.data[S.size] = x;
	S.size++;
}

char Pop(Stack& S)
{
	/* Declaring a function to remove an element from the stack

	Stack S - The stack from which to remove the top element */

	if (S.size < 0) {
		printf("Stack is empty");
		return char(255);
	}
	S.size--;
}
void main()
{
	int *height; /* Array of column lengths */
	int i, j; /* Cycle parameters */
	int n; /* Number of columns */
	int ans = 0; /* Maximum area */
	int h; /* The height of the rectangle in question */
	Stack S;

	/* Data input */
	printf("Enter the number of columns: ");
	scanf("%d", &n);


	if (n >= 1 && n <= 1000000) { /* If n is incorrect, the program will terminate immediately. */

		height = (int*)malloc(sizeof(int) * n);
		S.data = (int*)malloc(sizeof(int) * n);

		printf("Enter the height of each column: ");
		for (i = 0; i < n; i++) scanf("%d", &height[i]);

		for (i = n; i > 0; i--) {
			S.size = 0; // Initial number of elements on the stack

			for (j = 0; j < i; j++) Push(S, height[j]);

			h = S.data[S.size - 1];
			if (ans < S.data[S.size - 1]) ans = h; //The area is numerically equal to the height, since the column width is 1.
			Pop(S);

			for (j = 2; j <= i; j++) {
				if (h > S.data[S.size - 1]) h = S.data[S.size - 1];
				if (ans < h * j) ans = h * j;
				Pop(S);
			}
		}

		/* Result Output */
		printf("The maximum area is: %d", ans);
	}
	else printf("Invalid input. Number of columns from 1 to 1000000.");
}
