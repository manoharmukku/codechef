/* Codechef - April Long 2018 - Average of pairs */

#include <iostream>
#include <stdlib.h>
#include <unordered_map>
using namespace std;

int cmpfunc(const void* a, const void* b) {
	return (int*)a - (int*)b;
}

int main() {
	int T;
	scanf ("%d", &T);

	while (T--) {
		int N;
		scanf ("%d", &N);

		int i, j;
		int* A = (int*)malloc(N * sizeof(int));

		unordered_map<int, bool> isPresent;

		for (i = 0; i < N; i++)
			scanf ("%d", &A[i]);
		for (i = 0; i < N; i++)
			isPresent[A[i]] = true;

		qsort(A, N, sizeof(int), cmpfunc);

		int count = 0;
		for (i = 0; i < N; i++) {
			for (j = i+1; j < N; j++) {
				if ((A[i] + A[j]) % 2 == 0 && isPresent.find((A[i] + A[j]) / 2) != isPresent.end())
					count++;
			}
		}

		printf("%d\n", count);

		free(A);
	}

	return 0;
}