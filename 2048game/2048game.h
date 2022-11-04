#pragma once

int game(bool newGame);

void readStatistics();
void readStatisticsFile();
void writeFileStatistics();
void writeToStatistics(statisticsRecord);

int generateRandomTwoOrFour();
int getRandomZeroPosition();
int playerMove(int);
void delay(int milliseconds);
