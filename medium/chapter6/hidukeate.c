#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_YEAR 10000

int mday[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int dayofweek(int year, int month, int day)
{
	if (month == 1 || month == 2) {
		year--;
		month += 12;
	}
	return ((year + year/4 - year/100 + year/400 + (13*month+8)/5 + day)%7);
}

int is_leap(int year)
{
	return ((year%4 == 0 && year%100 != 0) || year%400 == 0);
}

int monthdays(int year, int month)
{
	if (month-- != 2) return mday[month];
	return mday[month] + is_leap(year);
}

void make_answer(int* ans) 
{
	int y, m, d;
	y = 1 + rand() % MAX_YEAR;
	m = 1 + rand() % 12;
	d = monthdays(y, m);
	ans[0] = y;
	ans[1] = m;
	ans[2] = d;
}

void print_answer(int* ans)
{
	printf("%5d 年 %2d 月 %2d 日\n", ans[0], ans[1], ans[2]);
}

int chk_answer(int* ans, int* input)
{
	int ret = 0;
	if (ans[0] != input[0]) {
		if (ans[0] > input[0]) 
			printf("年が小さいです\n");
		else
			printf("年が大きいです\n");
		ret++;
	}
	if (ans[1] != input[1]) {
		if (ans[1] > input[1]) 
			printf("月が小さいです\n");
		else
			printf("月が大きいです\n");
		ret++;
	}
	if (ans[2] != input[2]) {
		if (ans[2] > input[2]) 
			printf("日が小さいです\n");
		else
			printf("日が大きいです\n");
		ret++;
	}
	return ret;
}

int main(int argc, char* argv[])
{
	int y1, m1, y2, m2;
	int ans[3];
	int input[3];
	int* records;
	int max_trial;
	int i, j;

	srand(time(NULL));
	make_answer(ans);

	max_trial = (int)(log2(ans[0]) + log2(ans[1]) + log2(ans[2]));
	records = (int*)malloc(sizeof(int)*3*max_trial);

	printf("日付あてゲーム\n");
	printf("正解の年/月/日を推測してください\n");
	printf("年は 1 ~ %d の間です\n", MAX_YEAR);

	printf("答え: %5d 年 %2d 月 %2d 日\n", ans[0], ans[1], ans[2]);
	for (i = 0; i < max_trial; i++) {
		printf("%d 回目 (残り %d 回)\n", i+1, max_trial-i);
		while (1) {
			printf("年: "); 
			scanf("%d", input);
			if (input[0] < 1 || input[0] > MAX_YEAR) 
				printf("そんな年ねーよ\n");
			else
				break;
		}

		while (1) {
			printf("月: "); 
			scanf("%d", input+1);
			if (input[1] < 1 || input[1] > 12) 
				printf("そんな月ねーよ\n");
			else
				break;
		}

		while (1) {
			printf("日: "); 
			scanf("%d", input+2);
			if (input[2] < 1 || input[2] > monthdays(input[0], input[1])) 
				printf("そんな日ねーよ\n");
			else
				break;
		}

		records[i] = input[0];
		records[i+1] = input[1];
		records[i+2] = input[2];

		int chk = chk_answer(ans, input);
		if (chk == 0) {
			printf("正解!\n");
			break;
		}
		printf("不正解...\n");
	}

	printf("入力の履歴:\n");
	for (j = 0; j <= i; j++) {
		printf("%d 回目\n", j+1);
		printf("%5d 年 %2d 月 %2d 日\n", records[j], records[j+1], records[j+2]);
		printf("正解との差\n");
		printf("%5d, %2d, %2d\n", ans[0]-records[j], ans[1]-records[1], ans[2]-records[2]);
	}

	free(records);
	return 0;
}
