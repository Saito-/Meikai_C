#include <stdlib.h>
#include <stdio.h>

#define MAX 10

void print_array(int* a)
{
	int i;
	for (i = 0; i < MAX; i++) {
		printf("%2d ", a[i]);
	}
	putchar('\n');
}

int main()
{
	int a[MAX] = { 0 };
	int i = 0;
	int flg = 0;
	while (flg == 0) {
		printf("Add number to array: ");
		scanf("%d", a+i);
		print_array(a);
		printf("Continue? (0: yes, 1: no): ");
		scanf("%d", &flg);
		i = (i + 1) % 10;
	}

	return 0;
}
