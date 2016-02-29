#include <stdio.h>

double sum(double z[], int n)
{
	int i;
	double s = 0.0;

	for (i = 0; i < n; i++) 
		s += z[i];
	
	return s;
}

int main()
{
	double s;
	double x[5];
	int i;
	int n = sizeof(x) / sizeof(x[0]);

	for (i = 0; i < n; i++) {
		printf("x[%d]: ", i);
		scanf("%lf", x+i);
	}

	s = sum(x, n);
	printf("s = %f\n", s);
	return 0;
}
