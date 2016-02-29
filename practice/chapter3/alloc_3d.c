#include <stdio.h>
#include <stdlib.h>

int main()
{
	int (*x)[4][3];
	int nx = 5;

	x = calloc(nx * 4 * 3, sizeof(int));

	if (x == NULL) return 1;
	
	int i, j, k;
	for (i = 0; i < nx; i++) 
		for (j = 0; j < 4; j++)
			for (k = 0; k < 3; k++)
			printf("x[%d][%d][%d] = %d\n", i, j, k, x[i][j][k]);
	free(x);
	return 0;
}
