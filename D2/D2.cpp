#define _CRT_SECURE_NO_WARNINGS /* scanf does not generate errors */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/* Stack1 declaration */
const int MAXSIZE = 100;
struct Stack1 {
	char data[MAXSIZE];
	int size;
};

/* Stack1 declaration */
struct Stack2 {
	float data[MAXSIZE];
	int size;
};

void Push1(Stack1& S, char x)
{
	/* Declaring a function to add an element to the stack

	Stack S - The stack to add the element to
	char x - The element to be added to the stack */

	if (S.size == MAXSIZE) {
		printf("Stack full");
		return;
	}
	S.data[S.size] = x;
	S.size++;
}

void Push2(Stack2& S, float x)
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

char Pop1(Stack1& S)
{
	/* Declaring a function to remove an element from the stack

	Stack S - The stack from which to remove the top element */

	if (S.size == 0) {
		printf("Stack is empty");
	}
	S.size--;
	return S.data[S.size];
}

float Pop2(Stack2& S)
{
	/* Declaring a function to remove an element from the stack

	Stack S - The stack from which to remove the top element */

	if (S.size == 0) {
		printf("Stack is empty");
	}
	S.size--;
	return S.data[S.size];
}

void main()
{
	int i; /* Cycle parameter */
	int k = 0; // Parametr for strings
	Stack1 S1; // Stack for reverse polish notation
	Stack2 S2; // Stack to count
	char number[100]; // Variable to convert string to float
	char s[100]; // Expression
	int n; // String length
	int OK = 1; // Variable to exit when an error is encountered
	int count = 0; // Variable to exit when an error is encountered
	float res; // Variable to calculate
	char upper; // Stack element to be removed
	char p[200]; // String with reverse polish notation

	/* Data input */
	printf("Enter expression: ");
	gets_s(s);
	n = strlen(s);
	S1.size = 0;
	for (i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') OK = 1;
		else if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*') OK = 1;
		else if (s[i] == '(' || s[i] == ')') OK = 1;
		else OK = 0;
	}
	if (OK == 1) {
		for (i = 0; i < n; i++) {
			if (s[i] == '(') count++;
			else if (s[i] == ')') count--;
			if (count < 0) break;
		}
		if (count == 0) {
			for (i = 0; i < n; i++) {
				if (s[i] >= '0' && s[i] <= '9') {
					p[k] = s[i];
					k++;
				}
				else if (s[i] == '+' || s[i] == '-') {
					/* Since + and - have the lowest precedence, they "push" elements with the same precedence or higher into the string. */

					if (S1.size > 0)
					{
						if (S1.data[S1.size - 1] == '/' || S1.data[S1.size - 1] == '*' || S1.data[S1.size - 1] == '+' || S1.data[S1.size - 1] == '-')
						{
							p[k] = ' '; // Spaces will be needed for calculation
							k++;
							p[k] = Pop1(S1);
							k++;
							Push1(S1, s[i]);
						}
						else {
							p[k] = ' ';
							k++;
							Push1(S1, s[i]);
						}
					}
					else {
						p[k] = ' ';
						k++;
						Push1(S1, s[i]);
					}
				}
				else if (s[i] == '/' || s[i] == '*') {
					/* Since * and / have high precedence, they "push" elements with the same precedence into the string. */
					if (S1.data[S1.size - 1] == '/' || S1.data[S1.size - 1] == '*') {
						p[k] = ' ';
						k++;
						p[k] = Pop1(S1);
						k++;
						Push1(S1, s[i]);
					}
					else {
						p[k] = ' ';
						k++;
						Push1(S1, s[i]);
					}
				}
				/* Until the top element of the stack is the opening parenthesis, pop the elements off the stack onto the output string. 
				This removes the opening brace from the stack, but does not add it to the output string. */
				else if (s[i] == '(') Push1(S1, s[i]); 
				else if (s[i] == ')') {
					p[k] = ' ';
					k++;
					upper = Pop1(S1);
					while (upper != '(') {
						p[k] = upper;
						upper = Pop1(S1);
						k++;
					}
				}
			}
			if (p[k - 1] >= '0' && p[k - 1] <= '9') {
				p[k] = ' ';
				k++;
			}
			while (S1.size > 0) {// The remaining characters on the stack are output to a string
				p[k] = Pop1(S1);
				k++;
			}
			k = 0;
			S2.size = 0;
			for (i = 0; i < strlen(p); i++) {
				if (p[i] >= '0' && p[i] <= '9') {
					number[k] = p[i];
					k++;
				}
				else if (p[i] == ' ') {
					Push2(S2, atol(number));
					k = 0;
				}
				else if (p[i] == '/' || p[i] == '*' || p[i] == '+' || p[i] == '-') {
					res = Pop2(S2);;
					if (p[i] == '/') res = Pop2(S2) / res;
					if (p[i] == '*') res = Pop2(S2) * res;
					if (p[i] == '+') res = Pop2(S2) + res;
					if (p[i] == '-') res = Pop2(S2) - res;
					Push2(S2, res);
					res = 0;
				}
			}
			res = Pop2(S2);

			/* Result Output */
			printf("%f\n", res);
		}
		else printf("WRONG");
	}
	else printf("WRONG");
}