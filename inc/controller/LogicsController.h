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

		bool Swap();
		bool SwapBack();
		bool MoveDown();
		bool DropNew();

		bool FindAndRemoveChains();
		bool CheckForMoves();
		void HandleLMButtonClick(float x, float y);

		void DispatchDraw();

	private:
		bool SwapPossible();
		void CheckMoveValidity();

	private:
		View::GameBoardView* gameBoardView;
		Model::GameBoardModel* gameBoardModel;

		bool allowSwap;
		bool allowSwapBack;
		bool allowMoveDown;
		bool allowDropNew;
	};
}


#endif /* LOGICSCONTROLLER_H_ */
