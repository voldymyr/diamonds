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

	validPairSelected = false;

	allowSwap = false;
	allowSwapBack = false;
	allowMoveDown = false;
	allowDropNew = false;

	allMoved = 0;
	allDropped = 0;

	swapBackDone = false;
	move = 0.0;
	score = 0;
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

bool Controller::LogicsController::Swap(float move)
{
	Model::BoardElement lvlElement0 = gameBoardModel->GetLevelModelElementByID(swapPair[0].id);
	Model::BoardElement lvlElement1 = gameBoardModel->GetLevelModelElementByID(swapPair[1].id);
	Model::BoardElement element0 = gameBoardModel->GetBoardElementByID(swapPair[0].id);
	Model::BoardElement element1 = gameBoardModel->GetBoardElementByID(swapPair[1].id);

	// If elements are on the same x axis, move them vertically on y axis
	if(swapPair[0].pos.x == swapPair[1].pos.x)
	{
		if(swapPair[0].pos.y > swapPair[1].pos.y)
		{

				if(element0.pos.y <= lvlElement1.pos.y)
				{
					// swap
					element0.pos.y = lvlElement1.pos.y;
					element1.pos.y = lvlElement0.pos.y;

					element0.id = lvlElement1.id;
					element1.id = lvlElement0.id;

					gameBoardModel->SetBoardElementByID(lvlElement0.id, element1);
					gameBoardModel->SetBoardElementByID(lvlElement1.id, element0);

					return true;
				}
				else
				{
					element0.pos.y -= (int)move;
					element1.pos.y += (int)move;
					gameBoardModel->SetBoardElementByID(element0.id, element0);
					gameBoardModel->SetBoardElementByID(element1.id, element1);

					return false;
				}

		}
		else if(swapPair[0].pos.y < swapPair[1].pos.y)
		{
				if(element0.pos.y >= lvlElement1.pos.y)
				{
					// swap
					element0.pos.y = lvlElement1.pos.y;
					element1.pos.y = lvlElement0.pos.y;

					element0.id = lvlElement1.id;
					element1.id = lvlElement0.id;

					gameBoardModel->SetBoardElementByID(lvlElement0.id, element1);
					gameBoardModel->SetBoardElementByID(lvlElement1.id, element0);

					return true;
				}
				else
				{
					element0.pos.y += (int)move;
					element1.pos.y -= (int)move;
					gameBoardModel->SetBoardElementByID(element0.id, element0);
					gameBoardModel->SetBoardElementByID(element1.id, element1);

					return false;
				}

		}
	}
	else if(swapPair[0].pos.y == swapPair[1].pos.y) // if elements are on same y axis, move them horizontally
	{
		if(swapPair[0].pos.x > swapPair[1].pos.x)
		{
				if(element0.pos.x <= lvlElement1.pos.x)
				{
					// swap
					element0.pos.x = lvlElement1.pos.x;
					element1.pos.x = lvlElement0.pos.x;

					element0.id = lvlElement1.id;
					element1.id = lvlElement0.id;

					gameBoardModel->SetBoardElementByID(lvlElement0.id, element1);
					gameBoardModel->SetBoardElementByID(lvlElement1.id, element0);

					return true;
				}
				else
				{
					element0.pos.x -= (int)move;
					element1.pos.x += (int)move;
					gameBoardModel->SetBoardElementByID(element0.id, element0);
					gameBoardModel->SetBoardElementByID(element1.id, element1);

					return false;
				}
		}
		else
		{
				if(element0.pos.x >= lvlElement1.pos.x)
				{
					// swap
					element0.pos.x = lvlElement1.pos.x;
					element1.pos.x = lvlElement0.pos.x;

					element0.id = lvlElement1.id;
					element1.id = lvlElement0.id;

					gameBoardModel->SetBoardElementByID(lvlElement0.id, element1);
					gameBoardModel->SetBoardElementByID(lvlElement1.id, element0);

					return true;
				}
				else
				{
					element0.pos.x += (int)move;
					element1.pos.x -= (int)move;
					gameBoardModel->SetBoardElementByID(element0.id, element0);
					gameBoardModel->SetBoardElementByID(element1.id, element1);

					return false;
				}

		}
	}

}

