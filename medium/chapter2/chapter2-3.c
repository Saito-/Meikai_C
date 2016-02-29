#include <stdio.h>
#include <time.h>
#include <string.h>

void sleep(unsigned long t)
{
	clock_t c1, c2;
	c1 = clock();

	do {
		if ((c2 = clock()) == (clock_t)-1) return;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < t);
	return;
}

void bput(const char* msg, int d, int e, int n)
{
	int i;
	int len = strlen(msg);
	for (i = 0; i < n; i++) {
		printf("\r%s", msg);
		sleep(d);
		fflush(stdout);
		printf("\r%*s", len, " ");
		sleep(e);
		fflush(stdout);
	}
	return;
}

int main() 
{
	int i;
	char msg[] = "Hoge Hoge";
	bput(msg, 500, 500, 5);

	return 0;
}
