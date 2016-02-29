#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CNO 4

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

char* months[] = { "January", "February", "March", "April",
		     "May", "June", "July", "August",
		     "September", "October", "November", "December" };

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
	int num[12] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	int i;
	int count;
	int sw;
	int chk;
	int miss[12] = { 0 };
	char input[128];

	srand(time(NULL));

	for (i = 11; i > 0; i--) {
		int idx = rand() % 12;
		swap(int, num[i], num[idx]);
	}

	printf("月名の英語を入力してね (大文字・小文字どっちでもOK)\n");
	for (i = 0; i < 12; i++) {
		count = 0;
		do {
			printf("%d 月: ", num[i] + 1);
			scanf("%s", input);
			chk = strncmpx(input, months[num[i]], strlen(input));
			if (chk != 0) {
				miss[num[i]] = 1;
				count++;
				if (count < 5) {
					printf("ちがうよ. 正解を見る? 0-yes/1-no: ");
					scanf("%d", &sw);
					if (sw == 0) 
						printf("%d 月は %s です\n", num[i] + 1, months[num[i]]);
				}
			}
			if (count == 5)
				printf("%d 月は %s です\n", num[i] + 1, months[num[i]]);
		} while (chk != 0 && count < 5);
		printf("正解\n");
	}

	int miss_total = 0;
	for (i = 0; i < 12; i++) {
		miss_total += miss[i];
	}
	printf("12個のうち %d 個が正解でした\n", 12-miss_total);
	printf("正解した月: ");
	for (i = 0; i < 12; i++) {
		if (miss[i] == 0) 
			printf("%d 月, ", i+1);
	}
	printf("\n間違った月: ");
	for (i = 0; i < 12; i++) {
		if (miss[i] != 0) 
			printf("%d 月, ", i+1);
	}
	putchar('\n');
	return 0;
}
