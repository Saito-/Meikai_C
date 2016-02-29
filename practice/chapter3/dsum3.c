#include <stdio.h>

double sum(double (*z)[5])
{
	int i;
	double s = 0.0;

	for (i = 0; i < 5; i++) 
		s += (*z)[i];
	
	return s;
}

int main()
{
	double s;
	double x[5];
	int i;
	int n = sizeof(x) / sizeof(x[0]);

	for (i = 0; i < 5; i++) {
		printf("x[%d]: ", i);
		scanf("%lf", x+i);
	}

	s = sum(&x);
	printf("s = %f\n", s);
	return 0;
}
