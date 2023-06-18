#define _CRT_SECURE_NO_WARNINGS /* scanf does not generate errors */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Declaring global variables */
int count = 1; // Variable for counting vertices
int s_global; // Variable to store the starting vertex

void Number(int data[][101], int n, int s) {
	/* Declaring a function to count the number of vertices in a graph

	int data[][101] - The largest possible array to store the adjacency matrix of the graph
	int n - Number of graph vertices
	int s - Specified vertex */

	int i, j; // Loop variables

	for (i = 1; i <= n; i++) data[i][s] = 0;
	for (i = 1; i <= n; i++) {
		if (data[s][i] == 1) {
			count++;
			Number(data, n, i);
		}
	}
}

int main()
{
	/* Declaring variables */
	int n; // Number of graph vertices
	int s; // Specified vertex
	int i, j; // Loop variables
	int data[101][101]; // The largest possible array to store the adjacency matrix of the graph

	/* Input */
	scanf("%d", &n);
	scanf("%d", &s);

	if (n >= 1 && n <= 100 && s >= 1 && s <= n) { //Checking the correct data
		s_global = s;

		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++) {
				scanf("%d", &data[i][j]);
				if (i == j && data[i][j] == 1) { // Checking the correct data
					printf("Invalid Input");
					return 0;
				}
			}

		Number(data, n, s);

		/* Output */
		printf("\n%d", count);
	}
	else printf("Invalid Input");

	return 0;
}