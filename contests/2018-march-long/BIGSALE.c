/* Codechef - 2018 March Long Div2 - A Big Sale */

#include <stdio.h>
#include <stdlib.h>

int main() {
	int T;
	scanf ("%d", &T);

	while (T--) {
		int N;
		scanf ("%d", &N);

		double loss = 0.0;
		while (N--) {
			int price, quantity, discount;
			scanf ("%d %d %d", &price, &quantity, &discount);

			/* Loss for this item = q * (p - ((p + p*d/100) - (p + p*d/100)*(d/100))) = (q * p * d * d)/10000 */
			loss += (quantity * price * discount * discount) / 10000.0;
		}

		printf("%f\n", loss);
	}

	return 0;
}