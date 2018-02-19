/* Codechef: Mutated Minions */

#include <stdio.h>

int main() {
	int T; // Number of test cases
	scanf ("%d", &T);

	while (T--) {
		int N, K;
		scanf ("%d %d", &N, &K);

		int wolverineCount = 0;
		while (N--) {
			int DNA;
			scanf ("%d", &DNA);
			if ((DNA + K) % 7 == 0)
				++wolverineCount;
		}

		printf("%d\n", wolverineCount);
	}

	return 0;
}