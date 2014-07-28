/**
 * Game.h
 *
 *	Game is a class that represents this game, the Diamonds.
 *	This class contains game engine and uses its functionality to
 *	construct the game.
 *
 *	Game has access to all controllers of the game in order to
 *	be able to manipulate the game. Controllers internally manipulate
 *	their specific models and views.
 *
 *  Created on: Jul 1, 2014
 *      Author: khrystynka
 */

#ifndef GAME_H_
#define GAME_H_

#include "engine/GameEngine.h"
#include "controller/GameWindowController.h"
#include "controller/LogicsController.h"

class Game
{
public:
	Game();
	~Game();
	void CreateGameWindow(int w, int h, int bpp, Uint32 flags, const char* img, const char* title);
	void MainGameLoop();
	void SetLevelTime(float& t);
	void InitGameBoard(int w, int h);
	void LoadElementImages(map<ElementType, string>& imgs);
	void SetGameBoardDimension(int w, int h);
	void SetElementDimensions(int w, int h);
	void SetElementOffset(int offs);
	void SetElementsStartPixelsXY(int x, int y);

private:
	void RegisterEvent();
	void HandleLogicsEvent();
	bool HandleRestartEvent();
	bool HandleQuitEvent();
	void ResetGame();
	void UpdateTime(Uint32& old, Uint32& curr);
	void ProcessGameLogics(SDL_Surface*& window, float move);

private:
	GameEngine* gameEngine;
	Controller::GameWindowController* gameWindowController;
	Controller::LogicsController* logicsController;

	SDL_Event event;
	bool bQuit;
	float allowedLevelTime;
	float timeLeft;
	float mousePosX;
	float mousePosY;
	bool noMoreMoves;
};


#endif /* GAME_H_ */
