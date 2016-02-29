#include <stdio.h>

int main()
{
	int sdata = -1;
	unsigned udata = 1;

	printf("sdata < udata すなわち -1 < 1U は");
	if (sdata < udata)
		puts("真");
	else
		puts("偽");

	printf("(unsigned)sdata < udata すなわち (unsigned)-1 < 1U は");
	if ((unsigned)sdata < udata)
		puts("真");
	else
		puts("偽");

}
