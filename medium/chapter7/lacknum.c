#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STAGE 10
#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

int main()
{
	int i, j, stage;
	int dgt[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a[8];
	double t;
	time_t start, end;

	srand(time(NULL));

	printf("欠けている数字を入力してください\n");

	start = time(NULL);
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;
		int no;

		i = j = 0;
		while (i < 9) {
			if (i != x) 
				a[j++] = dgt[i];
			i++;
		}

		for (i = 7; i > 0; i--) {
			int idx = rand() % (i + 1);
			if (i != idx)
				swap(int, a[i], a[idx]);
		}

		for (i = 0; i < 8; i++) {
			printf("%d ", a[i]);
		}
		printf(": ");

		do {
			scanf("%d", &no);
		} while (no != dgt[x]);
	}

	end = time(NULL);

	t = difftime(end, start);

	printf("%.f 秒かかりました\n", t);

	if (t > 25.0)
		printf("おそい\n");
	else if (t > 20.0)
		printf("すこしおそい\n");
	else if (t > 17.0)
		printf("ふつう\n");
	else
		printf("はやい\n");

	return 0;
}
