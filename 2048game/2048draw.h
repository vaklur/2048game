#pragma once
#include "structures.h"

void drawMenu();
void drawStatistics(statisticsRecord statistics[10]);
void drawEndScore(char nickname[10],int score);
void drawGameField(int gameField[4][4], int score, char nickname[10]);
void numberColour(int number);
