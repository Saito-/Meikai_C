#include <stdio.h>
#include <time.h>
#include <ctype.h>

int main()
{
	FILE *fin, *fout;
	char fname[256];
	char ch;
	int count = 0;

	printf("Input file name: "); scanf("%s", fname);
	if ((fin = fopen(fname, "r")) == NULL) {
		printf("Input file cannot open\n");
		return 1;
	}
	printf("Output file name: "); scanf("%s", fname);
	if ((fout = fopen(fname, "a")) == NULL) {
		printf("Output file cannot open\n");
		return 1;
	}

	while ((ch = fgetc(fin)) != EOF) {
		char lower = tolower(ch);
		fputc(lower, fout);
	}

	fclose(fin); fclose(fout);

	return 0;
}
