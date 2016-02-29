#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int (max)(int a, int b)
{
	puts("関数版 max");
	return (a > b ? a : b);
}

int main()
{
	int x, y;
	
	printf("x: "); scanf("%d", &x);
	printf("y: "); scanf("%d", &y);

	printf("max(x, y) = %d\n", max(x, y));
	printf("(max)(x, y) = %d\n", (max)(x, y));

	return 0;
}
