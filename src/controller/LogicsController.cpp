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

bool Controller::LogicsController::HandleLMButtonClick(float x, float y)
{
	bool bStatus = false;

	int elID = IsElementClicked(x, y);
	if(PairSelected(elID))
	{
		bStatus = true;
		CheckMoveValidity();
	}

	return bStatus;
}

int Controller::LogicsController::IsElementClicked(float x, float y)
{
	int elID = -1;
	vector<Model::BoardElement> diamonds = gameBoardModel->GetBoardElements();

	for(unsigned int i = 0; i < diamonds.size(); i++)
	{
		if((x > diamonds.at(i).pos.x) && (x < diamonds.at(i).pos.x + gameBoardModel->GetElementWidth()) && (y > diamonds.at(i).pos.y) && (y < diamonds.at(i).pos.y + gameBoardModel->GetElementHeight()))
		{
			elID = diamonds.at(i).id;
			break;
		}
	}

	return elID;
}

bool Controller::LogicsController::PairSelected(int id)
{
	if(id < 0)
	{
		if(swapPair.empty())
			return false;
		else if(swapPair.size() == 1)
		{
			swapPair.clear();
			return false;
		}
	}
	else if(id >= 0)
	{
		if(swapPair.empty())
		{
			swapPair.push_back(gameBoardModel->GetBoardElementByID(id));
			return false;
		}
		else if(swapPair.size() == 1)
		{
			if(id != swapPair[0].id)
			{
				// get row and col of last selected element
				int element2Col = id % gameBoardModel->GetBoardWidth();
				int element2Row = id / gameBoardModel->GetBoardWidth();

				// get row and col of previously selected element
				int element1Col = swapPair[0].id % gameBoardModel->GetBoardWidth();
				int element1Row = swapPair[0].id / gameBoardModel->GetBoardWidth();

				// check if elements are on the same row and whether last element is to the left or to the right of previously selected element
				if( (element2Row == element1Row) && (element2Col == (element1Col - 1) || element2Col == (element1Col + 1)))
				{
					swapPair.push_back(gameBoardModel->GetBoardElementByID(id));
					return true;
				}
				else if((id == (swapPair[0].id + gameBoardModel->GetBoardWidth())) || (id == (swapPair[0].id - gameBoardModel->GetBoardWidth())))
				{
					swapPair.push_back(gameBoardModel->GetBoardElementByID(id));
					return true;
				}
				else
				{
					swapPair.clear();
					swapPair.push_back(gameBoardModel->GetBoardElementByID(id));
					return false;
				}
			}
			else
				return false;
		}
	}

}

void Controller::LogicsController::CheckMoveValidity()
{
	for(unsigned int i = 0; i < movesRegistry.size(); i++)
	{
		if((movesRegistry.at(i)[0] == swapPair[0].id) && (movesRegistry.at(i)[1] == swapPair[1].id))
		{
			allowSwap = true;
			break;
		}
		else if((movesRegistry.at(i)[0] == swapPair[1].id) && (movesRegistry.at(i)[1] == swapPair[0].id))
		{
			allowSwap = true;
			break;
		}
	}

	if(!allowSwap)
		allowSwapBack = true;
}

void Controller::LogicsController::DispatchDraw()
{

}

void Controller::LogicsController::InitGameBoard(int w, int h)
{
	gameBoardModel->SetBoardWidth(w);
	gameBoardModel->SetBoardHeight(h);
}
