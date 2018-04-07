/* Codechef - April Long 2018 - Count Good Prefixes*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int T;
	scanf ("%d", &T);

	while (T--) {
		int n;
		char* s = (char*)malloc(1003 * sizeof(char));

		scanf ("%s %d", s, &n);

		int countA = 0, countB = 0, count = 0;
		while (n--) {
			int i = 0;
			while (s[i] != '\0') {
				if (s[i] == 'a')
					++countA;
				else if (s[i] == 'b')
					++countB;
				if (countA > countB)
					++count;
				i++;
			}
		}

		free(s);

		printf("%d\n", count);
	}

	return 0;
}