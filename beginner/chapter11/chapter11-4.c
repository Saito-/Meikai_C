#include <stdio.h>
#include <ctype.h>
#include <string.h>

void str_toupper(char* str)
{
	while (*str = toupper(*str)) {
		str++;
	}
}

void str_tolower(char* str)
{
	while (*str = tolower(*str)) {
		str++;
	}
}

int main()
{
	char str[100];
	scanf("%s", str);
	printf("%s\n", str);
	str_toupper(str);
	printf("%s\n", str);
	str_tolower(str);
	printf("%s\n", str);

	return 0;
}
