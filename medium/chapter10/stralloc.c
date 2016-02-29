#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char st[16];
	char* pt;

	printf("文字列 st を入力してね: ");
	scanf("%s", st);

	pt = (char*)malloc(sizeof(char) * strlen(st) + 1);

	if (pt) {
		strcpy(pt, st);
		printf("st = %s\n", st);
		printf("pt = %s\n", pt);
		free(pt);
	}

	return 0;
}
