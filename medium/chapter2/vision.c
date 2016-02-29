#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
	int stage;
	int a, b, c;
	int ans;
	int n;
	clock_t start, end;

	srand((unsigned)time(NULL));
	printf("Game start\n");

	start = clock();

	for (stage = 0; stage < 10; stage++) {
		a = 10 + rand() % 99;
		b = 10 + rand() % 99;
		c = 10 + rand() % 99;

		n = rand() % 17;

		printf("%d%*s+%*s%d%*s+%*s%d = ",
			a, n, " ", n, " ", b, n, " ", n, " ", c);

		do {
			scanf("%d", &ans);
			if (ans == a + b + c) break;
			printf("Incorrect. Please reinput: ");
		} while (1);
	}

	end = clock();

	double t = (double)(end-start) / CLOCKS_PER_SEC;

	printf("\nGame over\n");
	printf("Clear time: %f sec\n", t);

	return 0;
}
