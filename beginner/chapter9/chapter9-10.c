#include <stdio.h>

void del_digit(char str[])
{
	int i, j;
	int length = 0;
	for (i = 0; str[i] != '\0'; i++) length++;
	
	for (i = 0; i < length+1; i++) {
		if (str[i] >= '1' && str[i] <= '9') {
			for (j = i; j < length+1; j++) {
				str[j] = str[j+1];
			}
			length--;
		}
	}
}

int main()
{
	char str[] = "AB1C9";
	printf("%s\n", str);
	del_digit(str);
	printf("%s\n", str);

	return 0;
}
