#include <stdio.h>

#define BANPEI 9999

double sum(double z[])
{
	int i;
	double s = 0.0;

	for (i = 0; z[i] != BANPEI; i++) 
		s += z[i];
	
	return s;
}

int main()
{
	double s;
	double x[6];
	int i;
	int n = sizeof(x) / sizeof(x[0]);

	for (i = 0; i < n-1; i++) {
		printf("x[%d]: ", i);
		scanf("%lf", x+i);
		if (x[i] == BANPEI) break;
	}

	if (i == n-1)
		x[i] = BANPEI;

	s = sum(x);
	printf("s = %f\n", s);
	return 0;
}
