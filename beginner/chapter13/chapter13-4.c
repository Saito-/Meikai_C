#include <stdio.h>
#include <time.h>

char data_file[] = "datetime.dat";

void get_data()
{
	FILE* fp;
	if ((fp = fopen(data_file, "r")) == NULL) {
		printf("First time\n");
	} else { 
		int year, month, day, hour, min, sec;
		char mood[100];

		fscanf(fp, "%d%d%d%d%d%d%s", &year, &month, &day, &hour, &min, &sec, mood);
		printf("Last time: %d/%d/%d/%d/%d/%d, mood: %s\n", year, month, day, hour, min, sec, mood);
		
		fclose(fp);
	}
}

void put_data()
{
	FILE* fp;
	time_t t;
	struct tm* local;

	if ((fp = fopen(data_file, "w")) == NULL) {
		printf("Cannot open file\n");
		return;
	}
	
	time(&t);
	local = localtime(&t);

	char mood[100];
	printf("Your mode: "); scanf("%s", mood);
	
	fprintf(fp, "%d %d %d %d %d %d %s\n",
		local->tm_year + 1900, local->tm_mon + 1, local->tm_mday,
		local->tm_hour, local->tm_min, local->tm_sec, mood);
	printf("Wrote file\n");
	fclose(fp);
}

int main()
{
	get_data();
	put_data();
	return 0;
}
