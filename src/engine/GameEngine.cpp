/*
 * GameEngine.cpp
 *
 *  Created on: Jun 30, 2014
 *      Author: khrystynka
 */

#include "../../inc/engine/GameEngine.h"
#include <iostream>

using namespace std;

GameEngine::GameEngine()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		cout << "Error in SDL_Init(): " << SDL_GetError() << endl;
	if(IMG_Init(IMG_INIT_JPG) < 0)
		cout << "Error in IMG_Init(): " << IMG_GetError() << endl;
	if(TTF_Init() < 0)
		cout << "Error in TTF_Init(): " << TTF_GetError() << endl;
}

GameEngine::~GameEngine()
{
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
