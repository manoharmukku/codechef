/* Codechef - April Long 2018 - Average of pairs */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1

int main() {
	int T;
	scanf ("%d", &T);

	while (T--) {
		int N;
		scanf ("%d", &N);

		int i, j;
		int* A = (int*)malloc(N * sizeof(int));

		char* isPresent = (char*)calloc(1001, sizeof(char));

		for (i = 0; i < N; i++) {
			scanf ("%d", &A[i]);
			isPresent[A[i]] = TRUE;
		}

		int count = 0;
		for (i = 0; i < N; i++) {
			for (j = i+1; j < N; j++) {
				if ((A[i] + A[j]) % 2 == 0 && isPresent[(A[i] + A[j]) / 2])
					count++;
			}
		}

		printf("%d\n", count);

		free(A);
		free(isPresent);
	}

	return 0;
}