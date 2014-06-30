/*
 * GameController.cpp
 *
 *  Created on: Jun 30, 2014
 *      Author: khrystynka
 */

#include "../inc/GameController.h"

Controller::GameController::GameController()
{
	gEngine = new GraphicsEngine;
	if(gEngine == NULL)
		cout << "Could not create Graphics Instance" << endl;
}

Controller::GameController::~GameController()
{
	delete gEngine;
}

void Controller::GameController::GameLoop()
{

}
