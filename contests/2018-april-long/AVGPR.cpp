/* Codechef - April Long 2018 - Average of pairs */

#include <iostream>
#include <stdlib.h>
#include <unordered_map>
using namespace std;

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