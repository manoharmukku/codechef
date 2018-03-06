/* Codechef - 2018 March Long Div2 - Chef and Glove */

#include <stdio.h>
#include <stdlib.h>

int main() {
	int T;
	scanf ("%d", &T);

	while (T--) {
		int N;
		scanf ("%d", &N);

		// Create memory for finger and sheathLength arrays
		long *fingerLength, *sheathLength;
		if (NULL == (fingerLength = (long*)malloc(N * sizeof(long))) || (NULL == (sheathLength = (long*)malloc(N * sizeof(long))))) {
			perror("Out of memory");
			exit(-1);
		}

		// Get the finger and sheath lengths
		int i;
		for (i = 0; i < N; i++)
			scanf ("%ld", &fingerLength[i]);
		for (i = 0; i < N; i++)
			scanf ("%ld", &sheathLength[i]);

		// Find out if it is front or back or both or none
		int front = 0, back = 0;
		for (i = 0; i < N; i++) {
			if (fingerLength[i] > sheathLength[i])
				break;
		}
		if (i == N) front = 1;

		for (i = 0; i < N; i++) {
			if (fingerLength[i] > sheathLength[N-i-1])
				break;
		}
		if (i == N) back = 1;

		if (front && back)
			printf("both\n");
		else if (front)
			printf("front\n");
		else if (back)
			printf("back\n");
		else
			printf("none\n");
	}

	return 0;
}