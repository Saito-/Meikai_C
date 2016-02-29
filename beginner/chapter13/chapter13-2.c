#include <stdio.h>

#define N 6

typedef struct {
	char name[100];
	double height;
	double weight;
} person;

void swap_person(person* x, person* y)
{
	double hx = x->height;
	double hy = y->height;
	person tmp = *y;
	*y = *x;
	*x = tmp;
}

void sort(person data[])
{
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N - i - 1; j++) {
			if (data[j].height > data[j+1].height)
				swap_person(&data[j], &data[j+1]);
		}
	}
}

void print_person(person data[])
{
	int i;
	for (i = 0; i < N; i++) {
		char* name = data[i].name;
		double height = data[i].height;
		double weight = data[i].weight;
		printf("%-10s %5.1f %5.1f\n", name, height, weight);
	}
}

int main()
{
	FILE* fp;
	person people[N];
	
	if ((fp = fopen("hw.dat", "r")) == NULL) { 
		printf("File can't open");
		return 1;
	}

	int i = 0;
	while (fscanf(fp, "%s%lf%lf", 
			people[i].name, 
			&people[i].height, 
			&people[i].weight) == 3) {
		i++;
	}
	fclose(fp);
	
	print_person(people);

	sort(people);

	print_person(people);

	return 0;

}
