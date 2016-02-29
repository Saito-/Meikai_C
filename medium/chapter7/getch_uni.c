#include <curses.h>
#include <stdio.h>
#include <ctype.h>

int main()
{
	int ch;
	int retry;

	initscr();
	cbreak();
	noecho();
	refresh();

	do {
		printf("キーを押して下さい\n");
		fflush(stdout);

		ch = getch();

		printf("\n\r押されたキーは %c で 値は %d です\n\r",
			isprint(ch) ? ch : ' ', ch);

		printf("もういちど? (Y/N): ");
		fflush(stdout);
		retry = getch();
		if (isprint(retry)) putchar(retry);

		putchar('\n');
		fflush(stdout);
	} while (retry == 'Y' || retry == 'y');

	endwin();
	return 0;
}
