#include <stdio.h>
#include <math.h>

#define diff(x, y) (x - y)

int main()
{
	int x;
	int y;
	printf("x = "); scanf("%d", &x);
	printf("y = "); scanf("%d", &y);
	printf("x - y = %d\n", diff(x, y));
	return 0;
}
