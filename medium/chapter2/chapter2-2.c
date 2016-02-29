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

void gput(const char* msg, int speed)
{
	int i;
	int len = strlen(msg);
	for (i = 0; i < len; i++) {
		putchar(msg[i]);
		sleep(speed);
		fflush(stdout);
	}
	return;
}

int main() 
{
	int i;
	char msg[] = "Hoge Hoge";
	int len = strlen(msg);
	gput(msg, 500);

	return 0;
}
