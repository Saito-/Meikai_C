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

void print_result(int snum, int spos, int keta)
{
	if (spos == keta)
		printf("正解!\n");
	else if (snum == 0) 
		printf("あなたの答えは全く違います\n");
	else {
		printf("あなたの答えは正しい数字を %d 個含んでいます\n", snum);

		if (spos == 0) 
			printf("でも, 場所はあっていません\n");
		else
			printf("そのうち, %d 個は位置も正解しています\n", spos);
	}
	printf("\n");
}

int main()
{
	int trial = 0;
	int chk;
	int hit, blow;
	char buf[128];
	clock_t start, end;
	int limit = 10;

	srand((unsigned)time(NULL));

	int keta;
	int* ans;

	printf("何桁にしますか? (1 ~ 10) を入力してください: ");
	scanf("%d", &keta);
	if (keta < 1 || keta > 10) {
		printf("死ね\n");
		return 1;
	}
	ans = (int*)malloc(sizeof(int) * keta);

	printf("マスターマインドをしましょう\n");
	printf("%d 桁の数字を推測してください\n", keta);
	printf("空白は入れず, %d つの数字を連続させて入力してください\n", keta);

	makedigits(ans, keta);
	//printf("%d%d%d%d%d%d\n", ans[0], ans[1], ans[2], ans[3], ans[4], ans[5]);

	start = clock();

	do {
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
		
		trial++;
		judge(buf, ans, &hit, &blow, keta);
		print_result(hit + blow, hit, keta);
		if (trial%3 ==0) {
			int hint;
			printf("ヒント:\n");
			printf("何桁目が知りたいですか? (1 ~ %d を入力してください): ", keta); 
			scanf("%d", &hint);
			if (hint < 1 || hint > keta) {
				printf("死ね\n");
				return 0;
			}
			printf("%d 桁目は %d です\n", hint, ans[hint-1]);
		}
		if (trial == limit) {
			printf("Game Over\n");
			int i;
			printf("正解: ");
			for (i = 0; i < keta; i++) 
				printf("%d", ans[i]);
			printf("\n");
			break;
		}
	} while (hit < keta);

	end = clock();

	printf("試行回数: %d\n", trial);
	printf("経過時間: %f\n", (double)(end - start)/CLOCKS_PER_SEC);

	return 0;
}

