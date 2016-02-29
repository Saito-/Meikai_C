#include <stdio.h>
#include <time.h>

char data_file[] = "datetime.bin";

void get_data()
{
	FILE* fp;
	if ((fp = fopen(data_file, "rb")) == NULL) {
		printf("First time\n");
	} else { 
		struct tm* local;
		fread(local, sizeof(struct tm), 1, fp);
		printf("%d %d %d %d %d %d\n",
			local->tm_year + 1900, local->tm_mon+1, local->tm_mday,
			local->tm_hour, local->tm_min, local->tm_sec);
		fclose(fp);
	}
}

void put_data()
{
	FILE* fp;
	time_t t;
	struct tm* local;

	if ((fp = fopen(data_file, "wb")) == NULL) {
		printf("Cannot open file\n");
		return;
	}
	
	time(&t);
	local = localtime(&t);
	fwrite(local, sizeof(struct tm), 1, fp);

	fclose(fp);
}

int main()
{
	put_data();
	get_data();
	return 0;
}
