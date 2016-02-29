#include <stdio.h>
#include <ctype.h>
#include <string.h>

void del_digit(char* str)
{
	while (*str) {
		printf("str: %p\n", str);
		if (*str >= '1' && *str <= '9') {
			char* ptr = str;
			printf("ptr: %p\n", ptr);
			while (*str) {
				*str = *(str+1);
				str++;
			}
			str = ptr;
		}
		str++;
	}
}

int main()
{
	char str[100] = "AB1C9";
	printf("%s\n", str);
	del_digit(str);
	printf("%s\n", str);

	return 0;
}
