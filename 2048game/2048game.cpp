#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_SECURE_NO_WARNINGS

#include "structures.h"
#include "2048game.h"
#include "2048draw.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>

// Global variables
statisticsRecord statistics[10];

int gameField[4][4];
int score;
char nickname[10];
bool gameEnd= true;

int game(bool newGame) {
	int gameOver = 0;
	// Initialize game field with zeros
	if (gameEnd == true && newGame == false) return 0;
	if (gameEnd == true || newGame == true) {
		strcpy(nickname, getNickName());
		score = 0;
		
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				gameField[i][j] = 0;
			}
		}
		gameField[0][0] = 2;
	}
	drawGameField(gameField,score,nickname);
	do {
		unsigned char key = 'm';
		
		key = getch();
		if (key == 0xE0) key = getch();
		// UP
		if (key == 'w' || key == 72)	gameOver = playerMove(1);
		// DOWN
		if (key == 's' || key == 80)	gameOver = playerMove(2);
		// LEFT
		if (key == 'a' || key == 75)	gameOver = playerMove(3);
		// RIGHT
		if (key == 'd' || key == 77) gameOver = playerMove(4);
		// RESTART
		if (key == 'r') game(true);
		// EXIT
		if (key == 'q') {
			gameEnd = false;
			break;
		}
		// GAME OVER
		if (gameOver == 1) {
			drawEndScore(nickname,score);
			statisticsRecord record;
			record.score = score;
			strcpy(record.nickname, nickname);
			writeToStatistics(record);
			writeFileStatistics();
			delay(5000);
			break;
			}
	}
	while (gameOver!=1);

	return 0;
}

int playerMove(int move) {
	/*
	1 - up
	2 - down
	3 - left
	4 - right
	*/
	int countMove = 0;
	if (move == 1) {
		// MOVE NUMBERS
		for (int j = 0; j < 4; j++) { // collums
			for (int i = 3; i > 0; i--) { // rows

				for (int k = 0; k < i; k++) {
					if (gameField[i - k][j] > 0 && gameField[i - k - 1][j] == 0) {
						gameField[i - 1 - k][j] = gameField[i - k][j];
						gameField[i - k][j] = 0;
						countMove++;
					}
				}
			}
		}

		// COUNT NUMBERS
		for (int j = 0; j < 4; j++) { // collums
			for (int i = 0; i < 3; i++) { // rows
				if (gameField[i][j] == gameField[i + 1][j]) {
					gameField[i][j] = gameField[i][j] + gameField[i + 1][j];
					score = score + gameField[i][j];
					gameField[i + 1][j] = 0;
					if(gameField[i][j]>0) countMove++;
				}
			}
		}

		// MOVE NUMBERS
		for (int j = 0; j < 4; j++) { // collums
			for (int i = 3; i > 0; i--) { // rows

				for (int k = 0; k < i; k++) {
					if (gameField[i - k][j] > 0 && gameField[i - k - 1][j] == 0) {
						gameField[i - 1 - k][j] = gameField[i - k][j];
						gameField[i - k][j] = 0;
					}
				}
			}
		}
	}
	else if (move == 2){
		// MOVE NUMBERS
		for (int j = 0; j < 4; j++) { // collums
			for (int i = 0; i < 3; i++) { // rows

				for (int k = 0; k < (3-i); k++) {
					if (gameField[i + k][j] > 0 && gameField[i + k + 1][j] == 0) {
						gameField[i + 1 + k][j] = gameField[i + k][j];
						gameField[i + k][j] = 0;
						countMove++;
					}
				}
			}
		}
		
		// COUNT NUMBERS
		for (int j = 0; j < 4; j++) { // collums
			for (int i = 0; i < 4; i++) { // rows
				if (gameField[i][j] == gameField[i + 1][j]) {
					gameField[i+1][j] = gameField[i][j] + gameField[i + 1][j];
					score = score + gameField[i+1][j];
					gameField[i ][j] = 0;
					if (gameField[i+1][j] > 0) countMove++;
				}
			}
		}

		// MOVE NUMBERS
		for (int j = 0; j < 4; j++) { // collums
			for (int i = 0; i < 3; i++) { // rows

				for (int k = 0; k < (3 - i); k++) {
					if (gameField[i + k][j] > 0 && gameField[i + k + 1][j] == 0) {
						gameField[i + 1 + k][j] = gameField[i + k][j];
						gameField[i + k][j] = 0;
					}
				}
			}
		}
	}
	else if (move == 3) {
		for (int j = 0; j < 4; j++) { // collums
			for (int i = 3; i > 0; i--) { // rows

				for (int k = 0; k < i; k++) {
					if (gameField[j] [i - k]> 0 && gameField[j][i - k - 1] == 0) {
						gameField[j][i - 1 - k] = gameField[j][i - k];
						gameField[j][i - k] = 0;
						countMove++;
					}
				}
			}
		}

		// COUNT NUMBERS
		for (int j = 0; j < 4; j++) { // collums
			for (int i = 0; i < 3; i++) { // rows
				if (gameField[j][i] == gameField[j][i + 1]) {
					gameField[j][i] = gameField[j][i] + gameField[j][i + 1];
					score = score + gameField[j][i];
					gameField[j][i + 1] = 0;
					if (gameField[j][i] > 0) countMove++;
				}
			}
		}

		// MOVE NUMBERS
		for (int j = 0; j < 4; j++) { // collums
			for (int i = 3; i > 0; i--) { // rows

				for (int k = 0; k < i; k++) {
					if (gameField[j][i - k] > 0 && gameField[j][i - k - 1] == 0) {
						gameField[j][i - 1 - k] = gameField[j][i - k];
						gameField[j][i - k] = 0;
					}
				}
			}
		}
	}
	else if (move == 4) {
	// MOVE NUMBERS
	for (int j = 0; j < 4; j++) { // collums
		for (int i = 0; i < 3; i++) { // rows

			for (int k = 0; k < (3 - i); k++) {
				if (gameField[j][i + k] > 0 && gameField[j][i + k + 1] == 0) {
					gameField[j][i + 1 + k] = gameField[j][i + k];
					gameField[j][i + k] = 0;
					countMove++;
				}
			}
		}
	}

	// COUNT NUMBERS
	for (int j = 0; j < 4; j++) { // collums
		for (int i = 0; i < 4; i++) { // rows
			if (gameField[j][i] == gameField[j][i + 1]) {
				gameField[j][i + 1] = gameField[j][i] + gameField[j][i + 1];
				score = score + gameField[j][i + 1];
				gameField[j][i] = 0;
				if (gameField[j][i+1] > 0) countMove++;
			}
		}
	}

	// MOVE NUMBERS
	for (int j = 0; j < 4; j++) { // collums
		for (int i = 0; i < 3; i++) { // rows

			for (int k = 0; k < (3 - i); k++) {
				if (gameField[j][i + k] > 0 && gameField[j][i + k + 1] == 0) {
					gameField[j][i + 1 + k] = gameField[j][i + k];
					gameField[j][i + k] = 0;
				}
			}
		}
	}
	}
	else {
		// Do nothing
	}

	//GENERATE NUMBERS ON ZEROS
	int zeroPosition = getRandomZeroPosition();
	if (zeroPosition == -1) {
		return 1;
	}
	if(countMove>0){			
		int row = zeroPosition / 4;
		int collum = zeroPosition % 4;
		gameField[row][collum] = generateRandomTwoOrFour();
		drawGameField(gameField,score,nickname);
	}
	return 0;
}

