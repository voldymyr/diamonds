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
