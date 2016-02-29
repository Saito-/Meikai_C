#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

int QNO;
char **eptr;

int go(const char* str)
{
	int i;
	int len = strlen(str);
	int mistake = 0;

	for (i = 0; i < len; i++) {
		printf(" %s \r", &str[i]);
		fflush(stdout);
		while (getch() != str[i]) mistake++;
	}
	return mistake;
}

int read_tango(const char* fname)
{
	int i;
	FILE* fp;
	if ((fp = fopen(fname, "r")) == NULL) return 1;

	fscanf(fp, "%d", &QNO);

	if ((eptr = calloc(QNO, sizeof(char*))) == NULL) return 1;

	for (i = 0; i < QNO; i++) {
		char etemp[1024];

		fscanf(fp, "%s", etemp);
		if ((eptr[i] = malloc(strlen(etemp) + 1)) == NULL) return 1;
		strcpy(eptr[i], etemp);
	}
	fclose(fp);
	return 0;
}

void word_training(const char *filename)
{
	int stage;
	int n;
	int qno, pno;
	int tno, mno;
	time_t start, end;
	char* str;
	
	if (read_tango(filename) == 1) {
		printf("\r単語帳ファイルの読み込み失敗\r\n");
		fflush(stdout);
		exit(1);
	}
	
	printf("-----タイピングゲーム-----\r\n");
	printf("何単語挑戦しますか? (1 ~ %d): ", QNO);
	fflush(stdout);
	echo();
	scanw("%d", &n);
	fflush(stdout);

	noecho();
	printf("\r%s の中の単語を %d 個練習します\r\n", filename, n);
	printf("スペースキーで開始\r\n");
	fflush(stdout);
	while(getch() != ' ');

	tno = mno = 0;
	pno = n;

	start = time(NULL);

	for (stage = 0; stage < n; stage++) {
		do {
			qno = rand() % QNO;
		} while (qno == pno);
		
		mno += go(eptr[qno]);
		tno += strlen(eptr[qno]);
		pno = qno;
	}

	end = time(NULL);

	printf("\r問題: %d 文字/ミス: %d 回\r\n", tno, mno);
	printf("\r経過時間: %.f 秒\r\n", difftime(end, start));
	fflush(stdout);
}

int main(int argc, char* argv[])
{
	int i;
	int n;
	int retry;
	char* fname;

	initscr();
	cbreak();
	noecho();
	refresh();

	if (argc == 2) 
		fname = argv[1];
	else
		fname = "C_TERM";

	srand(time(NULL));

	word_training(fname);

	for (i = 0; i < QNO; i++) {
		free(eptr[i]); 
	}
	free(eptr);

	printf("スペースキーで終了\r\n");
	fflush(stdout);
	while(getch() != ' ');
	
	endwin();
	return 0;
}
