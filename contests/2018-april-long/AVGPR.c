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

		int i;
		int* A = (int*)malloc(N * sizeof(int));

		int* presentCount = (int*)calloc(2*RANGE+1, sizeof(int));

		for (i = 0; i < N; i++) {
			scanf ("%d", &A[i]);
			presentCount[A[i] + RANGE]++;
		}

		long count = 0;
		int A_k;
		for (A_k = 0; A_k <= RANGE; A_k++) {
			if (presentCount[A_k + RANGE] <= 0) continue;
			int A_i, A_j;
			for (A_i = 2*A_k - RANGE, A_j = RANGE; A_i < A_j; A_i++, A_j--) {
				if (presentCount[A_i + RANGE] > 0 && presentCount[A_j + RANGE] > 0)
					count += presentCount[A_i + RANGE] * presentCount[A_j + RANGE];
			}
			if (A_i == A_j && presentCount[A_i + RANGE] >= 2)
				count += (presentCount[A_i + RANGE] * (presentCount[A_i + RANGE] - 1)) / 2;
		}

		for (A_k = -RANGE; A_k < 0 && presentCount[A_k + RANGE] > 0; A_k++) {
			if (presentCount[A_k + RANGE] <= 0) continue;
			int A_i, A_j;
			for (A_i = -RANGE, A_j = 2*A_k + RANGE; A_i < A_j; A_i++, A_j--) {
				if (presentCount[A_i + RANGE] > 0 && presentCount[A_j + RANGE] > 0)
					count += presentCount[A_i + RANGE] * presentCount[A_j + RANGE];
			}
			if (A_i == A_j && presentCount[A_i + RANGE] >= 2)
				count += (presentCount[A_i + RANGE] * (presentCount[A_i + RANGE] - 1)) / 2;
		}

		printf("%ld\n", count);

		free(A);
		free(presentCount);
	}

	return 0;
}