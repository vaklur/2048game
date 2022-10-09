#pragma once
#include "structures.h"

void drawMenu();
void drawStatistics(statisticsRecord statistics[10]);
void drawEndScore(char nickname[10],int score);
void drawGameField(int gameField[4][4], int score);
void numberColour(int number);
