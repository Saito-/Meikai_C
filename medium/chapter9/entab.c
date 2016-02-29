#include <stdio.h>
#include <stdlib.h>

void entab(FILE* src, FILE* dst, int width)
{
	int ch;
	int count = 0;
	int ntab = 0;
	int pos = 1;

	for (; (ch = fgetc(src)) != EOF; pos++) {
		if (ch == ' ') {
			if (pos % width != 0) {
				count++;
			} else {
				count = 0;
				ntab++;
			}
		} else {
			for (; ntab > 0; --ntab) {
				fputc('\t', dst);
			}
			if (ch == '\t') {
				count = 0;
			} else {
				for (; count > 0; count--) {
					fputc(' ', dst);
				}
			}
			fputc(ch, dst);
			if (ch == '\n') {
				pos = 0;
			} else if (ch == '\t') {
				pos += width - (pos - 1) % width - 1;
			}
		}
	}
}

int main(int argc, char* argv[])
{
	int width = 8;
	FILE* fp;

	if (argc < 2)
		entab(stdin, stdout, width);
	else {
		while (--argc > 0) {
			if (**(++argv) == '-') {
				if (*++(*argv) == 't')
					width = atoi(++*argv);
				else {
					fputs("パラメータが不正\n", stderr);
					return 1;
				}
			} else if ((fp = fopen(*argv, "r")) == NULL) {
				fprintf(stderr, "ファイル %s がオープンできない\n", *argv);
				return 1;
			} else {
				entab(fp, stdout, width);
				fclose(fp);
			}
		}
	}
	return 0;
}
