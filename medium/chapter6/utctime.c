#include <time.h>
#include <stdio.h>

void put_date(struct tm* timer)
{
	char* wday_name[] = { "日", "月", "火", "水", "木", "金", "土" };
	
	printf("%4d年%02d月%02d日(%s) %02d時%02d分%02d秒",
		timer->tm_year + 1900,
		timer->tm_mon + 1,
		timer->tm_mday,
		wday_name[timer->tm_wday],
		timer->tm_hour,
		timer->tm_min,
		timer->tm_sec	
	);
}	

int main()
{
	time_t t;
	struct tm* timer;

	time(&t);
	timer = gmtime(&t);

	printf("現在の日付, 時刻(UTC)は");
	put_date(timer);
	printf("です\n");

	return 0;
}

