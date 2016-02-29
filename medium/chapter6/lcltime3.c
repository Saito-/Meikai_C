#include <time.h>
#include <stdio.h>

int main()
{
	time_t t = time(NULL);
	printf("現在の日付・時刻: %s", ctime(&t));
	return 0;
}
