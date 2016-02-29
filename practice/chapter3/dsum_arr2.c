#include <stdio.h>

void sum(double (*z)[3], int n)
{
	int i, j;

	for (i = 0; i < n; i++) {
		double s = 0.0;
		for (j = 0; j < 3; j++) 
			s += (*z)[j];
		printf("%d 行の合計: %f\n", i, s);
		z++;
	}
}

int main()
{
	double s;
	double x[][3] = {
		{ 0.0, 1.0, 2.0 },
		{ 3.0, 4.0, 5.0 },
		{ 6.0, 7.0, 8.0 },
		{ 9.0, 10.0, 11.0 },
	};

	int n = sizeof(x) / sizeof(x[0]);
	sum(x, n);
	return 0;
}
