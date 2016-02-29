#include <stdio.h>

int str_chnum(char str[], int c)
{
	int i = 0;
	int count = 0;
	while (str[i] != '\0') {
		if (str[i] == c) count++;
		i++;
	}
	return count;
}

int main()
{
	char str[] = "ABCDEFCC";
	char ch = 'C';
	int no = str_chnum(str, ch);

	printf("Char %c appears in string str %s %d times\n", ch, str, no);

	return 0;
}
