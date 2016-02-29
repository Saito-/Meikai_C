#include <stdio.h>

void put_rstring(char str[])
{
	int i = 0;
	int length = 0;
	for (i = 0; str[i] != '\0'; i++) length++;
	
	for (i = 0; i < length+1; i++) {
		putchar(str[length-i]);
	}
	printf("\n");
}

int main()
{
	char str[] = "ABC";
	int n = 5;
	printf("%s\n", str);
	put_rstring(str);

	return 0;
}
