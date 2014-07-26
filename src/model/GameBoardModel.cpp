/*
 * GameBoardModel.cpp
 *
 *  Created on: Jul 4, 2014
 *      Author: khrystynka
 */


#include "../../inc/model/GameBoardModel.h"

Model::GameBoardModel::GameBoardModel()
{
	elementWidth = 0;
	elementHeight = 0;
	elementOffset = 0;
	elementStartPixelX = 0;
	elementStartPixelY = 0;
	boardWidth = 0;
	boardHeight = 0;
}

Model::GameBoardModel::~GameBoardModel()
{
}

void Model::GameBoardModel::InitLevelModel(vector<BoardElement> &lm)
{
	levelModel = lm;
}

vector<Model::BoardElement> Model::GameBoardModel::GetLevelModel() const
{
	return levelModel;
}

void Model::GameBoardModel::InitBoardElements(vector<BoardElement>& be)
{
	elements = be;
}

vector<Model::BoardElement> Model::GameBoardModel::GetBoardElements() const
{
	return elements;
}

Model::BoardElement Model::GameBoardModel::GetLevelModelElementByID(int id) const
{
	return levelModel.at(id);
}

Model::BoardElement Model::GameBoardModel::GetBoardElementByID(int id) const
{
	return elements.at(id);
}

void Model::GameBoardModel::SetBoardElementByID(int id, BoardElement el)
{
	elements.at(id) = el;
}

void Model::GameBoardModel::SetElementWidth(int w)
{
	elementWidth = w;
}

int Model::GameBoardModel::GetElementWidth() const
{
	return elementWidth;
}

void Model::GameBoardModel::SetElementHeight(int h)
{
	elementHeight = h;
}

int Model::GameBoardModel::GetElementHeight() const
{
	return elementHeight;
}

void Model::GameBoardModel::SetBoardWidth(int w)
{
	boardWidth = w;
}

int Model::GameBoardModel::GetBoardWidth() const
{
	return boardWidth;
}

void Model::GameBoardModel::SetBoardHeight(int h)
{
	boardHeight = h;
}

int Model::GameBoardModel::GetBoardHeight() const
{
	return boardHeight;
}

void Model::GameBoardModel::SetElementOffset(int offs)
{
	elementOffset = offs;
}

int Model::GameBoardModel::GetElementOffset() const
{
	return elementOffset;
}

void Model::GameBoardModel::SetElementStartPixelX(int x)
{
	elementStartPixelX = x;
}

int Model::GameBoardModel::GetElementStartPixelX() const
{
	return elementStartPixelX;
}

void Model::GameBoardModel::SetElementStartPixelY(int y)
{
	elementStartPixelY = y;
}

int Model::GameBoardModel::GetElementStartPixelY() const
{
	return elementStartPixelY;
}

void Model::GameBoardModel::LoadElementImages(map<ElementType, string>& imgs)
{
	for(map<ElementType, string>::iterator it = imgs.begin(); it != imgs.end(); ++it)
	{
		elementImages.insert(make_pair<ElementType, SDL_Surface*>(it->first, IMG_Load(it->second.c_str())));
		if(!elementImages.at(it->first))
			cout << "Could not load Element PNG: " << SDL_GetError() << endl;
	}
}

void Model::GameBoardModel::UnloadElementImages()
{
	for(map<ElementType, SDL_Surface*>::iterator it = elementImages.begin(); it!= elementImages.end(); ++it)
			SDL_FreeSurface(it->second);
}

map<ElementType, SDL_Surface*> Model::GameBoardModel::GetElementImages() const
{
	return elementImages;
}

int Model::GameBoardModel::GetNumElementImages()
{
	return elementImages.size();
}
