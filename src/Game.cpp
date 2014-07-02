/*
 * Game.cpp
 *
 *  Created on: Jul 1, 2014
 *      Author: khrystynka
 */

#include "../inc/Game.h"


Game::Game()
{
	gameEngine = new GameEngine;
	if(!gameEngine)
		cout << "Error: Could not init game engine" << endl;

	gameWindowController = new Controller::GameWindowController;
	if(!gameWindowController)
		cout << "Error: Could not init gameWindowController" << endl;

	logicsController = new Controller::LogicsController;
	if(!logicsController)
		cout << "Error: Could not init logicsController" << endl;
}

Game::~Game()
{
	delete logicsController;
	delete gameWindowController;
	delete gameEngine;
}

void Game::MainGameLoop()
{
	bool bQuit = false;
	SDL_Event event;


	//gameWindowController->DispatchSetMainWindow(755, 600, 32, SDL_SWSURFACE);
	//gameWindowController->DispatchSetMainWindowCaption("Diamonds", "Diamonds");
	//gameWindowController->DispatchSetBackgroundImage("BackGround.jpg");
	//gameWindowController->DispatchDrawBackgroundImage();
	SDL_Surface* screen = SDL_SetVideoMode(755, 600, 32, SDL_SWSURFACE);
	SDL_WM_SetCaption("Diamonds", "Diamonds");
	SDL_Surface* image = IMG_Load("rc/BackGround.jpg");
	SDL_BlitSurface(image, NULL, screen, NULL);

	while(!bQuit)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				bQuit = true;
		}

		SDL_Flip(screen);
		//gameWindowController->DispatchDrawBackgroundImage();
		//gameWindowController->DispatchUpdateWindow();

	}
}
