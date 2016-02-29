#include <stdio.h>

int main()
{
	int i;
	typedef int IntAry[];
	IntAry a = {1, 2, 3};
	IntAry b = {1, 2, 3, 4, 5};

	for (i = 0; i < 3; i++) 
		printf("a[%d] = %d\n", i, a[i]);
	for (i = 0; i < 5; i++) 
		printf("b[%d] = %d\n", i, b[i]);
	return 0;
}