bool Controller::LogicsController::SwapBack(float move)
{
	if(Swap(move))
	{
		if(swapBackDone)
		{
			swapBackDone = false;
			return true;
		}
		else
			swapBackDone = true;
	}

	return false;
}

bool Controller::LogicsController::MoveDown(float move)
{
	vector<Model::BoardElement> diamonds = gameBoardModel->GetBoardElements();
	vector<Model::BoardElement> level = gameBoardModel->GetLevelModel();
	move += 1;

	for(unsigned int i = 0; i < srcElementID.size(); i++)
	{
		if(movedDown.at(i) == false)
		{
			if(diamonds.at(srcElementID.at(i)).pos.y >= level.at(dstElementID.at(i)).pos.y)
			{
				diamonds.at(srcElementID.at(i)).pos.y = level.at(dstElementID.at(i)).pos.y;
				diamonds.at(srcElementID.at(i)).id = level.at(dstElementID.at(i)).id;

				diamonds.at(dstElementID.at(i)).pos.y = level.at(srcElementID.at(i)).pos.y;
				diamonds.at(dstElementID.at(i)).id = level.at(srcElementID.at(i)).id;

				swap(diamonds[srcElementID.at(i)], diamonds[dstElementID.at(i)]);

				gameBoardModel->SetBoardElementByID(srcElementID.at(i), diamonds.at(srcElementID.at(i)));
				gameBoardModel->SetBoardElementByID(dstElementID.at(i), diamonds.at(dstElementID.at(i)));

				allMoved++;
				movedDown.at(i) = true;
			}
			else
			{
				diamonds.at(srcElementID.at(i)).pos.y += (int)move;
				gameBoardModel->SetBoardElementByID(diamonds.at(srcElementID.at(i)).id, diamonds.at(srcElementID.at(i)));
			}
		}
	}

	// Return true only when all elements have finished moving down
	if(allMoved == srcElementID.size())
	{
		allMoved = 0;
		return true;
	}
	else
		return false;
}

bool Controller::LogicsController::DropNew(float move)
{
	vector<Model::BoardElement> diamonds = gameBoardModel->GetBoardElements();
	vector<Model::BoardElement> level = gameBoardModel->GetLevelModel();
	move += 1;

	for(unsigned int i = 0; i < toBeDropped.size(); i++)
	{
		if(dropped.at(i) == false)
		{
			if(diamonds.at(toBeDropped.at(i)).pos.y >= level.at(toBeDropped.at(i)).pos.y)
			{
				diamonds.at(toBeDropped.at(i)).pos.y = level.at(toBeDropped.at(i)).pos.y;

				gameBoardModel->SetBoardElementByID(toBeDropped.at(i), diamonds.at(toBeDropped.at(i)));
				allDropped++;
				dropped.at(i) = true;
			}
			else
			{
				diamonds.at(toBeDropped.at(i)).pos.y += (int)move;
				gameBoardModel->SetBoardElementByID(toBeDropped.at(i), diamonds.at(toBeDropped.at(i)));
			}
		}
	}

	if(allDropped == toBeDropped.size())
	{
		allDropped = 0;
		return true;
	}
	else
	{
		return false;
	}

	return true;
}

