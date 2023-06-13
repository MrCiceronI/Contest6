#define _CRT_SECURE_NO_WARNINGS /* scanf does not generate errors */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Stack declaration */
const int MAXSIZE = 100000;
struct Stack {
	char data[MAXSIZE];
	int size;
};


void Push(Stack* S, char x)
{
	/* Declaring a function to add an element to the stack 

	Stack S - The stack to add the element to
	char x - The element to be added to the stack */

	if (S->size == MAXSIZE) {
		printf("Stack full");
		return;
	}
	S->data[S->size] = x;
	S->size++;
}


char Pop(Stack* S)
{
	/* Declaring a function to remove an element from the stack 
	
	Stack S - The stack from which to remove the top element */

	if (S->size == 0) {
		printf("Stack is empty");
		return char(255);
	}
	S->size--;
	return S->data[S->size];
}

void main()
{
	char bracket_open[3] = {'(', '{', '['}; /* An array consisting of open brackets */
	char bracket_close[3] = {')', '}', ']'}; /* An array consisting of closed brackets */
	char s[100000]; /* String with brackets */
	char upper; /* Stack element to be removed */
	int i, k; /* Cycle parameters */
	int OK; /* Variable to exit the cycle when an error is encountered */
	int n; /* Number of brackets per line */
	Stack S;

	/* Data input */
	printf("Enter number of characters: ");
	scanf("%d", &n);

	if (n >= 1 && n <= 100000) { /* If n is incorrect, the program will terminate immediately. */
		printf("Enter a sequence of brackets: ");
		scanf("%s", s);

		S.size = 0; /* Initial number of elements on the stack */
		OK = 1;

		for (i = 0; OK && (i <= n); i++) /* Cycle through all elements in a string */
			for (k = 0; k < 3; k++) /* Check three types of brackets */
			{
				/* Open brackets */
				if (s[i] == bracket_open[k]) {
					Push(&S, s[i]); break;
				}
				/* Close brackets */
				if (s[i] == bracket_close[k]) {
					upper = Pop(&S);
					if (upper != bracket_open[k]) OK = 0; /* If the types of brackets do not match, then OK = 0 */
					break;
				}
			}

		/* Result Output */
		if (OK && (S.size == 0))
			printf("\nYes\n");
		else printf("\nNo\n");
	}
	else printf("Invalid input. Number of characters from 1 to 100000.");
}