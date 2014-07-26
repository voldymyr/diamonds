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

void Controller::LogicsController::DispatchDrawElements(SDL_Surface*& window)
{
	map<ElementType, SDL_Surface*> images = gameBoardModel->GetElementImages();
	vector<Model::BoardElement> els = gameBoardModel->GetBoardElements();

	gameBoardView->DrawElements(window, images, els);
}

void Controller::LogicsController::InitGameBoard(int w, int h)
{
	gameBoardModel->SetBoardWidth(w);
	gameBoardModel->SetBoardHeight(h);
}

void Controller::LogicsController::ShuffleElements()
{
	int bWidth = gameBoardModel->GetBoardWidth();
	int bHeight = gameBoardModel->GetBoardHeight();
	int elHeight = gameBoardModel->GetElementHeight();
	int elWidth = gameBoardModel->GetElementWidth();
	int elOffset = gameBoardModel->GetElementOffset();
	int numImages = gameBoardModel->GetNumElementImages();
	int initX = gameBoardModel->GetElementStartPixelX(); //320 not yet set
	int initY = gameBoardModel->GetElementStartPixelY(); //100
	int offset_x = elWidth + elOffset;
	int offset_y = 0;

	Model::BoardElement tmpEl;
	vector<Model::BoardElement> bElements;

	//elements.clear();

	for(int row = 0; row < bHeight; row++)
	{
		for(int col = 0; col < bWidth; col++)
		{
			// make sure we do not have more than 2 elements of same type in a row or column
			do
			{
				// generate element type, but not type "None"
				do
				{
					tmpEl.type = (ElementType)((rand() % numImages + 1) * 10);
				}while(tmpEl.type == None);

			}while(((col >= 2) && (tmpEl.type == bElements[(row * bWidth) + (col - 1)].type) && (tmpEl.type == bElements[(row * bWidth) + (col - 2)].type)) || ((row >= 2) && (tmpEl.type == bElements[((row - 1) * bWidth) + col].type) && (tmpEl.type == bElements[((row - 2) * bWidth) + col].type)));

			tmpEl.value = (int)tmpEl.type;
			tmpEl.id = (row * bWidth) + col;
			tmpEl.pos.h = 36;
			tmpEl.pos.w = 36;

			if(col == 0)
			{
				tmpEl.pos.x = initX;
				tmpEl.pos.y = initY + offset_y;
				offset_y += elHeight + elOffset;
			}
			else
				tmpEl.pos.x += offset_x;

			bElements.push_back(tmpEl);
		}
	}
	gameBoardModel->InitBoardElements(bElements);
}

void Controller::LogicsController::LoadElementImages(map<ElementType, string>& imgs)
{
	gameBoardModel->LoadElementImages(imgs);
}

void Controller::LogicsController::SetGameBoardDimension(int x, int y)
{
	gameBoardModel->SetBoardWidth(x);
	gameBoardModel->SetBoardHeight(y);
}

void Controller::LogicsController::SetElementDimensions(int x, int y)
{
	gameBoardModel->SetElementWidth(x);
	gameBoardModel->SetElementHeight(y);
}

void Controller::LogicsController::SetElementOffset(int offs)
{
	gameBoardModel->SetElementOffset(offs);
}

void Controller::LogicsController::SetElementsStartPixelsXY(int x, int y)
{
	gameBoardModel->SetElementStartPixelX(x);
	gameBoardModel->SetElementStartPixelY(y);
}
