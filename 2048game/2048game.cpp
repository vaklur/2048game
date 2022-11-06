#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_SECURE_NO_WARNINGS

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>

#include "structures.h"
#include "2048game.h"
#include "2048draw.h"
#include "2048statistics.h"

// Global variables
int gameField[4][4];
int score;
char nickname[10];
bool restart = false;

// Main function for game logic
void game(bool newGame) {
	// Control game over variable
	bool gameOver = false;
	// If is new game, redeclare the variables
	if (newGame == true) {
		// If the game was restarted, do not ask for a nickname
		if (restart == false) strcpy(nickname, getNickName());

		score = 0;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				gameField[i][j] = 0;
			}
		}
		gameField[0][0] = 2;
	}
	// If the game is played, load the save data 
	else {
		loadActualGame();
	}
	// Print game field
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
		if (key == 'r') {
			restart = true;
			game(true);
		}
		// EXIT
		if (key == 'q') {
			saveActualGame(true, nickname, gameField, score);
			break;
		}
		// GAME OVER
		if (gameOver == true) {
			saveActualGame(false, nickname, gameField, score);
			drawEndScore(nickname,score);
			statisticsRecord record;
			record.score = score;
			strcpy(record.nickname, nickname);
			writeToStatistics(record);
			delay(5000);
			break;
			}
	}
	while (gameOver!=true);
}

// Function for movement of numbers
bool playerMove(int move) {
	/* If variable move is:
	1 - up
	2 - down
	3 - left
	4 - right
	*/
	// Count of moves
	int countMove = 0;
	/*
	MOVEMENT OF NUMBERS
	*/
	// up
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
	// down
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
	// left
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
	// right
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

	//GENERATE NUMBERS RANDOM ON ZEROS
	int zeroPosition = getRandomZeroPosition();

	// No free position for generate new number
	if (zeroPosition == -1) {
		return true;
	}
	// If the number moves, give a new number to zero position
	if(countMove>0){			
		int row = zeroPosition / 4;
		int collum = zeroPosition % 4;
		gameField[row][collum] = generateRandomTwoOrFour();
		drawGameField(gameField,score,nickname);
	}
	return false;
}

// Get random position on zero in game field ( return -1 if no position in game field)
int getRandomZeroPosition() {
	int zeroPosition = 0;
	int zeroField = 0;

	// Control if the zero field exists and if not return -1
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (gameField[i][j] == 0) zeroField++;
		}
	}
	if (zeroField == 0) return -1;

	// Generate random zero position
	srand((unsigned)time(NULL));
	int random = 0;
	random = (rand() % zeroField);

	// Get a real zero position
	zeroField = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (gameField[i][j] == 0) {
				if (zeroField == random) zeroPosition = (i * 4) + j;
				zeroField++;
			}
		}
	}
	return zeroPosition;
}

// Generate random number 2 or 4 (Chance 50/50)
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

// Function for delay in msc
void delay(int milliseconds)
{
	long pause;
	clock_t now, then;

	pause = milliseconds * (CLOCKS_PER_SEC / 1000);
	now = then = clock();
	while ((now - then) < pause)
		now = clock();
}

// Save actual game to text file
void saveActualGame(bool exist, char nickname[10], int gameField[4][4], int score) {
	FILE* fp;
	fp = fopen("actualGame.txt", "w");
	if (fp)
	{
		if (exist == true) {
			fprintf(fp, "1\n");
		}
		else {
			fprintf(fp, "0\n");
		}
		nickname[strcspn(nickname, "\n")] = 0;
		fprintf(fp, "%s\n",nickname);
		fprintf(fp, "%i",score);
		for (int i = 0; i < 4; i++) {
			fprintf(fp, "\n%i;%i;%i;%i",gameField[i][0], gameField[i][1], gameField[i][2], gameField[i][3]);
		}
		fclose(fp);
	}
}

// Load actual game from text file
void loadActualGame() {
	FILE* fp;
	fp = fopen("actualGame.txt", "r");
	if (fp)
	{
		char str[60];
		int line = 0;
		while (fgets(str, 60, fp) != NULL) {
			char* ptr = strtok(str, ";");
			int position = 0;
			while (ptr != NULL) {
				if (line == 0);
				else if (line == 1) {
					strcpy(nickname, ptr);
				}
				else if (line == 2) {
					score = atoi(ptr);
				}
				else {
					if (position == 0) {
						gameField[line - 3][0] = atoi(ptr);
					}
					if (position == 1) {
						gameField[line - 3][1] = atoi(ptr);
					}
					if (position == 2) {
						gameField[line - 3][2] = atoi(ptr);
					}
					if (position == 3) {
						gameField[line - 3][3] = atoi(ptr);
					}
				}
				
				ptr = strtok(NULL, ";");
				position++;
			}
			line++;
		}
		fclose(fp);
	}
}

// Control if played game exist in text file
bool actualGameExist() {
	FILE* fp;
	char exists{};
	fp = fopen("actualGame.txt", "r");
	if (fp)
	{
		exists = fgetc(fp);		
		fclose(fp);
	}
	if (exists == '0') return false;
	else return true;
}


