/*
 * GameController.cpp
 *
 *  Created on: Jun 30, 2014
 *      Author: khrystynka
 */

#include "../inc/GameEngine.h"

Controller::GameEngine::GameEngine()
{
	graphicsEngine = new GraphicsEngine;
	if(graphicsEngine == NULL)
		cout << "Could not create Graphics Instance" << endl;
}

Controller::GameEngine::~GameEngine()
{
	delete graphicsEngine;
}
