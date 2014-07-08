/*
 * LogicsController.cpp
 *
 *  Created on: Jul 2, 2014
 *      Author: khrystynka
 */

#include "../../inc/controller/LogicsController.h"

Controller::LogicsController::LogicsController()
{
	gameBoardView = new View::GameBoardView();
	gameBoardModel = new Model::GameBoardModel();

	allowSwap = false;
	allowSwapBack = false;
	allowMoveDown = false;
	allowDropNew = false;
}

Controller::LogicsController::~LogicsController()
{
	delete gameBoardModel;
	delete gameBoardView;
}

bool Controller::LogicsController::SwapAllowed() const
{
	return allowSwap;
}

void Controller::LogicsController::SetSwapAllowed(bool status)
{
	allowSwap = status;
}

bool Controller::LogicsController::SwapBackAllowed() const
{
	return allowSwapBack;
}

void Controller::LogicsController::SetSwapBackAllowed(bool status)
{
	allowSwapBack = status;
}

bool Controller::LogicsController::MoveDownAllowed() const
{
	return allowMoveDown;
}

void Controller::LogicsController::SetMoveDownAllowed(bool status)
{
	allowMoveDown = status;
}

bool Controller::LogicsController::DropNewAllowed() const
{
	return allowDropNew;
}

void Controller::LogicsController::SetDropNewAllowed(bool status)
{
	allowDropNew = status;
}

bool Controller::LogicsController::Swap()
{
	return true;
}

bool Controller::LogicsController::SwapBack()
{
	return true;
}

bool Controller::LogicsController::MoveDown()
{
	return true;
}

bool Controller::LogicsController::DropNew()
{
	return true;
}

bool Controller::LogicsController::FindAndRemoveChains()
{
	return false;
}

bool Controller::LogicsController::CheckForMoves()
{
	return true;
}

void Controller::LogicsController::HandleLMButtonClick(float x, float y)
{
	if(SwapPossible())
		CheckMoveValidity();
}

bool Controller::LogicsController::SwapPossible()
{
	return false;
}

void Controller::LogicsController::CheckMoveValidity()
{
}
void Controller::LogicsController::DispatchDraw()
{

}
