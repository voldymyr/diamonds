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

void Controller::GameWindowController::LoadFont(TTF_Font*& font)
{
	gameWindowModel->SetTextFont(font);
}

void Controller::GameWindowController::LoadColor(SDL_Color* color)
{
	gameWindowModel->SetTextColor(color);
}

void Controller::GameWindowController::LoadNoMoreMoves(const char* str, int w, int h, int x, int y)
{
	TTF_Font* textFont = gameWindowModel->GetTextFont();

	SDL_Color textColor = gameWindowModel->GetTextColor();

	SDL_Surface* textSurface = TTF_RenderText_Blended(textFont, str, textColor);

	SDL_Rect rect;
	rect.h = h;
	rect.w = w;
	rect.x = x;
	rect.y = y;

	gameWindowModel->SetNoMoreMovesRect(&rect);

	gameWindowModel->SetNoMoreMovesStr(&textSurface);
}

void Controller::GameWindowController::DispatchDrawNoMoreMoves()
{
	SDL_Surface* window = gameWindowModel->GetMainWindow();
	SDL_Surface* text = gameWindowModel->GetNoMoreMovesStr();
	SDL_Rect rect = gameWindowModel->GetNoMoreMovesRect();
	gameWindowView->DrawImage(text, &rect, window);
}

void Controller::GameWindowController::LoadGameOver(const char* str, int w, int h, int x, int y)
{
	TTF_Font* textFont = gameWindowModel->GetTextFont();
	SDL_Color textColor = gameWindowModel->GetTextColor();

	SDL_Rect rect;
	rect.h = h;
	rect.w = w;
	rect.x = x;
	rect.y = y;

	SDL_Surface* textSurface = TTF_RenderText_Blended(textFont, str, textColor);

	gameWindowModel->SetGameOverStr(&textSurface);
	gameWindowModel->SetGameOverRect(&rect);
}

void Controller::GameWindowController::DispatchDrawGameOver()
{
	SDL_Surface* window = gameWindowModel->GetMainWindow();
	SDL_Surface* text = gameWindowModel->GetGameOverStr();
	SDL_Rect rect = gameWindowModel->GetGameOverRect();
	gameWindowView->DrawImage(text, &rect, window);
}

void Controller::GameWindowController::LoadTime(const char* timeStr)
{
	TTF_Font* textFont = gameWindowModel->GetTextFont();
	SDL_Color textColor = gameWindowModel->GetTextColor();

	SDL_Surface* timeSurface = TTF_RenderText_Blended(textFont, timeStr, textColor);
	gameWindowModel->SetTimeSurface(&timeSurface);
}

void Controller::GameWindowController::DispatchDrawTime()
{
	SDL_Surface* window = gameWindowModel->GetMainWindow();
	SDL_Surface* time = gameWindowModel->GetTimeSurface();
	SDL_Rect rect;
	rect.x = 90;
	rect.y = 445;
	gameWindowView->DrawImage(time, &rect, window);
}
