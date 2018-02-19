/* Codechef: The Minimum number of moves */

#include <stdio.h>
#include <limits.h>

int main() {
	// Increasing salary of all workers except one by 1 in one operation is
	// equivalent to two operations i.e. decrease salary of one worker by 1 and
	// then increase salary of all workers by 1

	// The second operation is redundant as it increases salary of all workers

	// Thus our only operation is decrease salary of one worker by 1

	// We decrease the salary of all workers to the min. of the given salaries

	// Thus number of operations = (w1 - wMin) + (w2 - wMin) + ... + (wN - wMin)

	int T; // Number of test cases
	scanf ("%d", &T);

	while (T--) {
		int N; // Number of workers
		scanf ("%d", &N);

		int w, wMin = INT_MAX, sum = 0, i;
		for (i = 0; i < N; i++) {
			scanf ("%d", &w);
			sum += w;
			if (w < wMin)
				wMin = w;
		}

		printf("%d\n", sum - (N * wMin));
	}
	
	return 0;
}