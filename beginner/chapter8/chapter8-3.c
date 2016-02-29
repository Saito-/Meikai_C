#include <stdio.h>
#include <math.h>

#define swap(type, x, y) { type tmp = y; y = x; x = tmp; }

int main()
{
	int x = 10;
	int y = 5;
	printf("(x, y) = (%d, %d)\n", x, y);
	swap(int, x, y)
	printf("(x, y) = (%d, %d)\n", x, y);
	return 0;
}
