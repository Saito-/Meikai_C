#include <stdio.h>
#include <math.h>

int main()
{
	int count_rows = 0;
	int i;

	while (1) {
		char ch;
		ch = getchar();
		if (ch == EOF) break;

		if (ch == '\n') count_rows++;
	}

	printf("Number of row: %d\n", count_rows);
	return 0;
}
