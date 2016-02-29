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

void telop(const char* msg, int d, int speed, int n)
{
	int i, j;
	int start = 0;
	int len = strlen(msg);

	for (i = 0; i < n*len; i++) {
		putchar('\r');
		for (j = 0; j < len; j++) {
			if (j + start < len)
				putchar(msg[start+j]);
			else
				putchar(msg[start+j-len]);
		}

		fflush(stdout);
		sleep(speed);

		if (d == 0) {
			if (start < len - 1) 
				start++;
			else 
				start = 0;
		} else {
			if (start > 0) 
				start--;
			else
				start = len - 1;
		}
	}
}

int main() 
{
	char msg[] = "Hoge Hoge ";

	telop(msg, 1, 500, 5);

	return 0;
}
