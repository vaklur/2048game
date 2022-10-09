#include <stdio.h>
#include <stdlib.h>

#include "structures.h"

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



void numberColour(int number);

void drawMenu() {
	system("cls");
	printf("**** Game 2048 ****\n\n");
	printf("\n");
	printf("1. -> Start new game\n");
	printf("2. -> Continue in actual game\n");
	printf("3. -> Statistics\n");
	printf("4. -> End game\n");
}

void drawStatistics(statisticsRecord statistics[10]) {
	system("cls");
	printf("*** Game 2048 ***");
	printf("\n\n\n");
	printf("Position\tNickname\tScore\n");
	for (int i = 0; i < 10; i++) {
		printf("%i\t\t%s\t\t%i\n", i + 1, statistics[i].nickname, statistics[i].score);
	}
	printf("\n\n");
	printf("(Q)Exit");
}

void drawEndScore(char nickname[10], int score) {
	system("cls");
	printf("\n\n\n !!! GAME OVER !!! \n\n\n");
	printf("PLAYER: %s\n", nickname);
	printf(" SCORE: %i \n\n\n", score);
}



void drawGameField(int gameFieldDraw[4][4], int score) {
	system("cls");
	printf("**** Game 2048 ****\n\n");
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