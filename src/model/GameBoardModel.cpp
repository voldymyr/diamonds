/*
 * GameBoardModel.cpp
 *
 *  Created on: Jul 4, 2014
 *      Author: khrystynka
 */


#include "../../inc/model/GameBoardModel.h"

Model::GameBoardModel::GameBoardModel()
{
}

Model::GameBoardModel::~GameBoardModel()
{
}

vector<Model::BoardElement> Model::GameBoardModel::GetLevelModel() const
{
	return levelModel;
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
