#include <ctype.h>
#include <stdio.h>
#include <limits.h>

void hdump(FILE* src, FILE* dst)
{
	int n;
	unsigned long count = 0;
	unsigned char buf[16];

	while ((n = fread(buf, 1, 16, src)) > 0) {
		int i;

		fprintf(dst, "%08lX ", count);

		for (i = 0; i < n; i++) {
			fprintf(dst, "%0*X ", (CHAR_BIT + 3) / 4, (unsigned)buf[i]);
		}

		if (n < 16) {
			for (i = n; i < 16; i++) {
				fputs("   ", dst);
			}
		}

		for (i = 0; i < n; i++) {
			fputc(isprint(buf[i]) ? buf[i] : '.', dst);
		}
		
		fputc('\n', dst);

		count += 16;
	}

	fputc('\n', dst);
}

int main(int argc, char* argv[])
{
	FILE* fp;

	if (argc < 2) {
		hdump(stdin, stdout);
	} else {
		while (--argc > 0) {
			if ((fp = fopen(*++argv, "rb")) == NULL) {
				fprintf(stderr, "ファイル %s がオープンできない\n", *argv);
				return 1;
			} else {
				hdump(fp, stdout);
				fclose(fp);
			}
		}
	}

	return 0;
}
