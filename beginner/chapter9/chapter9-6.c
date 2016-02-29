#include <stdio.h>

void put_stringn(char str[], int n)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; str[j] != '\0'; j++) {
			putchar(str[j]);
		}
	}
	printf("\n");
}

int main()
{
	char str[] = "ABC";
	int n = 5;
	printf("%s\n", str);
	put_stringn(str, n);

	return 0;
}
