/*
 * Driver.cpp
 *
 *  Created on: Jun 29, 2014
 *      Author: voldymyr
 */

#include <cstdlib>
#include <cstdio>
#include "../inc/Common.h"
#include "../inc/Game.h"


int main(int argc, char** argv)
{
	Game* theGame = new Game;
	if(!theGame)
		cout << "Could not create Game!" << endl;

	// Create and draw main window
	theGame->CreateGameWindow(755, 600, 32, SDL_HWSURFACE, "rc/BackGround.jpg", "Diamonds");
	theGame->DrawGameWindow();

	// Set level time
	float time = 60.0;
	theGame->SetLevelTime(time);

	// start the game
	theGame->MainGameLoop();

	return 0;
}

