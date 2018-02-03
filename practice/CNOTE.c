/* Codechef: Chef and Notebooks */

#include <stdio.h>

int main() {
	int T; // Number of test cases
	scanf ("%d", &T);

	while (T--) {
		int X, Y, K, N;
		scanf ("%d %d %d %d", &X, &Y, &K, &N);

		// He needs a book with at least (X-Y) pages
		// and whose price is at most K
		int reqPages = X - Y;
		int flag = 0;
		while (N--) {
			int pages, cost;
			scanf ("%d %d", &pages, &cost);
			if (pages >= reqPages && cost <= K) {
				flag = 1;
			}
		}
		if (flag == 1)
			printf("LuckyChef\n");
		else
			printf("UnluckyChef\n");
	}

	return 0;
}