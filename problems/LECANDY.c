/* Codechef: Little Elephant and Candies */

#include <stdio.h>

int main() {
    int T; // Number of test cases
    scanf ("%d", &T);

    int N; //Total number of elephants
    int C; // Total number of candies
    while (T--) {
        scanf ("%d %d", &N, &C);
        int total = 0;
        while (N--) {
        	int current;
        	scanf ("%d", &current);
        	total += current;
        }
        if (total <= C)
        	printf("Yes\n");
        else
       		printf("No\n");
    }
    return 0;
}
