/*
 * GameController.cpp
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
	};
}


#endif /* GAMEENGINE_H_ */
