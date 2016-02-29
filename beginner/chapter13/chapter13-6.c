#include <stdio.h>
#include <time.h>

int main()
{
	FILE* fp;
	char fname[256];
	char ch;
	int count = 0;

	printf("File name: "); scanf("%s", fname);
	if ((fp = fopen(fname, "r")) == NULL) {
		printf("File cannot open\n");
		return 1;
	}
	while ((ch = fgetc(fp)) != EOF) {
		if (ch == '\n') count++;
	}

	printf("Number of row: %d\n", count);
	fclose(fp);

	return 0;
}
