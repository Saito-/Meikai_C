#include <stdio.h>
#include <stdlib.h>

int main()
{
	int (*x)[3];
	int nx = 4;

	x = calloc(nx * 3, sizeof(int));

	if (x == NULL) return 1;
	
	int i, j;
	for (i = 0; i < nx; i++) 
		for (j = 0; j < 3; j++)
			printf("x[%d][%d] = %d\n", i, j, x[i][j]);
	free(x);
	return 0;
}
