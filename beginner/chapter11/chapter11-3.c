#include <stdio.h>
#include <string.h>

int str_chnum(const char* str, int c)
{
	int count = 0;
	while (*str) {
		if (*str++ == c) count++;
	}
	return count;
}

int main()
{
	char* str = "ABCDCCC";
	char ch = 'C';
	int count = str_chnum(str, ch);
	printf("%c is in %s %d times\n", ch, str, count);

	return 0;
}
