#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int answer_check(int input, int answer)
{
	if (input == answer) return 0;
	if (input > answer) return 1;
	else return -1;
}

void print_inputs(int* inputs, int ans, int max_trial)
{
	int i;
	for (i = 0; i < max_trial; i++) {
		printf("inputs[%d]: %d (ans - input = %d)\n", i, inputs[i], ans-inputs[i]);
	}
}

int pow10(int x)
{
	int r = 1;
	int i;
	for (i = 1; i <= x; i++) {
		r *= 10;
	}
	return r;
}

int make_answer(int min, int max)
{
	int range = max - min + 1;
	int rnd;
	int* tmp;
	int flg;
	do {
		rnd = min + rand() % range;
		int keta = (int)log10(rnd) + 1;
		if (keta == 1)
			return rnd;
		tmp = (int*)malloc(sizeof(int)*keta);
		flg = 0;
		int i, j;
		for (i = keta-1; i >= 0; i--) {
			tmp[i] = (rnd / pow10(i)) % 10;
		}

		for (i = 0; i < keta; i++) {
			int key = tmp[i];
			for (j = i; j < keta-1; j++) {
				if (tmp[j+1] == key) {
					flg = 1;
					continue;
				}
			}
		}

	} while (flg == 1);
	free(tmp);

	return rnd;
}

int main()
{
	int trial = 0;
	int input;
	int* inputs;
	int i;
	int max, min;

	int mode;
	int ans;
	srand((unsigned long)time(NULL));
	printf("モードを選択してください:\n");
	printf("0: EASY 1: NORMAL, 2: HARD, 3: EXTREME ");
	scanf("%d", &mode);

	switch (mode) {
	case 0:
		min = 1; max = 9;
		break;
	case 1:
		min = 1; max = 99;
		break;
	case 2:
		min = 1; max = 999;
		break;
	case 3:
		do {
			min = (int)rand() % RAND_MAX;
			max = (int)rand() % RAND_MAX;
		} while (min == max);
		
		if (min > max) {
			int tmp = max;
			max = min;
			min = tmp;
		}
		break;
	default:
		printf("バカ\n");
		min = 1; max = 99999;
		break;
	}

	int rand_range = (max-1) - (min-1);
	int max_trial = (int)log2(rand_range);
	ans = make_answer(min, max);

	inputs = (int*)malloc(sizeof(int) * max_trial);

	printf("正解の数は何でしょう? (%d ~ %d の間です)\n", min, max);
	printf("ヒント: 同じ数字は2個以上含まれません\n");

	do {
		printf("%d 回目 (残り%d 回)\n", trial, max_trial-trial);
		printf("あなたの答え: "); scanf("%d", &input);
		int chk = answer_check(input, ans);
		inputs[trial] = input;
		switch (chk) {
		case 0:
			printf("正解!\n");
			print_inputs(inputs, ans, max_trial);
			return 0;
		case -1:
			printf("不正解... (小さいです)\n");
			break;
		case 1:
			printf("不正解... (大きいです)\n");
			break;
		default:
			break;
		}
		trial++;
	} while (trial < max_trial);

	printf("Game Over\n");
	printf("正解: %d\n", ans);
	print_inputs(inputs, ans, max_trial);
	
	return 0;
}
