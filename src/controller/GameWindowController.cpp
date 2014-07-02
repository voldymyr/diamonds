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

void Controller::GameWindowController::DispatchSetBackgroundImage(const char *img)
{
	gameWindowModel->SetBackGroundIMG(img);
}

void Controller::GameWindowController::DispatchDrawBackgroundImage()
{
	SDL_Surface* background = gameWindowModel->GetBackGroundIMG();
	SDL_Surface* window = gameWindowModel->GetMainWIndow();
	int width = gameWindowModel->GetWindowWidth();
	int height = gameWindowModel->GetWindowHeight();

	gameWindowView->DrawImage(&background, &window, width, height);
}

void Controller::GameWindowController::DispatchUpdateWindow()
{
	SDL_Surface* window = gameWindowModel->GetMainWIndow();
	gameWindowView->UpdateWindow(&window);
}

void Controller::GameWindowController::DispatchSetMainWindow(int x, int y, int bpp, Uint32 flags)
{
	gameWindowModel->SetMainWindow(x, y, bpp, flags);
}

void Controller::GameWindowController::DispatchSetMainWindowCaption(const char* title, const char* icon)
{
	gameWindowModel->SetMainWindowCaption(title, icon);
}
