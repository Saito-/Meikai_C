#include <ctype.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "getputch.h"

#define MAX_STAGE 10
#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

int main()
{
	int i, j, x, stage;
	int dgt[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a[10];
	double t;
	time_t start, end;

	init_getputch();
	srand(time(NULL));

	printf("ダブっている数字を入力してください\n");
	printf("スペースキーで開始します\n");
	fflush(stdout);
	while (getch() != ' ');

	start = time(NULL);
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;
		int no;

		i = j = 0;
		while (i < 9) {
			a[j++] = dgt[i];
			if (i == x) 
				a[j++] = dgt[i];
			i++;
		}

		for (i = 9; i > 0; i--) {
			int idx = rand() % (i + 1);
			if (i != idx)
				swap(int, a[i], a[idx]);
		}

		for (i = 0; i < 10; i++) {
			printf("%d ", a[i]);
		}
		printf(": ");

		fflush(stdout);

		do {
			no = getch();
			if (isprint(no)) {
				putch(no);
				if (no != dgt[x] + '0') 
					putch('\b');
				else
					printf("\n");
			}
		} while (no != dgt[x] + '0');
	}

	end = time(NULL);

	t = difftime(end, start);

	printf("%.f 秒かかりました\n", t);

	if (t > 25.0)
		printf("おそい\n");
	else if (t > 20.0)
		printf("すこしおそい\n");
	else if (t > 17.0)
		printf("ふつう\n");
	else
		printf("はやい\n");

	term_getputch();
	return 0;
}
