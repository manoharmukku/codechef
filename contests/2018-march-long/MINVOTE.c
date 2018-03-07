/* Codechef - 2018 March Long Div2 - Minions and Voting */

#include <stdio.h>
#include <stdlib.h>

int main() {
	int T;
	scanf ("%d", &T);

	while (T--) {
		int N;
		scanf ("%d", &N);

		// Create memory for influence levels
		long * influenceLevel;
		if (NULL == (influenceLevel = (long*)malloc(N * sizeof(long)))) {
			perror("Out of memory");
			exit(-1);
		}

		// Fill the influenceLevels array
		int i, j;
		for (i = 0; i < N; i++) 
			scanf ("%ld", &influenceLevel[i]);

		// Create memory for Sum array to store sums of influence levels
		long long * sum;
		if (NULL == (sum = (long long *)malloc(N * sizeof(long long)))) {
			perror("Out of memory");
			exit(-1);
		}

		// Fill in the sum array
		// sum[i] contains influenceLevel[0] + influenceLevel[1] + ... + influenceLevel[i]
		sum[0] = influenceLevel[0];
		for (i = 1; i < N; i++) 
			sum[i] = sum[i-1] + influenceLevel[i];

		// Create memory for Vote counts initialized to 0
		int * votes;
		if (NULL == (votes = (int*)calloc(N, sizeof(int)))) {
			perror("Out of memory");
			exit(-1);
		}

		// Fill the votes array as follows
		// The sum of influence levels between i and j (excluding i and j, i < j) can
		// be obtained as betweenIJ = sum[j] - sum[i] - influenceLevel[j]
		// If influenceLevel[i] >= betweenIJ then ++votes[j]
		// If influenceLevel[j] >= betweenIJ then ++votes[i]
		// Loop for all possible i and j and fill in the votes array
		for (i = 0; i < N; i++) {
			for (j = i+1; j < N; j++) {
				long long betweenIJ = sum[j] - sum[i] - influenceLevel[j];
				if (influenceLevel[i] >= betweenIJ)
					++votes[j];
				if (influenceLevel[j] >= betweenIJ)
					++votes[i];
			}
		}

		// Output the votes count
		for (i = 0; i < N; i++)
			printf("%d ", votes[i]);
		printf("\n");
	}

	return 0;
}