#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CNO 4

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

int QNO;
char **jptr;
char **eptr;

void print_cand(const int* c, int sw)
{
	int i;

	for (i = 0; i < CNO; i++) {
		printf("(%d) %s  ", i, sw ? jptr[c[i]] : eptr[c[i]]);
	}
	printf(" : ");
}

int make_cand(int* c, int n)
{
	int i, j, x;

	c[0] = n;

	for (i = 1; i < CNO; i++) {
		do {
			x = rand() % QNO;
			for (j = 0; j < i; j++) {
				if (c[j] == x) break;
			}
		} while (i != j);
		c[i] = x;
	}

	j = rand() % CNO;
	if (j != 0) {
		swap(int, c[0], c[j]);
	}
	return j;
}

int read_tango(const char* fname)
{
	int i;
	FILE* fp;
	if ((fp = fopen(fname, "r")) == NULL) return 1;

	fscanf(fp, "%d", &QNO);

	if ((jptr = calloc(QNO, sizeof(char*))) == NULL) return 1;
	if ((eptr = calloc(QNO, sizeof(char*))) == NULL) return 1;

	for (i = 0; i < QNO; i++) {
		char etemp[1024];
		char jtemp[1024];

		fscanf(fp, "%s%s", etemp, jtemp);
		if ((eptr[i] = malloc(strlen(etemp) + 1)) == NULL) return 1;
		if ((jptr[i] = malloc(strlen(jtemp) + 1)) == NULL) return 1;
		strcpy(eptr[i], etemp);
		strcpy(jptr[i], jtemp);
	}
	fclose(fp);
	return 0;
}

int main(int argc, char* argv[])
{
	int i;
	int nq, pq;
	int na;
	int sw;
	int retry;
	int cand[CNO];
	char* fname;

	if (argc == 2) 
		fname = argv[1];
	else
		fname = "TANGO";
	if (read_tango(fname) == 1) {
		printf("単語帳ファイルの読み込み失敗\n");
		return 1;
	}

	srand(time(NULL));

	pq = QNO;

	do {
		int no;

		do {
			nq = rand() % QNO;
		} while (nq == pq);
		
		na = make_cand(cand, nq);
		sw = rand() % 2;

		printf("%s はどれ?\n", sw ? eptr[nq] : jptr[nq]);

		do {
			print_cand(cand, sw);
			scanf("%d", &no);
			if (no != na)
				puts("ちがうよ");
		} while (no != na);
		puts("せいかい");

		pq = nq;

		printf("もう一度? 0-いいえ/1-はい: ");
		scanf("%d", &retry);
	} while (retry == 1);

	for (i = 0; i < QNO; i++) {
		free(eptr[i]); free(jptr[i]);
	}
	free(eptr); free(jptr);
	return 0;
}