bool Controller::LogicsController::FindAndRemoveChains()
{
	chains.clear();
	vector<Model::BoardElement> elementsInChain;
	bool chainRemoved = false;
	int boardHeight = gameBoardModel->GetBoardHeight();
	int boardWidth = gameBoardModel->GetBoardWidth();
	vector<Model::BoardElement> diamonds = gameBoardModel->GetBoardElements();

	vector<int> elementsInXChain;
	vector<int> elementsInYChain;

	for(int row = 0; row < boardHeight; row++)
	{
		for(int col = 0; col < boardWidth; col++)
		{
			chains.clear();
			Model::BoardElement currentElement = diamonds[(row * boardWidth) + col];

			if(currentElement.type != None)
			{

				// check elements to the right
				for(int i = col + 1; i < boardWidth; i++)
				{
					if(diamonds[(row * boardWidth) + i].type == currentElement.type)
					{
						elementsInXChain.push_back(diamonds[(row * boardWidth) + i].id);
						elementsInChain.push_back(diamonds[(row * boardWidth) + i]);
					}
					else
						break;
				}

				// check elements to the left
				for(int j = col - 1; j >= 0; j--)
				{
					if(diamonds[(row * boardWidth) + j].type == currentElement.type)
					{
						elementsInXChain.push_back(diamonds[((row * boardWidth) + j)].id);
						elementsInChain.push_back(diamonds[(row * boardWidth) + j]);
					}
					else
						break;
				}

				// check if there are more than 3 elements in a row
				if((elementsInXChain.size() + 1) >= 3)
				{
					chains.push_back(elementsInChain);
					Model::BoardElement tmpEl = currentElement;
					tmpEl.type = None;
					gameBoardModel->SetBoardElementByID(tmpEl.id, tmpEl);

					for(unsigned int i = 0; i < elementsInXChain.size(); i++)
					{
						diamonds[elementsInXChain.at(i)].type = None;
						gameBoardModel->SetBoardElementByID(elementsInXChain.at(i), diamonds[elementsInXChain.at(i)]);
					}
					elementsInXChain.clear();
					chainRemoved = true;
				}
				else
				{
					elementsInXChain.clear();
					elementsInChain.clear();
				}

				// check elements down
				for(int ii = row + 1; ii < boardHeight; ii++)
				{
					if(diamonds[(ii * boardWidth) + col].type == currentElement.type)
					{
						elementsInYChain.push_back(diamonds[(ii * boardWidth) + col].id);
						elementsInChain.push_back(diamonds[(ii * boardWidth) + col]);
					}
					else
						break;
				}

				// check elements up
				for(int jj = row - 1; jj >= 0; jj--)
				{
					if(diamonds[(jj * boardWidth) + col].type == currentElement.type)
					{
						elementsInYChain.push_back(diamonds[(jj * boardWidth) + col].id);
						elementsInChain.push_back(diamonds[(jj * boardWidth) + col]);
					}
					else
						break;
				}

				// check if there are more than 3 elements in a column
				if((elementsInYChain.size() + 1) >= 3)
				{
					chains.push_back(elementsInChain);
					Model::BoardElement tmpEl = currentElement;
					tmpEl.type = None;
					gameBoardModel->SetBoardElementByID(tmpEl.id, tmpEl);

					for(unsigned int i = 0; i < elementsInYChain.size(); i++)
					{
						diamonds[elementsInYChain.at(i)].type = None;
						gameBoardModel->SetBoardElementByID(elementsInYChain.at(i), diamonds[elementsInYChain.at(i)]);
					}
					elementsInYChain.clear();
					chainRemoved = true;
				}
				else
				{
					elementsInYChain.clear();
					elementsInChain.clear();
				}

				CalculateScore();

			}
			else
				continue;

		}
	}

	return chainRemoved;
}

