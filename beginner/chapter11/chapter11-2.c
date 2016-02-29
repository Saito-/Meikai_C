#include <stdio.h>
#include <string.h>

char* str_char(const char* str, int c)
{
	while (*str) {
		if (*str == c) return (char*)str;
		str++;
	}
	return NULL;
}

int main()
{
	char* str = "ABCD";
	char ch = 'C';
	char* r = str_char(str, ch);
	printf("%c is in %s at %p\n", ch, str, r);

	return 0;
}
