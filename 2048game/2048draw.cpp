#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "2048draw.h"

// Colors
#define BLUE(string) "\x1b[34m" string "\x1b[0m"
#define RED(string) "\x1b[31m" string "\x1b[0m"
#define YELLOW(string) "\x1b[33m" string "\x1b[0m"
#define GREEN(string) "\x1b[32m" string "\x1b[0m"
#define PURPLE(string) "\x1b[35m" string "\x1b[0m"
#define CYAN(string) "\x1b[36m" string "\x1b[0m"
#define LIGHT_GRAY(string) "\x1b[37m" string "\x1b[0m"
#define LIGHT_GREEN(string) "\x1b[92m" string "\x1b[0m"
#define LIGHT_CYAN(string) "\x1b[96m" string "\x1b[0m"
#define LIGHT_BLUE(string) "\x1b[94m" string "\x1b[0m"
#define LIGHT_YELLOW(string) "\x1b[93m" string "\x1b[0m"

// Print get nickname dialog
char* getNickName() {
	char nickname[10];
	system("cls");
	printf("**** Game 2048 ****\n\n");
	printf("\n\n\n");
	printf("Enter you nickname (max 10 characters):");
	scanf("%9s", nickname);
	return nickname;
}

// Print the main menu
void drawMenu() {
	system("cls");
	printf("\n\n");
	printf("|------------------**** Game 2048 ****------------------|\n");
	printf("|\t\t\t\t\t\t\t|\n");
	printf("|\t\t1. -> Start new game\t\t\t|\n");
	printf("|\t\t2. -> Continue in actual game\t\t|\n");
	printf("|\t\t3. -> Statistics\t\t\t|\n");
	printf("|\t\t4. -> End game\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t|\n");
	printf("|-------------------------------------------------------|\n");
}

// Print statistics
void drawStatistics(statisticsRecord statistics[10]) {
	system("cls");
	printf("\n\n\n");
	printf("|------------------**** Game 2048 ****------------------|\n");
	printf("|\t\t\t\t\t\t\t|\n");
	printf("|\tPosition\tNickname\tScore\t\t|\n");
	for (int i = 0; i < 10; i++) {
		statistics[i].nickname[strcspn(statistics[i].nickname, "\n")] = 0;
		printf("|\t%i\t\t%s\t\t%i\t\t|\n", i + 1, statistics[i].nickname, statistics[i].score);
	}
	printf("|\t\t\t\t\t\t\t|\n");
	printf("|\t(Q)Exit\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t|\n");
	printf("|-------------------------------------------------------|\n");
}

// Print players score
void drawEndScore(char nickname[10], int score) {
	system("cls");
	printf("\n\n\n !!! GAME OVER !!! \n\n\n");
	printf("PLAYER: %s\n", nickname);
	printf(" SCORE: %i \n\n\n", score);
}

// Color the number
void numberColour(int number) {
	if (number == 2) printf("|" YELLOW("%i") "\t", number);
	else if (number == 4) printf("|" RED("%i") "\t", number);
	else if (number == 8) printf("|" BLUE("%i") "\t", number);
	else if (number == 16) printf("|" GREEN("%i") "\t", number);
	else if (number == 32) printf("|" PURPLE("%i") "\t", number);
	else if (number == 64) printf("|" CYAN("%i") "\t", number);
	else if (number == 128) printf("|" LIGHT_GRAY("%i") "\t", number);
	else if (number == 256) printf("|" LIGHT_CYAN("%i") "\t", number);
	else if (number == 512) printf("|" LIGHT_GREEN("%i") "\t", number);
	else if (number == 1024) printf("|" LIGHT_YELLOW("%i") "\t", number);
	else if (number == 2048) printf("|" LIGHT_BLUE("%i") "\t", number);
	else printf("|%i\t", number);
}

// Print game field
void drawGameField(int gameFieldDraw[4][4], int score, char nickname[10]) {
	system("cls");
	printf("**** Game 2048 ****\n\n");
	printf("Player: %s\n\n", nickname);
	printf("SCORE: %i\n", score);
	printf("|-------|-------|-------|-------|\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			numberColour(gameFieldDraw[i][j]);
		}
		printf("\n|-------|-------|-------|-------|\n");
	}
	printf("\n\n");
	printf("(W)Up (S)Down (A)Left (D)Right\n (R) Restart (Q)Exit");
}

