#define _CRT_SECURE_NO_WARNINGS /* scanf does not generate errors */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Stack declaration */
const int MAXSIZE = 100;
struct Stack {
	int data[MAXSIZE];
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

	if (S.size == 0) {
		printf("Stack is empty");
		return char(255);
	}
	S.size--;
}
void main()
{
	int wagon_number[100]; /* String with wagon numbers */
	int i; /* Cycle parameter */
	int k = 1; /* Variable for displaying wagons in ascending order of their number */
	int n; /* Number of wagons */
	Stack S;

	/* Data input */
	printf("Enter the number of wagons: ");
	scanf("%d", &n);
	
	if (n >= 1 && n <= 100) { /* If n is incorrect, the program will terminate immediately. */
		printf("Enter a sequence of wagons on rails: ");
		for (i = 0; i < n; i++) scanf("%d", &wagon_number[i]);

		S.size = 0; /* Initial number of elements on the stack */

		/* Wagon output cycle in order */
		for (i = 0; i < n; i++) {
			Push(S, wagon_number[i]);
			if (wagon_number[i] == k) { /* If the number of the wagon corresponds to the number k, then it is immediately displayed on the track */
				Pop(S);
				k++;
			}
		}

		/* Cycle for the withdrawal of the remaining wagons */
		while (S.size > 0) {
			if (S.data[S.size-1] == k) {
				Pop(S);
				k++;
			}
			else break;
		}

		/* Result Output */
		if (S.size == 0) printf("\nYes\n");
		else printf("\nNo\n");
	}
	else printf("Invalid input. Number of characters from 1 to 100.");
}