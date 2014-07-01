/*
 * GameWindowController.cpp
 *
 *  Created on: Jul 1, 2014
 *      Author: khrystynka
 */


#include "../../inc/controller/GameWindowController.h"


Controller::GameWindowController::GameWindowController()
{
	gameWindowModel = new Model::GameWindowModel;
	gameWindowView = new View::GameWindowView;
}

Controller::GameWindowController::~GameWindowController()
{
	delete gameWindowModel;
	delete gameWindowView;
}

void Controller::GameWindowController::LoadBackgroundImage(const char *img)
{
	SDL_Surface* background = IMG_Load(img);
	if(!background)
		cout << "Could not load Background IMG: " << SDL_GetError() << endl;

	gameWindowModel->SetBackGroundIMG(&background);
	//gameWindowView->DrawBackground(&gameWindowModel->GetBackGroundIMG(), &gameWindowModel->GetMainWIndow(), gameWindowModel->GetWindowWidth(), gameWindowModel->GetWindowHeight());
}
