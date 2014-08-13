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
	SDL_Surface* window = gameWindowModel->GetMainWindow();

	gameWindowView->DrawImage(background, window);
}

void Controller::GameWindowController::DispatchUpdateWindow()
{
	SDL_Surface* window = gameWindowModel->GetMainWindow();
	gameWindowView->UpdateWindow(window);
}

void Controller::GameWindowController::DispatchSetMainWindow(int x, int y, int bpp, Uint32 flags)
{
	gameWindowModel->SetMainWindow(x, y, bpp, flags);
}

void Controller::GameWindowController::DispatchSetMainWindowCaption(const char* title, const char* icon)
{
	gameWindowModel->SetMainWindowCaption(title, icon);
}

bool Controller::GameWindowController::GetUserInteractionStatus()
{
	return gameWindowModel->GetUserInteraction();
}

void Controller::GameWindowController::SetUserInteractionStatus(bool status)
{
	gameWindowModel->SetUserInteraction(status);
}

SDL_Surface* Controller::GameWindowController::GetMainWindow() const
{
	return gameWindowModel->GetMainWindow();
}

void Controller::GameWindowController::DispatchDrawNoMoreMoves()
{
	//SDL_Surface* window = gameWindowModel->GetMainWindow();
	//SDL_Surface* text = gameWindowModel->GetNoMoreMoves();
	//gameWindowView->DrawImage(text, window);
}

void Controller::GameWindowController::DispatchDrawGameOver()
{

}
