/*
 * GameController.cpp
 *
 *  Created on: Jun 29, 2014
 *      Author: voldymyr
 */

#ifndef GAMECONTROLLER_CPP_
#define GAMECONTROLLER_CPP_

#include "../inc/GraphicsEngine.h"
#include "../inc/LogicsController.h"
#include "../inc/EventController.h"

namespace Controller
{
	class GameController
	{
	public:
		GameController();
		~GameController();
		void GameLoop(void);

	private:
		GraphicsEngine *gEngine;
	};
}


#endif /* GAMECONTROLLER_CPP_ */
