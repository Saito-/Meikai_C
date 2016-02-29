#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand((unsigned)time(NULL));
	int i;

	for (i = 0; i < 10; i++) {
		printf("%d\n", rand()%10);
	}

	return 0;
}
