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

int main() 
{
	int i;
	char msg[] = "Hoge Hoge";
	int len = strlen(msg);

	while (1) {
		for (i = 0; i < len; i++) {
			sleep(500);
			putchar(msg[i]);
			fflush(stdout);
		}
		for (i = 0; i < len; i++) {
			sleep(500);
			printf("\b \b");
			fflush(stdout);
		}
	}
	return 0;
}
