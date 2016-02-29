#include <ctype.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#define MAX_STAGE 10
#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

int main()
{
	int i, j, x, stage;
	int dgt[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a[11];
	double t;
	time_t start, end;

	initscr();
	cbreak();
	noecho();
	refresh();

	srand(time(NULL));

	printf("ダブっている数字を入力してください\r\n");
	printf("スペースキーで開始します\r\n");
	fflush(stdout);
	while (getch() != ' ');

	start = time(NULL);
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 10;
		char no;

		i = j = 0;
		while (i < 10) {
			a[j++] = dgt[i];
			if (i == x) 
				a[j++] = dgt[i];
			i++;
		}

		for (i = 10; i > 0; i--) {
			int idx = rand() % (i + 1);
			if (i != idx)
				swap(int, a[i], a[idx]);
		}

		for (i = 0; i < 11; i++) {
			int nspace1 = 1 + rand() % 3;
			int nspace2 = 1 + rand() % 3;
			printf("%*s%d %*s", nspace1, "", a[i], nspace2, "");
			if ((i + 1) % 4 == 0)
				printf("\r\n");
		}

		printf("\r\n: ");

		fflush(stdout);

		do {
			no = getch();
			if (isprint(no)) {
				putchar(no);
				if (no != dgt[x] + '0') 
					putchar('\b');
				else
					printf("\n");
			}
		} while (no != dgt[x] + '0');
		printf("\r");
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
