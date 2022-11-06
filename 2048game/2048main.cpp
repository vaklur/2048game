/*
2048 game developed by Ing. Jakub Michalek 
Last version - 06.11.2022
*/
#include <stdio.h>
#include <conio.h>

#include "2048main.h"
#include "2048draw.h"
#include "2048game.h"
#include "2048statistics.h"

int main()
{
	do {
		// Print menu to terminal
		drawMenu();

		char key = getch();
		// Start new game
		if (key == '1') game(true);
		// Continue in actual game
		if (key == '2') {
			if (actualGameExist()) {
				game(false);
			}
		}
		// Statistics
		if (key == '3') readStatistics();
		// Quit game
		if (key == '4')	break;

	} while (1);
	
	return 0;
}
