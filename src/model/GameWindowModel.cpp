/*
 * GameViewModel.cpp
 *
 *  Created on: Jun 30, 2014
 *      Author: khrystynka
 */

#include "../../inc/model/GameWindowModel.h"

Model::GameWindowModel::GameWindowModel()
{
	windowWidth = 0;
	windowHeight = 0;
	mainWindow = NULL;
	backGroundIMG = NULL;
	backGroundRect.h = 0;
	backGroundRect.w = 0;
	backGroundRect.x = 0;
	backGroundRect.y = 0;
	textFont = NULL;
	textColor.b = 0;
	textColor.g = 0;
	textColor.r = 0;
	gameOverStr = NULL;
	gameOverRect.h = 0;
	gameOverRect.w = 0;
	gameOverRect.x = 0;
	gameOverRect.y = 0;
}

Model::GameWindowModel::~GameWindowModel()
{
	SDL_FreeSurface(mainWindow);
	SDL_FreeSurface(backGroundIMG);
	TTF_CloseFont(textFont);
	SDL_FreeSurface(gameOverStr);
}

void Model::GameWindowModel::SetWindowWidth(int width)
{
	windowWidth = width;
}

int Model::GameWindowModel::GetWindowWidth()
{
	return windowWidth;
}

void Model::GameWindowModel::SetWindowHeight(int height)
{
	windowHeight = height;
}

int Model::GameWindowModel::GetWindowHeight()
{
	return windowHeight;
}

void Model::GameWindowModel::SetMainWindow(int x, int y, int bpp, Uint32 flags)
{
	if(mainWindow)
	{
		SDL_FreeSurface(mainWindow);
		mainWindow = NULL;
	}

	windowWidth = x;
	windowHeight = y;
	mainWindow = SDL_SetVideoMode(x, y, bpp, flags);
	if(!mainWindow)
		cout << "Could not set main window: " << SDL_GetError() << endl;
}

SDL_Surface* Model::GameWindowModel::GetMainWindow()
{
	return mainWindow;
}

void Model::GameWindowModel::SetMainWindowCaption(const char* title, const char* icon)
{
	SDL_WM_SetCaption(title, icon);
}

void Model::GameWindowModel::SetBackGroundIMG(const char* img)
{
	if(backGroundIMG)
	{
		SDL_FreeSurface(backGroundIMG);
		backGroundIMG = NULL;
	}

	backGroundIMG = IMG_Load(img);
	if(!backGroundIMG)
		cout << "Could not load Background IMG: " << SDL_GetError() << endl;
}

SDL_Surface* Model::GameWindowModel::GetBackGroundIMG()
{
	return backGroundIMG;
}

void Model::GameWindowModel::SetBackGroundRect(SDL_Rect *rect)
{
	backGroundRect = *rect;
}

SDL_Rect Model::GameWindowModel::GetBackGroundRect()
{
	return backGroundRect;
}

void Model::GameWindowModel::SetTextFont(TTF_Font **font)
{
	textFont = *font;
}

TTF_Font* Model::GameWindowModel::GetTextFont()
{
	return textFont;
}

void Model::GameWindowModel::SetTextColor(SDL_Color *color)
{
	textColor = *color;
}

SDL_Color Model::GameWindowModel::GetTextColor()
{
	return textColor;
}

void Model::GameWindowModel::SetGameOverStr(SDL_Surface **surfaceStr)
{
	gameOverStr = *surfaceStr;
}

SDL_Surface* Model::GameWindowModel::GetGameOverStr()
{
	return gameOverStr;
}

void Model::GameWindowModel::SetGameOverRect(SDL_Rect *rect)
{
	gameOverRect = *rect;
}

SDL_Rect Model::GameWindowModel::GetGameOverRect()
{
	return gameOverRect;
}