bool Controller::LogicsController::CheckForMoves()
{
	movesRegistry.clear();
	int boardHeight = gameBoardModel->GetBoardHeight();
	int boardWidth = gameBoardModel->GetBoardWidth();
	vector<Model::BoardElement> diamonds = gameBoardModel->GetBoardElements();

	for(int row = 0; row < boardHeight; row++)
	{
		for(int col = 0; col < boardWidth; col++)
		{
			Model::BoardElement firstElement = diamonds[(row * boardWidth) + col];

			if(firstElement.type == None)
				continue;

			if(col < (boardWidth - 1))
			{
				Model::BoardElement nextElement = diamonds[(row * boardWidth) + (col + 1)];

				if(nextElement.type == None)
					continue;

				/* Swap elements in a row */
				int id = diamonds[(row * boardWidth) + col].id;
				diamonds[(row * boardWidth) + col].id = diamonds[(row * boardWidth) + (col + 1)].id;
				diamonds[(row * boardWidth) + (col + 1)].id = id;
				swap(diamonds[(row * boardWidth) + col], diamonds[(row * boardWidth) + (col + 1)]);

				/* Copy elements back to model */
				gameBoardModel->InitBoardElements(diamonds);

				/* Mark elements that form chains */
				if(ChainValid(col + 1, row) || ChainValid(col, row))
				{
					vector<Model::BoardElement> chain;
					chain.push_back(firstElement);
					chain.push_back(nextElement);
					movesRegistry.push_back(chain);
				}

				/* Swap elements back */
				id = diamonds[(row * boardWidth) + col].id;
				diamonds[(row * boardWidth) + col].id = diamonds[(row * boardWidth) + (col + 1)].id;
				diamonds[(row * boardWidth) + (col + 1)].id = id;
				swap(diamonds[(row * boardWidth) + col], diamonds[(row * boardWidth) + (col + 1)]);

				/* Copy elements back to model */
				gameBoardModel->InitBoardElements(diamonds);
			}

			if(row < (boardHeight - 1))
			{
				Model::BoardElement nextElement = diamonds[((row + 1) * boardWidth) + col];

				if(nextElement.type == None)
					continue;

				/* swap elements */
				int id = diamonds[(row * boardWidth) + col].id;
				diamonds[(row * boardWidth) + col].id = diamonds[((row + 1) * boardWidth) + col].id;
				diamonds[((row + 1) * boardWidth) + col].id = id;
				swap(diamonds[(row * boardWidth) + col], diamonds[((row + 1) * boardWidth) + col]);

				/* Copy elements back to model */
				gameBoardModel->InitBoardElements(diamonds);

				if(ChainValid(col, row + 1) || ChainValid(col, row))
				{
					vector<Model::BoardElement> chain;
					chain.push_back(firstElement);
					chain.push_back(nextElement);
					movesRegistry.push_back(chain);
				}

				/* Swap elements back */
				id = diamonds[(row * boardWidth) + col].id;
				diamonds[(row * boardWidth) + col].id = diamonds[((row + 1) * boardWidth) + col].id;
				diamonds[((row + 1) * boardWidth) + col].id = id;
				swap(diamonds[(row * boardWidth) + col], diamonds[((row + 1) * boardWidth) + col]);

				/* Copy elements back to model */
				gameBoardModel->InitBoardElements(diamonds);
			}
		}
	}

	if(movesRegistry.empty())
		return false;

	return true;
}

bool Controller::LogicsController::HandleLMButtonClick(float x, float y)
{
	bool bStatus = false;

	int elID = IsElementClicked(x, y);

	/* PairSelected should not be called if elID is negative */
	if(elID < 0)
	{
		swapPair.clear();
		return bStatus;
	}
	else
	{
		if(PairSelected(elID))
		{
			bStatus = true;
			CheckMoveValidity();
		}
	}

	return bStatus;
}

int Controller::LogicsController::IsElementClicked(float x, float y)
{
	int elID = -1;
	static vector<Model::BoardElement> diamonds = gameBoardModel->GetBoardElements();
    int elWidth = gameBoardModel->GetElementWidth();
    int elHeight = gameBoardModel->GetElementHeight();

	for(unsigned int i = 0; i < diamonds.size(); i++)
	{
		//if((x > diamonds.at(i).pos.x) && (x < diamonds.at(i).pos.x + elWidth) && (y > diamonds.at(i).pos.y) && (y < diamonds.at(i).pos.y + elHeight))
		if((x > diamonds.at(i).pos.x) && (x < diamonds.at(i).pos.x + elWidth))// && (y > diamonds.at(i).pos.y) && (y < diamonds.at(i).pos.y + elHeight))
		{
            if((y > diamonds.at(i).pos.y) && (y < diamonds.at(i).pos.y + elHeight))
            {       
			    elID = diamonds.at(i).id;
			    break;
            }
		}
	}

	return elID;
}

