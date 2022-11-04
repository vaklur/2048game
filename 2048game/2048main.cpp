#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>

#include "2048main.h"
#include "2048draw.h"
#include "2048game.h"

int menu();

int main()
{

	readStatisticsFile();
	menu();
	return 0;
}

int menu() {
	

	do {
		drawMenu();

		char key = getch();
		// Start new game
		if (key == '1') game(true);
		// Continue in actual game
		if (key == '2') {
			game(false);
		}
		// Statistics
		if (key == '3') readStatistics();
		// Quit game
		if (key == '4')	break;

	} while (1);


	return 0;
}