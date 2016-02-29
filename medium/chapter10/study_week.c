#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CNO 4

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

int strncmpx(const char* s1, const char* s2, size_t n)
{
	while (n && toupper(*s1) && toupper(*s2)) {
		if (toupper(*s1) != toupper(*s2)) 
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++; s2++; n--;
	}
	if (!n) return 0;
	if (*s1) return 1;
	return -1;
}

int main(int argc, char* argv[])
{
	int num[7] = { 0, 1, 2, 3, 4, 5, 6 };
	char* jweeks[] = { "日", "月", "火", "水", "木", "金", "土" };
	char* eweeks[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	int i;
	int count;
	int sw;
	int chk;
	int miss[7] = { 0 };
	char input[128];

	srand(time(NULL));

	for (i = 6; i > 0; i--) {
		int idx = rand() % 7;
		swap(int, num[i], num[idx]);
	}

	printf("曜日名の英語を入力してね (大文字・小文字どっちでもOK)\n");
	for (i = 0; i < 7; i++) {
		count = 0;
		do {
			printf("%s 曜日: ", jweeks[num[i]]);
			scanf("%s", input);
			chk = strncmpx(input, eweeks[num[i]], strlen(input));
			if (chk != 0) {
				miss[num[i]] = 1;
				count++;
				if (count < 5) {
					printf("ちがうよ. 正解を見る? 0-yes/1-no: ");
					scanf("%d", &sw);
					if (sw == 0) 
						printf("%s 曜日は %s です\n", jweeks[num[i]], eweeks[num[i]]);
				}
			}
			if (count == 5)
				printf("%s 曜日は %s です\n", jweeks[num[i]], eweeks[num[i]]);
		} while (chk != 0 && count < 5);
		printf("正解\n");
	}

	int miss_total = 0;
	for (i = 0; i < 7; i++) {
		miss_total += miss[i];
	}
	printf("7 個のうち %d 個が正解でした\n", 7-miss_total);
	printf("正解した曜日: ");
	for (i = 0; i < 7; i++) {
		if (miss[i] == 0) 
			printf("%s 曜日, ", jweeks[i]);
	}
	printf("\n間違った曜日: ");
	for (i = 0; i < 7; i++) {
		if (miss[i] != 0) 
			printf("%s 曜日, ", jweeks[i]);
	}
	putchar('\n');
	return 0;
}
