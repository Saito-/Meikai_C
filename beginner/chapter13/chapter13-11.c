#include <stdio.h>
#include <time.h>
#include <ctype.h>

int main()
{
	FILE* fp;
	char fname[256];
	double a[10] = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };

	printf("Write file name: "); scanf("%s", fname);
	if ((fp = fopen(fname, "wb")) == NULL) {
		printf("Output file cannot open\n");
		return 1;
	}
	fwrite(a, sizeof(double), 10, fp);
	fclose(fp);

	printf("Read file name: "); scanf("%s", fname);
	if ((fp = fopen(fname, "rb")) == NULL) {
		printf("Input file cannot open\n");
		return 1;
	}
	fread(a, sizeof(double), 10, fp);
	fclose(fp);

	int i;
	for (i = 0; i < 10; i++) {
		printf("a[%d] = %f\n", i, a[i]);
	}

	return 0;
}
