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
}

void Model::GameWindowModel::SetMainWindow(SDL_Surface **window)
{
	mainWindow = *window;
}

SDL_Surface* Model::GameWindowModel::GetMainWIndow()
{
	return mainWindow;
}
