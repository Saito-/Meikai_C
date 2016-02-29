#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double sum(double* a, int n)
{
	int i;
	double r = 0.0;
	for (i = 0; i < n; i++) {
		r += a[i];
	}
	return r;
}

int main() 
{
	int stage;
	int a, b, c;
	int ans;
	int n;
	clock_t start, end;
	double times[10] = { 0.0 };

	srand((unsigned)time(NULL));
	printf("Game start\n");

	for (stage = 0; stage < 10; stage++) {
		a = 10 + rand() % 99;
		b = 10 + rand() % 99;
		c = 10 + rand() % 99;

		n = rand() % 17;
		int pattern = rand() % 4;
		switch (pattern) {
		case 0:
			printf("%d%*s+%*s%d%*s+%*s%d = ",
				a, n, " ", n, " ", b, n, " ", n, " ", c);
			start = clock();
			do {
				scanf("%d", &ans);
				if (ans == a + b + c) break;
				printf("Incorrect. Please reinput: ");
			} while (1);
			end = clock();
			times[stage] = (double)(end-start) / CLOCKS_PER_SEC;
			break;
		case 1:
			printf("%d%*s-%*s%d%*s+%*s%d = ",
				a, n, " ", n, " ", b, n, " ", n, " ", c);
			start = clock();
			do {
				scanf("%d", &ans);
				if (ans == a - b + c) break;
				printf("Incorrect. Please reinput: ");
			} while (1);
			end = clock();
			times[stage] = (double)(end-start) / CLOCKS_PER_SEC;
			break;
		case 2:
			printf("%d%*s+%*s%d%*s-%*s%d = ",
				a, n, " ", n, " ", b, n, " ", n, " ", c);
			start = clock();
			do {
				scanf("%d", &ans);
				if (ans == a + b - c) break;
				printf("Incorrect. Please reinput: ");
			} while (1);
			end = clock();
			times[stage] = (double)(end-start) / CLOCKS_PER_SEC;
			break;
		case 3:
			printf("%d%*s-%*s%d%*s-%*s%d = ",
				a, n, " ", n, " ", b, n, " ", n, " ", c);
			start = clock();
			do {
				scanf("%d", &ans);
				if (ans == a - b - c) break;
				printf("Incorrect. Please reinput: ");
			} while (1);
			end = clock();
			times[stage] = (double)(end-start) / CLOCKS_PER_SEC;
			break;
		}
	}

	printf("\nGame over\n");
	printf("Clear time: %f sec\n", sum(times, 10));
	
	for (stage = 0; stage < 10; stage++) {
		printf("Stage %d, time: %f\n", stage, times[stage]);
	}
	printf("Mean time: %f\n", sum(times, 10)/10);

	return 0;
}
