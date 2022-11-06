#pragma once

void game(bool newGame);
int generateRandomTwoOrFour();
int getRandomZeroPosition();
bool playerMove(int move);

void saveActualGame(bool exist, char nickname[10], int gameField[4][4], int score);
void loadActualGame();
bool actualGameExist();

void delay(int milliseconds);