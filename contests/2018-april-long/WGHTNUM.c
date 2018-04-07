/* Codechef - April Long 2018 - Weight of Numbers */

#include <stdio.h>
#include <stdlib.h>

#define M 1000000007

unsigned long findPower(int x, unsigned long long N) {
	if (N == 0) return 1;
	if (N == 1) return x;

	unsigned long aux = findPower(x, N/2);
	unsigned long long result = (aux * aux) % M;

	// If N is odd
	if (N & 1ULL) {
		result = (x * result) % M;
	}

	return (unsigned long) result;
}

unsigned long findDigitsWithWeight(int W, unsigned long long N) {
	if (W < -9 || W > 8) return 0;

	if (W >= 0)
		return ((9 - W) * findPower(10, N-2)) % M;
	else
		return ((10 + W) * findPower(10, N-2)) % M;
}

int main() {
	int T;
	scanf ("%d", &T);

	while (T--) {
		unsigned long long N;
		scanf ("%llu", &N);

		int W;
		scanf ("%d", &W);

		printf("%lu\n", findDigitsWithWeight(W, N));
	}

	return 0;
}