#include <stdio.h>

int main()
{
	int sdata = -1;
	unsigned int udata = 1;

	printf("sdata < udata すなわち -1 < 1U は");
	if (sdata < udata)
		puts("真");
	else
		puts("偽");

	printf("sdata < (int)udata すなわち -1 < (int)1U は");
	if (sdata < (int)udata)
		puts("真");
	else
		puts("偽");

}
