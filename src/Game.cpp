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


	gameWindowController->DispatchSetMainWindow(755, 600, 32, SDL_SWSURFACE);
	gameWindowController->DispatchSetMainWindowCaption("Diamonds", "Diamonds");
	gameWindowController->DispatchSetBackgroundImage("rc/BackGround.jpg");
	gameWindowController->DispatchDrawBackgroundImage();

	while(!bQuit)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				bQuit = true;
		}

		//gameWindowController->DispatchDrawBackgroundImage();
		gameWindowController->DispatchUpdateWindow();

	}
}
