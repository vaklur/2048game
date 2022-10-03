// 2048game.cpp: Definuje vstupní bod pro aplikaci.
//

#include "2048game.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

// Colors
#define BLUE(string) "\x1b[34m" string "\x1b[0m"
#define RED(string) "\x1b[31m" string "\x1b[0m"
#define YELLOW(string) "\x1b[33m" string "\x1b[0m"
#define GREEN(string) "\x1b[32m" string "\x1b[0m"

// Functions
int menu();
int game();
int getNickName();
int drawGameField();
int generateRandomTwoOrFour();
int getRandomZeroPosition();
int playerMove(int);
void statistics();

// Global variables
int gameField[4][4];
int score;
char nickname[10];


void delay(int milliseconds);

int main()
{
	menu();
	return 0;
}

int menu() {
	char menu_option;
	do{
		system("cls");
		printf("Game 2048");
		printf("\n\n\n");
		printf("1. -> Start new game\n");
		printf("2. -> Continue in actual game\n");
		printf("3. -> Statistics\n");
		printf("4. -> End game\n");

		scanf_s("%c", &menu_option);

		switch (menu_option) {
			// Start game
			case '1':
				getNickName();
				break;
			// Continue in actual game
			case '2':
				break;
			// Statistics
			case '3':
				break;
			// Quit application
			case '4':
				break;
			default:
				printf("Invalid output");
				break;
		}
	} 
	while (menu_option != '4');


	return 0;
}

int getNickName() {
	system("cls");
	printf("Game 2048");
	printf("\n\n\n");
	printf("Enter you nickname (max 10 characters):");
	scanf("%9s", nickname);
	game();
	return 0;
}

int game() {
	// Initialize game field with zeros
	score = 0;
	int gameOver = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			gameField[i][j] = 0;
		}
	}
	gameField[0][0] = 2;
	drawGameField();
	do {
		char key = 'm';
		
		key = getch();
		// UP
		if (key == 'w')	gameOver = playerMove(1);	
		// DOWN
		if (key == 's')	gameOver = playerMove(2);
		// LEFT
		if (key == 'a')	gameOver = playerMove(3);
		// RIGHT
		if (key == 'd') gameOver = playerMove(4);
		// RESTART
		if (key == 'r') game();
		// EXIT
		if (key == 'q') break;
		// GAME OVER
		if (gameOver == 1) {
				system("cls");
				printf("\n\n\n !!! GAME OVER !!! \n\n\n");
				printf("PLAYER: %s\n",nickname);
				printf(" SCORE: %i \n\n\n", score);
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
		drawGameField();
	}
	return 0;
}

int drawGameField() {
	system("cls");
	printf("**** Game 2048 ****\n\n");
	printf("SCORE: %i\n",score);
	printf("|-------|-------|-------|-------|\n");
	printf("|" YELLOW("%i") "\t|" YELLOW("%i") "\t|" YELLOW("%i") "\t|" YELLOW("%i") "\t|\n", gameField[0][0], gameField[0][1], gameField[0][2], gameField[0][3]);
	printf("|-------|-------|-------|-------|\n");
	printf("|" YELLOW("%i") "\t|" YELLOW("%i") "\t|" YELLOW("%i") "\t|" YELLOW("%i") "\t|\n", gameField[1][0], gameField[1][1], gameField[1][2], gameField[1][3]);
	printf("|-------|-------|-------|-------|\n");
	printf("|" YELLOW("%i") "\t|" YELLOW("%i") "\t|" YELLOW("%i") "\t|" YELLOW("%i") "\t|\n", gameField[2][0], gameField[2][1], gameField[2][2], gameField[2][3]);
	printf("|-------|-------|-------|-------|\n");
	printf("|" YELLOW("%i") "\t|" YELLOW("%i") "\t|" YELLOW("%i") "\t|" YELLOW("%i") "\t|\n", gameField[3][0], gameField[3][1], gameField[3][2], gameField[3][3]);
	printf("|-------|-------|-------|-------|\n");
	printf("\n\n");
	printf("(W)Up (S)Down (A)Left (D)Right\n (R) Restart (Q)Exit");
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

void statistics() {

}
