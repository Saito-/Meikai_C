#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int num;
	char (*pt)[15];

	printf("文字列の個数を入力してね: ");
	scanf("%d", &num);

	pt = (char (*)[15])malloc(sizeof(char) * num * 15);

	if (pt) {
		int i;
		for (i = 0; i < num; i++) {
			printf("pt[%d]: ", i);
			scanf("%s", pt[i]);
		}
	

		for (i = 0; i < num; i++) {
			printf("pt[%d]: %s\n", i, pt[i]);
		}

		free(pt);
	}
	return 0;
}
