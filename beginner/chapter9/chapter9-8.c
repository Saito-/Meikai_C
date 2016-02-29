#include <stdio.h>

void rev_string(char str[])
{
	int i = 0;
	int length = 0;
	for (i = 0; str[i] != '\0'; i++) length++;
	
	for (i = 0; i < (length/2); i++) {
		char temp = str[length-i-1];
		str[length-i-1] = str[i];
		str[i] = temp;
	}
	str[length] = '\0';
}

int main()
{
	char str[] = "ABC";
	printf("%s\n", str);
	rev_string(str);
	printf("%s\n", str);

	return 0;
}
