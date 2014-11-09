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
	allowedLevelTime = 0.0;
	timeLeft = 0.0;
	mousePosX = mousePosY = 0;
	noMoreMoves = false;
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

void Game::MainGameLoop()
{
	Uint32 oldTime = 0, currentTime = 0;
	float move = 0.0;
	char numToStrTime[25];

	// Shuffle elements until there are moves available
	do
	{
		logicsController->ShuffleElements();
	}
	while(!logicsController->CheckForMoves());

	SDL_Surface* window = gameWindowController->GetMainWindow();

	currentTime = SDL_GetTicks();
	while(!bQuit)
	{
		gameWindowController->DispatchDrawBackgroundImage();
		logicsController->DispatchDrawElements(window);

		this->RegisterEvent();

		if(this->HandleQuitEvent())
			break;

		this->UpdateTime(oldTime, currentTime);
		timeLeft = (timeLeft < 0) ? 0 : timeLeft;

		sprintf(numToStrTime, "Time: %d", (int)timeLeft);
		gameWindowController->LoadTime(numToStrTime);

		char numToStrScore[50];
		sprintf(numToStrScore, "Score: %d", logicsController->GetScore());
		gameWindowController->LoadScore(numToStrScore);

		if(noMoreMoves)
		{
			gameWindowController->DispatchDrawNoMoreMoves();
			gameWindowController->DispatchDrawScore();

			if(this->HandleRestartEvent())
				continue;
		}
		else if(timeLeft <= 0)
		{
			if(!gameWindowController->GetUserInteractionStatus())
				gameWindowController->SetUserInteractionStatus(true);

			gameWindowController->DispatchDrawGameOver();
			gameWindowController->DispatchDrawScore();
			gameWindowController->DispatchDrawTime();

			if(this->HandleRestartEvent())
				continue;
		}
		else
		{
			gameWindowController->DispatchDrawTime();
			gameWindowController->DispatchDrawScore();

			if(gameWindowController->GetUserInteractionStatus())
				this->HandleLogicsEvent();

			/*
			 * Steps below should only be executed if 2 elements have been selected
			 * Some Flag should be created and checked
			 */

			if(logicsController->PairValid())
			{
				move = logicsController->CalculateMovePoints(oldTime, currentTime);
				this->ProcessGameLogics(window, move);
			}
		}

		gameWindowController->DispatchUpdateWindow();

		// Free related surfaces
		//gameWindowController->UnloadScore();
		//gameWindowController->UnloadTime();
	}

	window = NULL;
}

void Game::SetLevelTime(float& t)
{
	allowedLevelTime = t;
	timeLeft = allowedLevelTime;
}

void Game::InitGameBoard(int w, int h)
{
	logicsController->InitGameBoard(w, h);
}

void Game::LoadElementImages(map<ElementType, string>& imgs)
{
	logicsController->LoadElementImages(imgs);
}

void Game::SetGameBoardDimension(int w, int h)
{
	logicsController->SetGameBoardDimension(w, h);
}

void Game::SetElementDimensions(int w, int h)
{
	logicsController->SetElementDimensions(w, h);
}

void Game::SetElementOffset(int offs)
{
	logicsController->SetElementOffset(offs);
}

void Game::SetElementsStartPixelsXY(int x, int y)
{
	logicsController->SetElementsStartPixelsXY(x, y);
}

void Game::SetDropLineYPos(int y)
{
	logicsController->SetDropLineYPos(y);
}

void Game::SetFont(const char* fontStr, int size)
{
	TTF_Font* font = TTF_OpenFont(fontStr, size);
	gameWindowController->LoadFont(font);
}

void Game::SetColor(SDL_Color* color)
{
	gameWindowController->LoadColor(color);
}

void Game::SetNoMoreMovesStr(const char* str, int w, int h, int x, int y)
{
	gameWindowController->LoadNoMoreMoves(str, w, h, x, y);
}

void Game::SetGameOverStr(const char* str, int w, int h, int x, int y)
{
	gameWindowController->LoadGameOver(str, w, h, x, y);
}

void Game::RegisterEvent()
{
	SDL_PollEvent(&event);
}

void Game::HandleLogicsEvent()
{
	if(event.type == SDL_MOUSEBUTTONDOWN)
	{
		if(event.button.button == SDL_BUTTON_LEFT)
		{
			mousePosX = event.button.x;
			mousePosY = event.button.y;

			if(logicsController->HandleLMButtonClick(mousePosX, mousePosY))
				gameWindowController->SetUserInteractionStatus(false);
		}
	}
}

bool Game::HandleRestartEvent()
{
	bool processed = false;
	if(event.type == SDL_MOUSEBUTTONDOWN)
	{
		if(event.button.button == SDL_BUTTON_RIGHT)
		{
			processed = true;
			this->ResetGame();
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

void Game::ResetGame()
{
	if(timeLeft <= 0)
	{
		timeLeft = allowedLevelTime;
		logicsController->SetScore(0);
	}

	noMoreMoves = false;

	// Shuffle elements until there are moves available
	do
	{
		logicsController->ShuffleElements();
	}
	while(!logicsController->CheckForMoves());

	gameWindowController->SetUserInteractionStatus(true);
	logicsController->SetSwapAllowed(false);
	logicsController->SetSwapBackAllowed(false);
	logicsController->SetMoveDownAllowed(false);
	logicsController->SetDropNewAllowed(false);
	logicsController->ClearSwapPair();
	logicsController->GameReset();
}

void Game::UpdateTime(Uint32& old, Uint32& curr)
{
	old = curr;
	curr = SDL_GetTicks();
	timeLeft -= (curr - old) / 1000.0f;
}

void Game::ProcessGameLogics(SDL_Surface*& window, float move)
{
	if(logicsController->SwapAllowed())
	 {
		if(logicsController->Swap(move))
		{
			logicsController->FindChainsForSwapPair();
			logicsController->CalculateScore();
			logicsController->RemoveChainsFromBoard();
			logicsController->CountMoveSteps();
			logicsController->SetSwapAllowed(false);
			logicsController->SetMoveDownAllowed(true);
			logicsController->ClearSwapPair();
		}

		logicsController->DispatchDrawElements(window);
	 }
	 else if(logicsController->SwapBackAllowed())
	 {
		 if(logicsController->SwapBack(move))
		 {
			 logicsController->SetSwapBackAllowed(false);
			 gameWindowController->SetUserInteractionStatus(true);
			 logicsController->ClearSwapPair();
			 logicsController->SetValidPairSelected(false);
		 }

		 logicsController->DispatchDrawElements(window);
	 }
	 else if(logicsController->MoveDownAllowed())
	 {
		 if(logicsController->MoveDown(move))
		 {
			 logicsController->SetMoveDownAllowed(false);
			 logicsController->SetDropNewAllowed(true);
			 logicsController->CreateNewElements();
		 }

		 logicsController->DispatchDrawElements(window);
	 }
	 else if(logicsController->DropNewAllowed())
	 {
		 if(logicsController->DropNew(move))
		 {
			 logicsController->SetDropNewAllowed(false);
			 if(logicsController->FindAndRemoveChains())
			 {
				 //logicsController->CalculateScore();
				 logicsController->CountMoveSteps();
				 logicsController->SetMoveDownAllowed(true);
			 }
			 else
			 {
				 gameWindowController->SetUserInteractionStatus(true);
				 if(!logicsController->CheckForMoves())
					 noMoreMoves = true;

				 logicsController->SetValidPairSelected(false);
			 }
		 }

		 logicsController->DispatchDrawElements(window);
	 }

}
