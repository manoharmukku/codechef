/* Codechef - 2018 March Long Div2 - Minion Chef and Bananas */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long numberOfPiles(long* pileCount, int N, long K) {
	int i;
	float number_piles = 0.0;
	for (i = 0; i < N; i++)
		number_piles += ceil(pileCount[i] / (K * 1.0));
	return (long)number_piles;
}

int main() {
	int T;
	scanf ("%d", &T);

	while (T--) {
		int N;
		long H;
		scanf ("%d %ld", &N, &H);

		// Create memory for pileCounts
		long * pileCount;
		if (NULL == (pileCount = (long*)malloc(N * sizeof(long)))) {
			perror("Out of memory");
			exit(-1);
		}

		// Fill the pileCount array
		int i;
		for (i = 0; i < N; i++) 
			scanf ("%ld", &pileCount[i]);

		// Minimum possible value for K = 1 and
		// maximum possible value for K = max(pileCount[])
		// Perform binary search on the value of K from 1 to max(pileCount[]) and
		// for each K find if the number of piles formed after dividing the piles w.r.t K 
		// are < = > H and proceed accordingly in the binary search

		long low = 1L;
		long high = pileCount[0];
		for (i = 1; i < N; i++)
			if (pileCount[i] > high)
				high = pileCount[i];

		long K = high;
		while (low <= high) {
			long mid = low + (high - low) / 2;

			long number_piles = numberOfPiles(pileCount, N, mid);
			if (number_piles == H) {
				K = mid;
				break;
			}
			else if (number_piles < H) {
				K = mid;
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}

		printf("%ld\n", K);
	}

	return 0;
}