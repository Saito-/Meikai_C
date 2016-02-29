#include <time.h>
#include <stdio.h>

int dayofweek(int year, int month, int day)
{
	if (month == 1 || month == 2) {
		year--;
		month += 12;
	}
	return ((year + year/4 - year/100 + year/400 + (13*month+8)/5 + day)%7);
}

int main()
{
	int y, m, d, w;
	char *ws[] = { "日", "月", "火", "水", "木", "金", "土" };

	printf("曜日を求めます\n");
	printf("年: "); scanf("%d", &y);
	printf("月: "); scanf("%d", &m);
	printf("日: "); scanf("%d", &d);

	w = dayofweek(y, m, d);

	if (w != -1)
		printf("%s曜日です\n", ws[w]);
	else
		printf("エラーです\n");
	return 0;
}
