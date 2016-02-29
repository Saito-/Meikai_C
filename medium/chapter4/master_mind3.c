#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

void makedigits(int* x, int keta)
{
	int i, j;
	int tmp[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int ptn = 10;

	for (i = 0; i < keta; i++) {
		int idx = rand() % ptn;
		x[i] = tmp[idx];
	}
}

void sleep(unsigned long t)
{
	clock_t c1, c2;
	c1 = clock();

	do {
		if ((c2 = clock()) == (clock_t)-1) return;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < t);
	return;
}

void swap(int* a, int* b)
{
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

void makehints(int* hints, int keta)
{
	int i, j;
	int ptn = keta;

	for (i = 0; i < keta; i++) 
		hints[i] = i;

	for (i = 0; i < keta; i++) {
		int idx = rand() % keta;
		swap(hints+i, hints+idx);
	}
}

int check(const char* str, int keta)
{
	int i, j;
	if (strlen(str) != keta) return 1;

	for (i = 0; i < keta; i++) {
		if (!isdigit(str[i])) return 2;
	}
	return 0;
}

void judge(const char* str, const int* x, int* hit, int* blow, int keta)
{
	int i, j, k;
	int mul_x[10] = { 0 };
	int mul_str[10] = { 0 };

	for (i = 0; i < keta; i++) {
		mul_x[x[i]]++;
		mul_str[str[i]-'0']++;
	}

	/*
	for (i = 0; i < 10; i++) {
		printf("mul_str[%d] = %d, ", i, mul_str[i]);
		printf("mul_x[%d] = %d\n", i, mul_x[i]);
	}
	*/
	*hit = *blow = 0;

	for (i = 0; i < 10; i++) {
		if (mul_x[i] != 0 && mul_str[i] != 0) {
			if (mul_str[i] <= mul_x[i])
				(*blow)+=mul_str[i];
			else 
				(*blow)+=mul_x[i];
		}
	}

	if (*blow == 0) 
		return;
	for (i = 0; i < 10; i++) {
		if (mul_x[i] != 0 && mul_str[i] != 0) {
			for (j = 0; j < keta; j++) {
				if (((str[j] - '0') == i) && (x[j] == i)) {
					(*hit)++;
					(*blow)--;
				}
			}
		}
	}
}

void judge_ai(const int* str, const int* x, int* hit, int* blow, int keta)
{
	int i, j, k;
	int mul_x[10] = { 0 };
	int mul_str[10] = { 0 };

	for (i = 0; i < keta; i++) {
		mul_x[x[i]]++;
		mul_str[str[i]]++;
	}

	/*
	for (i = 0; i < 10; i++) {
		printf("mul_str[%d] = %d, ", i, mul_str[i]);
		printf("mul_x[%d] = %d\n", i, mul_x[i]);
	}
	*/
	*hit = *blow = 0;

	for (i = 0; i < 10; i++) {
		if (mul_x[i] != 0 && mul_str[i] != 0) {
			if (mul_str[i] <= mul_x[i])
				(*blow)+=mul_str[i];
			else 
				(*blow)+=mul_x[i];
		}
	}

	if (*blow == 0) 
		return;
	for (i = 0; i < 10; i++) {
		if (mul_x[i] != 0 && mul_str[i] != 0) {
			for (j = 0; j < keta; j++) {
				if ((str[j] == i) && (x[j] == i)) {
					(*hit)++;
					(*blow)--;
				}
			}
		}
	}
}


void print_ans(int* ans, int keta)
{
	int i;
	for (i = 0; i < keta; i++) 
		printf("%d", ans[i]);
	printf("\n");
}

void print_result(int snum, int spos, int keta)
{
	if (spos == keta)
		printf("正解!\n");
	else if (snum == 0) 
		printf("全く違います\n");
	else {
		printf("正しい数字を %d 個含んでいます\n", snum);

		if (spos == 0) 
			printf("でも, 場所はあっていません\n");
		else
			printf("そのうち, %d 個は位置も正解しています\n", spos);
	}
	printf("\n");
}

void cpu_ai(int* memory, int keta)
{
	int i;
	for (i = 0; i < keta; i++) {
		if (memory[i] == 0) 
			memory[i] = rand() % 10;
	}
}

int main()
{
	int trial = 0;
	int chk;
	int hit, blow;
	char buf[128];

	int keta;
	int* ans_p;
	int* ans_c;
	int hint;
	int* hints;
	int* memory;
	int i;

	srand((unsigned)time(NULL));
	
	printf("何桁にしますか? (1 ~ 10) を入力してください: ");
	scanf("%d", &keta);
	if (keta < 1 || keta > 10) {
		printf("死ね\n");
		return 1;
	}
	ans_p = (int*)malloc(sizeof(int) * keta);
	ans_c = (int*)malloc(sizeof(int) * keta);
	hints = (int*)malloc(sizeof(int) * keta);
	memory = (int*)calloc(keta, sizeof(int));
	
	printf("マスターマインドをしましょう\n");
	printf("%d 桁の数字を推測してください\n", keta);
	printf("空白は入れず, %d つの数字を連続させて入力してください\n", keta);

	makedigits(ans_p, keta);
	makedigits(ans_c, keta);
	makehints(hints, keta);

	do {
		printf("--------------------\n");
		printf("あなたの番です\n");
		printf("あなたの数列: "); print_ans(ans_p, keta);
		printf("CPUからのヒント:\n ");
		printf("何桁目を知りたいですか? (1 ~ %d を入力してください): ", keta);
		scanf("%d", &hint);
		if (hint < 1 || hint > keta) {
			printf("死ね\n");
			return 1;
		}
		printf("%d 桁目は %d です\n", hint, ans_c[hint-1]);
		do {
			printf("あなたの答え: ");
			scanf("%s", buf);

			chk = check(buf, keta);

			switch (chk) {
			case 1:
				printf("文字数がおかしいです\n");
				break;
			case 2:
				printf("数字以外は入力しないでください\n");
				break;
			}

		} while (chk != 0);
		
		judge(buf, ans_c, &hit, &blow, keta);
		print_result(hit + blow, hit, keta);
		if (hit == keta) {
			printf("あなたの勝ちです\n");
			break;
		}

		printf("--------------------\n");
		printf("CPUの番です\n");
		printf("プレイヤーからのヒント:\n");
		printf("%d 桁目は %d です\n", hints[trial]+1, ans_p[hints[trial]]);
		memory[hints[trial]] = ans_p[hints[trial]];
		cpu_ai(memory, keta);
		sleep(1000);
		printf("CPUの解答: ");
		print_ans(memory, keta);
		judge_ai(memory, ans_p, &hit, &blow, keta);
		print_result(hit+blow, hit, keta);
		if (hit == keta) {
			printf("コンピュータの勝ちです\n");
			break;
		}
		trial++;
	} while (hit < keta);

	free(ans_p); free(ans_c); free(memory); free(hints);
	return 0;
}

