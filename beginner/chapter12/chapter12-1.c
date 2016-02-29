#include <time.h>
#include <stdio.h>

void put_time()
{
	time_t current;
	struct tm *local;

	time(&current);
	local = localtime(&current);

	int hour = local->tm_hour;
	int min = local->tm_min;
	int sec = local->tm_sec;
	
	printf("%d時%d分%d秒\n", hour, min, sec);
}

int main()
{
	put_time();

	return 0;

}
