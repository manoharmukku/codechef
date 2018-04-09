/* Codechef - April Long 2018 - Count Good Prefixes*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(x, y) ((x < y) ? (x) : (y))

int main() {
	int T;
	scanf ("%d", &T);

	while (T--) {
		long n;
		char* s = (char*)malloc(1004 * sizeof(char));

		scanf ("%s %ld", s, &n);

		if (n <= 0) exit(-1); // invalid input

		int len = strlen(s);

		// difference[i] stores (count_of_a - count_of_b) till the index i in string s
		int* difference = (int*)malloc(len * sizeof(int));

		if (s[0] == 'a') difference[0] = 1;
		else if (s[0] == 'b') difference[0] = -1;
		else exit(-1); // error in input

		int i;
		for (i = 1; i < len; i++)
			if (s[i] == 'a')
				difference[i] = difference[i-1] + 1;
			else if (s[i] == 'b')
				difference[i] = difference[i-1] - 1;
			else exit(-1); // error in input

		long long count = 0;
		if (difference[len-1] == 0) {
			for (i = 0; i < len; i++) {
				if (difference[i] > 0)
					count += n;
			}
		}
		else if (difference[len-1] > 0) {
			for (i = 0; i < len; i++) {
				if (difference[i] <= 0) {
					long value = n - ((-difference[i]) / difference[len-1]) - 1;
					if (value > 0)
						count += value;
				}
				else 
					count += n;
			}
		}
		else {
			for (i = 0; i < len; i++) {
				if (difference[i] > 0) {
					if (difference[i] % (-difference[len-1]) == 0) {
						count += min(n, (difference[i] / (-difference[len-1])));
					}
					else {
						count += min(n, ((difference[i] / (-difference[len-1])) + 1));
					}
				}
			}
		}

		printf("%lld\n", count);

		free(s);
		free(difference);
	}

	return 0;
}