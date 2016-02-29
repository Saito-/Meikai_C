#include <stdio.h>

int z = 1;

int main()
{
	int x = z;
	int z = 0;
	int y = z;

	printf("(x, y, z) = (%d, %d, %d)\n", x, y, z);
	return 0;
}
