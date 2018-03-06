/* Codechef - 2018 March Long Div2 - Mix the Colors */

#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void* a, const void* b) {
	return (*(long*)a) < (*(long*)b);
}

int main() {
	int T;
	scanf ("%d", &T);

	while (T--) {
		int N;
		scanf ("%d", &N);

		// Create memory for the colors array
		long * colors;
		if (NULL == (colors = (long*)malloc(N * sizeof(long)))) {
			perror("Out of memory");
			exit(-1);
		}

		// Fill the colors array
		int i;
		for (i = 0; i < N; i++)
			scanf ("%ld", &colors[i]);

		// Sort the colors array
		qsort(colors, N, sizeof(long), cmpfunc);

		// Find the minimum mixings possible
		// It is nothing but the count of the repeated elements in the array
		int count = 0;
		for (i = 1; i < N; i++) {
			if (colors[i] == colors[i-1])
				++count;
		}

		printf("%d\n", count);
	}

	return 0;
}