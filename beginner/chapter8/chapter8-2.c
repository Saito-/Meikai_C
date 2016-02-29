#include <stdio.h>
#include <math.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))

int main()
{
	int w = 0;
	int x = 1;
	int y = 2;
	int z = 3;
	int max_a, max_b;
	max_a = max(max(w, x), max(y, z));
	max_b = max(max(max(w, x), y) ,z);
	printf("max_a = %d\n", max_a);
	printf("max_b = %d\n", max_b);
	return 0;
}
