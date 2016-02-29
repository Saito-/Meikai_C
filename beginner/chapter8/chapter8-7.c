#include <stdio.h>
#include <math.h>

#define swap(type, x, y) { type tmp = y; y = x; x = tmp; }

void print_marks(int n)
{
	int i;
	for (i = 0; i < n; i++) {
		putchar('*');
	}
	printf("\n");
}

int main()
{
	int counts[10] = { 0 };
	int i;

	printf("Type numbers: ");
	while (1) {
		char ch;
		ch = getchar();
		if (ch == EOF) break;

		if (ch >= '0' && ch <= '9') counts[ch-'0']++;
	}

	printf("Modes:\n");
	for (i = 0; i < 10; i++) {
		printf("%d: ", i); print_marks(counts[i]);
	}
	return 0;
}
