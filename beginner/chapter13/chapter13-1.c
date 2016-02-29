#include <stdio.h>

int main()
{
	FILE* fp;
	char fname[256];
	
	printf("File name: "); scanf("%s", fname);

	if ((fp = fopen(fname, "r")) == NULL) 
		printf("File %s does not exist\n", fname);
	else 
		printf("File %s exist\n", fname);
	
	fclose(fp);

	return 0;

}
