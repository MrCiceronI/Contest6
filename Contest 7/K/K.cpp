#define _CRT_SECURE_NO_WARNINGS /* scanf does not generate errors */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char s[12]; // Line for writing laws
	int node[100001]; // Array for writing laws in numerical form
	int n; // Number of laws
	int i; // Loop variable
	int count = 0; // Number of laws in force

	/* Input */
	scanf("%d", &n);

	if (n < 1 || n > 100000) { // //Checking the correct data
		printf("Invalid Input");
		return 0;
	}

	for (i = 1; i <= n; i++) {
		scanf("%s", &s);
		if ((strstr(s, "declare") != 0 && strlen(s) == 7) || (strstr(s, "cancel") && strlen(s) == 6)) { // //Checking the correct data
			if (strstr(s, "cancel") != 0) scanf("%d", &node[i]);
			else node[i] = 0;
		}
		else {
			printf("Invalid Input");
			return 0;
		}
	}

	for (i = n; i >= 1; i--) {
		if (node[i] > 0) node[node[i]] = -1;
	}
	for (i = 1; i <= n; i++) {
		if (node[i] >= 0) count++;
	}

	/* Output */
	printf("%d\n", count);
	for (i = 1; i <= n; i++) {
		if (node[i] >= 0) printf("%d ", i);
	}
}