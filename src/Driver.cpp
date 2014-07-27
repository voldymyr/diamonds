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
	srand(time(NULL));
	Game* theGame = new Game;
	if(!theGame)
		cout << "Could not create Game!" << endl;

	theGame->CreateGameWindow(755, 600, 32, SDL_HWSURFACE, "rc/BackGround.jpg", "Diamonds");

	string str1 = "rc/Yellow.png";
	string str2 = "rc/Green.png";
	string str3 = "rc/Blue.png";
	string str4 = "rc/Purple.png";
	string str5 = "rc/Red.png";

	map<ElementType, string> pngs;
	pngs.insert(make_pair<ElementType, string>(Yellow, str1));
	pngs.insert(make_pair<ElementType, string>(Green, str2));
	pngs.insert(make_pair<ElementType, string>(Blue, str3));
	pngs.insert(make_pair<ElementType, string>(Purple, str4));
	pngs.insert(make_pair<ElementType, string>(Red, str5));

	theGame->LoadElementImages(pngs);

	theGame->SetGameBoardDimension(8, 8);
	theGame->SetElementDimensions(36, 36);
	theGame->SetElementOffset(10);
	theGame->SetElementsStartPixelsXY(320, 100);

	// Set level time
	float t = 60.0;
	theGame->SetLevelTime(t);

	// start the game
	theGame->MainGameLoop();

	return 0;
}

