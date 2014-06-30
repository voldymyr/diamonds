/*
 * GameViewModel.cpp
 *
 *  Created on: Jun 30, 2014
 *      Author: khrystynka
 */

#include "../inc/GameWindowModel.h"

Model::GameWindowModel::GameWindowModel()
{
	mainWindow = NULL;
}

Model::GameWindowModel::~GameWindowModel()
{
	SDL_FreeSurface(mainWindow);
}
