#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int num;
	char **pt;

	printf("文字列の個数を入力してね: ");
	scanf("%d", &num);

	pt = (char **)calloc(num, sizeof(char*));

	if (pt) {
		int i;

		for (i = 0; i < num; i++) {
			pt[i] = NULL;
		}

		for (i = 0; i < num; i++) {
			char tmp[128];

			printf("pt[%d]: ", i);
			scanf("%s", tmp);

			pt[i] = (char*)malloc(strlen(tmp) + 1);

			if (pt[i] != NULL)
				strcpy(pt[i], tmp);
			else {
				printf("領域確保失敗\n");
				goto Free;
			}
		}
		for (i = 0; i < num; i++) {
			printf("pt[%d]: %s\n", i, pt[i]);
		}
Free:

		for (i = 0; i < num; i++) {
			free(pt[i]);
		}
		free(pt);
	}
	return 0;
}
