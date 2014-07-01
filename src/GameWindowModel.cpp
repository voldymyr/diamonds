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
	backGroundIMG = NULL;
	backGroundRect = {0, 0, 0, 0};
	textFont = NULL;
	textColor = {0, 0, 0};
	gameOverStr = NULL;
	gameOverRect = {0, 0, 0, 0};
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

void Model::GameWindowModel::SetBackGroundIMG(SDL_Surface **img)
{
	backGroundIMG = *img;
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
	textColor = color;
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
