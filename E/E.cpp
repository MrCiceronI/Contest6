#define _CRT_SECURE_NO_WARNINGS /* scanf does not generate errors */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/* Stack declaration */
const int MAXSIZE = 100;
struct Stack1 {
	char data[MAXSIZE];
	int size;
};

struct Stack2 {
	int data[MAXSIZE];
	int size;
};

void Push1(Stack1& S, char x)
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

int Pop2(Stack2& S)
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
	char s[100]; // Expression
	int n; //String length
	int OK = 1; // Variable to exit when an error is encountered
	int count = 0; // Variable to exit when an error is encountered
	int res; // Variable to calculate
	char upper; // Stack element to be removed
	char p[200]; // String with reverse polish notation

	/* Data input */
	printf("Enter expression: ");
	gets_s(s);
	n = strlen(s);
	S1.size = 0;
	for (i = 0; i < n; i++) {
		if (s[i] == '0' || s[i] == '1') OK = 1;
		else if (s[i] == '!' || s[i] == '&' || s[i] == '|' || s[i] == '^') OK = 1;
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
				if (s[i] == '0' || s[i] == '1') {
					p[k] = s[i];
					k++;
				}
				else if (s[i] == '^') /* Since ^ have the lowest precedence, they "push" elements with the same precedence or higher into the string. */
				{
					if (S1.size > 0) {
						if (S1.data[S1.size - 1] == '!' || S1.data[S1.size - 1] == '&' || S1.data[S1.size - 1] == '|' || S1.data[S1.size - 1] == '^')
						{
							p[k] = Pop1(S1);
							k++;
							Push1(S1, s[i]);
						}
						else {
							Push1(S1, s[i]);
						}
					}
					else Push1(S1, s[i]);
				}
				else if (s[i] == '&' || s[i] == '|') 
					/* Because & and | have medium precedence, they "push" elements of the same or higher precedence into the string. */
				{
					if (S1.size > 0) {
						if (S1.data[S1.size - 1] == '!' || S1.data[S1.size - 1] == '&' || S1.data[S1.size - 1] == '|')
						{
							p[k] = Pop1(S1);
							k++;
							Push1(S1, s[i]);
						}
						else {
							Push1(S1, s[i]);
						}
					}
					else Push1(S1, s[i]);
				}
				else if (s[i] == '!') /* Since ! have high precedence, they "push" elements with the same precedence into the string. */ 
				{
					if (S1.size > 0) {
						if (S1.data[S1.size - 1] == '!')
						{
							p[k] = Pop1(S1);
							k++;
							Push1(S1, s[i]);
						}
						else {
							Push1(S1, s[i]);
						}
					}
					else Push1(S1, s[i]);
				}
				/* Until the top element of the stack is the opening parenthesis, pop the elements off the stack onto the output string.
				This removes the opening brace from the stack, but does not add it to the output string. */
				else if (s[i] == '(') Push1(S1, s[i]);
				else if (s[i] == ')') {
					upper = Pop1(S1);
					while (upper != '(') {
						p[k] = upper;
						upper = Pop1(S1);
						k++;
					}
				}
			}
			while (S1.size > 0) { // The remaining characters on the stack are output to a string
				p[k] = Pop1(S1);
				k++;
			}
			k = 0;
			S2.size = 0;
			for (i = 0; i < n; i++) {
				if (p[i] == '0' || p[i] == '1') {
					if (p[i] == '0') Push2(S2, 0);
					else if (p[i] == '1') Push2(S2, 1);
				}
				else if (p[i] == '!' || p[i] == '^' || p[i] == '&' || p[i] == '|') {
					res = Pop2(S2);
					if (p[i] == '!') res = abs(res - 1);
					if (p[i] == '^') {
						res += Pop2(S2);
						if (res == 2) res = 0;
						else if (res == 0) res = 0;
						else res = 1;
					}
					if (p[i] == '&') res = Pop2(S2) & res;
					if (p[i] == '|') res = Pop2(S2) | res;
					Push2(S2, res);
					res = 0;
				}
			}
			res = Pop2(S2);

			/* Result Output */
			printf("%d\n", res);
		}
		else printf("WRONG");
	}
	else printf("WRONG");
}