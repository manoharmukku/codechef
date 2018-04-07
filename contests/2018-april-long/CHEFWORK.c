/* Codechef - April Long 2018 - Workers */

#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	scanf ("%d", &N);

	int i;
	int* coins = (int*)malloc(N * sizeof(int));
	int* type = (int*)malloc(N * sizeof(int));

	for (i = 0; i < N; i++) 
		scanf("%d", &coins[i]);

	for (i = 0; i < N; i++)
		scanf ("%d", &type[i]);

	int min_coins_type1 = 200000;
	int min_coins_type2 = 200000;
	int min_coins_type3 = 200000;

	for (i = 0; i < N; i++) {
		if (type[i] == 1) {
			if (coins[i] < min_coins_type1)
				min_coins_type1 = coins[i];
		}
		else if (type[i] == 2) {
			if (coins[i] < min_coins_type2)
				min_coins_type2 = coins[i];
		}
		else if (type[i] == 3) {
			if (coins[i] < min_coins_type3)
				min_coins_type3 = coins[i];
		}
	}

	printf("%d\n", ((min_coins_type1 + min_coins_type2) < min_coins_type3) ? (min_coins_type1 + min_coins_type2) : min_coins_type3);

	return 0;
}