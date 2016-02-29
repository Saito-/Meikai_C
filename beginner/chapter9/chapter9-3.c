#include <stdio.h>

int str_char(char str[], int c)
{
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] == c) return i;
		i++;
	}
	return -1;
}

int main()
{
	char str[] = "ABCDEF";
	char ch = 'C';
	int no = str_char(str, ch);

	printf("Char %c is in string str %s at %d\n", ch, str, no);

	return 0;
}
