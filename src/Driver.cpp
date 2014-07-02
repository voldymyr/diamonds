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

	theGame->MainGameLoop();

	printf("Hello World!");
	return 0;
}

