#include <stdio.h>

int main()
{
	int x, y;
	printf("x: "); scanf("%d", &x);
	printf("y: "); scanf("%d", &y);
	if (x == y) 
		printf("%d = %d\n", x, y);
	else
		printf("%d != %d\n", x, y);
	
	return 0;
}
