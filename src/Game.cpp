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

	bQuit = false;
	allowUserInteraction = true;
	allowedLevelTime = 0.0;
	timeLeft = 0.0;
	mousePosX = mousePosY = 0;
}

Game::~Game()
{
	delete logicsController;
	delete gameWindowController;
	delete gameEngine;
}

void Game::CreateGameWindow(int w, int h, int bpp, Uint32 flags, const char* img, const char* title)
{
	gameWindowController->DispatchSetMainWindow(w, h, bpp, flags);
	gameWindowController->DispatchSetMainWindowCaption(title, title);
	gameWindowController->DispatchSetBackgroundImage(img);
}

void Game::DrawGameWindow()
{
	gameWindowController->DispatchDrawBackgroundImage();
}

void Game::MainGameLoop()
{
	Uint32 oldTime = 0, currentTime = 0;

	gameWindowController->DispatchUpdateWindow();

	while(!bQuit)
	{
		this->RegisterEvent();

		if(this->HandleQuitEvent())
			break;

		if(timeLeft <= 0)
		{
			if(this->HandleRestartEvent())
				continue;
		}
		else
		{
			if(this->HandleLogicsEvent())
			{
				// check if mouse over element

				//cout << "Logics Event Happened!" << endl;
				//SDL_Delay(200);
			}
		}
	}
}

void Game::SetLevelTime(float& t)
{
	allowedLevelTime = t;
	timeLeft = allowedLevelTime;
}

void Game::RegisterEvent()
{
	SDL_PollEvent(&event);
}

bool Game::HandleLogicsEvent()
{
	bool handled = false;
	if(event.type == SDL_MOUSEBUTTONDOWN)
	{
		if(event.button.button == SDL_BUTTON_LEFT)
		{
			handled = true;
			mousePosX = event.button.x;
			mousePosY = event.button.y;
		}
	}

	return handled;
}

bool Game::HandleRestartEvent()
{
	bool processed = false;
	if(event.type == SDL_MOUSEBUTTONDOWN)
	{
		if(event.button.button == SDL_BUTTON_RIGHT)
		{
			processed = true;
			timeLeft = allowedLevelTime;
		}
	}

	return processed;
}

bool Game::HandleQuitEvent()
{
	if(event.type == SDL_QUIT)
	{
		bQuit = true;
	}

	return bQuit;
}
