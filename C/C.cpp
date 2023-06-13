#define _CRT_SECURE_NO_WARNINGS /* scanf does not generate errors */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Stack declaration */
const int MAXSIZE = 10000;
struct Stack {
	float data[MAXSIZE];
	int size;
};

void Push(Stack& S, float x)
{
	/* Declaring a function to add an element to the stack

	Stack S - The stack to add the element to
	float x - The element to be added to the stack */

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

	if (S.size == 0) {
		printf("Stack is empty");
		return char(255);
	}
	S.size--;
}

void main()
{
	float container_number1[10000]; /* Main array with elements */
	float container_number2[10000]; /* Array to sort */
	float t; /* Variable for sorting */
	int i, j, s; /* Cycle parameters */
	int n; /* Number of tests */
	int k; /* Number of containers in the test */
	int OK = 1;
	Stack S;

	/* Data input */
	printf("Enter the number of tests: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {

		printf("Enter the number of containers: ");
		scanf("%d", &k);

		if (k >= 1 && k <= 10000) {
			printf("Enter container priority: ");

			for (j = 0; j < k; j++) {
				scanf("%f", &container_number1[j]);
				container_number2[j] = container_number1[j];
			}

			S.size = 0; /* Initial number of elements on the stack */

			/* Sorting */
			for (j = 0; j < k - 1; j++)
				for (s = 0; s < k - 1 - j; s++) {
					if (container_number2[s] > container_number2[s + 1]) {
						t = container_number2[s];
						container_number2[s] = container_number2[s + 1];
						container_number2[s + 1] = t;
					}
				}
			s = 0; /* Start element number */

			/* Container release cycle in order */
			for (j = 0; j < k; j++) {
				Push(S, container_number1[j]);
				if (container_number1[j] == container_number2[s]) {
					Pop(S);
					s++;
				}
			}

			/* Removal cycle of the remaining containers */
			while (S.size > 0) {
				if (S.data[S.size-1] == container_number2[s]) {
					Pop(S);
					s++;
				}
				else break;
			}

			/* Result Output */
			if (S.size == 0) printf("Result 1\n");
			else printf("Result 0\n");
		}
		else printf("Invalid input. Number of containers from 1 to 10000.");
	}
}