int getRandomZeroPosition() {
	int zeroPosition = 0;
	int zeroField = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (gameField[i][j] == 0) zeroField++;
		}
	}
	//printf("Zero Field: %i\n", zeroField);
	if (zeroField == 0) return -1;

	srand((unsigned)time(NULL));
	int random = 0;
	random = (rand() % zeroField);

	//printf("Random: %i\n", random);
	zeroField = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (gameField[i][j] == 0) {
				if (zeroField == random) zeroPosition = (i * 4) + j;
				zeroField++;
			}
		}
	}
	//printf("zeroPosition: %i\n", zeroPosition);
	return zeroPosition;
}

int generateRandomTwoOrFour() {
	int number = 0;
	int randomNumber = 0;
	srand((unsigned)time(NULL));
	randomNumber = rand() % 10;
	if (randomNumber > 4) {
		number = 2;
	}
	else {
		number = 4;
	}
	return number;
}

void delay(int milliseconds)
{
	long pause;
	clock_t now, then;

	pause = milliseconds * (CLOCKS_PER_SEC / 1000);
	now = then = clock();
	while ((now - then) < pause)
		now = clock();
}

void readStatistics() {
	do {
		char key = 'm';
		drawStatistics(statistics);

		key = getch();
		if (key == 'q') break;
	} while (1);
}

void writeFileStatistics() {
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

void writeToStatistics(statisticsRecord record) {
	for (int i = 0; i < 10; i++) {
		if (statistics[i].score < record.score) {
			statisticsRecord help1{ "",statistics[i].score };
			strcpy(help1.nickname, statistics[i].nickname);

			statistics[i].score = record.score;
			strcpy(statistics[i].nickname, record.nickname);

			for (int j = (i + 1); j < 10; j++) {
				statisticsRecord help2{ "",statistics[j].score };
				strcpy(help2.nickname, statistics[j].nickname);

				statistics[j].score = help1.score;
				strcpy(statistics[j].nickname, help1.nickname);

				help1.score = help2.score;
				strcpy(help1.nickname, help2.nickname);
			}
			break;
		}

	}
}

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
					strcpy(statistics[line].nickname, ptr);
				}
				if (position == 1) {
					int score = atoi(ptr);
					statistics[line].score = score;
				}
				//printf("%s,", ptr);
				ptr = strtok(NULL, ";");
				position++;
			}
			line++;
		}
		fclose(fp);
	}
}



