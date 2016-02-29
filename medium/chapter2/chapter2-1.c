#include <stdio.h>
#include <time.h>
#include <string.h>

int main() 
{
	int i,j;
	clock_t start, end;

	start = clock();

	for (i = 1; i < 10; i++) {
		for (j = 1; j < 10; j++) {
			printf("%2d ", i*j);
		}
		printf("\n");
	}

	end = clock();

	double t = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time: %.8f\n", t);
	printf("clock: %.8f\n", (double)(end - start));
	return 0;
}
