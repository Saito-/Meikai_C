#include <stdio.h>
#include <limits.h>

int main()
{
	int x;
	signed char ch = CHAR_MAX;

	printf("ch: %d\n", ch);

	x = ch + 1;

	printf("x = ch + 1\n");
	printf("x: %d\n", x);

	x = ++ch;

	printf("x = ++ch\n");
	printf("x: %d\n", x);
	
	return 0;
}