bool Controller::LogicsController::PairValid(void)
{
	return validPairSelected;
}

void Controller::LogicsController::SetValidPairSelected(bool bStatus)
{
	validPairSelected = bStatus;
}

bool Controller::LogicsController::PairSelected(int id)
{
	if(id >= 0)
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
					validPairSelected = true;
					swapPair.push_back(gameBoardModel->GetBoardElementByID(id));
					return true;
				}
				else if((id == (swapPair[0].id + gameBoardModel->GetBoardWidth())) || (id == (swapPair[0].id - gameBoardModel->GetBoardWidth())))
				{
					validPairSelected = true;
					swapPair.push_back(gameBoardModel->GetBoardElementByID(id));
					return true;
				}
				else
				{
					validPairSelected = false;
					swapPair.clear();
					swapPair.push_back(gameBoardModel->GetBoardElementByID(id));
					return false;
				}
			}
			else
				return false;
		}
	}

	return true;
}

void Controller::LogicsController::CheckMoveValidity()
{
	for(unsigned int i = 0; i < movesRegistry.size(); i++)
	{
		if((movesRegistry.at(i)[0].id == swapPair[0].id) && (movesRegistry.at(i)[1].id == swapPair[1].id))
		{
			allowSwap = true;
			break;
		}
		else if((movesRegistry.at(i)[0].id == swapPair[1].id) && (movesRegistry.at(i)[1].id == swapPair[0].id))
		{
			allowSwap = true;
			break;
		}
	}

	if(!allowSwap)
		allowSwapBack = true;
}

