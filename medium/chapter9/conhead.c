#include <stdio.h>
#include <stdlib.h>

void conhead(FILE* src, FILE* dst, int n)
{
	int ch;
	int row = 1;
	char buf[256];

	while ((fgets(buf, sizeof(buf), src)) != NULL && row <= n) {
		fputs(buf, dst);
		row++;
	}
}

int main(int argc, char* argv[])
{
	int n = 10;
	FILE* fp;

	while (--argc > 0) {
		if (**(++argv) == '-') {
			if (*++(*argv) == 'n')
				n = atoi(++*argv);
			else {
				fputs("パラメータが不正\n", stderr);
				return 1;
			}
		} else if ((fp = fopen(*argv, "r")) == NULL) {
			fprintf(stderr, "ファイル %s がオープンできない\n", *argv);
			return 1;
		} else {
			conhead(fp, stdout, n);
			fclose(fp);
		}
	}
	return 0;
}
