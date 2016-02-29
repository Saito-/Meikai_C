#include <stdio.h>
#include <ctype.h>
#include <string.h>

int strtoi(const char* str)
{
	int i = 0;
	while (*str) {
		if (*str >= '0' && *str <= '9') {
			i *= 10;
			i += (*str - '0');
		}
		str++;
	}
	return i;
}

long strtol(const char* str)
{
	long i = 0;
	while (*str) {
		if (*str >= '0' && *str <= '9') {
			i *= 10;
			i += (*str - '0');
		}
		str++;
	}
	return i;
}

double strtof(const char* str)
{
	double num_int = 0.0;
	double num_dec = 0.0;

	char* str_int = strtok(str, ".");
	printf("%s\n", str_int);
	while (*str_int) {
		if (*str_int >= '0' && *str_int <= '9') {
			num_int *= 10.0;
			num_int += (*str_int - '0');
		}
		str_int++;
	}

	char* str_dec = strtok(NULL, ".");
	int keta = 1;
	printf("%s\n", str_dec);
	while (*str_dec) {
		if (*str_dec >= '0' && *str_dec <= '9') {
			num_dec += (*str_dec - '0') / (10.0 * (double)keta);
		}
		str_dec++;
		keta++;
	}

	return num_int + num_dec;
}


int main()
{
	char str[100] = "20.2";
	printf("%d\n", strtoi(str));
	printf("%ld\n", strtol(str));
	printf("%f\n", strtof(str));

	return 0;
}
