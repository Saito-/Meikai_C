#include <stdio.h>
#include <stdlib.h>

void detab(FILE* src, FILE* dst, int width)
{
	int ch, pos = 1;

	while ((ch = fgetc(src)) != EOF) {
		int num;

		switch (ch) {
		case '\t':
			num = width - (pos - 1) % width;
			for (; num > 0; num--) {
				fputc(' ', dst);
				pos++;
			}
			break;
		case '\n':
			fputc(ch, dst); pos = 1; break;
		default:
			fputc(ch, dst); pos++; break;
		}
	}
}

int main(int argc, char* argv[])
{
	int width = 8;
	FILE* fp;

	if (argc < 2)
		detab(stdin, stdout, width);
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
				detab(fp, stdout, width);
				fclose(fp);
			}
		}
	}
	return 0;
}
