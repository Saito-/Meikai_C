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
	int start = 0;
	char msg[] = "Hoge Hoge ";
	int len = strlen(msg);

	while (1) {
		putchar('\r');
		for (i = 0; i < len; i++) {
			if (i + start < len) 
				putchar(msg[start+i]);
			else 
				putchar(msg[start+i - len]);
		}

		fflush(stdout);
		sleep(500);
	
		if (start < len - 1) start++;
		else start = 0;
	}
	return 0;
}