bool Controller::LogicsController::ChainValid(int col, int row)
{
	int boardWidth = gameBoardModel->GetBoardWidth();
	int idx = (row * boardWidth) + col;
	vector<Model::BoardElement> diamonds = gameBoardModel->GetBoardElements();
	ElementType firstElType = diamonds[idx].type;

	// One element is already selected
	int numElsInRow = 1;

	// Check consequent elements to the right from clicked one
	for(int i = col + 1; i < boardWidth; i++)
	{
		if(diamonds[((row * boardWidth) + i)].type == firstElType)
			numElsInRow++;
		else
			break;
	}

	// Check consequent elements to the left from clicked one
	for(int i = col - 1; i >= 0; i--)
	{
		if(diamonds[(row * boardWidth) + i].type == firstElType)
			numElsInRow++;
		else
			break;
	}

	if(numElsInRow >= 3)
		return true;

	// One element is already selected
	int numElsInCol = 1;
	int boardHeight = gameBoardModel->GetBoardHeight();

	// Check consequent elements upward from clicked one
	for(int i = row + 1; i < boardHeight; i++)
	{
		if(diamonds[(i * boardWidth) + col].type == firstElType)
			numElsInCol++;
		else
			break;
	}

	// Check consequent elements downward from clicked one
	for(int i = row - 1; i >= 0; i--)
	{
		if(diamonds[(i * boardWidth) + col].type == firstElType)
			numElsInCol++;
		else
			break;
	}

	return (numElsInCol >= 3) ? true : false;
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
	gameBoardModel->ClearElements();

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

	// Initialize level model as well
	gameBoardModel->InitLevelModel(bElements);
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

float Controller::LogicsController::CalculateMovePoints(Uint32 old, Uint32 curr)
{
	return ((curr - old) / 1000.0f) * 200.0f;
}

void Controller::LogicsController::ClearSwapPair()
{
	swapPair.clear();
}

void Controller::LogicsController::FindChainsForSwapPair()
{
	chains.clear();
	vector<Model::BoardElement> elementsInChain;

	int bWidth = gameBoardModel->GetBoardWidth();
	int bHeight = gameBoardModel->GetBoardHeight();
	vector<Model::BoardElement> diamonds = gameBoardModel->GetBoardElements();

	/* There are two elements that have been swapped */
	for(int i = 0; i < 2; i++)
	{
		/* Identify row and col of current element */
		int col = swapPair.at(i).id % bWidth;
		int row = swapPair.at(i).id / bHeight;

		Model::BoardElement swappedEl = diamonds[((row * bWidth) + col)];
		elementsInChain.push_back(swappedEl);

		/* Check consequent elements to the right */
		for(int j = col + 1; j < bWidth; j++)
		{
			if(diamonds[((row * bWidth) + j)].type == swappedEl.type)
				elementsInChain.push_back(diamonds[((row * bWidth) + j)]);
			else
				break;
		}

		/* Check consequent elements to the left */
		for(int k = col - 1; k >= 0; k--)
		{
			if(diamonds[(row * bWidth) + k].type == swappedEl.type)
				elementsInChain.push_back(diamonds[((row * bWidth) + k)]);
			else
				break;
		}

		if(elementsInChain.size() >= 3)
		{
			chains.push_back(elementsInChain);

			elementsInChain.clear();
			elementsInChain.push_back(swappedEl);
		}
		else
		{
			elementsInChain.clear();
			elementsInChain.push_back(swappedEl);
		}


		/* Check consequent elements upward */
		for(int jj = row + 1; jj < bHeight; jj++)
		{
			if(diamonds[(jj * bHeight) + col].type == swappedEl.type)
				elementsInChain.push_back(diamonds[(jj * bHeight) + col]);
			else
				break;
		}

		/* Check consequent elements downward */
		for(int kk = row - 1; kk >= 0; kk--)
		{
			if(diamonds[(kk * bHeight) + col].type == swappedEl.type)
				elementsInChain.push_back(diamonds[(kk * bHeight) + col]);
			else
				break;
		}

		if(elementsInChain.size() >= 3)
		{
			chains.push_back(elementsInChain);

			elementsInChain.clear();
		}
		else
			elementsInChain.clear();
	}

}

void Controller::LogicsController::RemoveChainsFromBoard()
{
	vector<Model::BoardElement> diamonds = gameBoardModel->GetBoardElements();

	for(unsigned int i = 0; i < chains.size(); i++)
	{
		for(unsigned int j = 0; j < chains.at(i).size(); j++)
		{
			diamonds[chains.at(i).at(j).id].type = None;
			diamonds[chains.at(i).at(j).id].value = None;
		}
	}

	gameBoardModel->InitBoardElements(diamonds);
}

void Controller::LogicsController::CountMoveSteps()
{
	srcElementID.clear();
	dstElementID.clear();
	movedDown.clear();

	int bWidth = gameBoardModel->GetBoardWidth();
	int bHeight = gameBoardModel->GetBoardHeight();
	vector<Model::BoardElement> diamonds = gameBoardModel->GetBoardElements();

	int moveSteps = 0;

	/* Loop through the whole board of elements starting at the bottom right */
	for(int row = bHeight - 1; row >= 0; row--)
	{
		for(int col = bWidth - 1; col >= 0; col--)
		{
			/* Find element of type None and check how many elements
			 * of same type are there in a row or/and column */
			if(diamonds[(row * bWidth) + col].type == None)
			{
				bool bSkip = false;
				/* See if you can check elements below for type None */
				for(int i = 1; i < bHeight; i++)
				{
					if(((((row + i) * bWidth) + col) <= ((bWidth * bHeight) - 1)))
					{
						/* If None then we skip */
						if(diamonds[(((row + i) * bWidth) + col)].type == None)
						{
							bSkip = true;
							break;
						}
					}
					else
						break;
				}

				if(bSkip)
					continue;

				moveSteps++;

				for(int i = 1; i < bHeight; i++)
				{
					if(((((row + i) * bWidth) + col) <= ((bWidth * bHeight) - 1)))
					{
						/* Check if the type of this element is also None */
						if(diamonds[(((row + i) * bWidth) + col)].type == None)
						{
							moveSteps++;
						}
					}
					else
						break;
				}

				/* Go up in rows */
				for(int i = 1; i < bHeight; i++)
				{
					/* Make sure we do not go beyond upper boundary */
					if((row - i) >= 0)
					{
						/* Check how many elements above are of type None */
						if(diamonds[((row - i) * bWidth) + col].type == None)
							moveSteps++;
						else
						{
							srcElementID.push_back(diamonds[((row - i) * bWidth) + col].id);
							movedDown.push_back(false);
							dstElementID.push_back(diamonds[(((row - i) * bWidth) + col) + (moveSteps * bWidth)].id);
						}
					}
					else
						break;
				}
			}
			else
				continue;

			moveSteps = 0;
		}
	}

}

void Controller::LogicsController::CreateNewElements()
{
	toBeDropped.clear();
	dropped.clear();
	vector<ElementType> tmpElTypes;

	int bWidth = gameBoardModel->GetBoardWidth();
	int bHeight = gameBoardModel->GetBoardHeight();
	vector<Model::BoardElement> diamonds = gameBoardModel->GetBoardElements();
	int yPos = gameBoardModel->GetDropLineYPos();

	for(int row = 0; row < bHeight; row++)
	{
		for(int col = 0; col < bWidth; col++)
		{
			if(diamonds[(row * bWidth) + col].type == None)
			{
				// save element id for later use
				toBeDropped.push_back(((row * bWidth) + col));
				dropped.push_back(false);

				ElementType tmp;

				// Generate element type and check if 2 previously generated types are not the same
				do
				{
					// Generate element type, but not None
					do
					{
						unsigned int numImages = gameBoardModel->GetNumElementImages();
						tmp = (ElementType)((rand() % numImages + 1) * 10);
					}while(tmp == None);

				}while((toBeDropped.size() >= 2) && (tmp == tmpElTypes[(tmpElTypes.size() - 1)]) && (tmp == tmpElTypes[(tmpElTypes.size() - 2)]));

				// Save generated element type and assign it to current element on the game board
				tmpElTypes.push_back(tmp);
				diamonds[(row * bWidth) + col].type = tmp;
				diamonds[(row * bWidth) + col].value = (int)tmp;
				diamonds[(row * bWidth) + col].pos.y = yPos;

				gameBoardModel->SetBoardElementByID(((row * bWidth) + col), diamonds[(row * bWidth) + col]);
			}
		}
	}
	tmpElTypes.clear();

}

void Controller::LogicsController::SetDropLineYPos(int y)
{
	gameBoardModel->SetDropLineYPos(y);
}

void Controller::LogicsController::CalculateScore()
{
	int tmpScore = 0;
	int scorePerSwap = 0;

	for(unsigned int i = 0; i < chains.size(); i++)
	{
		tmpScore = 0;
		// Sum up elements in one chain
		for(unsigned int j = 0; j < chains.at(i).size(); j++)
			tmpScore += chains.at(i).at(j).value;

		// multiply calculated score per chain by 2 if chain has 4 or 5 elements
		if(chains.at(i).size() >= 4)
			tmpScore = tmpScore * 2;

		scorePerSwap += tmpScore;

	}

	// if user has matched 2 or more chains, multiply his result by 2
	if(chains.size() >= 2)
		scorePerSwap *= 2;

	score += scorePerSwap;

}

void Controller::LogicsController::GameReset()
{
	allMoved = allDropped = 0;
}

void Controller::LogicsController::SetScore(int newScore)
{
	score = newScore;
}

int Controller::LogicsController::GetScore()
{
	return score;
}