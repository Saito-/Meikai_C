#include <ctype.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

#define MAX_STAGE 20
#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

static int putch(ch)
{
	int result = putchar(ch);
	fflush(stdout);
	return result;
}

int main()
{
	char* qstr[] = { "0123456789",
			 "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
			 "abcdefghijklmnopqrstuvwxyz",
		       };
	int chmax[] = { 10, 26, 26 };
	int i, stage;
	int key;
	double t;
	time_t start, end;

	initscr();
	cbreak();
	noecho();
	refresh();

	srand(time(NULL));

	printf("連続する 3 つの数字, 英字から\r\n");
	printf("隠されている文字を入力してください\r\n");
	printf("EX: A ? C : と表示されたら B を\r\n");
	printf("EX: 4 5 ? : と表示されたら 6 を\r\n");
	printf("入力します\r\n");
	printf("スペースキーで開始\r\n");
	fflush(stdout);

	while (getch() != ' ');

	start = time(NULL);
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int qtype = rand() % 3;
		int nhead = rand() % (chmax[qtype] - 2);
		int x = rand() % 3;

		putchar('\r');

		for (i = 0; i < 3; i++) {
			if (i != x) 
				printf(" %c", qstr[qtype][nhead + i]);
			else
				printf(" ?");
		}

		printf(" : ");
		fflush(stdout);
		
		do {
			key = getch();
			if (isprint(key)) {
				putchar(key);
				if (key != qstr[qtype][nhead + x]) 
					putchar('\b');
			}
		} while (key != qstr[qtype][nhead + x]);
		putchar('\r');
		putchar('\n');
		fflush(stdout);
	}

	end = time(NULL);

	t = difftime(end, start);

	printf("%.f 秒かかりました\r\n", t);

	if (t > 50.0)
		printf("おそい\r\n");
	else if (t > 40.0)
		printf("すこしおそい\r\n");
	else if (t > 34.0)
		printf("ふつう\r\n");
	else
		printf("はやい\r\n");
	
	printf("スペースキーで終了\r\n");
	fflush(stdout);

	while (getch() != ' ');

	endwin();
	return 0;
}
