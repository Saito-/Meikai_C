#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEVEL_MIN 2
#define LEVEL_MAX 6

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
	int max_stage;
	int level;
	int success = 0;
	int* scores;
	clock_t start, end;

	srand((unsigned long)time(NULL));

	printf("プラスワントレーニング\n");
	printf("2桁の数字を記憶します\n");
	printf("それらに1を加えた数字を入力してください\n");

	do {
		printf("挑戦するレベル (%d ~ %d): ", LEVEL_MIN, LEVEL_MAX);
		scanf("%d", &level);
	} while (level < LEVEL_MIN || level > LEVEL_MAX);

	do {
		printf("トレーニング回数\n");
		scanf("%d", &max_stage);
	} while (max_stage <= 0);

	scores = (int*)calloc(max_stage, sizeof(int));

	start = clock();
	for (stage = 0; stage < max_stage; stage++) {
		int ans[LEVEL_MAX];
		int input[LEVEL_MAX];
		int seikai = 0;

		printf("第%dステージ\n", stage+1);

		for (i = 0; i < level; i++) {
			ans[i] = rand() % 90 + 10;
			printf("%d ", ans[i]);
		}
		fflush(stdout);
		sleep(300*level);
		printf("\r%*s\r", level*3, " ");

		for (i = 0; i < level; i++) {
			printf("%d 番目の数: ", i+1);
			scanf("%d", input+i);
		}

		for (i = 0; i < level; i++) {
			if (input[i] != ans[i] + 1)
				printf("X ");
			else {
				printf("O ");
				seikai++;
			}
		}
		putchar('\n');
	
		for (i = 0; i < level; i++) {
			printf("%2d ", ans[i]);
		}

		printf("%d 個正解です\n", seikai);
		scores[stage] = seikai;
		success += seikai;
	}

	end = clock();

	printf("終了\n");
	printf("正答率: %3.2f (%d / %d)\n", (double)(success * 100/(level*max_stage)), 
		success, level*max_stage);

	for (stage = 0; stage < max_stage; stage++) 
		printf("第%dステージ: %d\n", stage+1, scores[stage]);

	printf("経過時間: %f\n", (double)(end - start)/CLOCKS_PER_SEC);

	free(scores);

	return 0;
}
