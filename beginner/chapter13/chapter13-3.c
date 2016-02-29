#include <stdio.h>

#define N 6

typedef struct {
	char name[100];
	double height;
	double weight;
} person;

void write_profile(FILE* fp)
{
	double height, weight;
	char name[100];
	printf("Name: "); scanf("%s", name);
	printf("Height: "); scanf("%lf", &height);
	printf("Weight: "); scanf("%lf", &weight);

	fprintf(fp, "%s %f %f\n", name, height, weight);
	printf("Wrote data\n");
}

int main()
{
	FILE* fp;
	if ((fp = fopen("chapter13-3.dat", "a")) == NULL) {
		printf("Cannot open file\n");
		return 1;
	}
	
	while (1) {
		write_profile(fp);
		int n;
		printf("Continue? Yes:0, No:1 ");
		scanf("%d", &n);
		if (n) break;
	}

	fclose(fp);
	return 0;

}
