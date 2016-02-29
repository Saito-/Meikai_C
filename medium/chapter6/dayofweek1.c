#include <time.h>
#include <stdio.h>

int dayofweek(int year, int month, int day)
{
	struct tm t;
	t.tm_year = year - 1900;
	t.tm_mon = month - 1;
	t.tm_mday = day;
	t.tm_hour = 0;
	t.tm_min = 0;
	t.tm_sec = 0;
	t.tm_isdst = -1;

	if (mktime(&t) == (time_t)-1) return -1;
	return t.tm_wday;
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
