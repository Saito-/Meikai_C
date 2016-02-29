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

int pow10(int x)
{
	int i;
	int ret = 1;
	for (i = 0; i < x; i++) {
		ret *= 10;
	}
	return ret;
}

int get_onenum(int ans, int pos, int level) 
{
	int* temp;
	int i;
	temp = (int*)malloc(sizeof(int)*level);

	for (i = 0; i < level; i++) {
		temp[i] = ans % 10;
		ans /= 10;
	}
	int ret = temp[pos];
	free(temp);
	return ret;
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
		int ans;
		int input;

		ans = pow10(level-1) + rand() % (pow10(level-1) * 9);

		printf("%d", ans);
		fflush(stdout);
		sleep(125*level);

		int pos = rand() % level;

		printf("\r%*s\r%d 桁目は? 入力: ", level, " ", pos+1);
		scanf("%d", &input);

		if (get_onenum(ans, pos, level) != input) 
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
