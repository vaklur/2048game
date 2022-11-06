#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "2048statistics.h"
#include "2048draw.h"

// Statistics records
statisticsRecord statistics[10];

// Read statistics records from text file
void readStatisticsFile() {
	FILE* fp;
	fp = fopen("statistics.txt", "r");
	if (fp)
	{
		char str[60];
		int line = 0;
		while (fgets(str, 60, fp) != NULL) {
			char* ptr = strtok(str, ";");
			int position = 0;
			while (ptr != NULL) {
				if (position == 0) {
					strcpy_s(statistics[line].nickname, ptr);
				}
				if (position == 1) {
					int score = atoi(ptr);
					statistics[line].score = score;
				}
				ptr = strtok(NULL, ";");
				position++;
			}
			line++;
		}
		fclose(fp);
	}
}

// Read and print statistics records
void readStatistics() {
	readStatisticsFile();
	do {	
		drawStatistics(statistics);
		char key = getch();
		if (key == 'q') break;
	} while (1);
}

// Write statistics record to file
void writeFileStatistics(statisticsRecord statistics[10]) {
	FILE* fp;
	fp = fopen("statistics.txt", "w");
	if (fp)
	{
		for (int i = 0; i < 10; i++) {
			fprintf(fp, "%s;%i\n", statistics[i].nickname, statistics[i].score);
		}
	}
	fclose(fp);
}

// Write statistic record to statistics
void writeToStatistics(statisticsRecord record) {
	readStatisticsFile();
	for (int i = 0; i < 10; i++) {
		if (statistics[i].score < record.score) {
			statisticsRecord help1{ "",statistics[i].score };
			strcpy_s(help1.nickname, statistics[i].nickname);

			statistics[i].score = record.score;
			strcpy_s(statistics[i].nickname, record.nickname);

			for (int j = (i + 1); j < 10; j++) {
				statisticsRecord help2{ "",statistics[j].score };
				strcpy_s(help2.nickname, statistics[j].nickname);

				statistics[j].score = help1.score;
				strcpy_s(statistics[j].nickname, help1.nickname);

				help1.score = help2.score;
				strcpy_s(help1.nickname, help2.nickname);
			}
			break;
		}
	}
	writeFileStatistics(statistics);
}

