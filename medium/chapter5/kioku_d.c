#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STAGE 10
#define LEVEL_MIN 3
#define LEVEL_MAX 20

void sleep(unsigned long t)
{
	clock_t c1, c2;
	c1 = clock();

	do {
		if ((c2 = clock()) == (clock_t)-1) return;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < t);
	return;
}

int main()
{
	int i, stage;
	int level;
	int success = 0;
	clock_t start, end;

	srand((unsigned long)time(NULL));

	printf("数値記憶トレーニング\n");

	do {
		printf("挑戦するレベル (%d ~ %d): ", LEVEL_MIN, LEVEL_MAX);
		scanf("%d", &level);
	} while (level < LEVEL_MIN || level > LEVEL_MAX);

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		char ans[LEVEL_MAX+1];
		char input[LEVEL_MAX*2];

		ans[0] = '1' + rand() % 9;
		for (i = 1; i < level; i++) {
			ans[i] = '0' + rand() % 10;
		}
		ans[level] = '\0';
		
		printf("%s", ans);
		fflush(stdout);
		sleep(125*level);

		printf("\r%*s\r入力: ", level, " ");
		scanf("%s", input);

		if (strcmp(ans, input) != 0) 
			printf("不正解です\n");
		else {
			printf("正解です\n");
			success++;
		}
	}

	end = clock();

	printf("終了\n");
	printf("正答率: %3.2f (%d / %d)\n", (double)(success * 100/MAX_STAGE), success, MAX_STAGE);
	printf("経過時間: %f\n", (double)(end - start)/CLOCKS_PER_SEC);

	return 0;

}
