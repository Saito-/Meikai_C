#include <stdio.h>

void swap(int* x, int* y) 
{
	int tmp = *y;
	*y = *x;
	*x = tmp;
}

void sort2(int* x, int* y)
{
	if (*x > *y) swap(x, y);
}

void sort3(int* x, int* y, int* z)
{
	sort2(x, y);
	sort2(y, z);
	sort2(x, y);
}

int main()
{
	int x = 5;
	int y = 2;
	int z = 10;
	
	printf("x, y, z = %d, %d, %d\n", x, y, z);
	sort3(&x, &y, &z);
	printf("x, y, z = %d, %d, %d\n", x, y, z);

	
	return 0;
}
