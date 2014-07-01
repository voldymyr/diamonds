/*
 * GameEngine.h
 *
 * GameEngine is an engine of the game which incorporates graphics engine
 * GameEngine has control over all Models and operations with them as well as
 * View of the game.
 *
 * GameEngine consists of different controllers, such as EventController for processing
 * user events, Logics Controller for processing all game logics, GameWindowController
 * to control how game window is drawn and updated.
 *
 *  Created on: Jun 29, 2014
 *      Author: voldymyr
 */

#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_

#include "../inc/GraphicsEngine.h"
#include "../inc/LogicsController.h"
#include "../inc/EventController.h"

namespace Controller
{
	class GameEngine
	{
	public:
		GameEngine();
		~GameEngine();

	private:
		GraphicsEngine *graphicsEngine;
		//Controller::LogicsController *logicsController;
		//Controller::EventController *eventController;
	};
}


#endif /* GAMEENGINE_H_ */
