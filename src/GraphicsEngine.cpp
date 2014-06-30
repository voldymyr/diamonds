/*
 * GraphicsEngine.cpp
 *
 *  Created on: Jun 29, 2014
 *      Author: voldymyr
 */

#include "../inc/GraphicsEngine.h"

GraphicsEngine::GraphicsEngine(void)
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
			cout << "Error in SDL_Init(): " << SDL_GetError() << endl;
	if(IMG_Init(IMG_INIT_JPG) < 0)
		cout << "Error in IMG_Init(): " << IMG_GetError() << endl;
	if(TTF_Init() < 0)
		cout << "Error in TTF_Init(): " << TTF_GetError() << endl;
}

GraphicsEngine::~GraphicsEngine(void)
{
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
