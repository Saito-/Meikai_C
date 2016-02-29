#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mday[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int dayofweek(int year, int month, int day)
{
	if (month == 1 || month == 2) {
		year--;
		month += 12;
	}
	return ((year + year/4 - year/100 + year/400 + (13*month+8)/5 + day)%7);
}

int is_leap(int year)
{
	return ((year%4 == 0 && year%100 != 0) || year%400 == 0);
}

int monthdays(int year, int month)
{
	if (month-- != 2) return mday[month];
	return mday[month] + is_leap(year);
}

void make_calendar(int y, int m, char s[7][22])
{
	int i, k;
	int wd = dayofweek(y, m, 1);
	int mdays = monthdays(y, m);
	char tmp[4];

	sprintf(s[0], "%10d / %02d      ", y, m);

	for (k = 1; k < 7; k++) 
		s[k][0] = '\0';

	k = 1;
	sprintf(s[k], "%*s", 3*wd, "");

	for (i = 1; i <= mdays; i++) {
		sprintf(tmp, "%3d", i);
		strcat(s[k], tmp);
		if (++wd % 7 == 0) {
			if (s[k]) {
				k++;
			}
		}
	}

	while (++k < 7) 
		sprintf(s[k], "%21s", "");
}	

void print(char sbuf[3][7][22], int n)
{
	int i, j;

	for (i = 0; i < n; i++) {
		if (i == n-1)
			printf("%21s", sbuf[i][0]);
		else
			printf("%21s   ", sbuf[i][0]);
	}

	putchar('\n');

	for (i = 0; i < n; i++) {
		if (i == n-1) 
			printf(" 日 月 火 水 木 金 土");
		else
			printf(" 日 月 火 水 木 金 土   ");
	}
	putchar('\n');
	
	for (i = 0; i < n; i++) {
		if (i == n-1) 
			printf("----------------------");
		else
			printf("----------------------  ");
	}
	putchar('\n');

	char tmp[22];
	sprintf(tmp, "%21s", "");

	for (i = 1; i < 7; i++) {
		for (j = 0; j < n; j++) { 
			if (j == n-1) 
				printf("%-21s", sbuf[j][i]);
			else
				printf("%-21s   ", sbuf[j][i]);
		}	
		if (i == 5) {
			if (strcmp(sbuf[0][6], "") +
			    strcmp(sbuf[1][6], tmp) +
			    strcmp(sbuf[2][6], tmp) == 0)
				i += 2;
			
		}
		putchar('\n');
	}

	putchar('\n');
}

void put_calendar(int y1, int m1, int y2, int m2)
{
	int y = y1;
	int m = m1;
	int n = 0;
	char sbuf[3][7][22];

	while (y <= y2) {
		if (y == y2 && m > m2) break;
		make_calendar(y, m, sbuf[n++]);
		if (n == 3) {
			print(sbuf, n);
			n = 0;
		}
		m++;
		if (m == 13 && y < y2) {
			y++;
			m = 1;
		}
	}
	if (n)
		print(sbuf, n);
}

int chk_err(int y, int m)
{
	if (y < 0) {
		printf("そんな年ねーよ\n");
		return 1;
	}

	if (m < 1 || m > 12) {
		printf("そんな月ねーよ\n");
		return 2;
	}
	return 0;
}

int main()
{
	int y1, m1, y2, m2;
	int flg = 1;
	printf("カレンダーを表示します\n");

	do {
		printf("開始年月\n");
		printf("年: "); scanf("%d", &y1);
		printf("月: "); scanf("%d", &m1);
		flg = chk_err(y1, m1);
	} while (flg != 0);

	do {
		printf("終了年月\n");
		printf("年: "); scanf("%d", &y2);
		printf("月: "); scanf("%d", &m2);
		flg = chk_err(y2, m2);
		if (y2 < y1 || (y2 == y1 && m2 < m1)) {
			printf("終了年月がおかしい\n");
			flg = 3;
		}
	} while (flg != 0);

	put_calendar(y1, m1, y2, m2);
	return 0;
}
