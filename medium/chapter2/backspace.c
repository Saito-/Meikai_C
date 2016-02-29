#include <stdio.h>
#include <time.h>

void sleep(unsigned long t)
{
	clock_t c1, c2;
	c1 = clock();

	do {
		if ((c2 = clock()) == (clock_t)-1) return;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < t);
	return;
}

int main() 
{
	int i;

	printf("ABCDEFG");

	for (i = 0; i < 7; i++) {
		sleep(1000);
		printf("\b \b");
		fflush(stdout);
	}
	return 0;
}
