#include <stdio.h>
#include <string.h>

void put_string(const char* str)
{
	while (*str) {
		putchar(*str);
		str++;
	}
}

int main()
{
	char* str = "ABCD";

	put_string(str);

	return 0;
}
