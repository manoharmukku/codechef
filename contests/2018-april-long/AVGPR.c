/* Codechef - April Long 2018 - Average of pairs */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define RANGE 1000

int main() {
	int T;
	scanf ("%d", &T);

	while (T--) {
		int N;
		scanf ("%d", &N);

		int i, j;
		int* A = (int*)malloc(N * sizeof(int));

		int* presentCount = (int*)calloc(2*RANGE+1, sizeof(int));

		for (i = 0; i < N; i++) {
			scanf ("%d", &A[i]);
			presentCount[A[i] + RANGE]++;
		}

		int i, count = 0;
		for (i = -RANGE; i <= RANGE; i++) {
			
		}

		printf("%d\n", count);

		free(A);
		free(presentCount);
	}

	return 0;
}