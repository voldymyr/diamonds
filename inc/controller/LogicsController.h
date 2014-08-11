/*
 * LogicsController.h
 *
 *  Created on: Jun 29, 2014
 *      Author: voldymyr
 */

#ifndef LOGICSCONTROLLER_H_
#define LOGICSCONTROLLER_H_

#include "../model/GameBoardModel.h"
#include "../view/GameBoardView.h"

namespace Controller
{
	class LogicsController
	{
	public:
		LogicsController();
		~LogicsController();

		bool SwapAllowed() const;
		void SetSwapAllowed(bool status);
		bool SwapBackAllowed() const;
		void SetSwapBackAllowed(bool status);
		bool MoveDownAllowed() const;
		void SetMoveDownAllowed(bool status);
		bool DropNewAllowed() const;
		void SetDropNewAllowed(bool status);

		bool Swap(float move);
		bool SwapBack(float move);
		bool MoveDown(float move);
		bool DropNew(float move);

		bool FindAndRemoveChains();
		bool CheckForMoves();
		bool HandleLMButtonClick(float x, float y);

		void DispatchDrawElements(SDL_Surface*& window);
		void InitGameBoard(int w, int h);
		void ShuffleElements();
		void LoadElementImages(map<ElementType, string>& imgs);

		void SetGameBoardDimension(int x, int y);
		void SetElementDimensions(int x, int y);
		void SetElementOffset(int offs);
		void SetElementsStartPixelsXY(int x, int y);
		float CalculateMovePoints(Uint32 old, Uint32 curr);
		void ClearSwapPair();
		void FindChainsForSwapPair();
		void RemoveChainsFromBoard();
		void CountMoveSteps();
		void CreateNewElements();
		void SetDropLineYPos(int y);

	private:
		int IsElementClicked(float x, float y);
		bool PairSelected(int id);
		void CheckMoveValidity();
		bool ChainValid(int col, int row);

	private:
		View::GameBoardView* gameBoardView;
		Model::GameBoardModel* gameBoardModel;

		bool allowSwap;
		bool allowSwapBack;
		bool allowMoveDown;
		bool allowDropNew;

		bool swapBackDone;

		float move;

		// this vector holds all chains (3 or more elements in a row or/and column)
		vector<vector<Model::BoardElement> > chains;

		// ID of element on the board that will move down
		vector<int> srcElementID;

		// ID of element that srcElement should move to
		vector<int> dstElementID;

		// state of elements that are moving down (moved, not moved)
		vector<bool> movedDown;

		// IDs of elements that should be dropped
		vector<int> toBeDropped;

		// Pair of elements that are going to be swapped
		vector<Model::BoardElement> swapPair;

		// all possible moves are stored here
		vector< vector<Model::BoardElement> > movesRegistry;
	};
}


#endif /* LOGICSCONTROLLER_H_ */
