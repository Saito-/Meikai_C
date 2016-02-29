#include <time.h>
#include <stdio.h>
#include <stdlib.h>


/* x 秒経過するのを待つ */
/* 長い時間使えるが精度は低い */
int ssleep(double x)
{
	time_t t1 = time(NULL), t2;

	do {
		if (t2 = time(NULL) == (time_t)-1) return 0;
	} while (diffime(t2, t1) < x);
	return 1;
}

int main()
{
	int a, b, c, d;
	int input;
	time_t start, end;

	srand(time(NULL));

	a = rand() % 100;
	b = rand() % 100;
	c = rand() % 100;
	d = rand() % 100;

	printf("%d + %d + %d + %d = ", a, b, c, d);

	start = time(NULL);

	while (1) {
		scanf("%d", &input);
		if (input == a + b + c + d) break;
		printf("\n 再入力: ");
	}

	end = time(NULL);

	printf("%.0f 秒経過\n", difftime(end, start));

	return 0;
}
