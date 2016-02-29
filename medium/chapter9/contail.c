#include <stdio.h>
#include <stdlib.h>

int count_row(FILE* src)
{
	int row = 1;
	char buf[256];

	while ((fgets(buf, sizeof(buf), src)) != NULL)
		row++;
	return row;
}

void contail(FILE* src, FILE* dst, int n, int row)
{
	int r = 1;
	char buf[256];

	while ((fgets(buf, sizeof(buf), src)) != NULL) {
		if (row - r <= n) 
			fputs(buf, dst);
		r++;
	}
}

int main(int argc, char* argv[])
{
	int n = 10;
	FILE* fp;
	char* fname;

	if (argc < 2) {
		fprintf(stderr, "引数の個数がおかしい\n");
		return 1;
	}
	if (argc == 3) {
		if (argv[1][0] == '-') {
			if (argv[1][1] != 'n') {
				fprintf(stderr, "パラメータが不正\n");
				return 1;
			}
			n = atoi(argv[1]+2);
		}
		fname = argv[2];
	} else {
		fname = argv[1];
	}

	if ((fp = fopen(fname, "r")) == NULL) {
		fprintf(stderr, "ファイル %s がオープンできない\n", fname);
		return 1;
	}

	int row = count_row(fp);
	fp = fopen(fname, "r");

	contail(fp, stdout, n, row);
	fclose(fp);
	return 0;
}
