#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#define MAX_STAGE 10
#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

int main()
{
	int i, j, stage;
	int dgt[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a[9];
	double t;
	time_t start, end;

	initscr();
	cbreak();
	noecho();
	refresh();

	srand(time(NULL));

	printf("欠けている数字を入力してください\n\r");
	printf("スペースキーで開始\r\n");
	fflush(stdout);

	while (getch() != ' ');

	start = time(NULL);
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 10;
		char no;

		putchar('\r');

		i = j = 0;
		while (i < 10) {
			if (i != x) 
				a[j++] = dgt[i];
			i++;
		}

		for (i = 8; i > 0; i--) {
			int idx = rand() % (i + 1);
			if (i != idx)
				swap(int, a[i], a[idx]);
		}

		for (i = 0; i < 9; i++) {
			int numspace1 = 1 + rand() % 3;
			int numspace2 = 1 + rand() % 3;
			printf("%*s%d %*s", numspace1, "", a[i], numspace2, "");
			if ((i+1) % 3 == 0) 
				printf("\r\n");
		}
		printf(": ");
		fflush(stdout);

		do {
			no = getch();
			if (isprint(no)) {
				putchar(no);
				if (no != dgt[x] + '0') 
					putchar('\b');
			}
		} while (no != dgt[x] + '0');
		printf("\r\n");
		fflush(stdout);
	}

	end = time(NULL);

	t = difftime(end, start);

	printf("%.f 秒かかりました\r\n", t);

	if (t > 25.0)
		printf("おそい\r\n");
	else if (t > 20.0)
		printf("すこしおそい\r\n");
	else if (t > 17.0)
		printf("ふつう\r\n");
	else
		printf("はやい\r\n");
	
	printf("スペースキーで終了\r\n");
	fflush(stdout);

	while (getch() != ' ');

	endwin();

	return 0;
}
