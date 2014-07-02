/*
 * Game.h
 *
 *	Game is a class that represents this game, the Diamonds.
 *	This class contains game engine and uses its functionality to
 *	construct the game.
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
	void MainGameLoop(void);

private:
	GameEngine* gameEngine;
	Controller::GameWindowController* gameWindowController;
	Controller::LogicsController* logicsController;
};


#endif /* GAME_H_ */
